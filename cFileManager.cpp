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
    }
    return true;
}

void cFileManager::parseOption(wxString& start, wxString& end)
{
    start = start.Trim().Trim(false);
    end = start.AfterFirst('=').Trim(false);
    start = start.Lower();
    start = start.BeforeFirst('=').Trim();
    if (end.ends_with(';')) end.RemoveLast();
    end.Replace(wxString("\""), wxString(""), true); // Remove Speech marks
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
			"\t};\n"
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

    desc << "showMap = " << (set->showMap ? "1" : "0") << ";" << std::endl;
    desc << "corpseManagerMode = " << set->corpseMode << ";" << std::endl;
    desc << "disabledAI = " << (set->disableAI ? "1" : "0") << ";" << std::endl;
    desc << "enableDebugConsole = " << set->adminConsole << ";" << std::endl;

    desc << "disableChannels[] = {\n\t{\n\t\t0, " << (set->channels->global.chat ? "false" : "true") << ", " << (set->channels->global.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t1, " <<
        (set->channels->side.chat ? "false" : "true") << ", " << (set->channels->side.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t2, " <<
        (set->channels->command.chat ? "false" : "true") << ", " << (set->channels->command.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t3, " <<
        (set->channels->group.chat ? "false" : "true") << ", " << (set->channels->group.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t4, " <<
        (set->channels->vehicle.chat ? "false" : "true") << ", " << (set->channels->vehicle.voice ? "false" : "true") << "\n\t},\n\t{\n\t\t5, " <<
        (set->channels->direct.chat ? "false" : "true") << ", " << (set->channels->direct.voice ? "false" : "true") << "\n\t}\n};" << std::endl;

    desc << "//&&& Anything below this line will be saved. Do not add any settings above this line";

    desc << file.Trim().ToStdString() << std::endl;
    desc.close();
    return true;
}
