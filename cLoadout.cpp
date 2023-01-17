#include "cLoadout.h"

cLoadout::cLoadout()
{
	className = "NewLoadout";
	dispName = "";

	role = "";

	uniform = "";
	vest = "";
	helmet = "";
	backpack = "";

	primary = "";
	secondary = "";
}

cLoadout::cLoadout(wxString cName, wxString dName, wxString r, wxString u, wxString b, wxString p, wxString s, wxString v, wxString h, wxArrayString l, wxArrayString w, wxArrayString m, wxArrayString i)
{
	className = cName;
	dispName = dName;

	role = r;
	uniform = u;
	backpack = b;
	primary = p;
	secondary = s;
	vest = v;
	helmet = h;

	linked = l;
	weapons = w;
	mags = m;

	items = i;
}

cLoadoutDir::cLoadoutDir()
{
	
}

void cLoadoutDir::addLoadout(cLoadout* load)
{
	// Ensure No Duplicate Classes
	for (std::vector<cLoadout*>::iterator i = loadouts.begin(); i != loadouts.end(); ++i)
	{
		if ((*i)->className == load->className)
		{
			load->className = load->className + "1";
			addLoadout(load); // Since a name, unlikely to cause stack overflow
			return;
		}
	}
	loadouts.emplace_back(load);
}

void cLoadoutDir::removeLoadout(cLoadout* load)
{
	for (std::vector<cLoadout*>::iterator i = loadouts.begin(); i != loadouts.end(); ++i)
	{
		if ((*i)->className == load->className)
		{
			i = loadouts.erase(i);
			return;
		}
	}
}

void cLoadoutDir::removeLoadout(int idx)
{
	loadouts.erase(loadouts.begin() + idx);
}

void cLoadoutDir::removeLoadout(wxString cName)
{
	for (std::vector<cLoadout*>::iterator i = loadouts.begin(); i != loadouts.end(); ++i)
	{
		if ((*i)->className == cName)
		{
			i = loadouts.erase(i);
			return;
		}
	}
}
