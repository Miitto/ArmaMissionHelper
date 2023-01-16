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
	cSettings::mainSettings->gameType = getGameType();
	cSettings::mainSettings->minPlayers = getMinPlayers();
	cSettings::mainSettings->maxPlayers = getMaxPlayers();
	cSettings::mainSettings->respawnType = getRespawnType();
	cSettings::mainSettings->respawnOnStart = getStartRespawn();
	cSettings::mainSettings->hudOptions = getHudSettings();
	cSettings::mainSettings->showMap = getMap();
	cSettings::mainSettings->corpseMode = getCorpseMode();
	cSettings::mainSettings->disableAI = getAi();
	cSettings::mainSettings->adminConsole = getAdmin();
	cSettings::mainSettings->channels = getChannels();
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
