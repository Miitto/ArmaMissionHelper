#include "cLoadoutPanel.h"

void cLoadoutPanel::onUniformChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_uniform->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::onBackpackChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_backpack->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::onPrimaryChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_primary->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::onSecondaryChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_secondary->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::addCustomLinked(wxCommandEvent& event)
{
	wxString cust = m_linkedCustom->GetValue();
	if (cust != "") {
		addLinked(cust);
	}
	event.Skip();
}

void cLoadoutPanel::addPresetLinked(wxCommandEvent& event)
{
	wxString preset = m_linkedPresets->GetStringSelection();
	
	if (preset != "") {
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		addLinked(preset);
	}
	event.Skip();
}

void cLoadoutPanel::removePresetLinked(wxCommandEvent& event)
{
	wxString preset = m_linkedPresets->GetStringSelection();
	if (preset != "")
	{
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		for (int i = 0; i < m_linkedItemsLB->GetCount(); ++i)
		{
			if (m_linkedItemsLB->GetString(i) == preset)
			{
				m_linkedItemsLB->Delete(i);
			}
		}
	}
	event.Skip();
}

void cLoadoutPanel::removeLinked(wxCommandEvent& event)
{
	int idx = m_linkedItemsLB->GetSelection();
	if (idx != wxNOT_FOUND)
	{
		m_linkedItemsLB->Delete(idx);
	}
	event.Skip();
}

void cLoadoutPanel::onVestChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_vest->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::addCustomWeap(wxCommandEvent& event)
{
	wxString cust = m_weapCustom->GetValue();
	if (cust != "") {
		addWeapon(cust);
	}
	event.Skip();
}

void cLoadoutPanel::addPresetWeap(wxCommandEvent& event)
{
	wxString preset = m_weapPresets->GetStringSelection();
	if (preset != "") {
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		addWeapon(preset);
	}
	event.Skip();
}

void cLoadoutPanel::removePresetWeap(wxCommandEvent& event)
{
	wxString preset = m_weapPresets->GetStringSelection();
	if (preset != "")
	{
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		for (int i = 0; i < m_weaponsLB->GetCount(); ++i)
		{
			if (m_weaponsLB->GetString(i) == preset)
			{
				m_weaponsLB->Delete(i);
			}
		}
	}
	event.Skip();
}

void cLoadoutPanel::removeWeap(wxCommandEvent& event)
{
	int idx = m_weaponsLB->GetSelection();
	if (idx != wxNOT_FOUND)
	{
		m_weaponsLB->Delete(idx);
	}
	event.Skip();
}

void cLoadoutPanel::onHelmetChange(wxCommandEvent& event)
{
	wxString preset = event.GetString();

	if (preset.Contains(':')) {
		preset = preset.AfterFirst(':').Trim(false);
	}
	m_helmet->SetValue(preset);
	event.Skip();
}

void cLoadoutPanel::addCustomMag(wxCommandEvent& event)
{
	wxString cust = m_magCustom->GetValue();
	if (cust != "") {
		addMag(cust);
	}
	event.Skip();
}

void cLoadoutPanel::addPresetMag(wxCommandEvent& event)
{
	wxString preset = m_magPresets->GetStringSelection();
	if (preset != "") {
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		addMag(preset);
	}
	event.Skip();
}

void cLoadoutPanel::removePresetMag(wxCommandEvent& event)
{
	wxString preset = m_magPresets->GetStringSelection();
	if (preset != "")
	{
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		for (int i = 0; i < m_magLB->GetCount(); ++i)
		{
			if (m_magLB->GetString(i) == preset)
			{
				m_magLB->Delete(i);
			}
		}
	}
	event.Skip();
}

void cLoadoutPanel::updateMagAmount(wxCommandEvent& event)
{
	int sel = m_magLB->GetSelection();
	if (sel != wxNOT_FOUND)
	{
		wxString amount = m_magAmount->GetValue();
		if (amount != "")
		{
			wxString mag = m_magLB->GetString(sel).BeforeFirst('|');
			m_magLB->SetString(sel, mag + "|" + amount);
			m_magLB->Refresh();
		}
	}
	event.Skip();
}

void cLoadoutPanel::removeMag(wxCommandEvent& event)
{
	int idx = m_magLB->GetSelection();
	if (idx != wxNOT_FOUND)
	{
		m_magLB->Delete(idx);
	}
	event.Skip();
}

void cLoadoutPanel::addCustomItem(wxCommandEvent& event)
{
	wxString cust = m_itemCustom->GetValue();
	if (cust != "") {
		addItem(cust);
	}
	event.Skip();
}

void cLoadoutPanel::addPresetItem(wxCommandEvent& event)
{
	wxString preset = m_itemPresets->GetStringSelection();
	if (preset != "") {
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		addItem(preset);
	}
	event.Skip();
}

void cLoadoutPanel::removePresetItem(wxCommandEvent& event)
{
	wxString preset = m_itemPresets->GetStringSelection();
	if (preset != "")
	{
		if (preset.Contains(':')) {
			preset = preset.AfterFirst(':').Trim(false);
		}
		for (int i = 0; i < m_itemLB->GetCount(); ++i)
		{
			if (m_itemLB->GetString(i) == preset)
			{
				m_itemLB->Delete(i);
			}
		}
	}
	event.Skip();
}

void cLoadoutPanel::updateItemAmount(wxCommandEvent& event)
{
	int sel = m_itemLB->GetSelection();
	if (sel != wxNOT_FOUND)
	{
		wxString amount = m_itemAmount->GetValue();
		if (amount != "")
		{
			wxString mag = m_itemLB->GetString(sel).BeforeFirst('|');
			m_itemLB->SetString(sel, mag + "|" + amount);
			m_itemLB->Refresh();
		}
	}
	event.Skip();
}

void cLoadoutPanel::removeItem(wxCommandEvent& event)
{
	int idx = m_itemLB->GetSelection();
	if (idx != wxNOT_FOUND)
	{
		m_itemLB->Delete(idx);
	}
	event.Skip();
}

void cLoadoutPanel::itemSelected(wxCommandEvent& event)
{
	wxString amt = event.GetString().AfterFirst('|');
	m_itemAmount->SetValue(amt == "" ? wxString("1") : amt);
	event.Skip();
}

void cLoadoutPanel::magSelected(wxCommandEvent& event)
{
	wxString amt = event.GetString().AfterFirst('|');
	m_magAmount->SetValue(amt == "" ? wxString("1") : amt);
	event.Skip();
}