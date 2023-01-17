#pragma once
#include <wx/wx.h>
#include <vector>

class cLoadout
{
public:
	cLoadout();
	cLoadout(wxString cName, wxString dName, wxString r, wxString u, wxString b, wxString p, wxString s, wxString v, wxString h, wxArrayString l, wxArrayString w, wxArrayString m, wxArrayString i);
	wxString className;

	wxString dispName;
	wxString role;

	wxString uniform;
	wxString backpack;
	wxString primary;
	wxString secondary;
	wxString vest;
	wxString helmet;

	wxArrayString linked;
	wxArrayString weapons;

	wxArrayString mags;

	wxArrayString items;
};

class cLoadoutDir
{
public:
	cLoadoutDir();

	~cLoadoutDir()
	{
		for (std::vector<cLoadout*>::iterator i = loadouts.begin(); i != loadouts.end(); ++i)
		{
			delete (*i);
		}
	}

	void addLoadout(cLoadout* load);
	void removeLoadout(cLoadout* load);
	void removeLoadout(int idx);
	void removeLoadout(wxString cName);

	std::vector<cLoadout*> loadouts;
};