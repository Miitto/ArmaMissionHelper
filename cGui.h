///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/filepicker.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/listbox.h>
#include <wx/scrolwin.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class mainFrame
///////////////////////////////////////////////////////////////////////////////
class mainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar;
		wxMenu* m_file;
		wxMenu* m_options;
		wxNotebook* m_tabBook;
		wxPanel* m_settingsPane;
		wxPanel* m_panel81;
		wxStaticText* m_headerTxt;
		wxStaticText* m_gameTypeTxt;
		wxComboBox* m_gameType;
		wxStaticText* m_minPlayersTxt;
		wxTextCtrl* m_minPlayers;
		wxStaticText* m_maxPlayersTxr;
		wxTextCtrl* m_maxPlayers;
		wxStaticText* m_hudLabel;
		wxCheckBox* m_scriptedHud;
		wxCheckBox* m_unitInfo;
		wxCheckBox* m_vehRadar;
		wxCheckBox* m_vehCompass;
		wxCheckBox* m_tankDir;
		wxCheckBox* m_commandMenu;
		wxCheckBox* m_grpInfo;
		wxCheckBox* m_crosshair;
		wxCheckBox* m_vehDispPanel;
		wxCheckBox* m_deathMsg;
		wxCheckBox* m_forceDraw3D;
		wxStaticText* m_miscLabel;
		wxCheckBox* m_showMap;
		wxCheckBox* m_disableAi;
		wxStaticText* m_adminConsoleTxt;
		wxChoice* m_adminConsole;
		wxCheckBox* m_showCompass;
		wxCheckBox* m_showGPS;
		wxCheckBox* m_showWatch;
		wxCheckBox* m_showGroupIndicator;
		wxCheckBox* m_showUAVFeed;
		wxCheckBox* m_aiKills;
		wxStaticText* m_corpseTxt;
		wxStaticText* m_corpseManagerTxt;
		wxChoice* m_corpseManager;
		wxStaticText* m_corpseLimitTxt;
		wxTextCtrl* m_corpseLimit;
		wxStaticText* m_corpseMinTimeTxt;
		wxTextCtrl* m_corpseMinTime;
		wxStaticText* m_corpseMaxTimeTxt;
		wxTextCtrl* m_corpseMaxTime;
		wxStaticText* m_wreckTxt;
		wxStaticText* m_wreckManagerTxt;
		wxChoice* m_wreckManager;
		wxStaticText* m_wreckLimitTxt;
		wxTextCtrl* m_wreckLimit;
		wxStaticText* m_wreckMinTimeTxt;
		wxTextCtrl* m_wreckMinTime;
		wxStaticText* m_wreckMaxTimeTxt;
		wxTextCtrl* m_wreckMaxTime;
		wxStaticText* m_corpseWreckTxt;
		wxStaticText* m_minPlayerDistanceTxt;
		wxTextCtrl* m_minPlayerDistance;
		wxStaticText* m_disbaleChannel;
		wxStaticText* m_disableInfoTxt;
		wxStaticText* m_globalTxt;
		wxCheckBox* m_globalChat;
		wxCheckBox* m_globalVoice;
		wxStaticText* m_sideChatTxt;
		wxCheckBox* m_sideChat;
		wxCheckBox* m_sideVoice;
		wxStaticText* m_commandTxt;
		wxCheckBox* m_commandChat;
		wxCheckBox* m_commandVoice;
		wxStaticText* m_groupChatTxt;
		wxCheckBox* m_groupChat;
		wxCheckBox* m_groupVoice;
		wxStaticText* m_vehicleChatTxt;
		wxCheckBox* m_vehChat;
		wxCheckBox* m_vehVoice;
		wxStaticText* m_directChatTxt;
		wxStaticText* m_dirNoChatTxt;
		wxCheckBox* m_dirVoice;
		wxPanel* m_loadPane;
		wxPanel* m_panel7;
		wxTextCtrl* m_name;
		wxTextCtrl* m_author;
		wxPanel* m_panel12;
		wxStaticText* m_gameTypeLocation;
		wxPanel* m_panel8;
		wxTextCtrl* m_missionNameLocation;
		wxTextCtrl* m_missionAuthorLocation;
		wxPanel* m_panel9;
		wxFilePickerCtrl* m_missionBackground;
		wxFilePickerCtrl* m_worldBackground;
		wxPanel* m_respawnPanel;
		wxPanel* m_respawnLeftPanel;
		wxStaticText* m_respawnTypeTxt;
		wxChoice* m_respawnType;
		wxStaticText* m_startRespawnTxt;
		wxChoice* m_startRespawn;
		wxCheckBox* m_respawnButton;
		wxCheckBox* m_respawnDialog;
		wxStaticText* m_respawnDelayTxt;
		wxSlider* m_respawnDelaySlider;
		wxTextCtrl* m_respawnDelay;
		wxStaticText* m_respawnVehDelayTxt;
		wxSlider* m_vehRespawnDelaySlider;
		wxTextCtrl* m_vehRespawnDelay;
		wxStaticText* m_reviveSection;
		wxStaticText* m_reviveModeTxt;
		wxChoice* m_reviveMode;
		wxStaticText* m_damageModelTxt;
		wxChoice* m_damageModel;
		wxCheckBox* m_medicNeeded;
		wxCheckBox* m_fakConsumed;
		wxStaticText* m_reviveItem;
		wxChoice* m_reviveItem;
		wxStaticText* m_reviveTimeTxt;
		wxTextCtrl* m_reviveTime;
		wxStaticText* m_medicMultTxt;
		wxTextCtrl* m_medicMult;
		wxStaticText* m_forceRespawnDelayTxt;
		wxTextCtrl* m_forceRespawnDelay;
		wxStaticText* m_bleedOutTxt;
		wxTextCtrl* m_bleedOut;
		wxPanel* m_respawnMidPanel;
		wxStaticText* m_respawnInvTxt;
		wxButton* m_newLoadout;
		wxButton* m_dupeLoadout;
		wxStaticLine* m_staticline1;
		wxButton* m_renameLoadout;
		wxStaticLine* m_staticline2;
		wxButton* m_closeLoadout;
		wxStaticLine* m_staticline3;
		wxListBox* m_loadoutLB;
		wxStaticLine* m_staticline4;
		wxButton* m_delLoadout;
		wxNotebook* m_loadoutBook;
		wxScrolledWindow* m_defaultLoadout;
		wxStaticText* m_loadoutDispNameTxt;
		wxTextCtrl* m_loadoutDispName;
		wxStaticText* m_loadoutRoleTxt;
		wxTextCtrl* Assault;
		wxStaticText* m_uniformTxt;
		wxTextCtrl* m_uniform;
		wxListBox* m_uniformLB;
		wxStaticText* m_backpackTxt;
		wxTextCtrl* m_backpack;
		wxListBox* m_backpackLB;
		wxStaticText* m_primaryTxt;
		wxTextCtrl* m_primary;
		wxListBox* m_primaryLB;
		wxStaticText* m_secondaryTxt;
		wxTextCtrl* m_secondary;
		wxListBox* m_secondaryLB;
		wxStaticLine* m_staticline5;
		wxStaticText* m_otherEquip;
		wxTextCtrl* m_linkedCustom;
		wxButton* m_addLinkedCustom;
		wxListBox* m_linkedPresets;
		wxButton* m_addLinkPreset;
		wxButton* m_removeLinkPreset;
		wxButton* m_removeLinkEquip;
		wxListBox* m_linkedItemsLB;
		wxStaticText* m_vestTxt;
		wxTextCtrl* m_vest;
		wxListBox* m_vestLB;
		wxStaticLine* m_staticline6;
		wxStaticText* m_otherWeap;
		wxTextCtrl* m_weapCustom;
		wxButton* m_addWeapCustom;
		wxListBox* m_weapPresets;
		wxButton* m_addWeapPreset;
		wxButton* m_removeWeapPreset;
		wxButton* m_removeWeapEquip;
		wxListBox* m_weaponsLB;
		wxStaticText* m_helmetTxt;
		wxTextCtrl* m_helmet;
		wxListBox* m_helmetLB;
		wxStaticLine* m_staticline8;
		wxStaticText* m_magsTxt;
		wxTextCtrl* m_magCustom;
		wxButton* m_addMagCustom;
		wxListBox* m_magPresets;
		wxButton* m_addMagPreset;
		wxButton* m_removeMagPreset;
		wxStaticText* m_magAmountTxt;
		wxTextCtrl* m_magAmount;
		wxButton* m_updateMagAmount;
		wxButton* m_magRemove;
		wxListBox* m_magLB;
		wxStaticLine* m_staticline7;
		wxStaticText* m_itemTxt;
		wxTextCtrl* m_itemCustom;
		wxButton* m_addItemCustom;
		wxListBox* m_itemPresets;
		wxButton* m_addItemPreset;
		wxButton* m_removeItemPreset;
		wxStaticText* m_itemAmountTxt;
		wxTextCtrl* m_itemAmount;
		wxButton* m_itemUpdateAmount;
		wxButton* m_itemRemove;
		wxListBox* m_itemLB;
		wxPanel* m_eventPane;
		wxStaticText* m_staticText25;
		wxStatusBar* m_statusBar;

		// Virtual event handlers, override them in your derived class
		virtual void save( wxCommandEvent& event ) { event.Skip(); }
		virtual void saveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void open( wxCommandEvent& event ) { event.Skip(); }
		virtual void exit( wxCommandEvent& event ) { event.Skip(); }
		virtual void disableContextMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTabChange( wxNotebookEvent& event ) { event.Skip(); }
		virtual void gameTypeFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void minPlayersFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void maxPlayersFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void scriptedHudFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void unitInfoFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void vehRadarFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void vehInfoFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void tankDirFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void commandMenuFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void grpInfoFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void crosshairFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void vehDisplayPanelFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void deathMsgFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void forceDraw3DFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void showMapFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void disableAIFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void adminConsoleFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void corpseManagerFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void onMissionBackground( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void onMapBackground( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void respwanTypeFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void startRespawnFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void respawnDelaySliderUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void respawnDelayUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void vehRespawnDelaySliderUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void vehRespawnDelayUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void newLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void dupeLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void renameLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void closeLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void selectLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void deleteLoadout( wxCommandEvent& event ) { event.Skip(); }
		virtual void onUniformChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackpackChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPrimaryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSecondaryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVestChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelmetChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void updateMagAmount( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void updateItemAmount( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeItem( wxCommandEvent& event ) { event.Skip(); }


	public:

		mainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Arma Mission Helper"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1296,720 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		wxAuiManager m_mgr;

		~mainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class LoadoutPanel
///////////////////////////////////////////////////////////////////////////////
class LoadoutPanel : public wxPanel
{
	private:

	protected:
		wxScrolledWindow* m_defaultLoadout;
		wxStaticText* m_loadoutDispNameTxt1;
		wxTextCtrl* m_loadoutDispName1;
		wxStaticText* m_loadoutRoleTxt1;
		wxTextCtrl* Assault1;
		wxStaticText* m_uniformTxt1;
		wxTextCtrl* m_uniform1;
		wxListBox* m_uniformLB1;
		wxStaticText* m_backpackTxt1;
		wxTextCtrl* m_backpack1;
		wxListBox* m_backpackLB1;
		wxStaticText* m_primaryTxt1;
		wxTextCtrl* m_primary1;
		wxListBox* m_primaryLB1;
		wxStaticText* m_secondaryTxt1;
		wxTextCtrl* m_secondary1;
		wxListBox* m_secondaryLB1;
		wxStaticLine* m_staticline51;
		wxStaticText* m_otherEquip1;
		wxTextCtrl* m_linkedCustom1;
		wxButton* m_addLinkedCustom1;
		wxListBox* m_linkedPresets1;
		wxButton* m_addLinkPreset1;
		wxButton* m_removeLinkPreset1;
		wxButton* m_removeLinkEquip1;
		wxListBox* m_linkedItemsLB1;
		wxStaticText* m_vestTxt1;
		wxTextCtrl* m_vest1;
		wxListBox* m_vestLB1;
		wxStaticLine* m_staticline61;
		wxStaticText* m_otherWeap1;
		wxTextCtrl* m_weapCustom1;
		wxButton* m_addWeapCustom1;
		wxListBox* m_weapPresets1;
		wxButton* m_addWeapPreset1;
		wxButton* m_removeWeapPreset1;
		wxButton* m_removeWeapEquip1;
		wxListBox* m_weaponsLB1;
		wxStaticText* m_helmetTxt1;
		wxTextCtrl* m_helmet1;
		wxListBox* m_helmetLB1;
		wxStaticLine* m_staticline81;
		wxStaticText* m_magsTxt1;
		wxTextCtrl* m_magCustom1;
		wxButton* m_addMagCustom1;
		wxListBox* m_magPresets1;
		wxButton* m_addMagPreset1;
		wxButton* m_removeMagPreset1;
		wxStaticText* m_magAmountTxt1;
		wxTextCtrl* m_magAmount1;
		wxButton* m_updateMagAmount1;
		wxButton* m_magRemove1;
		wxListBox* m_magLB1;
		wxStaticLine* m_staticline71;
		wxStaticText* m_itemTxt1;
		wxTextCtrl* m_itemCustom1;
		wxButton* m_addItemCustom1;
		wxListBox* m_itemPresets1;
		wxButton* m_addItemPreset1;
		wxButton* m_removeItemPreset1;
		wxStaticText* m_itemAmountTxt1;
		wxTextCtrl* m_itemAmount1;
		wxButton* m_itemUpdateAmount1;
		wxButton* m_itemRemove1;
		wxListBox* m_itemLB1;

		// Virtual event handlers, override them in your derived class
		virtual void onUniformChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBackpackChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPrimaryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSecondaryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeLinked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVestChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeWeap( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelmetChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void updateMagAmount( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeMag( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCustomItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void addPresetItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void removePresetItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void updateItemAmount( wxCommandEvent& event ) { event.Skip(); }
		virtual void removeItem( wxCommandEvent& event ) { event.Skip(); }


	public:

		LoadoutPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 666,756 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~LoadoutPanel();

};

