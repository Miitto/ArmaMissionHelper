#include "cMain.h"

// Settings Page

wxString cMain::getGameType() {
	return m_gameType->GetValue();
}

int cMain::getMinPlayers() {
	wxString val = m_minPlayers->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 1;
	}
	return int(num);
}

int cMain::getMaxPlayers() {
	wxString val = m_maxPlayers->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 30;
	}
	return int(num);
}

int cMain::getRespawnType() {
	return m_respawnType->GetCurrentSelection();
}

int cMain::getStartRespawn() {
	return (m_startRespawn->GetCurrentSelection() - 1);
}

std::bitset<11> cMain::getHudSettings() {
	std::bitset<11> hud;
	hud.set(0, m_scriptedHud->IsChecked());
	hud.set(1, m_unitInfo->IsChecked());
	hud.set(2, m_vehRadar->IsChecked());
	hud.set(3, m_vehCompass->IsChecked());
	hud.set(4, m_tankDir->IsChecked());
	hud.set(5, m_commandMenu->IsChecked());
	hud.set(6, m_grpInfo->IsChecked());
	hud.set(7, m_crosshair->IsChecked());
	hud.set(8, m_vehDispPanel->IsChecked());
	hud.set(9, m_deathMsg->IsChecked());
	hud.set(10, m_forceDraw3D->IsChecked());
	return hud;
}

bool cMain::getMap() {
	return m_showMap->IsChecked();
}

int cMain::getCorpseMode() {
	return m_corpseManager->GetCurrentSelection();
}

bool cMain::getAi() {
	return m_disableAi->IsChecked();
}

int cMain::getAdmin() {
	return m_adminConsole->GetCurrentSelection();
}

ChannelSet* cMain::getChannels() {
	ChannelSet* channels = new ChannelSet();
	channels->global.chat = m_globalChat->IsChecked();
	channels->global.voice = m_globalVoice->IsChecked();
	channels->side.chat = m_sideChat->IsChecked();
	channels->side.voice = m_sideVoice->IsChecked();
	channels->command.chat = m_commandChat->IsChecked();
	channels->command.voice = m_commandVoice->IsChecked();
	channels->group.chat = m_groupChat->IsChecked();
	channels->group.voice = m_groupVoice->IsChecked();
	channels->vehicle.chat = m_vehChat->IsChecked();
	channels->vehicle.voice = m_vehVoice->IsChecked();
	channels->direct.voice = m_dirVoice->IsChecked(); // Direct has no chat
	return channels;
}

int cMain::getCorpseLimit()
{
	wxString val = m_corpseLimit->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 15;
	}
	return int(num);
}

int cMain::getCorpseMinTime()
{
	wxString val = m_corpseMinTime->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 10;
	}
	return int(num);
}

int cMain::getCorpseMaxTime()
{
	wxString val = m_corpseMaxTime->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 3600;
	}
	return int(num);
}

int cMain::getWreckMode()
{
	return m_wreckManager->GetCurrentSelection();
}

int cMain::getWreckLimit()
{
	wxString val = m_wreckLimit->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 15;
	}
	return int(num);
}

int cMain::getWreckMinTime()
{
	wxString val = m_wreckMinTime->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 10;
	}
	return int(num);
}

int cMain::getWreckMaxTime()
{
	wxString val = m_wreckMaxTime->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 36000;
	}
	return int(num);
}

int cMain::getMinPlayerDistance()
{
	wxString val = m_minPlayerDistance->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 0;
	}
	return int(num);
}

bool cMain::getAiKills()
{
	return m_aiKills->IsChecked();
}

bool cMain::getUAV()
{
	return m_showUAVFeed->IsChecked();
}

bool cMain::getGroupInd()
{
	return m_showGroupIndicator->IsChecked();
}

bool cMain::getWatch()
{
	return m_showWatch->IsChecked();
}

bool cMain::getGPS()
{
	return m_showGPS->IsChecked();
}

bool cMain::getCompass()
{
	return m_showCompass->IsChecked();
}




// Load Screen Page

wxString cMain::getMapName() {
	return m_name->GetValue();
}

wxString cMain::getMapAuthor() {
	return m_author->GetValue();
}

wxString cMain::getMissionName() {
	return m_missionNameLocation->GetValue();
}

wxString cMain::getMissionAuthor() {
	return m_missionAuthorLocation->GetValue();
}

wxString cMain::getMissionBackground() {
	return m_missionBackground->GetPath();
}

wxString cMain::getMapBackground() {
	return m_worldBackground->GetPath();
}

wxArrayString cMain::getLoadTexts() {
	wxArrayString txts;
	int itemCnt = m_loadingTextLB->GetCount();
	for (int i = 0; i < itemCnt; ++i)
	{
		txts.push_back(m_loadingTextLB->GetString(i));
	}
	return txts;
}

// Settings Setters

void cMain::setGameType(wxString type)
{
	m_gameType->SetValue(type);
}

void cMain::setMinPlayers(int min)
{
	m_minPlayers->SetValue(wxString::Format(wxT("%i"), min));
}

void cMain::setMaxPlayers(int max)
{
	m_maxPlayers->SetValue(wxString::Format(wxT("%i"), max));
}

void cMain::setRespawnType(int type)
{
	m_respawnType->SetSelection(type);
}

void cMain::setStartRespawn(int type)
{
	m_startRespawn->SetSelection(type + 1);
}

void cMain::setHudSettings(std::bitset<11> hud)
{
	m_scriptedHud->SetValue(hud[0]);
	m_unitInfo->SetValue(hud[1]);
	m_vehRadar->SetValue(hud[2]);
	m_vehCompass->SetValue(hud[3]);
	m_tankDir->SetValue(hud[4]);
	m_commandMenu->SetValue(hud[5]);
	m_grpInfo->SetValue(hud[6]);
	m_crosshair->SetValue(hud[7]);
	m_vehDispPanel->SetValue(hud[8]);
	m_deathMsg->SetValue(hud[9]);
	m_forceDraw3D->SetValue(hud[10]);
}

void cMain::setMap(bool map)
{
	m_showMap->SetValue(map);
}

void cMain::setCorpseMode(int type)
{
	m_corpseManager->SetSelection(type);
}

void cMain::setAi(bool ai)
{
	m_disableAi->SetValue(ai);
}

void cMain::setAdmin(int admin)
{
	m_adminConsole->SetSelection(admin);
}

void cMain::setChannels(ChannelSet* channels)
{
	m_globalChat->SetValue(channels->global.chat);
	m_globalVoice->SetValue(channels->global.voice);
	m_sideChat->SetValue(channels->side.chat);
	m_sideVoice->SetValue(channels->side.voice);
	m_commandChat->SetValue(channels->command.chat);
	m_commandVoice->SetValue(channels->command.voice);
	m_groupChat->SetValue(channels->group.chat);
	m_groupVoice->SetValue(channels->group.voice);
	m_vehChat->SetValue(channels->vehicle.chat);
	m_vehVoice->SetValue(channels->vehicle.voice);
	m_dirVoice->SetValue(channels->direct.voice);
}

void cMain::setCorpseLimit(int num)
{
	m_corpseLimit->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setCorpseMinTime(int num)
{
	m_corpseMinTime->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setCorpseMaxTime(int num)
{
	m_corpseMaxTime->SetValue(wxString::Format(wxT("%i"), num));
}



void cMain::setWreckMode(int type)
{
	m_wreckManager->SetSelection(type);
}

void cMain::setWreckLimit(int num)
{
	m_wreckLimit->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setWreckMinTime(int num)
{
	m_wreckMinTime->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setWreckMaxTime(int num)
{
	m_wreckMaxTime->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setMinPlayerDistance(int num)
{
	m_minPlayerDistance->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setCompass(bool set)
{
	m_showCompass->SetValue(set);
}

void cMain::setGPS(bool set)
{
	m_showGPS->SetValue(set);
}

void cMain::setWatch(bool set)
{
	m_showWatch->SetValue(set);
}

void cMain::setUAV(bool set)
{
	m_showUAVFeed->SetValue(set);
}

void cMain::setAiKills(bool set)
{
	m_aiKills->SetValue(set);
}

void cMain::setGroupInd(bool set)
{
	m_showGroupIndicator->SetValue(set);
}


// Load Screen Setters

void cMain::setMapAuthor(wxString name)
{
	m_author->SetValue(name);
}

void cMain::setMapName(wxString name)
{
	m_name->SetValue(name);
}

void cMain::setMissionBackground(wxString back)
{
	m_missionBackground->SetPath(back);
}

void cMain::setMissionAuthor(wxString name)
{
	m_missionAuthorLocation->SetValue(name);
}

void cMain::setMissionName(wxString name)
{
	m_missionNameLocation->SetValue(name);
}

void cMain::setMapBackground(wxString back)
{
	m_worldBackground->SetPath(back);
}

void cMain::setLoadTexts(wxArrayString txts) {
	for (wxArrayString::iterator i = txts.begin(); i != txts.end(); ++i) {
		m_loadingTextLB->Append(*i);
	}
}


// Respawn Getters

bool cMain::getRespawnButton()
{
	return m_respawnButton->IsChecked();
}

bool cMain::getRespawnDialog()
{
	return m_respawnDialog->IsChecked();
}

int cMain::getRespawnDelay()
{
	wxString val = m_respawnDelay->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

int cMain::getVehRespawnDelay()
{
	wxString val = m_vehRespawnDelay->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

int cMain::getReviveMode()
{
	return m_reviveMode->GetCurrentSelection();
}

int cMain::getDamageModel()
{
	return m_damageModel->GetCurrentSelection();
}

bool cMain::getMedic()
{
	return m_medicNeeded->IsChecked();
}

bool cMain::getFAK()
{
	return m_fakConsumed->IsChecked();
}

int cMain::getReviveItem()
{
	return m_reviveItem->GetCurrentSelection();
}

int cMain::getReviveTime()
{
	wxString val = m_reviveTime->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

int cMain::getMedicMult()
{
	wxString val = m_medicMult->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

int cMain::getForceRespawnDelay()
{
	wxString val = m_forceRespawnDelay->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

int cMain::getBleedOutTime()
{
	wxString val = m_bleedOut->GetValue();
	long num;
	if (!val.ToLong(&num)) {
		return 5;
	}
	return int(num);
}

// Respawn Setters

void cMain::setRespawnButton(bool set)
{
	m_respawnButton->SetValue(set);
}

void cMain::setRespawnDialog(bool set)
{
	m_respawnDialog->SetValue(set);
}

void cMain::setRespawnDelay(int num)
{
	m_respawnDelay->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setVehRespawnDelay(int num)
{
	m_vehRespawnDelay->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setReviveMode(int type)
{
	m_reviveMode->SetSelection(type);
}

void cMain::setDamageModel(int num)
{
	m_damageModel->SetSelection(num);
}

void cMain::setMedic(bool set)
{
	m_medicNeeded->SetValue(set);
}

void cMain::setFAK(bool set)
{
	m_fakConsumed->SetValue(set);
}

void cMain::setReviveItem(int num)
{
	m_reviveItem->SetSelection(num);
}

void cMain::setReviveTime(int num)
{
	m_reviveTime->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setMedicMult(int num)
{
	m_medicMult->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setForceRespawnDelay(int num)
{
	m_forceRespawnDelay->SetValue(wxString::Format(wxT("%i"), num));
}

void cMain::setBleedOutTime(int num)
{
	m_bleedOut->SetValue(wxString::Format(wxT("%i"), num));
}
