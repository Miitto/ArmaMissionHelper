///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cGui.h"

///////////////////////////////////////////////////////////////////////////

mainFrame::mainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_menubar = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_save;
	m_save = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_save );

	wxMenuItem* m_saveAs;
	m_saveAs = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Save As") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_saveAs );

	m_file->AppendSeparator();

	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_open );

	m_file->AppendSeparator();

	wxMenuItem* m_import;
	m_import = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Import Settings") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_import );

	wxMenuItem* m_export;
	m_export = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Export Settings") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_export );

	m_file->AppendSeparator();

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menubar->Append( m_file, wxT("File") );

	m_options = new wxMenu();
	wxMenuItem* m_contextMenu;
	m_contextMenu = new wxMenuItem( m_options, wxID_ANY, wxString( wxT("Disable Context Menu") ) , wxEmptyString, wxITEM_NORMAL );
	m_options->Append( m_contextMenu );

	m_menubar->Append( m_options, wxT("Options") );

	this->SetMenuBar( m_menubar );

	m_tabBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_tabBook, wxAuiPaneInfo() .Center() .CaptionVisible( false ).CloseButton( false ).Movable( false ).Dock().Resizable().FloatingSize( wxDefaultSize ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).CentrePane() );

	m_settingsPane = new wxPanel( m_tabBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* settingsMainSizer;
	settingsMainSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	settingsMainSizer->AddGrowableCol( 1 );
	settingsMainSizer->SetFlexibleDirection( wxBOTH );
	settingsMainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_panel81 = new wxPanel( m_settingsPane, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* settingsLeftSizer;
	settingsLeftSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	settingsLeftSizer->SetFlexibleDirection( wxBOTH );
	settingsLeftSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_headerTxt = new wxStaticText( m_panel81, wxID_ANY, wxT("Header"), wxDefaultPosition, wxDefaultSize, 0 );
	m_headerTxt->SetLabelMarkup( wxT("Header") );
	m_headerTxt->Wrap( -1 );
	m_headerTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsLeftSizer->Add( m_headerTxt, 0, wxALL, 5 );


	settingsLeftSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_gameTypeTxt = new wxStaticText( m_panel81, wxID_ANY, wxT("Game Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_gameTypeTxt->Wrap( -1 );
	settingsLeftSizer->Add( m_gameTypeTxt, 0, wxALL, 5 );

	m_gameType = new wxComboBox( m_panel81, wxID_ANY, wxT("COOP"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_gameType->Append( wxT("COOP") );
	m_gameType->Append( wxT("DM | Deathmatch") );
	m_gameType->Append( wxT("CTF | Capture The Flag") );
	m_gameType->Append( wxT("CTI | Capture The Island") );
	m_gameType->Append( wxT("SC | Sector Control") );
	m_gameType->Append( wxT("TDM | Team Deathmatch") );
	m_gameType->Append( wxT("RPG") );
	m_gameType->Append( wxT("Sandbox") );
	m_gameType->Append( wxT("KOTH | King Of the Hill") );
	m_gameType->Append( wxT("LastMan") );
	m_gameType->Append( wxT("Survive") );
	m_gameType->Append( wxT("Zeus") );
	m_gameType->Append( wxT("Support") );
	m_gameType->Append( wxT("EndGame") );
	m_gameType->Append( wxT("Apex") );
	m_gameType->Append( wxT("Escape") );
	m_gameType->Append( wxT("Patrol | Combat Patrol") );
	m_gameType->Append( wxT("Vanguard") );
	m_gameType->Append( wxT("Warlords") );
	m_gameType->SetSelection( 0 );
	settingsLeftSizer->Add( m_gameType, 0, wxALL, 5 );

	m_minPlayersTxt = new wxStaticText( m_panel81, wxID_ANY, wxT("Min Players"), wxDefaultPosition, wxDefaultSize, 0 );
	m_minPlayersTxt->Wrap( -1 );
	settingsLeftSizer->Add( m_minPlayersTxt, 0, wxALL, 5 );

	m_minPlayers = new wxTextCtrl( m_panel81, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_minPlayers, 0, wxALL, 5 );

	m_maxPlayersTxr = new wxStaticText( m_panel81, wxID_ANY, wxT("Max Players"), wxDefaultPosition, wxDefaultSize, 0 );
	m_maxPlayersTxr->Wrap( -1 );
	settingsLeftSizer->Add( m_maxPlayersTxr, 0, wxALL, 5 );

	m_maxPlayers = new wxTextCtrl( m_panel81, wxID_ANY, wxT("30"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_maxPlayers, 0, wxALL, 5 );

	m_hudLabel = new wxStaticText( m_panel81, wxID_ANY, wxT("HUD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_hudLabel->Wrap( -1 );
	m_hudLabel->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsLeftSizer->Add( m_hudLabel, 0, wxALL, 5 );


	settingsLeftSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_scriptedHud = new wxCheckBox( m_panel81, wxID_ANY, wxT("Scripted HUD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_scriptedHud->SetValue(true);
	settingsLeftSizer->Add( m_scriptedHud, 0, wxALL, 5 );

	m_unitInfo = new wxCheckBox( m_panel81, wxID_ANY, wxT("Vehicle and Unit Info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_unitInfo->SetValue(true);
	settingsLeftSizer->Add( m_unitInfo, 0, wxALL, 5 );

	m_vehRadar = new wxCheckBox( m_panel81, wxID_ANY, wxT("Vehicle Radar"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_vehRadar, 0, wxALL, 5 );

	m_vehCompass = new wxCheckBox( m_panel81, wxID_ANY, wxT("Vehicle Compass"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_vehCompass, 0, wxALL, 5 );

	m_tankDir = new wxCheckBox( m_panel81, wxID_ANY, wxT("Tank Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_tankDir->SetValue(true);
	settingsLeftSizer->Add( m_tankDir, 0, wxALL, 5 );

	m_commandMenu = new wxCheckBox( m_panel81, wxID_ANY, wxT("Command Menu"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_commandMenu, 0, wxALL, 5 );

	m_grpInfo = new wxCheckBox( m_panel81, wxID_ANY, wxT("Group Info"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_grpInfo, 0, wxALL, 5 );

	m_crosshair = new wxCheckBox( m_panel81, wxID_ANY, wxT("HUD && Crosshair"), wxDefaultPosition, wxDefaultSize, 0 );
	m_crosshair->SetValue(true);
	settingsLeftSizer->Add( m_crosshair, 0, wxALL, 5 );

	m_vehDispPanel = new wxCheckBox( m_panel81, wxID_ANY, wxT("Vehicle Panels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vehDispPanel->SetValue(true);
	settingsLeftSizer->Add( m_vehDispPanel, 0, wxALL, 5 );

	m_deathMsg = new wxCheckBox( m_panel81, wxID_ANY, wxT("Death Msgs"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_deathMsg, 0, wxALL, 5 );

	m_forceDraw3D = new wxCheckBox( m_panel81, wxID_ANY, wxT("Force Draw 3D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_forceDraw3D->SetValue(true);
	settingsLeftSizer->Add( m_forceDraw3D, 0, wxALL, 5 );


	settingsLeftSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_miscLabel = new wxStaticText( m_panel81, wxID_ANY, wxT("Misc"), wxDefaultPosition, wxDefaultSize, 0 );
	m_miscLabel->Wrap( -1 );
	m_miscLabel->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsLeftSizer->Add( m_miscLabel, 0, wxALL, 5 );


	settingsLeftSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_showMap = new wxCheckBox( m_panel81, wxID_ANY, wxT("Show Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showMap->SetValue(true);
	settingsLeftSizer->Add( m_showMap, 0, wxALL, 5 );

	m_disableAi = new wxCheckBox( m_panel81, wxID_ANY, wxT("Disable AI"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_disableAi, 0, wxALL, 5 );

	m_adminConsoleTxt = new wxStaticText( m_panel81, wxID_ANY, wxT("Admin Console"), wxDefaultPosition, wxDefaultSize, 0 );
	m_adminConsoleTxt->Wrap( -1 );
	settingsLeftSizer->Add( m_adminConsoleTxt, 0, wxALL, 5 );

	wxString m_adminConsoleChoices[] = { wxT("0  : Disable"), wxT("1 : Admin"), wxT("2 : Everyone") };
	int m_adminConsoleNChoices = sizeof( m_adminConsoleChoices ) / sizeof( wxString );
	m_adminConsole = new wxChoice( m_panel81, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_adminConsoleNChoices, m_adminConsoleChoices, 0 );
	m_adminConsole->SetSelection( 1 );
	settingsLeftSizer->Add( m_adminConsole, 0, wxALL, 5 );

	m_showCompass = new wxCheckBox( m_panel81, wxID_ANY, wxT("Enable Compass"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showCompass->SetValue(true);
	settingsLeftSizer->Add( m_showCompass, 0, wxALL, 5 );

	m_showGPS = new wxCheckBox( m_panel81, wxID_ANY, wxT("Enable GPS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showGPS->SetValue(true);
	settingsLeftSizer->Add( m_showGPS, 0, wxALL, 5 );

	m_showWatch = new wxCheckBox( m_panel81, wxID_ANY, wxT("Enable Watch"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showWatch->SetValue(true);
	settingsLeftSizer->Add( m_showWatch, 0, wxALL, 5 );

	m_showGroupIndicator = new wxCheckBox( m_panel81, wxID_ANY, wxT("Group Indicator Instead of GPS"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_showGroupIndicator, 0, wxALL, 5 );

	m_showUAVFeed = new wxCheckBox( m_panel81, wxID_ANY, wxT("Enable UAV Feed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showUAVFeed->SetValue(true);
	settingsLeftSizer->Add( m_showUAVFeed, 0, wxALL, 5 );

	m_aiKills = new wxCheckBox( m_panel81, wxID_ANY, wxT("Show AI Kills in Scoreboard"), wxDefaultPosition, wxDefaultSize, 0 );
	settingsLeftSizer->Add( m_aiKills, 0, wxALL, 5 );


	m_panel81->SetSizer( settingsLeftSizer );
	m_panel81->Layout();
	settingsLeftSizer->Fit( m_panel81 );
	settingsMainSizer->Add( m_panel81, 1, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* settingsCorpseSizer;
	settingsCorpseSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	settingsCorpseSizer->SetFlexibleDirection( wxBOTH );
	settingsCorpseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_corpseTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Corpse Managment"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseTxt->Wrap( -1 );
	m_corpseTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsCorpseSizer->Add( m_corpseTxt, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer83;
	fgSizer83 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer83->SetFlexibleDirection( wxBOTH );
	fgSizer83->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_corpseManagerTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Corpse Manager"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseManagerTxt->Wrap( -1 );
	fgSizer83->Add( m_corpseManagerTxt, 0, wxALL, 5 );

	wxString m_corpseManagerChoices[] = { wxT("0 : None "), wxT("1 : All"), wxT("2 : Respawned"), wxT("3 : All but Respawned") };
	int m_corpseManagerNChoices = sizeof( m_corpseManagerChoices ) / sizeof( wxString );
	m_corpseManager = new wxChoice( m_settingsPane, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_corpseManagerNChoices, m_corpseManagerChoices, 0 );
	m_corpseManager->SetSelection( 2 );
	fgSizer83->Add( m_corpseManager, 0, wxALL, 5 );

	m_corpseLimitTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Corpse Limit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseLimitTxt->Wrap( -1 );
	fgSizer83->Add( m_corpseLimitTxt, 0, wxALL, 5 );

	m_corpseLimit = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("15"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer83->Add( m_corpseLimit, 0, wxALL, 5 );

	m_corpseMinTimeTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Removal Min Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseMinTimeTxt->Wrap( -1 );
	fgSizer83->Add( m_corpseMinTimeTxt, 0, wxALL, 5 );

	m_corpseMinTime = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer83->Add( m_corpseMinTime, 0, wxALL, 5 );

	m_corpseMaxTimeTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Removal Max Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseMaxTimeTxt->Wrap( -1 );
	fgSizer83->Add( m_corpseMaxTimeTxt, 0, wxALL, 5 );

	m_corpseMaxTime = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("3600"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer83->Add( m_corpseMaxTime, 0, wxALL, 5 );


	settingsCorpseSizer->Add( fgSizer83, 1, wxEXPAND, 5 );

	m_wreckTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Wreck Managment"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wreckTxt->Wrap( -1 );
	m_wreckTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsCorpseSizer->Add( m_wreckTxt, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer831;
	fgSizer831 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer831->SetFlexibleDirection( wxBOTH );
	fgSizer831->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_wreckManagerTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Wreck Manager"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wreckManagerTxt->Wrap( -1 );
	fgSizer831->Add( m_wreckManagerTxt, 0, wxALL, 5 );

	wxString m_wreckManagerChoices[] = { wxT("0 : None "), wxT("1 : All"), wxT("2 : Respawned"), wxT("3 : All but Respawned") };
	int m_wreckManagerNChoices = sizeof( m_wreckManagerChoices ) / sizeof( wxString );
	m_wreckManager = new wxChoice( m_settingsPane, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_wreckManagerNChoices, m_wreckManagerChoices, 0 );
	m_wreckManager->SetSelection( 2 );
	fgSizer831->Add( m_wreckManager, 0, wxALL, 5 );

	m_wreckLimitTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Wreck Limit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wreckLimitTxt->Wrap( -1 );
	fgSizer831->Add( m_wreckLimitTxt, 0, wxALL, 5 );

	m_wreckLimit = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("15"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer831->Add( m_wreckLimit, 0, wxALL, 5 );

	m_wreckMinTimeTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Removal Min Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wreckMinTimeTxt->Wrap( -1 );
	fgSizer831->Add( m_wreckMinTimeTxt, 0, wxALL, 5 );

	m_wreckMinTime = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer831->Add( m_wreckMinTime, 0, wxALL, 5 );

	m_wreckMaxTimeTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Removal Max Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_wreckMaxTimeTxt->Wrap( -1 );
	fgSizer831->Add( m_wreckMaxTimeTxt, 0, wxALL, 5 );

	m_wreckMaxTime = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("36000"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer831->Add( m_wreckMaxTime, 0, wxALL, 5 );


	settingsCorpseSizer->Add( fgSizer831, 1, wxEXPAND, 5 );

	m_corpseWreckTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Corpse && Wreck Managment"), wxDefaultPosition, wxDefaultSize, 0 );
	m_corpseWreckTxt->Wrap( -1 );
	m_corpseWreckTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsCorpseSizer->Add( m_corpseWreckTxt, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer8311;
	fgSizer8311 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8311->SetFlexibleDirection( wxBOTH );
	fgSizer8311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_minPlayerDistanceTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Min Player Distance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_minPlayerDistanceTxt->Wrap( -1 );
	fgSizer8311->Add( m_minPlayerDistanceTxt, 0, wxALL, 5 );

	m_minPlayerDistance = new wxTextCtrl( m_settingsPane, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8311->Add( m_minPlayerDistance, 0, wxALL, 5 );


	settingsCorpseSizer->Add( fgSizer8311, 1, wxEXPAND, 5 );


	settingsMainSizer->Add( settingsCorpseSizer, 1, wxEXPAND, 5 );

	wxFlexGridSizer* settingsChannelSizer;
	settingsChannelSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	settingsChannelSizer->SetFlexibleDirection( wxBOTH );
	settingsChannelSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_disbaleChannel = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Channels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_disbaleChannel->Wrap( -1 );
	m_disbaleChannel->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	settingsChannelSizer->Add( m_disbaleChannel, 0, wxALL, 5 );


	settingsChannelSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_disableInfoTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Tick to Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_disableInfoTxt->Wrap( -1 );
	settingsChannelSizer->Add( m_disableInfoTxt, 0, wxALL, 5 );

	m_globalTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("0 Global"), wxDefaultPosition, wxDefaultSize, 0 );
	m_globalTxt->Wrap( -1 );
	m_globalTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_globalTxt, 0, wxALL, 5 );

	m_globalChat = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_globalChat->SetValue(true);
	settingsChannelSizer->Add( m_globalChat, 0, wxALL, 5 );

	m_globalVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_globalVoice->SetValue(true);
	settingsChannelSizer->Add( m_globalVoice, 0, wxALL, 5 );

	m_sideChatTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("1 Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sideChatTxt->Wrap( -1 );
	m_sideChatTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_sideChatTxt, 0, wxALL, 5 );

	m_sideChat = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sideChat->SetValue(true);
	settingsChannelSizer->Add( m_sideChat, 0, wxALL, 5 );

	m_sideVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sideVoice->SetValue(true);
	settingsChannelSizer->Add( m_sideVoice, 0, wxALL, 5 );

	m_commandTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("2 Command"), wxDefaultPosition, wxDefaultSize, 0 );
	m_commandTxt->Wrap( -1 );
	m_commandTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_commandTxt, 0, wxALL, 5 );

	m_commandChat = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_commandChat->SetValue(true);
	settingsChannelSizer->Add( m_commandChat, 0, wxALL, 5 );

	m_commandVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_commandVoice->SetValue(true);
	settingsChannelSizer->Add( m_commandVoice, 0, wxALL, 5 );

	m_groupChatTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("3 Group"), wxDefaultPosition, wxDefaultSize, 0 );
	m_groupChatTxt->Wrap( -1 );
	m_groupChatTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_groupChatTxt, 0, wxALL, 5 );

	m_groupChat = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_groupChat->SetValue(true);
	settingsChannelSizer->Add( m_groupChat, 0, wxALL, 5 );

	m_groupVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_groupVoice->SetValue(true);
	settingsChannelSizer->Add( m_groupVoice, 0, wxALL, 5 );

	m_vehicleChatTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("4 Vehicle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vehicleChatTxt->Wrap( -1 );
	m_vehicleChatTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_vehicleChatTxt, 0, wxALL, 5 );

	m_vehChat = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vehChat->SetValue(true);
	settingsChannelSizer->Add( m_vehChat, 0, wxALL, 5 );

	m_vehVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vehVoice->SetValue(true);
	settingsChannelSizer->Add( m_vehVoice, 0, wxALL, 5 );

	m_directChatTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("5 Direct"), wxDefaultPosition, wxDefaultSize, 0 );
	m_directChatTxt->Wrap( -1 );
	m_directChatTxt->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	settingsChannelSizer->Add( m_directChatTxt, 0, wxALL, 5 );

	m_dirNoChatTxt = new wxStaticText( m_settingsPane, wxID_ANY, wxT("Has No Chat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_dirNoChatTxt->Wrap( -1 );
	settingsChannelSizer->Add( m_dirNoChatTxt, 0, wxALL, 5 );

	m_dirVoice = new wxCheckBox( m_settingsPane, wxID_ANY, wxT("Voice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_dirVoice->SetValue(true);
	settingsChannelSizer->Add( m_dirVoice, 0, wxALL, 5 );


	settingsMainSizer->Add( settingsChannelSizer, 1, wxEXPAND, 5 );


	m_settingsPane->SetSizer( settingsMainSizer );
	m_settingsPane->Layout();
	settingsMainSizer->Fit( m_settingsPane );
	m_tabBook->AddPage( m_settingsPane, wxT("Settings"), true );
	m_loadPane = new wxPanel( m_tabBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 3, 0, 0, 0 );
	fgSizer5->AddGrowableCol( 0 );
	fgSizer5->SetFlexibleDirection( wxVERTICAL );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_panel7 = new wxPanel( m_loadPane, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel7->SetBackgroundColour( wxColour( 78, 78, 78 ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_name = new wxTextCtrl( m_panel7, wxID_ANY, wxT("Map Name"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_name, 0, wxALL, 5 );

	m_author = new wxTextCtrl( m_panel7, wxID_ANY, wxT("Map Author"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_author, 0, wxALL, 5 );


	m_panel7->SetSizer( bSizer1 );
	m_panel7->Layout();
	bSizer1->Fit( m_panel7 );
	fgSizer5->Add( m_panel7, 1, wxEXPAND | wxALL, 0 );

	m_panel12 = new wxPanel( m_loadPane, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel12->SetBackgroundColour( wxColour( 182, 182, 182 ) );

	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgSizer7->Add( 250, 100, 1, wxEXPAND, 5 );


	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_gameTypeLocation = new wxStaticText( m_panel12, wxID_ANY, wxT("Game Type"), wxDefaultPosition, wxSize( 250,-1 ), 0 );
	m_gameTypeLocation->Wrap( -1 );
	m_gameTypeLocation->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_gameTypeLocation->SetBackgroundColour( wxColour( 145, 145, 145 ) );

	fgSizer7->Add( m_gameTypeLocation, 0, wxALL, 1 );


	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_panel8 = new wxPanel( m_panel12, wxID_ANY, wxDefaultPosition, wxSize( -1,200 ), wxTAB_TRAVERSAL );
	m_panel8->SetBackgroundColour( wxColour( 39, 39, 39 ) );

	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8->AddGrowableCol( 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_missionNameLocation = new wxTextCtrl( m_panel8, wxID_ANY, wxT("Mission Name"), wxDefaultPosition, wxSize( 225,-1 ), 0 );
	fgSizer8->Add( m_missionNameLocation, 0, wxALL, 5 );

	m_missionAuthorLocation = new wxTextCtrl( m_panel8, wxID_ANY, wxT("Mission Author"), wxDefaultPosition, wxSize( 200,18 ), 0 );
	fgSizer8->Add( m_missionAuthorLocation, 0, wxALL, 5 );

	m_panel9 = new wxPanel( m_panel8, wxID_ANY, wxDefaultPosition, wxSize( -1,150 ), wxTAB_TRAVERSAL );
	m_panel9->SetBackgroundColour( wxColour( 114, 114, 114 ) );

	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	fgSizer9->SetMinSize( wxSize( -1,150 ) );

	fgSizer9->Add( 1, 100, 1, wxEXPAND, 5 );


	fgSizer9->Add( 0, 0, 1, wxEXPAND, 5 );

	m_missionBackground = new wxFilePickerCtrl( m_panel9, wxID_ANY, wxT("Mission Background"), wxT("Mission Background"), wxT("*.paa"), wxDefaultPosition, wxSize( 230,-1 ), wxFLP_DEFAULT_STYLE );
	fgSizer9->Add( m_missionBackground, 0, wxALL, 5 );


	m_panel9->SetSizer( fgSizer9 );
	m_panel9->Layout();
	fgSizer8->Add( m_panel9, 1, wxEXPAND | wxALL, 5 );


	m_panel8->SetSizer( fgSizer8 );
	m_panel8->Layout();
	fgSizer7->Add( m_panel8, 1, wxEXPAND | wxALL, 1 );


	fgSizer7->Add( 25, 170, 1, wxEXPAND, 5 );


	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_worldBackground = new wxFilePickerCtrl( m_panel12, wxID_ANY, wxT("World Background"), wxT("World Background"), wxT("*.paa"), wxDefaultPosition, wxSize( 250,-1 ), wxFLP_DEFAULT_STYLE );
	fgSizer7->Add( m_worldBackground, 0, wxALL, 5 );


	m_panel12->SetSizer( fgSizer7 );
	m_panel12->Layout();
	fgSizer7->Fit( m_panel12 );
	fgSizer5->Add( m_panel12, 1, wxEXPAND | wxALL, 0 );


	m_loadPane->SetSizer( fgSizer5 );
	m_loadPane->Layout();
	fgSizer5->Fit( m_loadPane );
	m_tabBook->AddPage( m_loadPane, wxT("Load Screen"), false );
	m_respawnPanel = new wxPanel( m_tabBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer10->AddGrowableCol( 3 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_respawnLeftPanel = new wxPanel( m_respawnPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* respawnLeft;
	respawnLeft = new wxFlexGridSizer( 0, 2, 0, 0 );
	respawnLeft->SetFlexibleDirection( wxBOTH );
	respawnLeft->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_respawnTypeTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Respawn Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnTypeTxt->Wrap( -1 );
	respawnLeft->Add( m_respawnTypeTxt, 0, wxALL, 5 );

	wxString m_respawnTypeChoices[] = { wxT("0 : None ( Don't Respawn)"), wxT("1 : Bird (Respawn as Seagul)"), wxT("2 : Instant (Respawn on death point)"), wxT("3 : Base (Respawn on Custom Point)"), wxT("4 : Group (Respawn on your group)"), wxT("5 : Side (Respawn on member of your side)"), wxEmptyString };
	int m_respawnTypeNChoices = sizeof( m_respawnTypeChoices ) / sizeof( wxString );
	m_respawnType = new wxChoice( m_respawnLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_respawnTypeNChoices, m_respawnTypeChoices, 0 );
	m_respawnType->SetSelection( 0 );
	respawnLeft->Add( m_respawnType, 0, wxALL, 5 );

	m_startRespawnTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Respawn On Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startRespawnTxt->Wrap( -1 );
	respawnLeft->Add( m_startRespawnTxt, 0, wxALL, 5 );

	wxString m_startRespawnChoices[] = { wxT("-1 (Don't Respawn, Don't run script)"), wxT("0 (Don't Respawn, Run Script)"), wxT("1 (Respawn, Run Script)") };
	int m_startRespawnNChoices = sizeof( m_startRespawnChoices ) / sizeof( wxString );
	m_startRespawn = new wxChoice( m_respawnLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_startRespawnNChoices, m_startRespawnChoices, 0 );
	m_startRespawn->SetSelection( 0 );
	respawnLeft->Add( m_startRespawn, 0, wxALL, 5 );

	m_respawnButton = new wxCheckBox( m_respawnLeftPanel, wxID_ANY, wxT("Respawn Button"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnButton->SetToolTip( wxT("Only Works with BASE and INSTANT Respawn Types") );

	respawnLeft->Add( m_respawnButton, 0, wxALL, 5 );

	m_respawnDialog = new wxCheckBox( m_respawnLeftPanel, wxID_ANY, wxT("Respawn Dialog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnDialog->SetToolTip( wxT("Only works with BASE Respawn Type") );

	respawnLeft->Add( m_respawnDialog, 0, wxALL, 5 );

	m_respawnDelayTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Respawn Delay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnDelayTxt->Wrap( -1 );
	respawnLeft->Add( m_respawnDelayTxt, 0, wxALL, 5 );

	wxFlexGridSizer* respawnDelaySizer;
	respawnDelaySizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	respawnDelaySizer->SetFlexibleDirection( wxBOTH );
	respawnDelaySizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_respawnDelaySlider = new wxSlider( m_respawnLeftPanel, wxID_ANY, 5, 0, 100, wxDefaultPosition, wxSize( 150,-1 ), wxSL_HORIZONTAL );
	m_respawnDelaySlider->SetMinSize( wxSize( 150,-1 ) );
	m_respawnDelaySlider->SetMaxSize( wxSize( 250,-1 ) );

	respawnDelaySizer->Add( m_respawnDelaySlider, 0, wxALL, 5 );

	m_respawnDelay = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnDelaySizer->Add( m_respawnDelay, 0, wxALL, 5 );


	respawnLeft->Add( respawnDelaySizer, 1, wxEXPAND, 5 );

	m_respawnVehDelayTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Vehicle Respawn Delay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnVehDelayTxt->Wrap( -1 );
	respawnLeft->Add( m_respawnVehDelayTxt, 0, wxALL, 5 );

	wxFlexGridSizer* vehRespawnDelaySizer;
	vehRespawnDelaySizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	vehRespawnDelaySizer->SetFlexibleDirection( wxBOTH );
	vehRespawnDelaySizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_vehRespawnDelaySlider = new wxSlider( m_respawnLeftPanel, wxID_ANY, 5, 0, 100, wxDefaultPosition, wxSize( 150,-1 ), wxSL_HORIZONTAL );
	m_vehRespawnDelaySlider->SetMinSize( wxSize( 150,-1 ) );
	m_vehRespawnDelaySlider->SetMaxSize( wxSize( 250,-1 ) );

	vehRespawnDelaySizer->Add( m_vehRespawnDelaySlider, 0, wxALL, 5 );

	m_vehRespawnDelay = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	vehRespawnDelaySizer->Add( m_vehRespawnDelay, 0, wxALL, 5 );


	respawnLeft->Add( vehRespawnDelaySizer, 1, wxEXPAND, 5 );

	m_reviveSection = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Revive"), wxDefaultPosition, wxDefaultSize, 0 );
	m_reviveSection->Wrap( -1 );
	m_reviveSection->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	respawnLeft->Add( m_reviveSection, 0, wxALL, 5 );


	respawnLeft->Add( 0, 0, 1, wxEXPAND, 5 );

	m_reviveModeTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Revive Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_reviveModeTxt->Wrap( -1 );
	respawnLeft->Add( m_reviveModeTxt, 0, wxALL, 5 );

	wxString m_reviveModeChoices[] = { wxT("0 : Disabled"), wxT("1: Enabled"), wxT("2 : Player Attribute Dependant") };
	int m_reviveModeNChoices = sizeof( m_reviveModeChoices ) / sizeof( wxString );
	m_reviveMode = new wxChoice( m_respawnLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_reviveModeNChoices, m_reviveModeChoices, 0 );
	m_reviveMode->SetSelection( 1 );
	respawnLeft->Add( m_reviveMode, 0, wxALL, 5 );

	m_damageModelTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Damage Model"), wxDefaultPosition, wxDefaultSize, 0 );
	m_damageModelTxt->Wrap( -1 );
	respawnLeft->Add( m_damageModelTxt, 0, wxALL, 5 );

	wxString m_damageModelChoices[] = { wxT("0 : Basic"), wxT("1: Advanced"), wxT("2 : Realistic") };
	int m_damageModelNChoices = sizeof( m_damageModelChoices ) / sizeof( wxString );
	m_damageModel = new wxChoice( m_respawnLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_damageModelNChoices, m_damageModelChoices, 0 );
	m_damageModel->SetSelection( 0 );
	respawnLeft->Add( m_damageModel, 0, wxALL, 5 );

	m_medicNeeded = new wxCheckBox( m_respawnLeftPanel, wxID_ANY, wxT("Requires Medic"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_medicNeeded, 0, wxALL, 5 );

	m_fakConsumed = new wxCheckBox( m_respawnLeftPanel, wxID_ANY, wxT("FAK Consumed"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_fakConsumed, 0, wxALL, 5 );

	m_reviveItem = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Item Needed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_reviveItem->Wrap( -1 );
	respawnLeft->Add( m_reviveItem, 0, wxALL, 5 );

	wxString m_reviveItemChoices[] = { wxT("0 : None"), wxT("1: Medkit"), wxT("2 : Medkit or First Aid Kit (FAK)"), wxEmptyString };
	int m_reviveItemNChoices = sizeof( m_reviveItemChoices ) / sizeof( wxString );
	m_reviveItem = new wxChoice( m_respawnLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_reviveItemNChoices, m_reviveItemChoices, 0 );
	m_reviveItem->SetSelection( 2 );
	respawnLeft->Add( m_reviveItem, 0, wxALL, 5 );

	m_reviveTimeTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Revive Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_reviveTimeTxt->Wrap( -1 );
	respawnLeft->Add( m_reviveTimeTxt, 0, wxALL, 5 );

	m_reviveTime = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_reviveTime, 0, wxALL, 5 );

	m_medicMultTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Medic Multiplier"), wxDefaultPosition, wxDefaultSize, 0 );
	m_medicMultTxt->Wrap( -1 );
	respawnLeft->Add( m_medicMultTxt, 0, wxALL, 5 );

	m_medicMult = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_medicMult, 0, wxALL, 5 );

	m_forceRespawnDelayTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Force Respawn Delay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_forceRespawnDelayTxt->Wrap( -1 );
	respawnLeft->Add( m_forceRespawnDelayTxt, 0, wxALL, 5 );

	m_forceRespawnDelay = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_forceRespawnDelay, 0, wxALL, 5 );

	m_bleedOutTxt = new wxStaticText( m_respawnLeftPanel, wxID_ANY, wxT("Bleed Out Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bleedOutTxt->Wrap( -1 );
	respawnLeft->Add( m_bleedOutTxt, 0, wxALL, 5 );

	m_bleedOut = new wxTextCtrl( m_respawnLeftPanel, wxID_ANY, wxT("300"), wxDefaultPosition, wxDefaultSize, 0 );
	respawnLeft->Add( m_bleedOut, 0, wxALL, 5 );


	m_respawnLeftPanel->SetSizer( respawnLeft );
	m_respawnLeftPanel->Layout();
	respawnLeft->Fit( m_respawnLeftPanel );
	fgSizer10->Add( m_respawnLeftPanel, 1, wxEXPAND | wxALL, 5 );


	fgSizer10->Add( 10, 1000, 1, wxEXPAND, 5 );

	m_respawnMidPanel = new wxPanel( m_respawnPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer18->AddGrowableCol( 0 );
	fgSizer18->AddGrowableRow( 10 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_respawnInvTxt = new wxStaticText( m_respawnMidPanel, wxID_ANY, wxT("Respawn Inventory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_respawnInvTxt->Wrap( -1 );
	m_respawnInvTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	fgSizer18->Add( m_respawnInvTxt, 0, wxALL, 5 );

	m_newLoadout = new wxButton( m_respawnMidPanel, wxID_ANY, wxT("New Loadout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_newLoadout->SetMinSize( wxSize( 150,30 ) );
	m_newLoadout->SetMaxSize( wxSize( 250,30 ) );

	fgSizer18->Add( m_newLoadout, 0, wxALL, 5 );

	m_dupeLoadout = new wxButton( m_respawnMidPanel, wxID_ANY, wxT("Duplicate Loadout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_dupeLoadout->SetMinSize( wxSize( 150,30 ) );
	m_dupeLoadout->SetMaxSize( wxSize( 250,30 ) );

	fgSizer18->Add( m_dupeLoadout, 0, wxALL, 5 );

	m_staticline1 = new wxStaticLine( m_respawnMidPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer18->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_renameLoadout = new wxButton( m_respawnMidPanel, wxID_ANY, wxT("Rename Loadout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_renameLoadout->SetMinSize( wxSize( 150,30 ) );
	m_renameLoadout->SetMaxSize( wxSize( 250,30 ) );

	fgSizer18->Add( m_renameLoadout, 0, wxALL, 5 );

	m_staticline2 = new wxStaticLine( m_respawnMidPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer18->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_closeLoadout = new wxButton( m_respawnMidPanel, wxID_ANY, wxT("Close Loadout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_closeLoadout->SetMinSize( wxSize( 150,30 ) );
	m_closeLoadout->SetMaxSize( wxSize( 250,30 ) );

	fgSizer18->Add( m_closeLoadout, 0, wxALL, 5 );

	m_staticline3 = new wxStaticLine( m_respawnMidPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer18->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_loadoutLB = new wxListBox( m_respawnMidPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_loadoutLB->SetMinSize( wxSize( 150,250 ) );
	m_loadoutLB->SetMaxSize( wxSize( 250,500 ) );

	fgSizer18->Add( m_loadoutLB, 0, wxALL, 5 );

	m_staticline4 = new wxStaticLine( m_respawnMidPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer18->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );


	fgSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_delLoadout = new wxButton( m_respawnMidPanel, wxID_ANY, wxT("Delete Loadout"), wxDefaultPosition, wxDefaultSize, 0 );
	m_delLoadout->SetMinSize( wxSize( 150,30 ) );
	m_delLoadout->SetMaxSize( wxSize( 250,30 ) );

	fgSizer18->Add( m_delLoadout, 0, wxALL, 5 );


	m_respawnMidPanel->SetSizer( fgSizer18 );
	m_respawnMidPanel->Layout();
	fgSizer18->Fit( m_respawnMidPanel );
	fgSizer10->Add( m_respawnMidPanel, 1, wxEXPAND | wxALL, 5 );

	m_loadoutBook = new wxNotebook( m_respawnPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_loadoutBook->SetForegroundColour( wxColour( 192, 192, 192 ) );
	m_loadoutBook->SetBackgroundColour( wxColour( 192, 192, 192 ) );

	m_defaultLoadout = new wxScrolledWindow( m_loadoutBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	m_defaultLoadout->SetScrollRate( 5, 5 );
	wxFlexGridSizer* loadoutPageSizer;
	loadoutPageSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	loadoutPageSizer->SetFlexibleDirection( wxBOTH );
	loadoutPageSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* loadoutRow1Sizer;
	loadoutRow1Sizer = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow1Sizer->SetFlexibleDirection( wxBOTH );
	loadoutRow1Sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_loadoutDispNameTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Display Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loadoutDispNameTxt->Wrap( -1 );
	fgSizer21->Add( m_loadoutDispNameTxt, 0, wxALL, 5 );

	m_loadoutDispName = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("Light"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer21->Add( m_loadoutDispName, 0, wxALL, 5 );

	m_loadoutRoleTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Role (Optional)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loadoutRoleTxt->Wrap( -1 );
	fgSizer21->Add( m_loadoutRoleTxt, 0, wxALL, 5 );

	Assault = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("Assault"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer21->Add( Assault, 0, wxALL, 5 );

	wxFlexGridSizer* uniformSizer;
	uniformSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	uniformSizer->SetFlexibleDirection( wxBOTH );
	uniformSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_uniformTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Uniform"), wxDefaultPosition, wxDefaultSize, 0 );
	m_uniformTxt->Wrap( -1 );
	m_uniformTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	uniformSizer->Add( m_uniformTxt, 0, wxALL, 5 );

	m_uniform = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("U_B_CombatUniform_mcam_tshirt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_uniform->SetMinSize( wxSize( 150,25 ) );
	m_uniform->SetMaxSize( wxSize( 150,25 ) );

	uniformSizer->Add( m_uniform, 0, wxALL, 5 );

	m_uniformLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_uniformLB->SetMinSize( wxSize( 150,150 ) );
	m_uniformLB->SetMaxSize( wxSize( 150,250 ) );

	uniformSizer->Add( m_uniformLB, 0, wxALL, 5 );


	fgSizer21->Add( uniformSizer, 1, wxEXPAND, 5 );

	wxFlexGridSizer* backpackSizer;
	backpackSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	backpackSizer->SetFlexibleDirection( wxBOTH );
	backpackSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_backpackTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Backpack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_backpackTxt->Wrap( -1 );
	m_backpackTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	backpackSizer->Add( m_backpackTxt, 0, wxALL, 5 );

	m_backpack = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("B_AssaultPack_mcamo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_backpack->SetMinSize( wxSize( 150,25 ) );
	m_backpack->SetMaxSize( wxSize( 150,25 ) );

	backpackSizer->Add( m_backpack, 0, wxALL, 5 );

	m_backpackLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_backpackLB->SetMinSize( wxSize( 150,150 ) );
	m_backpackLB->SetMaxSize( wxSize( 150,250 ) );

	backpackSizer->Add( m_backpackLB, 0, wxALL, 5 );


	fgSizer21->Add( backpackSizer, 1, wxEXPAND, 5 );


	loadoutRow1Sizer->Add( fgSizer21, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* primarySizer;
	primarySizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	primarySizer->SetFlexibleDirection( wxBOTH );
	primarySizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_primaryTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Primary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_primaryTxt->Wrap( -1 );
	m_primaryTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	primarySizer->Add( m_primaryTxt, 0, wxALL, 5 );

	m_primary = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("arifle_MXC_F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_primary->SetMinSize( wxSize( 150,25 ) );
	m_primary->SetMaxSize( wxSize( 150,25 ) );

	primarySizer->Add( m_primary, 0, wxALL, 5 );

	m_primaryLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_primaryLB->SetMinSize( wxSize( 150,217 ) );
	m_primaryLB->SetMaxSize( wxSize( 150,250 ) );

	primarySizer->Add( m_primaryLB, 0, wxALL, 5 );


	fgSizer22->Add( primarySizer, 1, wxEXPAND, 5 );

	wxFlexGridSizer* secondarySizer;
	secondarySizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	secondarySizer->SetFlexibleDirection( wxBOTH );
	secondarySizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_secondaryTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Secondary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_secondaryTxt->Wrap( -1 );
	m_secondaryTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	secondarySizer->Add( m_secondaryTxt, 0, wxALL, 5 );

	m_secondary = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_secondary->SetMinSize( wxSize( 150,25 ) );
	m_secondary->SetMaxSize( wxSize( 150,25 ) );

	secondarySizer->Add( m_secondary, 0, wxALL, 5 );

	m_secondaryLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_secondaryLB->SetMinSize( wxSize( 150,217 ) );
	m_secondaryLB->SetMaxSize( wxSize( 150,250 ) );

	secondarySizer->Add( m_secondaryLB, 0, wxALL, 5 );


	fgSizer22->Add( secondarySizer, 1, wxEXPAND, 5 );


	loadoutRow1Sizer->Add( fgSizer22, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow1Sizer, 1, wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow2Sizer;
	loadoutRow2Sizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	loadoutRow2Sizer->SetFlexibleDirection( wxBOTH );
	loadoutRow2Sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* linkedSizer;
	linkedSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	linkedSizer->SetFlexibleDirection( wxBOTH );
	linkedSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_otherEquip = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Other Equipment (Linked Items)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_otherEquip->Wrap( -1 );
	m_otherEquip->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	linkedSizer->Add( m_otherEquip, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer32;
	fgSizer32 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer32->SetFlexibleDirection( wxBOTH );
	fgSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer33;
	fgSizer33 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer33->SetFlexibleDirection( wxBOTH );
	fgSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_linkedCustom = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( m_linkedCustom, 0, wxALL, 5 );

	m_addLinkedCustom = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33->Add( m_addLinkedCustom, 0, wxALL, 5 );

	m_linkedPresets = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_linkedPresets->Append( wxT("Map : ItemMap") );
	m_linkedPresets->Append( wxT("Compass : ItemCompass") );
	m_linkedPresets->Append( wxT("Watch : ItemWatch") );
	m_linkedPresets->Append( wxT("Radio : ItemRadio") );
	m_linkedPresets->SetMinSize( wxSize( 130,150 ) );
	m_linkedPresets->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer33->Add( m_linkedPresets, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer35;
	fgSizer35 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer35->AddGrowableRow( 1 );
	fgSizer35->SetFlexibleDirection( wxBOTH );
	fgSizer35->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addLinkPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35->Add( m_addLinkPreset, 0, wxALL, 5 );

	m_removeLinkPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35->Add( m_removeLinkPreset, 0, wxALL, 5 );

	m_removeLinkEquip = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove ->"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35->Add( m_removeLinkEquip, 0, wxALL, 5 );


	fgSizer33->Add( fgSizer35, 1, wxEXPAND, 5 );


	fgSizer32->Add( fgSizer33, 1, wxEXPAND, 5 );

	m_linkedItemsLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_linkedItemsLB->Append( wxT("ItemMap") );
	m_linkedItemsLB->Append( wxT("ItemCompass") );
	m_linkedItemsLB->Append( wxT("ItemWatch") );
	m_linkedItemsLB->Append( wxT("ItemRadio") );
	m_linkedItemsLB->Append( wxT("optic_Aco") );
	m_linkedItemsLB->Append( wxT("acc_flashlight") );
	m_linkedItemsLB->SetMinSize( wxSize( 150,185 ) );
	m_linkedItemsLB->SetMaxSize( wxSize( 150,500 ) );

	fgSizer32->Add( m_linkedItemsLB, 0, wxALL, 5 );


	linkedSizer->Add( fgSizer32, 1, wxEXPAND, 5 );


	loadoutRow2Sizer->Add( linkedSizer, 1, wxEXPAND, 5 );


	loadoutRow2Sizer->Add( 10, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* vestSizer;
	vestSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	vestSizer->SetFlexibleDirection( wxBOTH );
	vestSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_vestTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Vest"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vestTxt->Wrap( -1 );
	m_vestTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	vestSizer->Add( m_vestTxt, 0, wxALL, 5 );

	m_vest = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("V_Chestrig_khk"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vest->SetMinSize( wxSize( 150,25 ) );
	m_vest->SetMaxSize( wxSize( 150,25 ) );

	vestSizer->Add( m_vest, 0, wxALL, 5 );

	m_vestLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_vestLB->SetMinSize( wxSize( 150,150 ) );
	m_vestLB->SetMaxSize( wxSize( 150,250 ) );

	vestSizer->Add( m_vestLB, 0, wxALL, 5 );


	loadoutRow2Sizer->Add( vestSizer, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow2Sizer, 1, wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow3Sizer;
	loadoutRow3Sizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	loadoutRow3Sizer->SetFlexibleDirection( wxBOTH );
	loadoutRow3Sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* otherWeapSizer;
	otherWeapSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	otherWeapSizer->SetFlexibleDirection( wxBOTH );
	otherWeapSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_otherWeap = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Other Weapons"), wxDefaultPosition, wxDefaultSize, 0 );
	m_otherWeap->Wrap( -1 );
	m_otherWeap->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	otherWeapSizer->Add( m_otherWeap, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer321;
	fgSizer321 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer321->SetFlexibleDirection( wxBOTH );
	fgSizer321->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer331;
	fgSizer331 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer331->SetFlexibleDirection( wxBOTH );
	fgSizer331->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_weapCustom = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer331->Add( m_weapCustom, 0, wxALL, 5 );

	m_addWeapCustom = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer331->Add( m_addWeapCustom, 0, wxALL, 5 );

	m_weapPresets = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_weapPresets->Append( wxT("Binocular") );
	m_weapPresets->SetMinSize( wxSize( 130,150 ) );
	m_weapPresets->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer331->Add( m_weapPresets, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer351;
	fgSizer351 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer351->AddGrowableRow( 1 );
	fgSizer351->SetFlexibleDirection( wxBOTH );
	fgSizer351->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addWeapPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer351->Add( m_addWeapPreset, 0, wxALL, 5 );

	m_removeWeapPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer351->Add( m_removeWeapPreset, 0, wxALL, 5 );

	m_removeWeapEquip = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove ->"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer351->Add( m_removeWeapEquip, 0, wxALL, 5 );


	fgSizer331->Add( fgSizer351, 1, wxEXPAND, 5 );


	fgSizer321->Add( fgSizer331, 1, wxEXPAND, 5 );

	m_weaponsLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_weaponsLB->Append( wxT("Binocular") );
	m_weaponsLB->SetMinSize( wxSize( 150,185 ) );
	m_weaponsLB->SetMaxSize( wxSize( 150,500 ) );

	fgSizer321->Add( m_weaponsLB, 0, wxALL, 5 );


	otherWeapSizer->Add( fgSizer321, 1, wxEXPAND, 5 );


	loadoutRow3Sizer->Add( otherWeapSizer, 1, wxEXPAND, 5 );


	loadoutRow3Sizer->Add( 10, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* helmetSizer;
	helmetSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	helmetSizer->SetFlexibleDirection( wxBOTH );
	helmetSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_helmetTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Helmet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helmetTxt->Wrap( -1 );
	m_helmetTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	helmetSizer->Add( m_helmetTxt, 0, wxALL, 5 );

	m_helmet = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("H_Watchcap_blk"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helmet->SetMinSize( wxSize( 150,25 ) );
	m_helmet->SetMaxSize( wxSize( 150,25 ) );

	helmetSizer->Add( m_helmet, 0, wxALL, 5 );

	m_helmetLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_helmetLB->SetMinSize( wxSize( 150,150 ) );
	m_helmetLB->SetMaxSize( wxSize( 150,250 ) );

	helmetSizer->Add( m_helmetLB, 0, wxALL, 5 );


	loadoutRow3Sizer->Add( helmetSizer, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow3Sizer, 1, wxEXPAND, 5 );

	m_staticline8 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow4Sizer;
	loadoutRow4Sizer = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow4Sizer->AddGrowableCol( 0 );
	loadoutRow4Sizer->SetFlexibleDirection( wxBOTH );
	loadoutRow4Sizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* magLeftSide;
	magLeftSide = new wxFlexGridSizer( 0, 1, 0, 0 );
	magLeftSide->SetFlexibleDirection( wxBOTH );
	magLeftSide->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magsTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Magazines"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magsTxt->Wrap( -1 );
	m_magsTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	magLeftSide->Add( m_magsTxt, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer3211;
	fgSizer3211 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer3211->SetFlexibleDirection( wxBOTH );
	fgSizer3211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer3311;
	fgSizer3311 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3311->SetFlexibleDirection( wxBOTH );
	fgSizer3311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magCustom = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3311->Add( m_magCustom, 0, wxALL, 5 );

	m_addMagCustom = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3311->Add( m_addMagCustom, 0, wxALL, 5 );

	m_magPresets = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_magPresets->Append( wxT("30Rnd_65x39_caseless_mag") );
	m_magPresets->SetMinSize( wxSize( 130,150 ) );
	m_magPresets->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer3311->Add( m_magPresets, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer3511;
	fgSizer3511 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer3511->AddGrowableRow( 0 );
	fgSizer3511->SetFlexibleDirection( wxBOTH );
	fgSizer3511->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addMagPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3511->Add( m_addMagPreset, 0, wxALL, 5 );

	m_removeMagPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3511->Add( m_removeMagPreset, 0, wxALL, 5 );


	fgSizer3311->Add( fgSizer3511, 1, wxEXPAND, 5 );


	fgSizer3211->Add( fgSizer3311, 1, wxEXPAND, 5 );


	magLeftSide->Add( fgSizer3211, 1, wxEXPAND, 5 );


	loadoutRow4Sizer->Add( magLeftSide, 1, wxEXPAND, 5 );

	wxFlexGridSizer* magMiddle;
	magMiddle = new wxFlexGridSizer( 0, 1, 0, 0 );
	magMiddle->AddGrowableRow( 2 );
	magMiddle->SetFlexibleDirection( wxBOTH );
	magMiddle->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magAmountTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Amount"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magAmountTxt->Wrap( -1 );
	magMiddle->Add( m_magAmountTxt, 0, wxALL, 5 );

	m_magAmount = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magAmount->SetMinSize( wxSize( 120,-1 ) );

	magMiddle->Add( m_magAmount, 0, wxALL, 5 );

	m_updateMagAmount = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Update Amount ->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_updateMagAmount->SetMinSize( wxSize( 120,-1 ) );

	magMiddle->Add( m_updateMagAmount, 0, wxALL, 5 );

	m_magRemove = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove -->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magRemove->SetMinSize( wxSize( 120,-1 ) );

	magMiddle->Add( m_magRemove, 0, wxALL, 5 );


	loadoutRow4Sizer->Add( magMiddle, 1, wxEXPAND, 5 );

	wxFlexGridSizer* magRightSide;
	magRightSide = new wxFlexGridSizer( 0, 2, 0, 0 );
	magRightSide->SetFlexibleDirection( wxBOTH );
	magRightSide->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_magLB->Append( wxT("30Rnd_65x39_caseless_mag|2") );
	m_magLB->Append( wxT("SmokeShell") );
	m_magLB->SetMinSize( wxSize( 150,215 ) );
	m_magLB->SetMaxSize( wxSize( 150,500 ) );

	magRightSide->Add( m_magLB, 0, wxALL, 5 );


	loadoutRow4Sizer->Add( magRightSide, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow4Sizer, 1, wxEXPAND, 5 );

	m_staticline7 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow5Sizer1;
	loadoutRow5Sizer1 = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow5Sizer1->AddGrowableCol( 0 );
	loadoutRow5Sizer1->SetFlexibleDirection( wxBOTH );
	loadoutRow5Sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* itemLeftSide;
	itemLeftSide = new wxFlexGridSizer( 0, 1, 0, 0 );
	itemLeftSide->SetFlexibleDirection( wxBOTH );
	itemLeftSide->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Items"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemTxt->Wrap( -1 );
	m_itemTxt->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	itemLeftSide->Add( m_itemTxt, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer32111;
	fgSizer32111 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer32111->SetFlexibleDirection( wxBOTH );
	fgSizer32111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer33111;
	fgSizer33111 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer33111->SetFlexibleDirection( wxBOTH );
	fgSizer33111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemCustom = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33111->Add( m_itemCustom, 0, wxALL, 5 );

	m_addItemCustom = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33111->Add( m_addItemCustom, 0, wxALL, 5 );

	m_itemPresets = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_itemPresets->Append( wxT("First Aid Kit") );
	m_itemPresets->SetMinSize( wxSize( 130,150 ) );
	m_itemPresets->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer33111->Add( m_itemPresets, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer35111;
	fgSizer35111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer35111->AddGrowableRow( 0 );
	fgSizer35111->SetFlexibleDirection( wxBOTH );
	fgSizer35111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addItemPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35111->Add( m_addItemPreset, 0, wxALL, 5 );

	m_removeItemPreset = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35111->Add( m_removeItemPreset, 0, wxALL, 5 );


	fgSizer33111->Add( fgSizer35111, 1, wxEXPAND, 5 );


	fgSizer32111->Add( fgSizer33111, 1, wxEXPAND, 5 );


	itemLeftSide->Add( fgSizer32111, 1, wxEXPAND, 5 );


	loadoutRow5Sizer1->Add( itemLeftSide, 1, wxEXPAND, 5 );

	wxFlexGridSizer* itemMiddle;
	itemMiddle = new wxFlexGridSizer( 0, 1, 0, 0 );
	itemMiddle->AddGrowableRow( 2 );
	itemMiddle->SetFlexibleDirection( wxBOTH );
	itemMiddle->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemAmountTxt = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Amount"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemAmountTxt->Wrap( -1 );
	itemMiddle->Add( m_itemAmountTxt, 0, wxALL, 5 );

	m_itemAmount = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemAmount->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle->Add( m_itemAmount, 0, wxALL, 5 );

	m_itemUpdateAmount = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Update Amount ->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemUpdateAmount->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle->Add( m_itemUpdateAmount, 0, wxALL, 5 );

	m_itemRemove = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove -->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemRemove->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle->Add( m_itemRemove, 0, wxALL, 5 );


	loadoutRow5Sizer1->Add( itemMiddle, 1, wxEXPAND, 5 );

	wxFlexGridSizer* itemRightSide;
	itemRightSide = new wxFlexGridSizer( 0, 2, 0, 0 );
	itemRightSide->SetFlexibleDirection( wxBOTH );
	itemRightSide->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemLB = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_itemLB->Append( wxT("FirstAidKit|1") );
	m_itemLB->SetMinSize( wxSize( 150,215 ) );
	m_itemLB->SetMaxSize( wxSize( 150,500 ) );

	itemRightSide->Add( m_itemLB, 0, wxALL, 5 );


	loadoutRow5Sizer1->Add( itemRightSide, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow5Sizer1, 1, wxEXPAND, 5 );


	m_defaultLoadout->SetSizer( loadoutPageSizer );
	m_defaultLoadout->Layout();
	loadoutPageSizer->Fit( m_defaultLoadout );
	m_loadoutBook->AddPage( m_defaultLoadout, wxT("Blufor1"), false );

	fgSizer10->Add( m_loadoutBook, 1, wxEXPAND | wxALL, 5 );


	m_respawnPanel->SetSizer( fgSizer10 );
	m_respawnPanel->Layout();
	fgSizer10->Fit( m_respawnPanel );
	m_tabBook->AddPage( m_respawnPanel, wxT("Respawn"), false );
	m_eventPane = new wxPanel( m_tabBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText25 = new wxStaticText( m_eventPane, wxID_ANY, wxT("Coming Soon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer11->Add( m_staticText25, 0, wxALL, 5 );


	m_eventPane->SetSizer( fgSizer11 );
	m_eventPane->Layout();
	fgSizer11->Fit( m_eventPane );
	m_tabBook->AddPage( m_eventPane, wxT("Events"), false );

	m_statusBar = this->CreateStatusBar( 3, 0, wxID_ANY );

	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::save ), this, m_save->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::saveAs ), this, m_saveAs->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::open ), this, m_open->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::exit ), this, m_exit->GetId());
	m_options->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainFrame::disableContextMenu ), this, m_contextMenu->GetId());
	m_tabBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( mainFrame::onTabChange ), NULL, this );
	m_gameType->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::gameTypeFocus ), NULL, this );
	m_minPlayers->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::minPlayersFocus ), NULL, this );
	m_maxPlayers->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::maxPlayersFocus ), NULL, this );
	m_scriptedHud->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::scriptedHudFocus ), NULL, this );
	m_unitInfo->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::unitInfoFocus ), NULL, this );
	m_vehRadar->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehRadarFocus ), NULL, this );
	m_vehCompass->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehInfoFocus ), NULL, this );
	m_tankDir->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::tankDirFocus ), NULL, this );
	m_commandMenu->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::commandMenuFocus ), NULL, this );
	m_grpInfo->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::grpInfoFocus ), NULL, this );
	m_crosshair->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::crosshairFocus ), NULL, this );
	m_vehDispPanel->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehDisplayPanelFocus ), NULL, this );
	m_deathMsg->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::deathMsgFocus ), NULL, this );
	m_forceDraw3D->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::forceDraw3DFocus ), NULL, this );
	m_showMap->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::showMapFocus ), NULL, this );
	m_disableAi->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::disableAIFocus ), NULL, this );
	m_adminConsole->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::adminConsoleFocus ), NULL, this );
	m_corpseManager->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::corpseManagerFocus ), NULL, this );
	m_wreckManager->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::corpseManagerFocus ), NULL, this );
	m_missionBackground->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( mainFrame::onMissionBackground ), NULL, this );
	m_worldBackground->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( mainFrame::onMapBackground ), NULL, this );
	m_respawnType->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::respwanTypeFocus ), NULL, this );
	m_startRespawn->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::startRespawnFocus ), NULL, this );
	m_respawnDelaySlider->Connect( wxEVT_SLIDER, wxCommandEventHandler( mainFrame::respawnDelaySliderUpdate ), NULL, this );
	m_respawnDelay->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( mainFrame::respawnDelayUpdate ), NULL, this );
	m_vehRespawnDelaySlider->Connect( wxEVT_SLIDER, wxCommandEventHandler( mainFrame::vehRespawnDelaySliderUpdate ), NULL, this );
	m_vehRespawnDelay->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( mainFrame::vehRespawnDelayUpdate ), NULL, this );
	m_newLoadout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::newLoadout ), NULL, this );
	m_dupeLoadout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::dupeLoadout ), NULL, this );
	m_renameLoadout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::renameLoadout ), NULL, this );
	m_closeLoadout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::closeLoadout ), NULL, this );
	m_loadoutLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::selectLoadout ), NULL, this );
	m_delLoadout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::deleteLoadout ), NULL, this );
	m_uniformLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onUniformChange ), NULL, this );
	m_backpackLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onBackpackChange ), NULL, this );
	m_primaryLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onPrimaryChange ), NULL, this );
	m_secondaryLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onSecondaryChange ), NULL, this );
	m_addLinkedCustom->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomLinked ), NULL, this );
	m_addLinkPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetLinked ), NULL, this );
	m_removeLinkPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetLinked ), NULL, this );
	m_removeLinkEquip->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeLinked ), NULL, this );
	m_vestLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onVestChange ), NULL, this );
	m_addWeapCustom->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomWeap ), NULL, this );
	m_addWeapPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetWeap ), NULL, this );
	m_removeWeapPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetWeap ), NULL, this );
	m_removeWeapEquip->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeWeap ), NULL, this );
	m_helmetLB->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onHelmetChange ), NULL, this );
	m_addMagCustom->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomMag ), NULL, this );
	m_addMagPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetMag ), NULL, this );
	m_removeMagPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetMag ), NULL, this );
	m_updateMagAmount->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::updateMagAmount ), NULL, this );
	m_magRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeMag ), NULL, this );
	m_addItemCustom->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomItem ), NULL, this );
	m_addItemPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetItem ), NULL, this );
	m_removeItemPreset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetItem ), NULL, this );
	m_itemUpdateAmount->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::updateItemAmount ), NULL, this );
	m_itemRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeItem ), NULL, this );
}

mainFrame::~mainFrame()
{
	// Disconnect Events
	m_tabBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( mainFrame::onTabChange ), NULL, this );
	m_gameType->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::gameTypeFocus ), NULL, this );
	m_minPlayers->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::minPlayersFocus ), NULL, this );
	m_maxPlayers->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::maxPlayersFocus ), NULL, this );
	m_scriptedHud->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::scriptedHudFocus ), NULL, this );
	m_unitInfo->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::unitInfoFocus ), NULL, this );
	m_vehRadar->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehRadarFocus ), NULL, this );
	m_vehCompass->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehInfoFocus ), NULL, this );
	m_tankDir->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::tankDirFocus ), NULL, this );
	m_commandMenu->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::commandMenuFocus ), NULL, this );
	m_grpInfo->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::grpInfoFocus ), NULL, this );
	m_crosshair->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::crosshairFocus ), NULL, this );
	m_vehDispPanel->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::vehDisplayPanelFocus ), NULL, this );
	m_deathMsg->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::deathMsgFocus ), NULL, this );
	m_forceDraw3D->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::forceDraw3DFocus ), NULL, this );
	m_showMap->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::showMapFocus ), NULL, this );
	m_disableAi->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::disableAIFocus ), NULL, this );
	m_adminConsole->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::adminConsoleFocus ), NULL, this );
	m_corpseManager->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::corpseManagerFocus ), NULL, this );
	m_wreckManager->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::corpseManagerFocus ), NULL, this );
	m_missionBackground->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( mainFrame::onMissionBackground ), NULL, this );
	m_worldBackground->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( mainFrame::onMapBackground ), NULL, this );
	m_respawnType->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::respwanTypeFocus ), NULL, this );
	m_startRespawn->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( mainFrame::startRespawnFocus ), NULL, this );
	m_respawnDelaySlider->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( mainFrame::respawnDelaySliderUpdate ), NULL, this );
	m_respawnDelay->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( mainFrame::respawnDelayUpdate ), NULL, this );
	m_vehRespawnDelaySlider->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( mainFrame::vehRespawnDelaySliderUpdate ), NULL, this );
	m_vehRespawnDelay->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( mainFrame::vehRespawnDelayUpdate ), NULL, this );
	m_newLoadout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::newLoadout ), NULL, this );
	m_dupeLoadout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::dupeLoadout ), NULL, this );
	m_renameLoadout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::renameLoadout ), NULL, this );
	m_closeLoadout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::closeLoadout ), NULL, this );
	m_loadoutLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::selectLoadout ), NULL, this );
	m_delLoadout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::deleteLoadout ), NULL, this );
	m_uniformLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onUniformChange ), NULL, this );
	m_backpackLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onBackpackChange ), NULL, this );
	m_primaryLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onPrimaryChange ), NULL, this );
	m_secondaryLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onSecondaryChange ), NULL, this );
	m_addLinkedCustom->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomLinked ), NULL, this );
	m_addLinkPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetLinked ), NULL, this );
	m_removeLinkPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetLinked ), NULL, this );
	m_removeLinkEquip->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeLinked ), NULL, this );
	m_vestLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onVestChange ), NULL, this );
	m_addWeapCustom->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomWeap ), NULL, this );
	m_addWeapPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetWeap ), NULL, this );
	m_removeWeapPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetWeap ), NULL, this );
	m_removeWeapEquip->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeWeap ), NULL, this );
	m_helmetLB->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( mainFrame::onHelmetChange ), NULL, this );
	m_addMagCustom->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomMag ), NULL, this );
	m_addMagPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetMag ), NULL, this );
	m_removeMagPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetMag ), NULL, this );
	m_updateMagAmount->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::updateMagAmount ), NULL, this );
	m_magRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeMag ), NULL, this );
	m_addItemCustom->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addCustomItem ), NULL, this );
	m_addItemPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::addPresetItem ), NULL, this );
	m_removeItemPreset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removePresetItem ), NULL, this );
	m_itemUpdateAmount->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::updateItemAmount ), NULL, this );
	m_itemRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainFrame::removeItem ), NULL, this );

	m_mgr.UnInit();

}

LoadoutPanel::LoadoutPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetForegroundColour( wxColour( 192, 192, 192 ) );
	this->SetBackgroundColour( wxColour( 192, 192, 192 ) );

	wxBoxSizer* loadoutPanelSizer;
	loadoutPanelSizer = new wxBoxSizer( wxVERTICAL );

	m_defaultLoadout = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	m_defaultLoadout->SetScrollRate( 5, 5 );
	wxFlexGridSizer* loadoutPageSizer;
	loadoutPageSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	loadoutPageSizer->SetFlexibleDirection( wxBOTH );
	loadoutPageSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* loadoutRow1Sizer1;
	loadoutRow1Sizer1 = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow1Sizer1->SetFlexibleDirection( wxBOTH );
	loadoutRow1Sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer211;
	fgSizer211 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer211->SetFlexibleDirection( wxBOTH );
	fgSizer211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_loadoutDispNameTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Display Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loadoutDispNameTxt1->Wrap( -1 );
	fgSizer211->Add( m_loadoutDispNameTxt1, 0, wxALL, 5 );

	m_loadoutDispName1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("Light"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer211->Add( m_loadoutDispName1, 0, wxALL, 5 );

	m_loadoutRoleTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Role (Optional)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loadoutRoleTxt1->Wrap( -1 );
	fgSizer211->Add( m_loadoutRoleTxt1, 0, wxALL, 5 );

	Assault1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("Assault"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer211->Add( Assault1, 0, wxALL, 5 );

	wxFlexGridSizer* uniformSizer1;
	uniformSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	uniformSizer1->SetFlexibleDirection( wxBOTH );
	uniformSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_uniformTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Uniform"), wxDefaultPosition, wxDefaultSize, 0 );
	m_uniformTxt1->Wrap( -1 );
	m_uniformTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	uniformSizer1->Add( m_uniformTxt1, 0, wxALL, 5 );

	m_uniform1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("U_B_CombatUniform_mcam_tshirt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_uniform1->SetMinSize( wxSize( 150,25 ) );
	m_uniform1->SetMaxSize( wxSize( 150,25 ) );

	uniformSizer1->Add( m_uniform1, 0, wxALL, 5 );

	m_uniformLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_uniformLB1->SetMinSize( wxSize( 150,150 ) );
	m_uniformLB1->SetMaxSize( wxSize( 150,250 ) );

	uniformSizer1->Add( m_uniformLB1, 0, wxALL, 5 );


	fgSizer211->Add( uniformSizer1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* backpackSizer1;
	backpackSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	backpackSizer1->SetFlexibleDirection( wxBOTH );
	backpackSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_backpackTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Backpack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_backpackTxt1->Wrap( -1 );
	m_backpackTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	backpackSizer1->Add( m_backpackTxt1, 0, wxALL, 5 );

	m_backpack1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("B_AssaultPack_mcamo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_backpack1->SetMinSize( wxSize( 150,25 ) );
	m_backpack1->SetMaxSize( wxSize( 150,25 ) );

	backpackSizer1->Add( m_backpack1, 0, wxALL, 5 );

	m_backpackLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_backpackLB1->SetMinSize( wxSize( 150,150 ) );
	m_backpackLB1->SetMaxSize( wxSize( 150,250 ) );

	backpackSizer1->Add( m_backpackLB1, 0, wxALL, 5 );


	fgSizer211->Add( backpackSizer1, 1, wxEXPAND, 5 );


	loadoutRow1Sizer1->Add( fgSizer211, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer221;
	fgSizer221 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer221->SetFlexibleDirection( wxBOTH );
	fgSizer221->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* primarySizer1;
	primarySizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	primarySizer1->SetFlexibleDirection( wxBOTH );
	primarySizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_primaryTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Primary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_primaryTxt1->Wrap( -1 );
	m_primaryTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	primarySizer1->Add( m_primaryTxt1, 0, wxALL, 5 );

	m_primary1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("arifle_MXC_F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_primary1->SetMinSize( wxSize( 150,25 ) );
	m_primary1->SetMaxSize( wxSize( 150,25 ) );

	primarySizer1->Add( m_primary1, 0, wxALL, 5 );

	m_primaryLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_primaryLB1->SetMinSize( wxSize( 150,217 ) );
	m_primaryLB1->SetMaxSize( wxSize( 150,250 ) );

	primarySizer1->Add( m_primaryLB1, 0, wxALL, 5 );


	fgSizer221->Add( primarySizer1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* secondarySizer1;
	secondarySizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	secondarySizer1->SetFlexibleDirection( wxBOTH );
	secondarySizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_secondaryTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Secondary"), wxDefaultPosition, wxDefaultSize, 0 );
	m_secondaryTxt1->Wrap( -1 );
	m_secondaryTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	secondarySizer1->Add( m_secondaryTxt1, 0, wxALL, 5 );

	m_secondary1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_secondary1->SetMinSize( wxSize( 150,25 ) );
	m_secondary1->SetMaxSize( wxSize( 150,25 ) );

	secondarySizer1->Add( m_secondary1, 0, wxALL, 5 );

	m_secondaryLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_secondaryLB1->SetMinSize( wxSize( 150,217 ) );
	m_secondaryLB1->SetMaxSize( wxSize( 150,250 ) );

	secondarySizer1->Add( m_secondaryLB1, 0, wxALL, 5 );


	fgSizer221->Add( secondarySizer1, 1, wxEXPAND, 5 );


	loadoutRow1Sizer1->Add( fgSizer221, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow1Sizer1, 1, wxEXPAND, 5 );

	m_staticline51 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline51, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow2Sizer1;
	loadoutRow2Sizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	loadoutRow2Sizer1->SetFlexibleDirection( wxBOTH );
	loadoutRow2Sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* linkedSizer1;
	linkedSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	linkedSizer1->SetFlexibleDirection( wxBOTH );
	linkedSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_otherEquip1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Other Equipment (Linked Items)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_otherEquip1->Wrap( -1 );
	m_otherEquip1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	linkedSizer1->Add( m_otherEquip1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer322;
	fgSizer322 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer322->SetFlexibleDirection( wxBOTH );
	fgSizer322->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer332;
	fgSizer332 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer332->SetFlexibleDirection( wxBOTH );
	fgSizer332->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_linkedCustom1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer332->Add( m_linkedCustom1, 0, wxALL, 5 );

	m_addLinkedCustom1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer332->Add( m_addLinkedCustom1, 0, wxALL, 5 );

	m_linkedPresets1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_linkedPresets1->Append( wxT("Map : ItemMap") );
	m_linkedPresets1->Append( wxT("Compass : ItemCompass") );
	m_linkedPresets1->Append( wxT("Watch : ItemWatch") );
	m_linkedPresets1->Append( wxT("Radio : ItemRadio") );
	m_linkedPresets1->SetMinSize( wxSize( 130,150 ) );
	m_linkedPresets1->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer332->Add( m_linkedPresets1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer352;
	fgSizer352 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer352->AddGrowableRow( 1 );
	fgSizer352->SetFlexibleDirection( wxBOTH );
	fgSizer352->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addLinkPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer352->Add( m_addLinkPreset1, 0, wxALL, 5 );

	m_removeLinkPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer352->Add( m_removeLinkPreset1, 0, wxALL, 5 );

	m_removeLinkEquip1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove ->"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer352->Add( m_removeLinkEquip1, 0, wxALL, 5 );


	fgSizer332->Add( fgSizer352, 1, wxEXPAND, 5 );


	fgSizer322->Add( fgSizer332, 1, wxEXPAND, 5 );

	m_linkedItemsLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_linkedItemsLB1->Append( wxT("ItemMap") );
	m_linkedItemsLB1->Append( wxT("ItemCompass") );
	m_linkedItemsLB1->Append( wxT("ItemWatch") );
	m_linkedItemsLB1->Append( wxT("ItemRadio") );
	m_linkedItemsLB1->Append( wxT("optic_Aco") );
	m_linkedItemsLB1->Append( wxT("acc_flashlight") );
	m_linkedItemsLB1->SetMinSize( wxSize( 150,185 ) );
	m_linkedItemsLB1->SetMaxSize( wxSize( 150,500 ) );

	fgSizer322->Add( m_linkedItemsLB1, 0, wxALL, 5 );


	linkedSizer1->Add( fgSizer322, 1, wxEXPAND, 5 );


	loadoutRow2Sizer1->Add( linkedSizer1, 1, wxEXPAND, 5 );


	loadoutRow2Sizer1->Add( 10, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* vestSizer1;
	vestSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	vestSizer1->SetFlexibleDirection( wxBOTH );
	vestSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_vestTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Vest"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vestTxt1->Wrap( -1 );
	m_vestTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	vestSizer1->Add( m_vestTxt1, 0, wxALL, 5 );

	m_vest1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("V_Chestrig_khk"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vest1->SetMinSize( wxSize( 150,25 ) );
	m_vest1->SetMaxSize( wxSize( 150,25 ) );

	vestSizer1->Add( m_vest1, 0, wxALL, 5 );

	m_vestLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_vestLB1->SetMinSize( wxSize( 150,150 ) );
	m_vestLB1->SetMaxSize( wxSize( 150,250 ) );

	vestSizer1->Add( m_vestLB1, 0, wxALL, 5 );


	loadoutRow2Sizer1->Add( vestSizer1, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow2Sizer1, 1, wxEXPAND, 5 );

	m_staticline61 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline61, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow3Sizer1;
	loadoutRow3Sizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	loadoutRow3Sizer1->SetFlexibleDirection( wxBOTH );
	loadoutRow3Sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* otherWeapSizer1;
	otherWeapSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	otherWeapSizer1->SetFlexibleDirection( wxBOTH );
	otherWeapSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_otherWeap1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Other Weapons"), wxDefaultPosition, wxDefaultSize, 0 );
	m_otherWeap1->Wrap( -1 );
	m_otherWeap1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	otherWeapSizer1->Add( m_otherWeap1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer3212;
	fgSizer3212 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer3212->SetFlexibleDirection( wxBOTH );
	fgSizer3212->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer3312;
	fgSizer3312 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3312->SetFlexibleDirection( wxBOTH );
	fgSizer3312->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_weapCustom1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3312->Add( m_weapCustom1, 0, wxALL, 5 );

	m_addWeapCustom1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3312->Add( m_addWeapCustom1, 0, wxALL, 5 );

	m_weapPresets1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_weapPresets1->Append( wxT("Binocular") );
	m_weapPresets1->SetMinSize( wxSize( 130,150 ) );
	m_weapPresets1->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer3312->Add( m_weapPresets1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer3512;
	fgSizer3512 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer3512->AddGrowableRow( 1 );
	fgSizer3512->SetFlexibleDirection( wxBOTH );
	fgSizer3512->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addWeapPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3512->Add( m_addWeapPreset1, 0, wxALL, 5 );

	m_removeWeapPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3512->Add( m_removeWeapPreset1, 0, wxALL, 5 );

	m_removeWeapEquip1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove ->"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3512->Add( m_removeWeapEquip1, 0, wxALL, 5 );


	fgSizer3312->Add( fgSizer3512, 1, wxEXPAND, 5 );


	fgSizer3212->Add( fgSizer3312, 1, wxEXPAND, 5 );

	m_weaponsLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_weaponsLB1->Append( wxT("Binocular") );
	m_weaponsLB1->SetMinSize( wxSize( 150,185 ) );
	m_weaponsLB1->SetMaxSize( wxSize( 150,500 ) );

	fgSizer3212->Add( m_weaponsLB1, 0, wxALL, 5 );


	otherWeapSizer1->Add( fgSizer3212, 1, wxEXPAND, 5 );


	loadoutRow3Sizer1->Add( otherWeapSizer1, 1, wxEXPAND, 5 );


	loadoutRow3Sizer1->Add( 10, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* helmetSizer1;
	helmetSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	helmetSizer1->SetFlexibleDirection( wxBOTH );
	helmetSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_helmetTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Helmet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helmetTxt1->Wrap( -1 );
	m_helmetTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	helmetSizer1->Add( m_helmetTxt1, 0, wxALL, 5 );

	m_helmet1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("H_Watchcap_blk"), wxDefaultPosition, wxDefaultSize, 0 );
	m_helmet1->SetMinSize( wxSize( 150,25 ) );
	m_helmet1->SetMaxSize( wxSize( 150,25 ) );

	helmetSizer1->Add( m_helmet1, 0, wxALL, 5 );

	m_helmetLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_helmetLB1->SetMinSize( wxSize( 150,150 ) );
	m_helmetLB1->SetMaxSize( wxSize( 150,250 ) );

	helmetSizer1->Add( m_helmetLB1, 0, wxALL, 5 );


	loadoutRow3Sizer1->Add( helmetSizer1, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow3Sizer1, 1, wxEXPAND, 5 );

	m_staticline81 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline81, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow4Sizer1;
	loadoutRow4Sizer1 = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow4Sizer1->AddGrowableCol( 0 );
	loadoutRow4Sizer1->SetFlexibleDirection( wxBOTH );
	loadoutRow4Sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* magLeftSide1;
	magLeftSide1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	magLeftSide1->SetFlexibleDirection( wxBOTH );
	magLeftSide1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magsTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Magazines"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magsTxt1->Wrap( -1 );
	m_magsTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	magLeftSide1->Add( m_magsTxt1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer32112;
	fgSizer32112 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer32112->SetFlexibleDirection( wxBOTH );
	fgSizer32112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer33112;
	fgSizer33112 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer33112->SetFlexibleDirection( wxBOTH );
	fgSizer33112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magCustom1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33112->Add( m_magCustom1, 0, wxALL, 5 );

	m_addMagCustom1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer33112->Add( m_addMagCustom1, 0, wxALL, 5 );

	m_magPresets1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_magPresets1->Append( wxT("30Rnd_65x39_caseless_mag") );
	m_magPresets1->SetMinSize( wxSize( 130,150 ) );
	m_magPresets1->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer33112->Add( m_magPresets1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer35112;
	fgSizer35112 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer35112->AddGrowableRow( 0 );
	fgSizer35112->SetFlexibleDirection( wxBOTH );
	fgSizer35112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addMagPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35112->Add( m_addMagPreset1, 0, wxALL, 5 );

	m_removeMagPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer35112->Add( m_removeMagPreset1, 0, wxALL, 5 );


	fgSizer33112->Add( fgSizer35112, 1, wxEXPAND, 5 );


	fgSizer32112->Add( fgSizer33112, 1, wxEXPAND, 5 );


	magLeftSide1->Add( fgSizer32112, 1, wxEXPAND, 5 );


	loadoutRow4Sizer1->Add( magLeftSide1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* magMiddle1;
	magMiddle1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	magMiddle1->AddGrowableRow( 2 );
	magMiddle1->SetFlexibleDirection( wxBOTH );
	magMiddle1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magAmountTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Amount"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magAmountTxt1->Wrap( -1 );
	magMiddle1->Add( m_magAmountTxt1, 0, wxALL, 5 );

	m_magAmount1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magAmount1->SetMinSize( wxSize( 120,-1 ) );

	magMiddle1->Add( m_magAmount1, 0, wxALL, 5 );

	m_updateMagAmount1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Update Amount ->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_updateMagAmount1->SetMinSize( wxSize( 120,-1 ) );

	magMiddle1->Add( m_updateMagAmount1, 0, wxALL, 5 );

	m_magRemove1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove -->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_magRemove1->SetMinSize( wxSize( 120,-1 ) );

	magMiddle1->Add( m_magRemove1, 0, wxALL, 5 );


	loadoutRow4Sizer1->Add( magMiddle1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* magRightSide1;
	magRightSide1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	magRightSide1->SetFlexibleDirection( wxBOTH );
	magRightSide1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_magLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_magLB1->Append( wxT("30Rnd_65x39_caseless_mag|2") );
	m_magLB1->Append( wxT("SmokeShell") );
	m_magLB1->SetMinSize( wxSize( 150,215 ) );
	m_magLB1->SetMaxSize( wxSize( 150,500 ) );

	magRightSide1->Add( m_magLB1, 0, wxALL, 5 );


	loadoutRow4Sizer1->Add( magRightSide1, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow4Sizer1, 1, wxEXPAND, 5 );

	m_staticline71 = new wxStaticLine( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	loadoutPageSizer->Add( m_staticline71, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* loadoutRow5Sizer11;
	loadoutRow5Sizer11 = new wxFlexGridSizer( 1, 0, 0, 0 );
	loadoutRow5Sizer11->AddGrowableCol( 0 );
	loadoutRow5Sizer11->SetFlexibleDirection( wxBOTH );
	loadoutRow5Sizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* itemLeftSide1;
	itemLeftSide1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	itemLeftSide1->SetFlexibleDirection( wxBOTH );
	itemLeftSide1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Items"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemTxt1->Wrap( -1 );
	m_itemTxt1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	itemLeftSide1->Add( m_itemTxt1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer321111;
	fgSizer321111 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer321111->SetFlexibleDirection( wxBOTH );
	fgSizer321111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizer331111;
	fgSizer331111 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer331111->SetFlexibleDirection( wxBOTH );
	fgSizer331111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemCustom1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer331111->Add( m_itemCustom1, 0, wxALL, 5 );

	m_addItemCustom1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Custom"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer331111->Add( m_addItemCustom1, 0, wxALL, 5 );

	m_itemPresets1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_itemPresets1->Append( wxT("First Aid Kit") );
	m_itemPresets1->SetMinSize( wxSize( 130,150 ) );
	m_itemPresets1->SetMaxSize( wxSize( 150,-1 ) );

	fgSizer331111->Add( m_itemPresets1, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer351111;
	fgSizer351111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer351111->AddGrowableRow( 0 );
	fgSizer351111->SetFlexibleDirection( wxBOTH );
	fgSizer351111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_addItemPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Add Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer351111->Add( m_addItemPreset1, 0, wxALL, 5 );

	m_removeItemPreset1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove Preset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer351111->Add( m_removeItemPreset1, 0, wxALL, 5 );


	fgSizer331111->Add( fgSizer351111, 1, wxEXPAND, 5 );


	fgSizer321111->Add( fgSizer331111, 1, wxEXPAND, 5 );


	itemLeftSide1->Add( fgSizer321111, 1, wxEXPAND, 5 );


	loadoutRow5Sizer11->Add( itemLeftSide1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* itemMiddle1;
	itemMiddle1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	itemMiddle1->AddGrowableRow( 2 );
	itemMiddle1->SetFlexibleDirection( wxBOTH );
	itemMiddle1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemAmountTxt1 = new wxStaticText( m_defaultLoadout, wxID_ANY, wxT("Amount"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemAmountTxt1->Wrap( -1 );
	itemMiddle1->Add( m_itemAmountTxt1, 0, wxALL, 5 );

	m_itemAmount1 = new wxTextCtrl( m_defaultLoadout, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemAmount1->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle1->Add( m_itemAmount1, 0, wxALL, 5 );

	m_itemUpdateAmount1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Update Amount ->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemUpdateAmount1->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle1->Add( m_itemUpdateAmount1, 0, wxALL, 5 );

	m_itemRemove1 = new wxButton( m_defaultLoadout, wxID_ANY, wxT("Remove -->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_itemRemove1->SetMinSize( wxSize( 120,-1 ) );

	itemMiddle1->Add( m_itemRemove1, 0, wxALL, 5 );


	loadoutRow5Sizer11->Add( itemMiddle1, 1, wxEXPAND, 5 );

	wxFlexGridSizer* itemRightSide1;
	itemRightSide1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	itemRightSide1->SetFlexibleDirection( wxBOTH );
	itemRightSide1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_itemLB1 = new wxListBox( m_defaultLoadout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_itemLB1->Append( wxT("FirstAidKit|1") );
	m_itemLB1->SetMinSize( wxSize( 150,215 ) );
	m_itemLB1->SetMaxSize( wxSize( 150,500 ) );

	itemRightSide1->Add( m_itemLB1, 0, wxALL, 5 );


	loadoutRow5Sizer11->Add( itemRightSide1, 1, wxEXPAND, 5 );


	loadoutPageSizer->Add( loadoutRow5Sizer11, 1, wxEXPAND, 5 );


	m_defaultLoadout->SetSizer( loadoutPageSizer );
	m_defaultLoadout->Layout();
	loadoutPageSizer->Fit( m_defaultLoadout );
	loadoutPanelSizer->Add( m_defaultLoadout, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( loadoutPanelSizer );
	this->Layout();

	// Connect Events
	m_uniformLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onUniformChange ), NULL, this );
	m_backpackLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onBackpackChange ), NULL, this );
	m_primaryLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onPrimaryChange ), NULL, this );
	m_secondaryLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onSecondaryChange ), NULL, this );
	m_addLinkedCustom1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomLinked ), NULL, this );
	m_addLinkPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetLinked ), NULL, this );
	m_removeLinkPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetLinked ), NULL, this );
	m_removeLinkEquip1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeLinked ), NULL, this );
	m_vestLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onVestChange ), NULL, this );
	m_addWeapCustom1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomWeap ), NULL, this );
	m_addWeapPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetWeap ), NULL, this );
	m_removeWeapPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetWeap ), NULL, this );
	m_removeWeapEquip1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeWeap ), NULL, this );
	m_helmetLB1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onHelmetChange ), NULL, this );
	m_addMagCustom1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomMag ), NULL, this );
	m_addMagPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetMag ), NULL, this );
	m_removeMagPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetMag ), NULL, this );
	m_updateMagAmount1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::updateMagAmount ), NULL, this );
	m_magRemove1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeMag ), NULL, this );
	m_addItemCustom1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomItem ), NULL, this );
	m_addItemPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetItem ), NULL, this );
	m_removeItemPreset1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetItem ), NULL, this );
	m_itemUpdateAmount1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::updateItemAmount ), NULL, this );
	m_itemRemove1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeItem ), NULL, this );
}

LoadoutPanel::~LoadoutPanel()
{
	// Disconnect Events
	m_uniformLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onUniformChange ), NULL, this );
	m_backpackLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onBackpackChange ), NULL, this );
	m_primaryLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onPrimaryChange ), NULL, this );
	m_secondaryLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onSecondaryChange ), NULL, this );
	m_addLinkedCustom1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomLinked ), NULL, this );
	m_addLinkPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetLinked ), NULL, this );
	m_removeLinkPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetLinked ), NULL, this );
	m_removeLinkEquip1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeLinked ), NULL, this );
	m_vestLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onVestChange ), NULL, this );
	m_addWeapCustom1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomWeap ), NULL, this );
	m_addWeapPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetWeap ), NULL, this );
	m_removeWeapPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetWeap ), NULL, this );
	m_removeWeapEquip1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeWeap ), NULL, this );
	m_helmetLB1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LoadoutPanel::onHelmetChange ), NULL, this );
	m_addMagCustom1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomMag ), NULL, this );
	m_addMagPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetMag ), NULL, this );
	m_removeMagPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetMag ), NULL, this );
	m_updateMagAmount1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::updateMagAmount ), NULL, this );
	m_magRemove1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeMag ), NULL, this );
	m_addItemCustom1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addCustomItem ), NULL, this );
	m_addItemPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::addPresetItem ), NULL, this );
	m_removeItemPreset1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removePresetItem ), NULL, this );
	m_itemUpdateAmount1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::updateItemAmount ), NULL, this );
	m_itemRemove1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadoutPanel::removeItem ), NULL, this );

}
