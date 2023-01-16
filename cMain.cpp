#include "cMain.h"

cMain* cMain::mainWindow;

cMain::cMain( wxWindow* parent )
:
mainFrame( parent )
{
	mainWindow = this;
	m_statusBar->SetStatusText("No Mission Open", 2);
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
}

void cMain::updateLoadScreen() {
	cLoadScreen* set = cLoadScreen::getLoadScreen();
	set->mapName = getMapName();
	set->mapAuthor = getMapAuthor();

	set->missionName = getMissionName();
	set->missionAuthor = getMissionAuthor();
	set->missionBackground = getMissionBackground();

	set->mapBackground = getMapBackground();
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

	cFileManager::readSettings(path + "description.ext", cSettings::mainSettings);
	setSettings();
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
}
