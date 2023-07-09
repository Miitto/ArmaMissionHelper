#pragma once

#include <wx/wx.h>

class cLoadScreen
{
	
public:

	cLoadScreen();
	static cLoadScreen* mainScreen;

	static cLoadScreen* getLoadScreen() {
		return mainScreen;
	}

	wxString mapName;
	wxString mapAuthor;
	
	wxString missionName;
	wxString missionAuthor;
	wxString missionBackground;

	wxString mapBackground;

	wxArrayString loadTxts;
};

