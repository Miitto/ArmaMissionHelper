#include "cMain.h"



void cMain::save(wxCommandEvent& event)
{
	save();
	event.Skip();
}

void cMain::save()
{
	m_statusBar->SetStatusText("Saving...", 1);
	updateSettings();
	updateLoadScreen();
	if (cDetails::missionPath == "")
	{
		wxMessageBox("No Mission Opened", "Cannot Save");
	}
	if (cFileManager::writeSettings(cDetails::missionPath + "description.ext", cSettings::getMain(), cLoadScreen::getLoadScreen()))
	{
		m_statusBar->SetStatusText("Saved", 1);
	}
}

void cMain::saveAs(wxCommandEvent& event)
{
	m_statusBar->SetStatusText("Saving...", 1);
	updateSettings();
	updateLoadScreen();
	wxString path;
	if (FAILED(cFileManager::basicFolderOpen(path))) {
		m_statusBar->SetStatusText("Invalid Path, Closed", 1);
		return;
	}
	if (!path.EndsWith('/') || !path.EndsWith('\\')) {
		path.Append('\\');
	}
	cDetails::missionPath = path;
	if (cFileManager::writeSettings(cDetails::missionPath + "description.ext", cSettings::getMain(), cLoadScreen::getLoadScreen()))
	{
		m_statusBar->SetStatusText("Saved", 1);
	}
	m_statusBar->SetStatusText(cDetails::missionPath, 2);
	event.Skip();
}

void cMain::open(wxCommandEvent& event)
{
	wxString path;
	if (FAILED(cFileManager::basicFolderOpen(path))) {
		m_statusBar->SetStatusText("Invalid Path, Closed", 1);
		return;
	}
	if (!path.EndsWith('/') || !path.EndsWith('\\')) {
		path.Append('\\');
	}
	cDetails::missionPath = path;
	m_statusBar->SetStatusText(cDetails::missionPath, 2);
	m_statusBar->SetStatusText("Opened New Mission", 1);
	open_new_path(path);
	event.Skip();
}

void cMain::exit(wxCommandEvent& event)
{
	int dialog_return_value = wxNO;
	wxMessageDialog* dial = new wxMessageDialog(this, "Do you want to Save on Exit?", _("Save and Exit"), wxYES_NO | wxYES_DEFAULT | wxICON_QUESTION);
	dialog_return_value = dial->ShowModal();
	if (dialog_return_value)
	{
		save();
		std::ofstream{ cDetails::missionPath.ToStdString() + "description.ext" };
	}
	event.Skip();
}

void cMain::onTabChange(wxBookCtrlEvent& event)
{
	
	wxWindow* curWin = this->m_tabBook->GetCurrentPage();
	// If Settings Page
	int oldSel = event.GetOldSelection();
	if (oldSel == 0) updateSettings();
	else if (oldSel == 1) updateLoadScreen();
	event.Skip();
}

void cMain::gameTypeFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Set Mission Game Type", 0);
	event.Skip();
}

void cMain::minPlayersFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Set Min Players for Mission to Start", 0);
	event.Skip();
}

void cMain::maxPlayersFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Set Max Players in Mission", 0);
	event.Skip();
}

void cMain::respawnTypeFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Set the mode to use for Respawn", 0);
	event.Skip();
}

void cMain::startRespawnFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Whether to respawn / run events when player joins mission", 0);
	event.Skip();
}

void cMain::scriptedHudFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Overall HUD", 0);
	event.Skip();
}

void cMain::unitInfoFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Unit Info", 0);
	event.Skip();
}

void cMain::vehRadarFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Vehicle Radar", 0);
	event.Skip();
}

void cMain::vehInfoFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Vehicle Health / Ammo", 0);
	event.Skip();
}

void cMain::tankDirFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Tank Dir Indicator", 0);
	event.Skip();
}

void cMain::commandMenuFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Command Menu Enable", 0);
	event.Skip();
}

void cMain::grpInfoFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Group Member Overlay", 0);
	event.Skip();
}

void cMain::crosshairFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Crosshair and some other elements", 0);
	event.Skip();
}

void cMain::vehDisplayPanelFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Veh Side Panels (GPS Display)", 0);
	event.Skip();
}

void cMain::deathMsgFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Show Death Msgs", 0);
	event.Skip();
}

void cMain::forceDraw3DFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Force Icons for Draw3D events", 0);
	event.Skip();
}

void cMain::showMapFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Show Map at mission start", 0);
	event.Skip();
}

void cMain::corpseManagerFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("What the corpse Manager should remove when corpse threshold is reached", 0);
	event.Skip();
}

void cMain::disableAIFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Disable AI in the mission", 0);
	event.Skip();
}

void cMain::adminConsoleFocus(wxFocusEvent& event)
{
	m_statusBar->SetStatusText("Who has access to the admin console", 0);
	event.Skip();
}

void cMain::disableContextMenu(wxCommandEvent& event)
{
	wxRegKey dirKeyBack(wxRegKey::HKCU, "Software\\Classes\\directory\\Background\\shell");
	if (dirKeyBack.HasSubKey("ArmaMissionHelper"))
	{
		wxString key = "ArmaMissionHelper";
		dirKeyBack.DeleteKey(key);
	}

	wxRegKey dirKey(wxRegKey::HKCU, "Software\\Classes\\directory\\shell");
	if (dirKey.HasSubKey("ArmaMissionHelper"))
	{
		wxString key = "ArmaMissionHelper";
		dirKey.DeleteKey(key);
	}
}

void cMain::onMapBackground(wxFileDirPickerEvent& event)
{
	wxString path = m_worldBackground->GetPath();
	if (path.Contains(cDetails::missionPath))
	{
		path.Replace(cDetails::missionPath, "");
		m_worldBackground->SetPath(path);
	}
}

void cMain::onMissionBackground(wxFileDirPickerEvent& event)
{
	wxString path = m_missionBackground->GetPath();
	if (path.Contains(cDetails::missionPath))
	{
		path.Replace(cDetails::missionPath, "");
		m_missionBackground->SetPath(path);
	}
}
