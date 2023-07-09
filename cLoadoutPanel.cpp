#include "cLoadoutPanel.h"

cLoadoutPanel::cLoadoutPanel( wxWindow* parent )
:
LoadoutPanel( parent )
{
	loadLists();
}


cLoadoutPanel::cLoadoutPanel(wxWindow* parent, cLoadout* load)
:
LoadoutPanel(parent)
{
	loadLists();
	updateLoadout(load);
}

void cLoadoutPanel::loadLists() {
	wxString path = wxStandardPaths::Get().GetUserLocalDataDir();
	wxArrayString primaries, secondaries, uniforms, backpacks, linked, weapons, vest, helmets, mags, items;
	cFileManager::readLoadoutLists(primaries, secondaries, uniforms, backpacks, linked, weapons, vest, helmets, mags, items);

	m_primaryLB->Append(primaries);
	m_secondaryLB->Append(secondaries);
	m_uniformLB->Append(uniforms);
	m_backpackLB->Append(backpacks);
	m_linkedPresets->Append(linked);
	m_weapPresets->Append(weapons);
	m_vestLB->Append(vest);
	m_helmetLB->Append(helmets);
	m_magPresets->Append(mags);
	m_itemPresets->Append(items);
}

cLoadoutPanel::~cLoadoutPanel()
{
}

void cLoadoutPanel::updateLoadout(cLoadout* load)
{
	addMag(load);
	addItem(load);
	addLinked(load);
	addWeapon(load);
}

void cLoadoutPanel::addMag(cLoadout* load)
{
	addMag(load->mags);
}

void cLoadoutPanel::addMag(wxArrayString mags) {
	for (auto i = mags.begin(); i != mags.end(); ++i) {
		addMag(*i);
	}
}

void cLoadoutPanel::addMag(wxString mag)
{
	bool foundDupe = false;

	for (int idx = 0; idx < m_magLB->GetCount(); ++idx) {
		if (m_magLB->GetString(idx).Lower().BeforeFirst('|') == mag.Lower()) {
			wxString cur = m_magLB->GetString(idx);

			if (cur.Contains("|")) {
				int cnt = cHelpers::toInt(cur.AfterFirst('|'), 1) + 1;
				wxString newStr = cur.BeforeFirst('|') + "|" + wxString::Format(wxT("%i"), cnt);
				m_magLB->SetString(idx, newStr);
				foundDupe = true;
				break;
			}
			cur.Append("|2");
			m_magLB->SetString(idx, cur);
			foundDupe = true;
			break;
		}
	}
	if (!foundDupe) {
		wxString magToAdd = mag + "|1";
		wxLogDebug("Adding New Mag: " + magToAdd);
		m_magLB->Append(magToAdd);
		m_magLB->Refresh();
	}
}

void cLoadoutPanel::addItem(cLoadout* load)
{
	addItem(load->items);
}


void cLoadoutPanel::addItem(wxArrayString items) {
	for (auto i = items.begin(); i != items.end(); ++i) {
		addItem(*i);
	}
}

void cLoadoutPanel::addItem(wxString item)
{
	bool foundDupe = false;

	for (int idx = 0; idx < m_itemLB->GetCount(); ++idx) {
		if (m_itemLB->GetString(idx).Lower().BeforeFirst('|') == item.Lower()) {
			wxString cur = m_itemLB->GetString(idx);

			if (cur.Contains("|")) {
				int cnt = cHelpers::toInt(cur.AfterFirst('|'), 1) + 1;
				wxString newStr = cur.BeforeFirst('|') + "|" + wxString::Format(wxT("%i"), cnt);
				m_itemLB->SetString(idx, newStr);
				foundDupe = true;
				break;
			}
			cur.Append("|2");
			m_itemLB->SetString(idx, cur);
			foundDupe = true;
			break;
		}
	}
	if (!foundDupe) {
		wxString itemToAdd = item + "|1";
		wxLogDebug("Added New Item: " + itemToAdd);
		m_itemLB->Append(itemToAdd);
		m_itemLB->Refresh();
	}
}


void cLoadoutPanel::addLinked(cLoadout* load) {
	addLinked(load->linked);
}

void cLoadoutPanel::addLinked(wxArrayString linked)
{
	for (auto i = linked.begin(); i != linked.end(); ++i) {
		addLinked(*i);
	}
}

void cLoadoutPanel::addLinked(wxString link)
{
	bool foundDupe = false;

	for (int idx = 0; idx < m_itemLB->GetCount(); ++idx) {
		if (m_itemLB->GetString(idx).Lower() == link.Lower()) {
			foundDupe = true;
			break;
		}
	}
	if (!foundDupe) {
		m_linkedItemsLB->Append(link);
	}
}

void cLoadoutPanel::addWeapon(cLoadout* load) {
	addWeapon(load->weapons);
}

void cLoadoutPanel::addWeapon(wxArrayString weapons)
{
	for (auto i = weapons.begin(); i != weapons.end(); ++i) {
		addWeapon(*i);
	}
}

void cLoadoutPanel::addWeapon(wxString weap)
{
	bool foundDupe = false;

	for (int idx = 0; idx < m_itemLB->GetCount(); ++idx) {
		if (m_itemLB->GetString(idx).Lower() == weap.Lower()) {
			foundDupe = true;
			break;
		}
	}
	if (!foundDupe) {
		m_weaponsLB->Append(weap);
	}
}
