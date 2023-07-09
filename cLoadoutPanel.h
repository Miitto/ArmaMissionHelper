#ifndef __cLoadoutPanel__
#define __cLoadoutPanel__

/**
@file
Subclass of LoadoutPanel, which is generated by wxFormBuilder.
*/

#include <wx/stdpaths.h>
#include "cGui.h"
#include "cFileManager.h"
#include "cHelpers.h"
#include "cLoadout.h"

//// end generated include

/** Implementing LoadoutPanel */
class cLoadoutPanel : public LoadoutPanel
{
protected:
	// Handlers for LoadoutPanel events.
	void onUniformChange(wxCommandEvent& event);
	void onBackpackChange(wxCommandEvent& event);
	void onPrimaryChange(wxCommandEvent& event);
	void onSecondaryChange(wxCommandEvent& event);
	void addCustomLinked(wxCommandEvent& event);
	void addPresetLinked(wxCommandEvent& event);
	void removePresetLinked(wxCommandEvent& event);
	void removeLinked(wxCommandEvent& event);
	void onVestChange(wxCommandEvent& event);
	void addCustomWeap(wxCommandEvent& event);
	void addPresetWeap(wxCommandEvent& event);
	void removePresetWeap(wxCommandEvent& event);
	void removeWeap(wxCommandEvent& event);
	void onHelmetChange(wxCommandEvent& event);
	void addCustomMag(wxCommandEvent& event);
	void addPresetMag(wxCommandEvent& event);
	void removePresetMag(wxCommandEvent& event);
	void updateMagAmount(wxCommandEvent& event);
	void removeMag(wxCommandEvent& event);
	void magSelected(wxCommandEvent& event);
	void addCustomItem(wxCommandEvent& event);
	void addPresetItem(wxCommandEvent& event);
	void removePresetItem(wxCommandEvent& event);
	void updateItemAmount(wxCommandEvent& event);
	void removeItem(wxCommandEvent& event);
	void itemSelected(wxCommandEvent& event);

public:
	/** Constructor */
	cLoadoutPanel( wxWindow* parent );
	cLoadoutPanel(wxWindow* parent, cLoadout* load);
	~cLoadoutPanel();

	void loadLists();

	friend class cMain;
//// end generated class members

	wxString className;

	void updateLoadout(cLoadout* load);

	void addMag(cLoadout* load);
	void addMag(wxArrayString mags);
	void addMag(wxString mag);

	void addItem(cLoadout* load);
	void addItem(wxArrayString items);
	void addItem(wxString item);

	void addWeapon(cLoadout* load);
	void addWeapon(wxArrayString weapons);
	void addWeapon(wxString weapon);

	void addLinked(cLoadout* load);
	void addLinked(wxArrayString linked);
	void addLinked(wxString link);

};

#endif // __cLoadoutPanel__
