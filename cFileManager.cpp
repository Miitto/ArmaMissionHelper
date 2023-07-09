#include "cFileManager.h"

HRESULT cFileManager::basicFolderOpen(WCHAR*& path)
{
    // CoCreate the File Open Dialog object.
    IFileDialog* pfd = NULL;
    HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&pfd));
    if (SUCCEEDED(hr))
    {
        // Create an event handling object, and hook it up to the dialog.
        IFileDialogEvents* pfde = NULL;
        hr = CDialogEventHandler::CreateInstance(IID_PPV_ARGS(&pfde));
        if (SUCCEEDED(hr))
        {
            // Hook up the event handler.
            DWORD dwCookie;
            hr = pfd->Advise(pfde, &dwCookie);
            if (SUCCEEDED(hr))
            {
                // Set the options on the dialog.
                DWORD dwFlags;

                // Before setting, always get the options first in order 
                // not to override existing options.
                hr = pfd->GetOptions(&dwFlags);
                if (SUCCEEDED(hr))
                {
                    // In this case, get shell items only for file system items.
                    hr = pfd->SetOptions(dwFlags | FOS_PICKFOLDERS);
                    if (SUCCEEDED(hr))
                    {
                        // Show the dialog
                        hr = pfd->Show(NULL);
                        if (SUCCEEDED(hr))
                        {
                            // Obtain the result once the user clicks 
                            // the 'Open' button.
                            // The result is an IShellItem object.
                            IShellItem* psiResult;
                            hr = pfd->GetResult(&psiResult);
                            if (SUCCEEDED(hr))
                            {
                                // We are just going to print out the 
                                // name of the file for sample sake.
                                hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH,
                                    &path);
                                if (SUCCEEDED(hr))
                                {
                                    CoTaskMemFree(path);
                                }
                                psiResult->Release();
                            }
                        }
                    }
                    else {
                        MessageBoxW(NULL, L"Failed", L"Error", MB_OK);
                    }
                }
                // Unhook the event handler.
                pfd->Unadvise(dwCookie);
            }
            pfde->Release();
        }
        pfd->Release();
    }
    return hr;
}

HRESULT cFileManager::basicFolderOpen(wxString& path) {
    WCHAR* w_path;
    const HRESULT hr = basicFolderOpen(w_path);
    path = w_path;
    return hr;
}

bool cFileManager::readSettings(const wxString path, cSettings* set)
{
    std::string text;
    std::vector<wxString> lines;
    std::ifstream desc(path.ToStdString());

    while (std::getline(desc, text))
    {
        lines.emplace_back(text);
    }

    desc.close();

    for (std::vector<wxString>::iterator i = lines.begin(); i != lines.end(); ++i)
    {
        i->Trim(false);
        wxString start, end;
        start = *i;
        parseOption(start, end);
        if (start == wxT("gametype")) set->gameType = end;
        OPT("minplayers") set->minPlayers = cHelpers::toInt(end, 1);
        OPT("maxplayers") set->maxPlayers = cHelpers::toInt(end, 45);
        OPT("respawn") set->respawnType = cHelpers::toInt(end, 3);
        OPT("respawnonstart") set->respawnOnStart = cHelpers::toInt(end, -1);
        OPT("showmap") set->showMap = end == wxT("1") ? true : false;
        OPT("corpsemanagermode") set->corpseMode = cHelpers::toInt(end, 2);
        OPT("disabledai") set->disableAI = end == wxT("1") ? true : false;
        OPT("enabledebugconsole") set->adminConsole = cHelpers::toInt(end, 1);
        OPT("respawnbutton") set->respawnButton = end == wxT("1") ? true : false;
        OPT("respawndelay") set->respawnDelay = cHelpers::toInt(end, 5);
        OPT("respawnvehicledelay") set->vehRespawnDelay = cHelpers::toInt(end, 5);
        OPT("respawndialog") set->respawnDialog = end == wxT("1") ? true : false;
        OPT("revivemode") set->reviveMode = cHelpers::toInt(end, 0);
        OPT("reviveunconsciousstatemode") set->damageModel = cHelpers::toInt(end, 0);
        OPT("reviverequiredtrait") set->medicNeeded = end == wxT("1") ? true : false;
        OPT("reviverequireditems") set->reviveItem = cHelpers::toInt(end, 2);
        OPT("reviverequireditemsfakconsumed") set->fakConsumed = end == wxT("1") ? true : false;
        OPT("revivemedicspeedmultiplier") set->medicMult = cHelpers::toInt(end, 2);
        OPT("revivedelay") set->reviveTime = cHelpers::toInt(end, 6);
    	OPT("reviveforcerespawndelay") set->respawnDelay = cHelpers::toInt(end, 3);
        OPT("revivebleedoutdelay") set->bleedOutTime = cHelpers::toInt(end, 120);
        OPT("corpselimit") set->corpseLimit = cHelpers::toInt(end, 15);
        OPT("corpseremovalmintime") set->corpseMinTime = cHelpers::toInt(end, 10);
        OPT("corpseremovalmaxtime") set->corpseMaxTime = cHelpers::toInt(end, 3600);
        OPT("wreckmanagermode") set->wreckMode = cHelpers::toInt(end, 2);
        OPT("wrecklimit") set->wreckLimit = cHelpers::toInt(end, 15);
        OPT("wreckremovalmintime") set->wreckMinTime = cHelpers::toInt(end, 10);
        OPT("wreckremovealmaxtime") set->wreckMaxTime = cHelpers::toInt(end, 36000);
        OPT("minplayerdistance") set->minPlayerDistance = cHelpers::toInt(end, 0);
        OPT("aikills") set->aiKills = end == wxT("1") ? true : false;
        OPT("showcompass") set->showCompass = end == wxT("1") ? true : false;
        OPT("showwatch") set->showWatch = end == wxT("1") ? true : false;
        OPT("showgps") set->showGPS = end == wxT("1") ? true : false;
        OPT("showuavfeed") set->showUAVFeed = end == wxT("1") ? true : false;
        OPT("showgroupindicator") set->groupIndicator = end == wxT("1") ? true : false;
        else if (start.starts_with("showhud"))
        {
            std::bitset<11> hud;
            wxString toParse;
	        while (true)
	        {
                wxString opt = i->BeforeFirst('/'); // remove comments
                opt.Replace(" ", "", true); // Remove all spaces
                opt.Replace("\t", "", true); // Remove all Tabs
                if (opt.Contains('{')) {
                    toParse.Append(opt.AfterFirst('{'));
                }
                else if (i->Contains("};"))
                {
                    toParse.Append(opt.BeforeFirst('}'));
                    break;
                } else
                {
                    toParse.Append(opt);
                }
                ++i;
	        }
            toParse.Replace("\n", "", true); // should now be format num,num,num,num
            wxStringTokenizer tokenizer(toParse, ",");
            int cnt = 0;
            while (tokenizer.HasMoreTokens())
            {
                wxString token = tokenizer.GetNextToken();
                // process token here
                hud.set(cnt, (token == wxT("1") ? true : false));
                ++cnt;
            }
            cSettings::mainSettings->hudOptions = hud;

        }
        else if (start.starts_with("disablechannels"))
        {
            wxString toParse;
            while (true) {
                wxString opt = i->BeforeFirst('/'); // remove comments
                opt.Replace(" ", "", true); // Remove all spaces
                opt.Replace("\t", "", true); // Remove all Tabs
                opt.Replace("\n", "", true); // Remove all New lines
                if (opt.Contains("};")) {
                    toParse.Append(opt.BeforeLast('}'));
                    break;
                }
                toParse.Append(opt);
                ++i;
            }
            toParse = toParse.AfterFirst('{');
            toParse.Replace("},{", ":", true);
            wxStringTokenizer tokenizer(toParse, ":");
            int cnt = 0;
            ChannelSet* channels = new ChannelSet();
            while (tokenizer.HasMoreTokens())
            {
                wxString token = tokenizer.GetNextToken();
                // process token here
                token.Replace('{', "", true);
                token.Replace('}', "", true);

                int id = cHelpers::toInt(token.BeforeFirst(','), 0);
                wxString chatStr = token.AfterFirst(',').BeforeLast(',');
                wxString voiceStr = token.AfterLast(',');

                bool chat = chatStr.MakeLower() == wxT("false");
                bool voice = voiceStr.MakeLower() == wxT("false");

                channels->set(id, chat, voice);
            }
            delete cSettings::mainSettings->channels;
            cSettings::mainSettings->channels = channels;
        }
        else if (i->Lower().Contains("cfgrespawninventory"))
        {
            LOG("Hit Cfg Inv");
            wxString curClass; // MUST have value
            wxString dispName = "";
            wxString role = "";

            wxString weap = "";
            wxString mags = "";
            wxString linked = "";
            wxString items = "";

            wxString uniform = "";
            wxString backpack = "";
            wxString vest = "";
            wxString helmet = "";

            wxString primary = "";
            wxString secondary = "";

            bool inSpeach = false;

            bool doubleClose = false;
             // Move from cfgRespawn line
            ++i;
            while (!i->Contains("};") && !doubleClose) // Break when class is closed
            {
                i->Replace("\t", "", true); // Remove Tabs
                i->Replace(";", "", true); // Remove ;
                i->Trim(false);


                if (i->starts_with("class")) {
                    curClass = i->Mid(5).BeforeFirst('{').Trim().Trim(false);
                    do {
                        *i = i->BeforeFirst('/').Trim().Trim(false);

                        wxString start1, end1; // Up here, Since needs to not be made lower to keep end1 true to config
                        start1 = *i;
                        parseOption(start1, end1, false);
                        if (start1.Lower().starts_with("uniformclass"))
                        {
                            end1.Replace("\"", "", true);
                            *i = i->BeforeFirst('/').Trim().Trim(false);
                            if (end1.ends_with(";")) {
                                end1.RemoveLast();
                            }
                            uniform = end1;
                        }
                        else if (start1.Lower().starts_with("backpack"))
                        {
                            end1.Replace("\"", "", true);
                            *i = i->BeforeFirst('/').Trim().Trim(false);
                            if (end1.ends_with(";")) {
                                end1.RemoveLast();
                            }
                            backpack = end1;
                        }
                        else if (start1.Lower().starts_with("displayname"))
                        {
                            end1.Replace("\"", "", true);
                            *i = i->BeforeFirst('/').Trim().Trim(false);
                            if (end1.ends_with(";")) {
                                end1.RemoveLast();
                            }
                            dispName = end1;
                        }
                        else if (start1.Lower().starts_with("role"))
                        {
                            end1.Replace("\"", "", true);
                            *i = i->BeforeFirst('/').Trim().Trim(false);
                            if (end1.ends_with(";")) {
                                end1.RemoveLast();
                            }
                            role = end1;
                        }

                        *i = i->Lower();
                        if (i->starts_with("weapons[]"))
                        {
                            weap.Append(i->AfterFirst('{')); // Add any info on first line
                            ++i;
                            while (!i->Contains("};")) // Iterate until param ends
                            {
                                i->Replace("\t", "", true); // Remove Whitespace
                                i->Replace(" ", "", true);
                                *i = i->BeforeFirst('/').Trim().Trim(false);

                                weap.Append(*i); // Append Line data
                                ++i;
                            }
                            weap.Append(i->BeforeFirst('}')); // Add any info on last line
                            ++i;
                            continue;
                        }
                        if (i->starts_with("magazines[]"))
                        {
                            mags.Append(i->AfterFirst('{')); // Add any info on first line
                            ++i;
                            while (!i->Contains("};")) // Iterate until param ends
                            {
                                i->Replace("\t", "", true); // Remove Whitespace
                                i->Replace(" ", "", true);
                                *i = i->BeforeFirst('/').Trim().Trim(false);

                                mags.Append(*i); // Append Line data
                                ++i;
                            }
                            mags.Append(i->BeforeFirst('}')); // Add any info on last line
                            ++i;
                            continue;
                        }
                        if (i->starts_with("items[]"))
                        {
                            items.Append(i->AfterFirst('{')); // Add any info on first line
                            ++i;
                            while (!i->Contains("};")) // Iterate until param ends
                            {
                                i->Replace("\t", "", true); // Remove Whitespace
                                i->Replace(" ", "", true);
                                *i = i->BeforeFirst('/').Trim().Trim(false);

                                items.Append(*i); // Append Line data
                                ++i;
                            }
                            items.Append(i->BeforeFirst('}')); // Add any info on last line
                            ++i;
                            continue;
                        }
                        if (i->starts_with("linkeditems[]"))
                        {
                            linked.Append(i->AfterFirst('{')); // Add any info on first line
                            ++i;
                            while (!i->Contains("};")) // Iterate until param ends
                            {
                                i->Replace("\t", "", true); // Remove Whitespace
                                i->Replace(" ", "", true);
                                *i = i->BeforeFirst('/').Trim().Trim(false);

                                linked.Append(*i); // Append Line data
                                ++i;
                            }
                            linked.Append(i->BeforeFirst('}')); // Add any info on last line
                            ++i;
                            continue;
                        }
                        ++i;
                    } while (!i->Contains("};"));
                    if (i->AfterFirst('}').Contains("};")) // Class closing, make sure we arn't moving out 2 scopes at once
                    {
                        doubleClose = true;
                    }
                    // Class Closed, save contents
                    linked.Replace("\"", "", true);
                    weap.Replace("\"", "", true);
                    mags.Replace("\"", "", true);
                    items.Replace("\"", "", true);
                    linked.Replace("\n", "", true);
                    weap.Replace("\n", "", true);
                    mags.Replace("\n", "", true);
                    items.Replace("\n", "", true);

                    wxArrayString linkedItems;
                    { // Linked Parse
                        wxStringTokenizer tokenizer(linked, ",");
                        int cnt = 0;
                        while (tokenizer.HasMoreTokens())
                        {
                            wxString token = tokenizer.GetNextToken();
                            // process token here
                            if (token.starts_with("V_")) // Hacked Approach, don't have enough data to be able to tell if is actually a vest... rely on dev good practice in hope
                            {
                                vest = token.Trim().Trim(false);
                            }
                            else if (token.starts_with("H_"))
                            {
                                helmet = token.Trim().Trim(false);
                            } else
                            {
                                linkedItems.push_back(token.Trim().Trim(false));
                            }
                        }
                    }
                    wxArrayString weapons;
                    { // Weap Parse
                        wxStringTokenizer tokenizer(weap, ",");
                        int cnt = 0;
                        while (tokenizer.HasMoreTokens())
                        {
                            wxString token = tokenizer.GetNextToken();
                            // process token here
                            switch (cnt)
                            {
                            case 0:
                                primary = token.Trim().Trim(false);
                                break;
                            case 1:
                                secondary = token.Trim().Trim(false);
                                break;
                            default:
                                weapons.push_back(token.Trim().Trim(false));
                            }
                            ++cnt;
                        }
                    }
                    wxArrayString magazines;
                    { // Mags Parse
                        wxStringTokenizer tokenizer(mags, ",");
                        int cnt = 0;
                        while (tokenizer.HasMoreTokens())
                        {
                            wxString token = tokenizer.GetNextToken();
                            // process token here
                            magazines.push_back(token.Trim().Trim(false));
                        }
                    }
                    wxArrayString itemList;
                    { // Items Parse
                        wxStringTokenizer tokenizer(items, ",");
                        int cnt = 0;
                        while (tokenizer.HasMoreTokens())
                        {
                            wxString token = tokenizer.GetNextToken();
                            // process token here
                            itemList.push_back(token.Trim().Trim(false));
                        }
                    }
                    cSettings* set = cSettings::getMain();
                    LOG("Added " + curClass);
                    set->loadouts->addLoadout(new cLoadout(curClass, dispName, role, uniform, backpack, primary, secondary, vest, helmet, linkedItems, weapons, magazines, itemList));
                }
                ++i;
            }
        }
    }
    return true;
}

void cFileManager::parseOption(wxString& start, wxString& end, bool makeLower, char descriminator)
{
    start = start.BeforeFirst('/').Trim().Trim(false);
    end = start.AfterFirst(descriminator).Trim(false);
    if (makeLower) {
        start = start.Lower();
    }
    start = start.BeforeFirst(descriminator).Trim();
    if (end.ends_with(';')) end.RemoveLast();
    end.Replace(wxString("\""), wxString(""), true); // Remove Speech marks
}

bool cFileManager::readLoadoutLists(wxArrayString& primaries, wxArrayString& secondaries, wxArrayString& uniforms, wxArrayString& backpacks, wxArrayString& linked, wxArrayString& weapons, wxArrayString& vest,
                                    wxArrayString& helmets, wxArrayString& mags, wxArrayString& items) {
    wxString path = wxStandardPaths::Get().GetUserLocalDataDir() + "\\loadouts.cfg";

    std::string text;
    std::vector<wxString> lines;
    if (!std::filesystem::exists(path.ToStdString())) {
        if (!std::filesystem::exists(wxStandardPaths::Get().GetUserLocalDataDir().ToStdString())) std::filesystem::create_directories(wxStandardPaths::Get().GetUserLocalDataDir().ToStdString()); // Create dirs for ofstream
        std::ofstream cfg(path.ToStdString()); // Create File if it does't exists for Users Ease of Use
        cfg << "// How to Add items\n"
            "// primary:display_name:class_name\n"
            "// secondary:display_name:class_name\n"
            "// uniform:display_name:class_name\n"
            "// backpack:display_name:class_name\n"
            "// linked:display_name:class_name\n"
            "// other_weap:display_name:class_name\n"
            "// vest:display_name:class_name\n"
            "// helmet:display_name:class_name\n"
            "// mag:display_name:class_name\n"
            "// item:display_name:class_name\n"
            << std::endl;
        return false; // No Settings Read
    }
    std::ifstream desc(path.ToStdString());

    while (std::getline(desc, text))
    {
        lines.emplace_back(text);
    }

    for (std::vector<wxString>::iterator i = lines.begin(); i != lines.end(); ++i)
    {
        wxString start, end;
        start = *i;
        parseOption(start, end, true, ':');
        if (start == "primary") primaries.push_back(end);
        OPT("secondary") secondaries.push_back(end);
        OPT("uniform") uniforms.push_back(end);
        OPT("backpack") backpacks.push_back(end);
        OPT("linked") linked.push_back(end);
        OPT("other_weap") weapons.push_back(end);
        OPT("vest") vest.push_back(end);
        OPT("helmet") helmets.push_back(end);
        OPT("mag") mags.push_back(end);
        OPT("item") items.push_back(end);
    }
    return true;
}

bool cFileManager::readLoadScreen(const wxString path, cLoadScreen* set)
{
    std::string text;
    std::vector<wxString> lines;
    std::ifstream desc(path.ToStdString());

    while (std::getline(desc, text))
    {
        lines.emplace_back(text);
    }

    desc.close();
    bool isMap = false;
    for (std::vector<wxString>::iterator i = lines.begin(); i != lines.end(); ++i)
    {
        i->Trim(false);
        wxString start, end;
        start = *i;
        parseOption(start, end);
        if (start == wxT("onloadname")) set->missionName = end;
        OPT("loadscreen") set->missionBackground = end;
        OPT("description") set->mapName = end;
        OPT("picturemap") set->mapBackground = end;
        else if (i->Lower().Contains("cfgworlds")) isMap = true;
        if (isMap)
        {
            if (start == wxT("author")) set->mapAuthor = end;
            OPT("loadingtexts[]") {
                wxArrayString loadTxt;
                { // Items Parse
                    wxStringTokenizer tokenizer(end, ",");
                    while (tokenizer.HasMoreTokens())
                    {
                        wxString token = tokenizer.GetNextToken();
                        token.Replace("{", "");
                        token.Replace("}", "");
                        // process token here
                        loadTxt.push_back(token.Trim().Trim(false));
                    }
                }
                set->loadTxts = loadTxt;
            }
            if (i->Contains("};")) {
                isMap = false;
            }
        }
        OPT("author") set->missionAuthor = end;
    }
    return true;
}

bool cFileManager::writeSettings(wxString path, cSettings* set, cLoadScreen* load)
{
    std::ifstream descIn(path.ToStdString());

    std::string text;
    wxString file;
    bool isCustom = false;
    while (std::getline(descIn, text))
    {
        if (isCustom) file.append("\n" + text);
        if (text.starts_with("//&&&")) isCustom = true;
    }
    descIn.close();
    std::ofstream desc(path.ToStdString());

    desc << "author = \"" << load->missionAuthor << "\";" << std::endl;
    desc << "onLoadName = \"" << load->missionName << "\";" << std::endl;
    desc << "onLoadMission = \"" << load->missionName << "\";" << std::endl;
    desc << "loadScreen = \"" << load->missionBackground << "\";" << std::endl;
    desc << "briefingName = \"" << load->missionName << "\";\n" << std::endl;

    desc << "class Header\n"
        "{\n"
        "\tgameType = " << set->gameType << ";\n"
        "\tminPlayers = " << set->minPlayers << ";\n"
        "\tmaxPlayers = " << set->maxPlayers << ";\n"
        "};\n" << std::endl;

    desc << "class CfgWorlds\n"
        "{\n"
        "\tclass Any\n"
        "\t{\n"
        "\t\tauthor = \"" << load->mapAuthor << "\";\n"
        "\t\tdescription = \"" << load->mapName << "\";\n"
        "\t\tpictureMap = \"" << load->mapBackground << "\";\n"
        "\t\tpictureShot = \"" << load->mapBackground << "\";\n"
        "\t\tloadingTexts[] = {";
    for (int i = 0; i < load->loadTxts.size(); ++i) {
        desc << "\"" << load->loadTxts[i] << "\"";
        if (i + 1 != load->loadTxts.size()) {
            desc << ", ";
        }
    }
    desc << "};" << std::endl;

    desc << "\t};\n"
        "};\n" << std::endl;

    desc << "respawn = " << set->respawnType << ";" << std::endl;
    desc << "respawnOnStart = " << set->respawnOnStart << ";\n" << std::endl;

    desc << "overviewText = \"" << load->missionName << " " << load->missionAuthor << "\";" << std::endl;
    desc << "overviewTextLocked = \"" << load->missionName << " " << load->missionAuthor << " | Mission Locked\";\n" << std::endl;

    std::bitset<11> hud = set->hudOptions;
    desc << "showHUD[] = {\n\t" <<
        hud.test(0) << ",\n\t" <<
        hud.test(1) << ",\n\t" <<
        hud.test(2) << ",\n\t" <<
        hud.test(3) << ",\n\t" <<
        hud.test(4) << ",\n\t" <<
        hud.test(5) << ",\n\t" <<
        hud.test(6) << ",\n\t" <<
        hud.test(7) << ",\n\t" <<
        hud.test(8) << ",\n\t" <<
        hud.test(9) << ",\n\t" <<
        hud.test(10) << ",\n};\n" << std::endl;

    desc << "showMap = " << (set->showMap ? "1" : "0") << ";\n" << std::endl;

    desc << "showWatch = " << (set->showWatch ? "1" : "0") << ";" << std::endl;
    desc << "showGPS = " << (set->showGPS ? "1" : "0") << ";" << std::endl;
    desc << "showCompass = " << (set->showCompass ? "1" : "0") << ";" << std::endl;
    desc << "showUAVFeed = " << (set->showUAVFeed ? "1" : "0") << ";" << std::endl;
    desc << "showGroupIndicator = " << (set->groupIndicator ? "1" : "0") << ";\n" << std::endl;

    desc << "aiKills = " << (set->aiKills ? "1" : "0") << ";\n" << std::endl;

    desc << "corpseManagerMode = " << set->corpseMode << ";" << std::endl;
    desc << "corpseLimit = " << set->corpseLimit << ";" << std::endl;
    desc << "corpseRemovalMinTime = " << set->corpseMinTime << ";" << std::endl;
    desc << "corpseRemovalMaxTime = " << set->corpseMaxTime << ";\n" << std::endl;

    desc << "wreckManagerMode = " << set->wreckMode << ";" << std::endl;
    desc << "wreckLimit = " << set->wreckLimit << ";" << std::endl;
    desc << "wreckRemovalMinTime = " << set->wreckMinTime << ";" << std::endl;
    desc << "wreckRemovalMaxTime = " << set->wreckMaxTime << ";" << std::endl;
    desc << "minPlayerDistance = " << set->minPlayerDistance << ";\n" << std::endl;

    desc << "respawnButton = " << (set->respawnButton ? "1" : "0") << ";" << std::endl;
    desc << "respawnDialog = " << (set->respawnDialog ? "1" : "0") << ";" << std::endl;
    desc << "reviveRequiredTrait = " << (set->medicNeeded ? "1" : "0") << ";" << std::endl;
    desc << "reviveRequiredItemsFakConsumed = " << (set->fakConsumed ? "1" : "0") << ";\n" << std::endl;

    desc << "respawnDelay = " << set->respawnDelay << ";" << std::endl;
    desc << "respawnVehicleDelay = " << set->vehRespawnDelay << ";\n" << std::endl;

    desc << "reviveMode = " << set->reviveMode << ";" << std::endl;
    desc << "reviveUnconsciousStateMode = " << set->damageModel << ";\n" << std::endl;

    desc << "reviveRequiredItems = " << set->reviveItem << ";" << std::endl;
    desc << "reviveMedicSpeedMultiplier = " << set->medicMult << ";" << std::endl;
    desc << "reviveDelay = " << set->reviveTime << ";" << std::endl;
    desc << "reviveForceRespawnDelay = " << set->forceRespawnDelay << ";" << std::endl;
    desc << "reviveBleedOutDelay = " << set->bleedOutTime << ";\n" << std::endl;

    desc << "disabledAI = " << (set->disableAI ? "1" : "0") << ";" << std::endl;
    desc << "enableDebugConsole = " << set->adminConsole << ";\n" << std::endl;

    desc << "disableChannels[] = {\n\t{\n\t\t0, " << (set->channels->global.chat ? "false" : "true") << ", " << (set->channels->global.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t1, " <<
        (set->channels->side.chat ? "false" : "true") << ", " << (set->channels->side.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t2, " <<
        (set->channels->command.chat ? "false" : "true") << ", " << (set->channels->command.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t3, " <<
        (set->channels->group.chat ? "false" : "true") << ", " << (set->channels->group.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t4, " <<
        (set->channels->vehicle.chat ? "false" : "true") << ", " << (set->channels->vehicle.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t5, " <<
        (set->channels->direct.chat ? "false" : "true") << ", " << (set->channels->direct.voice ? "false" : "true") << "\n\t}\n};\n" << std::endl;

    desc << "class CfgRespawnInventory\n{" << std::endl;

    cLoadoutDir* dir = set->loadouts;

    for (auto it = dir->loadouts.begin(); it != dir->loadouts.end(); ++it) {
        cLoadout* load = *it;

        desc << "\tclass " << load->className << std::endl;
        desc << "\t{\n"
            "\t\tdisplayName = \"" << load->dispName << "\";\n"
            "\t\trole = \"" << load->role << "\";\n" << std::endl;

        wxString weap;
        desc << "\t\tweapons[] = {" << std::endl;
        weap.Append("\t\t\t\"" + load->primary + "\",\n");
        weap.Append("\t\t\t\"" + load->secondary + "\",\n");
        for (auto i = load->weapons.begin(); i != load->weapons.end(); ++i) {
            weap.Append("\t\t\t\"" + i->Trim().Trim(false) + "\",\n");
        }
        weap.RemoveLast(2); // Remove trailing , and new line
        desc << weap << "\n"
            "\t\t};" << std::endl;

        wxString mag;
        desc << "\t\tmagazines[] = {" << std::endl;
        for (auto i = load->mags.begin(); i != load->mags.end(); ++i) {
            mag.Append("\t\t\t\"" + i->Trim().Trim(false) + "\",\n");
        }
        mag.RemoveLast(2); // Remove trailing , and new line
        desc << mag << "\n"
            "\t\t};" << std::endl;

        wxString link;
        desc << "\t\tlinkedItems[] = {" << std::endl;
        link.Append("\t\t\t\"" + load->vest + "\",\n");
        link.Append("\t\t\t\"" + load->helmet + "\",\n");
        for (auto i = load->linked.begin(); i != load->linked.end(); ++i) {
            link.Append("\t\t\t\"" + i->Trim().Trim(false) + "\",\n");
        }
        link.RemoveLast(2); // Remove trailing , and new line
        desc << link << "\n"
            "\t\t};" << std::endl;

        wxString item;
        desc << "\t\titems[] = {" << std::endl;
        for (auto i = load->items.begin(); i != load->items.end(); ++i) {
            item.Append("\t\t\t\"" + i->Trim().Trim(false) + "\",\n");
        }
        item.RemoveLast(2); // Remove trailing , and new line
        desc << item << "\n"
            "\t\t};\n" << std::endl;

        desc << "\t\tuniformClass = \"" << load->uniform << "\";" << std::endl;
        desc << "\t\tbackpack = \"" << load->backpack << "\";\n"
            "\t};\n};" << std::endl;
    }


    desc << "//&&& Anything below this line will be saved. Do not add any settings above this line";

    desc << file.Trim().ToStdString() << std::endl;
    desc.close();
    return true;
}
