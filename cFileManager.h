#pragma once

#define OPT(s) else if (start == wxT(s))
#define LOG(s) wxLogDebug(s)

#include <wx/wx.h>
#include <wx/tokenzr.h>
#include <shlwapi.h>
#include "CDialogEventHandler.h"
#include <filesystem>
#include "cSettings.h"
#include "cLoadScreen.h"
#include <iostream>
#include  <fstream>
#include "cHelpers.h"
#include "cLoadout.h"

class cFileManager
{
public:
	static HRESULT basicFolderOpen(WCHAR*& path);
	static HRESULT basicFolderOpen(wxString& path);
	static bool readSettings(wxString path, cSettings* set);
	static void parseOption(wxString& start, wxString& end, bool makeLower = true);
	static bool readLoadScreen(wxString path, cLoadScreen* set);
	static bool writeSettings(wxString path, cSettings* set, cLoadScreen* load);
};

