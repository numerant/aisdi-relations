/***************************************************************
 * Name:      AisdiRelationsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

#ifndef AISDIRELATIONSMAIN_H
#define AISDIRELATIONSMAIN_H

/** Deklaracje, że nazwy klas pojawią się później w kodzie */
class PanelTitleMaintance;
class PanelGroupsMaintance;
class PanelInboxMaintance;
class PanelMulTreeMaintance;
class PanelStatisticsMaintance;
class PanelUsembersMaintance;

/** Include'y klas projektu */
#include "../src/Database.h"
#include "../src/IOInterface.h"
#include "../src/Parameters.h"

//(*Headers(AisdiRelationsFrame)
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/html/htmlwin.h>
//*)

class AisdiRelationsFrame: public wxFrame
{
    friend class PanelTitleMaintance;
    friend class PanelGroupsMaintance;
    friend class PanelInboxMaintance;
    friend class PanelMulTreeMaintance;
    friend class PanelStatisticsMaintance;
    friend class PanelUsembersMaintance;
public:

    AisdiRelationsFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~AisdiRelationsFrame();

    /** Dopisane pola */
    bool settingsEnabled = true;

    /** Dopisane metody */
    void  ShowTitle(void);

private:

    //(*Handlers(AisdiRelationsFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnT_ImageButtonAddClick(wxCommandEvent& event);
    void OnT_ImageButtonImportClick(wxCommandEvent& event);
    void OnT_ImageButtonLoadClick(wxCommandEvent& event);
    void OnT_ImageButtonInboxClick(wxCommandEvent& event);
    void OnT_ImageButtonUsembersClick(wxCommandEvent& event);
    void OnI_ImageButtonTitleClick(wxCommandEvent& event);
    void OnI_ImageButtonUsembersClick(wxCommandEvent& event);
    void OnU_ImageButtonInboxClick(wxCommandEvent& event);
    void OnU_ImageButtonTitleClick(wxCommandEvent& event);
    void OnI_ImageButtonSearchClick(wxCommandEvent& event);
    void OnU_ImageButtonSearchClick(wxCommandEvent& event);
    void OnU_ImageButtonSwitchListClick(wxCommandEvent& event);
    void OnT_ImageButtonFolderClick(wxCommandEvent& event);
    void OnT_ImageButtonFilesClick(wxCommandEvent& event);
    void OnI_ListInboxItemSelect(wxListEvent& event);
    void OnI_ListInboxItemActivated(wxListEvent& event);
    void OnI_ImageButtonAddClick(wxCommandEvent& event);
    void OnI_ImageButtonSaveClick(wxCommandEvent& event);
    void OnI_ImageButtonSettingsClick(wxCommandEvent& event);
    void OnI_ImageButtonMulTreeClick(wxCommandEvent& event);
    void OnI_ImageButtonStatsClick(wxCommandEvent& event);
    void OnI_ImageButtonGroupsClick(wxCommandEvent& event);
    void OnI_ImageButtonDeleteClick(wxCommandEvent& event);
    void OnI_ImageButtonSenderClick(wxCommandEvent& event);
    void OnI_ImageButtonReceiverClick(wxCommandEvent& event);
    void OnI_ImageButtonShowTreeClick(wxCommandEvent& event);
    void OnI_SearchCtrlTextEnter(wxCommandEvent& event);
    void OnI_ListInboxColumnClick(wxListEvent& event);
    void OnU_ImageButtonAddClick(wxCommandEvent& event);
    void OnU_ImageButtonSaveClick(wxCommandEvent& event);
    void OnU_ImageButtonSettingsClick(wxCommandEvent& event);
    void OnU_ImageButtonMulTreeClick(wxCommandEvent& event);
    void OnU_ImageButtonDeleteClick(wxCommandEvent& event);
    void OnU_ImageButtonShowGroupClick(wxCommandEvent& event);
    void OnU_ImageButtonGroupsClick(wxCommandEvent& event);
    void OnU_ImageButtonStatsClick(wxCommandEvent& event);
    void OnU_ImageButtonDeleteClick1(wxCommandEvent& event);
    void OnU_ImageButtonSwitchContentClick(wxCommandEvent& event);
    void OnU_SearchCtrlTextEnter(wxCommandEvent& event);
    void OnU_ListUsembersItemSelect(wxListEvent& event);
    void OnU_ListUsembersColumnClick(wxListEvent& event);
    void OnU_ListOutboxItemSelect(wxListEvent& event);
    void OnU_ListOutboxColumnClick(wxListEvent& event);
    void OnU_ListInboxItemSelect(wxListEvent& event);
    void OnU_ListInboxColumnClick(wxListEvent& event);
    void OnT_ImageButtonMulTreeClick(wxCommandEvent& event);
    void OnT_ImageButtonStatsClick(wxCommandEvent& event);
    void OnT_ImageButtonGroupsClick(wxCommandEvent& event);
    void OnT_ImageButtonSettingsClick(wxCommandEvent& event);
    void OnT_ImageButtonTxtClick(wxCommandEvent& event);
    void OnT_ImageButtonBinClick(wxCommandEvent& event);
    void OnT_CheckBoxRecursiveClick(wxCommandEvent& event);
    //*)

    //(*Identifiers(AisdiRelationsFrame)
    static const long ID_STATICBITMAP2;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT11;
    static const long ID_IMAGEBUTTON37;
    static const long ID_IMAGEBUTTON36;
    static const long ID_IMAGEBUTTON35;
    static const long ID_IMAGEBUTTON34;
    static const long ID_IMAGEBUTTON33;
    static const long ID_IMAGEBUTTON32;
    static const long ID_IMAGEBUTTON18;
    static const long ID_IMAGEBUTTON17;
    static const long ID_IMAGEBUTTON16;
    static const long ID_IMAGEBUTTON15;
    static const long ID_IMAGEBUTTON14;
    static const long ID_IMAGEBUTTON13;
    static const long ID_IMAGEBUTTON12;
    static const long ID_STATICLINE2;
    static const long ID_STATICLINE3;
    static const long ID_STATICLINE4;
    static const long ID_STATICLINE6;
    static const long ID_STATICTEXT60;
    static const long ID_STATICTEXT59;
    static const long ID_STATICTEXT58;
    static const long ID_STATICTEXT57;
    static const long ID_STATICTEXT56;
    static const long ID_STATICTEXT30;
    static const long ID_STATICTEXT31;
    static const long ID_STATICTEXT29;
    static const long ID_STATICTEXT28;
    static const long ID_STATICTEXT27;
    static const long ID_STATICTEXT26;
    static const long ID_STATICTEXT25;
    static const long ID_STATICTEXT24;
    static const long ID_STATICBOX5;
    static const long ID_CHECKBOX1;
    static const long ID_PANEL10;
    static const long ID_PANEL3;
    static const long ID_STATICBITMAP3;
    static const long ID_STATICTEXT54;
    static const long ID_STATICTEXT55;
    static const long ID_STATICTEXT53;
    static const long ID_STATICTEXT52;
    static const long ID_STATICTEXT51;
    static const long ID_STATICTEXT50;
    static const long ID_STATICTEXT49;
    static const long ID_STATICTEXT48;
    static const long ID_STATICTEXT47;
    static const long ID_STATICTEXT46;
    static const long ID_STATICTEXT45;
    static const long ID_STATICTEXT62;
    static const long ID_STATICTEXT44;
    static const long ID_STATICBOX3;
    static const long ID_STATICBOX4;
    static const long ID_STATICBITMAP7;
    static const long ID_LISTCTRL2;
    static const long ID_LISTCTRL4;
    static const long ID_LISTCTRL3;
    static const long ID_STATICTEXT17;
    static const long ID_STATICTEXT16;
    static const long ID_STATICTEXT15;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT14;
    static const long ID_STATICTEXT12;
    static const long ID_PANEL9;
    static const long ID_STATICTEXT19;
    static const long ID_STATICTEXT23;
    static const long ID_STATICTEXT22;
    static const long ID_STATICTEXT21;
    static const long ID_STATICTEXT20;
    static const long ID_STATICTEXT18;
    static const long ID_HTMLWINDOW2;
    static const long ID_STATICLINE8;
    static const long ID_PANEL8;
    static const long ID_IMAGEBUTTON10;
    static const long ID_IMAGEBUTTON11;
    static const long ID_IMAGEBUTTON9;
    static const long ID_IMAGEBUTTON8;
    static const long ID_IMAGEBUTTON7;
    static const long ID_IMAGEBUTTON6;
    static const long ID_IMAGEBUTTON5;
    static const long ID_IMAGEBUTTON4;
    static const long ID_IMAGEBUTTON31;
    static const long ID_IMAGEBUTTON3;
    static const long ID_IMAGEBUTTON2;
    static const long ID_IMAGEBUTTON1;
    static const long ID_IMAGEBUTTON39;
    static const long ID_SEARCHCTRL2;
    static const long ID_PANEL4;
    static const long ID_STATICBITMAP4;
    static const long ID_PANEL5;
    static const long ID_STATICBITMAP5;
    static const long ID_PANEL6;
    static const long ID_STATICBITMAP6;
    static const long ID_PANEL7;
    static const long ID_STATICBITMAP1;
    static const long ID_STATICTEXT61;
    static const long ID_STATICTEXT35;
    static const long ID_STATICTEXT34;
    static const long ID_STATICTEXT33;
    static const long ID_STATICTEXT32;
    static const long ID_STATICTEXT39;
    static const long ID_STATICTEXT38;
    static const long ID_STATICTEXT37;
    static const long ID_STATICTEXT36;
    static const long ID_STATICTEXT43;
    static const long ID_STATICTEXT42;
    static const long ID_STATICTEXT41;
    static const long ID_STATICTEXT40;
    static const long ID_STATICBOX1;
    static const long ID_LISTCTRL1;
    static const long ID_STATICBOX2;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT5;
    static const long ID_STATICLINE1;
    static const long ID_HTMLWINDOW1;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT7;
    static const long ID_IMAGEBUTTON29;
    static const long ID_IMAGEBUTTON28;
    static const long ID_IMAGEBUTTON27;
    static const long ID_IMAGEBUTTON26;
    static const long ID_IMAGEBUTTON25;
    static const long ID_IMAGEBUTTON24;
    static const long ID_IMAGEBUTTON23;
    static const long ID_IMAGEBUTTON22;
    static const long ID_IMAGEBUTTON30;
    static const long ID_IMAGEBUTTON21;
    static const long ID_IMAGEBUTTON20;
    static const long ID_IMAGEBUTTON38;
    static const long ID_IMAGEBUTTON19;
    static const long ID_SEARCHCTRL1;
    static const long ID_PANEL2;
    static const long ID_PANEL1;
    static const long idMenuNew;
    static const long idMenuOpen;
    static const long idMenuOpenFolder;
    static const long idMenuSave;
    static const long idMenuProperties;
    static const long idMenuQuit;
    static const long idMenuImportText;
    static const long idMenuImportBin;
    static const long idMenuExportText;
    static const long idMenuExportBin;
    static const long idMenuAbout;
    static const long idMenuHelp;
    //*)

    //(*Declarations(AisdiRelationsFrame)
    wxStaticBitmap* BitmapBackgroundTitle;
    wxStaticBox* U_StaticBoxUsembers;
    wxBitmapButton        *T_ImageButtonUsembers;
    wxStaticText* I_LabelFrom;
    wxStaticText* T_LabelUsembers;
    wxBitmapButton        *U_ImageButtonSearch;
    wxPanel* U_PanelStats;
    wxStaticText* T_LabelFiles;
    wxStaticText* T_LabelMulTree;
    wxHtmlWindow* U_HtmlContent;
    wxStaticText* U_LabelDate;
    wxStaticText* U_LabelMulTree;
    wxBitmapButton        *I_ImageButtonSender;
    wxPanel* PanelStatistics;
    wxBitmapButton        *T_ImageButtonAdd;
    wxStaticText* I_StaticTextTo;
    wxStaticText* I_LabelSender;
    wxStaticText* I_LabelSettings;
    wxListCtrl* U_ListUsembers;
    wxBitmapButton        *I_ImageButtonUsembers;
    wxStaticText* U_LabelTitle;
    wxFileDialog* FileDialog;
    wxPanel* U_PanelEmail;
    wxStaticText* I_LabelSubject;
    wxStaticText* U_LabelSettings;
    wxBitmapButton        *I_ImageButtonDelete;
    wxBitmapButton        *U_ImageButtonInbox;
    wxStaticText* T_LabelSettings;
    wxBitmapButton        *U_ImageButtonDelete;
    wxBitmapButton        *T_ImageButtonSettings;
    wxStaticText* U_LabelFromTo;
    wxBitmapButton        *I_ImageButtonAdd;
    wxMenuItem* MenuItem12;
    wxStaticText* I_StaticTextDate;
    wxStaticText* U_StaticTextSubject;
    wxStaticBitmap* BitmapBackgroundGroups;
    wxBitmapButton        *U_ImageButtonShowGroup;
    wxStaticBitmap* I_BitmapBackground;
    wxPanel* PanelGroups;
    wxStaticText* T_LabelGroups;
    wxMenu* Menu3;
    wxStaticText* U_StaticTextDate;
    wxStaticText* T_LabelAdd;
    wxBitmapButton        *U_ImageButtonSettings;
    wxStaticText* U_LabelName;
    wxStaticBitmap* U_BitmapUsember;
    wxBitmapButton        *T_ImageButtonBin;
    wxBitmapButton        *U_ImageButtonSwitchContent;
    wxBitmapButton        *T_ImageButtonFiles;
    wxBitmapButton        *U_ImageButtonMulTree;
    wxStaticText* I_LabelTo;
    wxStaticText* T_LabelStats;
    wxStaticText* I_LabelMulTree;
    wxBitmapButton        *U_ImageButtonTitle;
    wxStaticText* U_LabelEmail;
    wxStaticLine* T_StaticLineOpenH;
    wxBitmapButton        *T_ImageButtonStats;
    wxStaticText* I_StaticTextFrom;
    wxBitmapButton        *U_ImageButtonSwitchList;
    wxBitmapButton        *T_ImageButtonTxt;
    wxStaticLine* T_StaticLineImportH;
    wxPanel* PanelMain;
    wxBitmapButton        *T_ImageButtonGroups;
    wxPanel* T_PanelSettings;
    wxSearchCtrl* I_SearchCtrl;
    wxBitmapButton        *U_ImageButtonStats;
    wxStaticText* I_LabelAdd;
    wxStaticText* T_LabelTxt;
    wxDirDialog* DirDialog;
    wxStaticText* U_LabelInbox;
    wxStaticText* U_LabelAdd;
    wxMenuItem* MenuItem3;
    wxBitmapButton        *U_ImageButtonAdd;
    wxStaticLine* I_LineContentSeparator;
    wxStaticText* I_LabelDelete;
    wxStaticBitmap* BitmapBackgroundUsembers;
    wxBitmapButton        *I_ImageButtonMulTree;
    wxStaticText* U_StaticTextName;
    wxStaticBox* I_EmailContentBorder;
    wxHtmlWindow* I_HtmlEmailContent;
    wxStaticBitmap* BitmapBackgroundTree;
    wxMenuItem* MenuItem9;
    wxStaticBox* I_InboxBorder;
    wxBitmapButton        *T_ImageButtonLoad;
    wxStaticLine* U_LineContentSeparator;
    wxStaticText* U_LabelShowGroup;
    wxBitmapButton        *T_ImageButtonMulTree;
    wxBitmapButton        *U_ImageButtonSave;
    wxBitmapButton        *U_ImageButtonGroups;
    wxStaticText* U_LabelGroup;
    wxBitmapButton        *T_ImageButtonFolder;
    wxMenuItem* MenuItem11;
    wxStaticText* I_LabelSave;
    wxStaticText* I_LabelGroups;
    wxPanel* PanelMulTree;
    wxBitmapButton        *I_ImageButtonReceiver;
    wxStaticText* T_LabelBin;
    wxStaticText* I_LabelDate;
    wxListCtrl* I_ListInbox;
    wxPanel* PanelInbox;
    wxMenuItem* MenuItem5;
    wxStaticLine* T_StaticLineAddH;
    wxBitmapButton        *I_ImageButtonSettings;
    wxStaticText* U_StaticTextEmail;
    wxSearchCtrl* U_SearchCtrl;
    wxStaticText* U_LabelSave;
    wxStaticText* T_LabelFolder;
    wxStaticText* U_LabelDelete;
    wxMenuItem* MenuItem10;
    wxStaticText* U_LabelSubject;
    wxBitmapButton        *I_ImageButtonGroups;
    wxStaticText* U_StaticTextFromTo;
    wxStaticText* U_LabelSearch;
    wxStaticText* T_LabelInbox;
    wxStaticBox* T_BorderSettings;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem4;
    wxBitmapButton        *I_ImageButtonShowTree;
    wxStaticText* I_LabelSearch;
    wxPanel* PanelTitle;
    wxStaticText* I_LabelStats;
    wxBitmapButton        *T_ImageButtonImport;
    wxStaticText* I_StaticTextSubject;
    wxStaticText* U_LabelSwitchList;
    wxBitmapButton        *I_ImageButtonSave;
    wxStaticLine* T_StaticLineAddV;
    wxBitmapButton        *T_ImageButtonInbox;
    wxStaticText* U_StaticTextGroup;
    wxStaticText* T_LabelLoad;
    wxListCtrl* U_ListInbox;
    wxStaticText* I_LabelShowTree;
    wxBitmapButton        *I_ImageButtonTitle;
    wxBitmapButton        *I_ImageButtonSearch;
    wxPanel* PanelUsembers;
    wxStaticText* I_LabelUsembers;
    wxStaticBox* U_StaticBoxInfo;
    wxBitmapButton        *I_ImageButtonStats;
    wxStaticText* T_StaticTextTitle2;
    wxMenuItem* MenuItem8;
    wxStaticBitmap* BitmapBackgroundStatistics;
    wxCheckBox* T_CheckBoxRecursive;
    wxStaticText* I_LabelTitle;
    wxStaticText* T_LabelImport;
    wxStaticText* I_LabelReceiver;
    wxStaticText* U_LabelStats;
    wxStaticText* T_StaticTextTitle1;
    wxListCtrl* U_ListOutbox;
    wxStaticText* U_LabelGroups;
    wxStaticText* U_LabelSwitchContent;
    wxStaticText* T_StaticTextTitle3;
    //*)

    PanelTitleMaintance* P_Title;
    PanelGroupsMaintance * P_Groups;
    PanelInboxMaintance * P_Inbox;
    PanelMulTreeMaintance * P_MulTree;
    PanelStatisticsMaintance * P_Stats ;
    PanelUsembersMaintance * P_Usembers ;
    Database * database;
    IOInterface * iointerface;
    DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
