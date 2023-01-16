#pragma once

#include "cMain.h"

#include <wx/wxprec.h>
#include <wx/cmdline.h>
#include <wx/msw/registry.h>
#include <wx/stdpaths.h>
#include <wx/msgdlg.h>


#include "resource.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class cApp : public wxApp
{
public:
	cApp();
	~cApp();
	virtual bool OnInit();
	virtual int OnExit();
	virtual int OnRun();
	virtual void OnInitCmdLine(wxCmdLineParser& parser);
	virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

	cMain* m_main = nullptr;
	std::string openFile;

};

static const wxCmdLineEntryDesc g_cmdLineDesc[] =
{
	 { wxCMD_LINE_PARAM, NULL, NULL, "Open File", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
	 { wxCMD_LINE_SWITCH, "h", "help", "displays help on the command line parameters",
		  wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	 { wxCMD_LINE_SWITCH, "t", "test", "test switch"},

	 { wxCMD_LINE_NONE }
};

DECLARE_APP(cApp);
