#include "cMain.h"

cMain* cMain::mainWindow;

cMain::cMain( wxWindow* parent )
:
mainFrame( parent )
{
	mainWindow = this;
	m_statusBar->SetStatusText("No Mission Open", 2);
}

cMain::~cMain() {
	wxLogDebug("Deleting cMain");
}

void cMain::updateSettings() {
	cSettings* set = cSettings::getMain();
	set->gameType = getGameType();
	set->minPlayers = getMinPlayers();
	set->maxPlayers = getMaxPlayers();
	set->respawnType = getRespawnType();
	set->respawnOnStart = getStartRespawn();
	set->hudOptions = getHudSettings();
	set->showMap = getMap();
	set->corpseMode = getCorpseMode();
	set->disableAI = getAi();
	set->adminConsole = getAdmin();
	set->channels = getChannels();

	set->showCompass = getCompass();
	set->showGPS = getGPS();
	set->showWatch = getWatch();
	set->groupIndicator = getGroupInd();
	set->showUAVFeed = getUAV();
	set->aiKills = getAiKills();

	set->wreckMode = getWreckMode();
	set->wreckLimit = getWreckLimit();
	set->wreckMinTime = getWreckMinTime();
	set->wreckMaxTime = getWreckMaxTime();

	set->corpseLimit = getCorpseLimit();
	set->corpseMinTime = getCorpseMinTime();
	set->corpseMaxTime = getCorpseMaxTime();

	set->minPlayerDistance = getMinPlayerDistance();

	set->respawnButton = getRespawnButton();
	set->respawnDialog = getRespawnDialog();
	set->respawnDelay = getRespawnDelay();
	set->vehRespawnDelay = getVehRespawnDelay();

	set->reviveMode = getReviveMode();
	set->damageModel = getDamageModel();
	set->medicNeeded = getMedic();
	set->fakConsumed = getFAK();
	set->reviveItem = getReviveItem();
	set->reviveTime = getReviveTime();
	set->medicMult = getMedicMult();
	set->forceRespawnDelay = getForceRespawnDelay();
	set->bleedOutTime = getBleedOutTime();

	updateLoadouts();
}

void cMain::updateLoadScreen() {
	cLoadScreen* set = cLoadScreen::getLoadScreen();
	set->mapName = getMapName();
	set->mapAuthor = getMapAuthor();

	set->missionName = getMissionName();
	set->missionAuthor = getMissionAuthor();
	set->missionBackground = getMissionBackground();

	set->mapBackground = getMapBackground();

	set->loadTxts = getLoadTexts();
}

void cMain::updateLoadouts() {
	cSettings* set = cSettings::getMain();
	cLoadoutDir* dir = set->loadouts;

	
	for (auto it = loadoutPages.begin(); it != loadoutPages.end(); ++it) {
		cLoadout* load = nullptr;
		cLoadoutPanel* pane = *it;
		for (auto i = dir->loadouts.begin(); i != dir->loadouts.end(); ++i) {
			if ((*i)->className == (*it)->className) {
				load = *i;
			}
		}
		if (load == nullptr) {
			wxLogDebug("Invalid Loadout to save");
			continue; // didnt find matching loadout
		}

		load->dispName = pane->m_loadoutDispName->GetValue();
		load->role = pane->m_role->GetValue();

		load->uniform = pane->m_uniform->GetValue();
		load->backpack = pane->m_backpack->GetValue();
		load->vest = pane->m_vest->GetValue();
		load->helmet = pane->m_helmet->GetValue();

		load->primary = pane->m_primary->GetValue();
		load->secondary = pane->m_secondary->GetValue();

		wxArrayString mags;
		wxLogDebug("Saving Mags");
		for (int idx = 0; idx < pane->m_magLB->GetCount(); ++idx) {
			wxString item = pane->m_magLB->GetString(idx);
			if (item.Contains("|")) {
				int cnt = cHelpers::toInt(item.AfterFirst('|'), 1);
				for (int i = 0; i < cnt; ++i) {
					mags.push_back(item.BeforeFirst('|').Trim(true).Trim());
				}
				continue;
			}
			mags.push_back(item.Trim(true).Trim());
		}

		load->mags = mags;

		wxArrayString items;
		wxLogDebug("Saving Items");
		for (int idx = 0; idx < pane->m_itemLB->GetCount(); ++idx) {
			wxString item = pane->m_itemLB->GetString(idx);
			if (item.Contains("|")) {
				int cnt = cHelpers::toInt(item.AfterFirst('|'), 1);
				for (int i = 0; i < cnt; ++i) {
					items.push_back(item.BeforeFirst('|').Trim(true).Trim());
				}
				continue;
			}
			items.push_back(item.Trim(true).Trim());
		}

		load->items = items;

		wxArrayString linked;
		for (int idx = 0; idx < pane->m_linkedItemsLB->GetCount(); ++idx) {
			linked.push_back(pane->m_linkedItemsLB->GetString(idx).Trim(true).Trim());
		}
		load->linked = linked;

		wxArrayString weap;
		for (int idx = 0; idx < pane->m_weaponsLB->GetCount(); ++idx) {
			weap.push_back(pane->m_weaponsLB->GetString(idx).Trim(true).Trim());
		}
		load->weapons = weap;
	}
}

void cMain::open_new_path() {
	open_new_path(cDetails::missionPath);
}

void cMain::open_new_path(const wxString path) {
	cDetails::missionPath = path;
	if (!std::filesystem::exists(path.ToStdString() + "description.ext")) {
		int dialog_return_value = wxNO;
		wxMessageDialog* dial = new wxMessageDialog(this, "Cannot find File:\n" + path.ToStdString() + "description.ext\n" "Create it now?", _("Description.ext missing"), wxYES_NO | wxYES_DEFAULT | wxICON_QUESTION);
		dialog_return_value = dial->ShowModal();
		if (dialog_return_value == wxYES)
		{
			wxMessageBox("File Created");
			std::ofstream {cDetails::missionPath.ToStdString() + "description.ext"};
		}
		return;
	}

	cSettings* set = cSettings::getMain();

	cLoadoutDir* loadDir = set->loadouts;
	std::vector<cLoadout*> loadouts = loadDir->loadouts;

	for (auto it = loadouts.begin(); it != loadouts.end(); ++it)
	{
		deleteLoadout((*it)->className);
	}
	m_loadoutLB->Clear();
	loadouts.clear(); // Ensure its clear

	cFileManager::readSettings(path + "description.ext", cSettings::getMain());
	setSettings();
	setLoadouts();
	cFileManager::readLoadScreen(path + "description.ext", cLoadScreen::getLoadScreen());
	setLoadScreen();
}

void cMain::setSettings()
{
	cSettings* set = cSettings::mainSettings;
	setGameType(set->gameType);
	setMinPlayers(set->minPlayers);
	setMaxPlayers(set->maxPlayers);
	setRespawnType(set->respawnType);
	setStartRespawn(set->respawnOnStart);
	setHudSettings(set->hudOptions);
	setMap(set->showMap);
	setCorpseMode(set->corpseMode);
	setAi(set->disableAI);
	setAdmin(set->adminConsole);
	setChannels(set->channels);

	setCompass(set->showCompass);
	setGPS(set->showGPS);
	setWatch(set->showWatch);
	setGroupInd(set->groupIndicator);
	setUAV(set->showUAVFeed);
	setAiKills(set->aiKills);

	setCorpseLimit(set->corpseLimit);
	setCorpseMinTime(set->corpseMinTime);
	setCorpseMaxTime(set->corpseMaxTime);
	setWreckLimit(set->wreckLimit);
	setWreckMode(set->wreckMode);
	setWreckMinTime(set->wreckMinTime);
	setWreckMaxTime(set->wreckMaxTime);

	setMinPlayerDistance(set->minPlayerDistance);

	setRespawnButton(set->respawnButton);
	setRespawnDialog(set->respawnDialog);
	setRespawnDelay(set->respawnDelay);
	setVehRespawnDelay(set->vehRespawnDelay);

	setReviveMode(set->reviveMode);
	setDamageModel(set->damageModel);
	setMedic(set->medicNeeded);
	setFAK(set->fakConsumed);
	setReviveItem(set->reviveItem);
	setReviveTime(set->reviveTime);
	setMedicMult(set->medicMult);
	setForceRespawnDelay(set->forceRespawnDelay);
	setBleedOutTime(set->bleedOutTime);
}

void cMain::setLoadScreen()
{
	cLoadScreen* set = cLoadScreen::getLoadScreen();
	setMapName(set->mapName);
	setMapAuthor(set->mapAuthor);
	setMissionName(set->missionName);
	setMissionAuthor(set->missionAuthor);
	setMissionBackground(set->missionBackground);
	setMapBackground(set->mapBackground);
	setLoadTexts(set->loadTxts);
}

void cMain::setLoadouts()
{
	cSettings* set = cSettings::getMain();

	cLoadoutDir* loadDir = set->loadouts;
	std::vector<cLoadout*> loadouts = loadDir->loadouts;

	for (std::vector<cLoadout*>::iterator i = loadouts.begin(); i != loadouts.end(); ++i)
	{
		cLoadout* load = *i;


		cLoadoutPanel* loadPage = new cLoadoutPanel(m_loadoutBook);

		loadPage->className = load->className;

		loadPage->m_loadoutDispName->SetValue(load->dispName);
		loadPage->m_role->SetValue(load->role);

		loadPage->m_uniform->SetValue(load->uniform);
		loadPage->m_backpack->SetValue(load->backpack);

		loadPage->m_primary->SetValue(load->primary);
		loadPage->m_secondary->SetValue(load->secondary);

		loadPage->m_vest->SetValue(load->vest);
		loadPage->m_helmet->SetValue(load->helmet);


		loadPage->updateLoadout(load);

		m_loadoutBook->AddPage(loadPage, load->className, false);

		m_loadoutLB->Append(load->className);

		loadoutPages.emplace_back(loadPage);
	}
}

void cMain::deleteLoadout(wxString className)
{
	

	int itemCnt = m_loadoutLB->GetCount();
	for (int i = 0; i < itemCnt; ++i)
	{
		if (m_loadoutLB->GetString(i) == className)
		{
			LOG("Removed LB Item for " + className);
			m_loadoutLB->Delete(i);
			break;
		}
	}

	cSettings* set = cSettings::getMain();
	set->loadouts->removeLoadout(className);

	for (auto it = loadoutPages.begin(); it != loadoutPages.end(); ++it) { // Remove Page from list
		if ((*it)->className == className) {
			LOG("Deleting Page " + className);
			loadoutPages.erase(it); // Remove hanging pointer from list, error when deleting, hope wxWidgets manages that to avoid a leak
			break;
		}
	}

	LOG("Page Size: " + wxString::Format(wxT("%i"), int(loadoutPages.size())));
	for (auto it = loadoutPages.begin(); it != loadoutPages.end(); ++it) {
		LOG("Loadout Page Remaining: " + (*it)->className);
	}

	int pageCnt = m_loadoutBook->GetPageCount();
	for (int idx = 0; idx < pageCnt; ++idx) { // Remove Tab
		if (m_loadoutBook->GetPageText(idx) == className)
		{
			LOG("Removed Tab For " + className);
			m_loadoutBook->RemovePage(idx);
			break;
		}
	}
}