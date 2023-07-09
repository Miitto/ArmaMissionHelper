# include "cMain.h"

void cMain::newLoadout(wxCommandEvent& event)
{
	cSettings* set = cSettings::getMain();
	auto loadouts = set->loadouts->loadouts;

	wxString cNamePage;
	if (m_loadoutBook->GetPageCount() > 0)
	{
		cNamePage = m_loadoutBook->GetPageText(m_loadoutBook->GetSelection());
	}

	wxString name = cNamePage;
	wxTextEntryDialog* getName = new wxTextEntryDialog(this, "Creating New Loadout", "New Loadout", name);
	getName->ShowModal();
	name = getName->GetValue();

	if (name.IsEmpty()) {
		wxMessageBox("Loadout name cannot be blank", "Invalid Name");
		return;
	}

	if (m_loadoutBook->GetPageCount() > 0)
	{
		for (auto it = loadouts.begin(); it != loadouts.end(); ++it) { // Check if class name already exists
			if ((*it)->className == name) {
				wxMessageBox("There is already a loadout with that name", "Invalid Name");
				return;
			}
		}
	}

	cLoadout* newLoad = new cLoadout();
	newLoad->className = name; // Only value we have, for now
	set->loadouts->addLoadout(newLoad);

	cLoadoutPanel* loadPage = new cLoadoutPanel(m_loadoutBook); // Create new Loadout Page

	loadPage->className = newLoad->className;

	loadPage->m_loadoutDispName->SetValue(newLoad->dispName);
	loadPage->m_role->SetValue(newLoad->role);

	loadPage->m_uniform->SetValue(newLoad->uniform);
	loadPage->m_backpack->SetValue(newLoad->backpack);

	loadPage->m_primary->SetValue(newLoad->primary);
	loadPage->m_secondary->SetValue(newLoad->secondary);

	loadPage->m_vest->SetValue(newLoad->vest);
	loadPage->m_helmet->SetValue(newLoad->helmet);

	loadPage->updateLoadout(newLoad);

	m_loadoutBook->AddPage(loadPage, newLoad->className, true);

	m_loadoutLB->Append(name);

	loadoutPages.emplace_back(loadPage);
}

void cMain::dupeLoadout(wxCommandEvent& event)
{
	if (m_loadoutBook->GetPageCount() < 1)
	{
		return;
	}
	cSettings* set = cSettings::getMain();
	auto loadouts = set->loadouts->loadouts;

	wxString cNamePage;
	if (m_loadoutBook->GetPageCount() > 0)
	{
		cNamePage = m_loadoutBook->GetPageText(m_loadoutBook->GetSelection());
	}

	wxString newName = cNamePage;
	wxTextEntryDialog* getName = new wxTextEntryDialog(this, "Copying " + cNamePage + "to: ", "Duplicate Loadout", newName);
	getName->ShowModal();
	newName = getName->GetValue();

	if (newName.IsEmpty()) {
		wxMessageBox("Loadout name cannot be blank", "Invalid Name");
		return;
	}

	cLoadout* oldLoadout = nullptr;
	for (auto it = loadouts.begin(); it != loadouts.end(); ++it) { // Check if class name already exists
		if ((*it)->className == newName) {
			wxMessageBox("There is already a loadout with that name", "Invalid Name");
			return;
		}
		if ((*it)->className == cNamePage) // Found Class to Duplicate
		{
			oldLoadout = *it;
		}
	}

	if (oldLoadout == nullptr)
	{
		wxMessageBox("Loadout to Dupe not found", "Error");
		return;
	}

	cLoadout* newLoad = new cLoadout(newName, oldLoadout->dispName, oldLoadout->role, oldLoadout->uniform, oldLoadout->backpack, oldLoadout->primary, oldLoadout->secondary,
		oldLoadout->vest, oldLoadout->helmet, oldLoadout->linked, oldLoadout->weapons, oldLoadout->mags, oldLoadout->items);
	set->loadouts->addLoadout(newLoad);

	cLoadoutPanel* loadPage = new cLoadoutPanel(m_loadoutBook); // Create new Loadout Page

	loadPage->className = newLoad->className;

	loadPage->m_loadoutDispName->SetValue(newLoad->dispName);
	loadPage->m_role->SetValue(newLoad->role);

	loadPage->m_uniform->SetValue(newLoad->uniform);
	loadPage->m_backpack->SetValue(newLoad->backpack);

	loadPage->m_primary->SetValue(newLoad->primary);
	loadPage->m_secondary->SetValue(newLoad->secondary);

	loadPage->m_vest->SetValue(newLoad->vest);
	loadPage->m_helmet->SetValue(newLoad->helmet);

	loadPage->updateLoadout(newLoad);

	m_loadoutBook->AddPage(loadPage, newLoad->className, true);

	m_loadoutLB->Append(newName);

	loadoutPages.emplace_back(loadPage);
}

void cMain::renameLoadout(wxCommandEvent& event)
{
	if (m_loadoutBook->GetPageCount() < 1)
	{
		return;
	}
	cSettings* set = cSettings::getMain();
	auto loadouts = set->loadouts->loadouts;

	wxString cNamePage;
	if (m_loadoutBook->GetPageCount() > 0)
	{
		cNamePage = m_loadoutBook->GetPageText(m_loadoutBook->GetSelection());
	}
	wxString rename = cNamePage;
	wxTextEntryDialog* getName = new wxTextEntryDialog(this, "Renaming " + cNamePage + "to: ", "Rename Loadout", rename);
	getName->ShowModal();
	rename = getName->GetValue();

	if (rename.IsEmpty()) {
		wxMessageBox("Loadout name cannot be blank", "Invalid Name");
		return;
	}

	for (auto it = loadouts.begin(); it != loadouts.end(); ++it) { // Check if class name already exists
		if ((*it)->className == rename) {
			wxMessageBox("There is already a loadout with that name", "Invalid Name");
			return;
		}
	}

	int pageCnt = m_loadoutBook->GetPageCount();
	for (int idx = 0; idx < pageCnt; ++idx) { // Rename Page Title
		if (m_loadoutBook->GetPageText(idx) == cNamePage)
		{
			m_loadoutBook->SetPageText(idx, rename);
		}
	}

	int itemCnt = m_loadoutLB->GetCount();
	for (int i = 0; i < itemCnt; ++i)
	{
		if (m_loadoutLB->GetString(i) == cNamePage)
		{
			m_loadoutLB->SetString(i, rename);
			break;
		}
	}

	
	for (auto it = loadouts.begin(); it != loadouts.end(); ++it) { // Rename Loadout
		if ((*it)->className == cNamePage) {
			cLoadout* load = *it;
			load->className = rename;
			break;
		}
	}

	for (auto it = loadoutPages.begin(); it != loadoutPages.end(); ++it) { // Rename Page Class Name
		if ((*it)->className == cNamePage) {
			(*it)->className = rename;
			break;
		}
	}
}

void cMain::closeLoadout(wxCommandEvent& event)
{
	if (m_loadoutBook->GetPageCount() < 1)
	{
		return;
	}

	wxString cNamePage = m_loadoutBook->GetPageText(m_loadoutBook->GetSelection());
	int pageCnt = m_loadoutBook->GetPageCount();
	for (int idx = 0; idx < pageCnt; ++idx) { // Remove Tab
		if (m_loadoutBook->GetPageText(idx) == cNamePage)
		{
			m_loadoutBook->RemovePage(idx);
			return;
		}
	}
}

void cMain::deleteLoadout(wxCommandEvent& event)
{
	if (m_loadoutBook->GetPageCount() < 1)
	{
		return;
	}

	wxString cNameLB = m_loadoutLB->GetStringSelection();
	wxString cNamePage = m_loadoutBook->GetPageText(m_loadoutBook->GetSelection());

	if (cNameLB != cNamePage)
	{
		wxMessageBox("Loadout Selection must equal Loadout Page Opened", "2 Step Delete Failure");
		return;
	}

	deleteLoadout(cNameLB);
}

void cMain::selectLoadout(wxCommandEvent& event)
{
	wxString cName = event.GetString();
	if (m_loadoutBook->GetPageCount() > 0)
	{
		int pageCnt = m_loadoutBook->GetPageCount();
		for (int idx = 0; idx < pageCnt; ++idx) {
			if (m_loadoutBook->GetPageText(idx) == cName)
			{
				m_loadoutBook->SetSelection(idx);
				return;
			}
		}
	}
	for (auto it = loadoutPages.begin(); it != loadoutPages.end(); ++it) {
		if ((*it)->className == cName) {
			m_loadoutBook->AddPage(*it, cName, true);
			return;
		}
	}
}
