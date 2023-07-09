#include "cApp.h"

IMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
	if (!wxApp::OnInit()) return false;



	m_main = new cMain(nullptr);
	m_main->SetIcon(wxICON(ICO_APP));
	m_main->Show();


	cSettings* settings = new cSettings();
	cLoadScreen* loadScreen = new cLoadScreen();


	if (!openFile.empty()) {
		openFile.append("\\");
		m_main->open_new_path(openFile);
	}

	wxString exe = wxStandardPaths::Get().GetExecutablePath();

	wxRegKey keyBack(wxRegKey::HKCU, "Software\\Classes\\directory\\Background\\shell\\ArmaMissionHelper");
	wxRegKey dirKeyBack(wxRegKey::HKCU, "Software\\Classes\\directory\\Background\\shell");
	wxRegKey cmdBack(wxRegKey::HKCU, "Software\\Classes\\directory\\Background\\shell\\ArmaMissionHelper\\command");
	if (!dirKeyBack.HasSubKey("ArmaMissionHelper"))
	{
		keyBack.Create();
		keyBack.SetValue("", "Open A&3 Miss&ion He&lper");
		keyBack.SetValue("Icon", exe);
		cmdBack.Create();
		cmdBack.SetValue("", "\"" + exe + "\" \"%V\"");
	} else
	{
		wxString Key, Val;
		Key = "Icon";
		keyBack.QueryValue(Key, Val);
		if (Val != exe)
		{
			keyBack.SetValue("Icon", exe);
		}
		if (cmdBack.QueryDefaultValue() != "\"" + exe + "\" \"%V\"")
		{
			cmdBack.SetValue("", "\"" + exe + "\" \"%V\"");
		}
	}

	wxRegKey key(wxRegKey::HKCU, "Software\\Classes\\directory\\shell\\ArmaMissionHelper");
	wxRegKey cmd(wxRegKey::HKCU, "Software\\Classes\\directory\\shell\\ArmaMissionHelper\\command");
	wxRegKey dirKey(wxRegKey::HKCU, "Software\\Classes\\directory\\shell");
	if (!dirKey.HasSubKey("ArmaMissionHelper"))
	{
		key.Create();
		key.SetValue("", "Open A&3 Miss&ion He&lper");
		key.SetValue("Icon", exe);

		cmd.Create();
		cmd.SetValue("", "\"" + exe + "\" \"%V\"");
	} else
	{
		wxString Key, Val;
		Key = "Icon";
		key.QueryValue(Key, Val);
		if (Val != exe)
		{
			key.SetValue("Icon", exe);
		}
		if (cmd.QueryDefaultValue() != "\"" + exe + "\" \"%V\"")
		{
			cmd.SetValue("", "\"" + exe + "\" \"%V\"");
		}
	}





	return true;
}

int cApp::OnExit()
{
	wxLogDebug("cApp Exit");
	delete cSettings::getMain();
	delete cLoadScreen::getLoadScreen();
	return 0;
}

int cApp::OnRun()
{
	int exitcode = wxApp::OnRun();
	wxLogDebug("Got Exitcode");
	return exitcode;
}

void cApp::OnInitCmdLine(wxCmdLineParser& parser)
{
	parser.SetDesc(g_cmdLineDesc);
	// Cannot use / as that would break /<path>
	parser.SetSwitchChars(wxT("-"));
}

bool cApp::OnCmdLineParsed(wxCmdLineParser& parser)
{

	wxArrayString files;
	wxString path;
	for (int i = 0; i < parser.GetParamCount(); i++)
	{
		wxString param = parser.GetParam(i);
		files.Add(param);
		if (param.starts_with("/") || param.starts_with("\\") || (param.c_str()[1]) == ':') {
			openFile = param;
		}
	}

	return true;
}