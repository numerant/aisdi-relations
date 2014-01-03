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
class PanelNotifyMaintance;

/** Include'y klas projektu */
#include "../src/Database.h"
#include "../src/IOInterface.h"
#include "../src/Parameters.h"
#include "../src/Statistics.h"

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
#include <wx/timer.h>
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
    friend class PanelNotifyMaintance;

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
    void OnM_ImageButtonTitleClick(wxCommandEvent& event);
    void OnG_ImageButtonTitleClick(wxCommandEvent& event);
    void OnS_ImageButtonTitleClick(wxCommandEvent& event);
    void OnG_ImageButtonInboxClick(wxCommandEvent& event);
    void OnG_ImageButtonUsembersClick(wxCommandEvent& event);
    void OnG_ImageButtonStatsClick(wxCommandEvent& event);
    void OnG_ImageButtonMulTreeClick(wxCommandEvent& event);
    void OnM_ImageButtonStatsClick(wxCommandEvent& event);
    void OnM_ImageButtonGroupsClick(wxCommandEvent& event);
    void OnM_ImageButtonUsembersClick(wxCommandEvent& event);
    void OnM_ImageButtonInboxClick(wxCommandEvent& event);
    void OnS_ImageButtonInboxClick(wxCommandEvent& event);
    void OnS_ImageButtonUsembersClick(wxCommandEvent& event);
    void OnS_ImageButtonGroupsClick(wxCommandEvent& event);
    void OnS_ImageButtonMulTreeClick(wxCommandEvent& event);
    void OnTimer1Trigger(wxTimerEvent& event);
    void OnPanelStatisticsPaint(wxPaintEvent& event);
    void OnS_PanelEmailPerMonthPaint(wxPaintEvent& event);
    void OnS_PanelEmailPerMonthLeftDClick(wxMouseEvent& event);
    void OnS_PanelCountersPaint(wxPaintEvent& event);
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
    static const long ID_PANEL3;
    static const long ID_STATICBITMAP6;
    static const long ID_STATICTEXT63;
    static const long ID_STATICTEXT69;
    static const long ID_STATICTEXT68;
    static const long ID_STATICTEXT67;
    static const long ID_STATICTEXT66;
    static const long ID_IMAGEBUTTON46;
    static const long ID_IMAGEBUTTON45;
    static const long ID_IMAGEBUTTON44;
    static const long ID_IMAGEBUTTON43;
    static const long ID_IMAGEBUTTON40;
    static const long ID_PANEL7;
    static const long ID_STATICBITMAP4;
    static const long ID_STATICTEXT77;
    static const long ID_STATICTEXT76;
    static const long ID_STATICTEXT75;
    static const long ID_STATICTEXT74;
    static const long ID_STATICTEXT65;
    static const long ID_IMAGEBUTTON54;
    static const long ID_IMAGEBUTTON53;
    static const long ID_IMAGEBUTTON52;
    static const long ID_IMAGEBUTTON51;
    static const long ID_IMAGEBUTTON42;
    static const long ID_STATICBOX9;
    static const long ID_STATICTEXT84;
    static const long ID_STATICTEXT91;
    static const long ID_STATICTEXT90;
    static const long ID_STATICTEXT89;
    static const long ID_STATICTEXT88;
    static const long ID_STATICTEXT86;
    static const long ID_STATICTEXT87;
    static const long ID_STATICTEXT81;
    static const long ID_STATICTEXT85;
    static const long ID_STATICLINE7;
    static const long ID_STATICLINE5;
    static const long ID_STATICTEXT92;
    static const long ID_STATICTEXT93;
    static const long ID_STATICTEXT94;
    static const long ID_STATICTEXT95;
    static const long ID_STATICTEXT96;
    static const long ID_STATICTEXT97;
    static const long ID_STATICTEXT98;
    static const long ID_STATICTEXT99;
    static const long ID_PANEL13;
    static const long ID_STATICBOX7;
    static const long ID_PANEL12;
    static const long ID_PANEL5;
    static const long ID_STATICBITMAP5;
    static const long ID_STATICTEXT73;
    static const long ID_STATICTEXT72;
    static const long ID_STATICTEXT71;
    static const long ID_STATICTEXT70;
    static const long ID_STATICTEXT64;
    static const long ID_IMAGEBUTTON50;
    static const long ID_IMAGEBUTTON49;
    static const long ID_IMAGEBUTTON48;
    static const long ID_IMAGEBUTTON47;
    static const long ID_IMAGEBUTTON41;
    static const long ID_PANEL6;
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
    static const long ID_STATICBOX6;
    static const long ID_STATICTEXT78;
    static const long ID_STATICTEXT79;
    static const long ID_STATICTEXT80;
    static const long ID_STATICTEXT83;
    static const long ID_STATICTEXT82;
    static const long ID_PANEL11;
    static const long ID_STATICBOX5;
    static const long ID_CHECKBOX1;
    static const long ID_PANEL10;
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
    static const long ID_TIMER1;
    //*)

    //(*Declarations(AisdiRelationsFrame)
    wxBitmapButton        *M_ImageButtonInbox;
    wxStaticText* N_StaticTextTitle;
    wxBitmapButton        *I_ImageButtonSave;
    wxStaticText* U_LabelInbox;
    wxMenuItem* MenuItem8;
    wxStaticText* M_LabelGroups;
    wxStaticLine* T_StaticLineImportH;
    wxStaticText* S_LabelUsembers;
    wxBitmapButton        *S_ImageButtonGroups;
    wxBitmapButton        *S_ImageButtonTitle;
    wxTimer Timer1;
    wxBitmapButton        *S_ImageButtonMulTree;
    wxStaticText* S_LabelGroups;
    wxBitmapButton        *T_ImageButtonImport;
    wxFileDialog* FileDialog;
    wxPanel* PanelNotify;
    wxStaticText* I_LabelShowTree;
    wxStaticText* I_LabelDate;
    wxBitmapButton        *U_ImageButtonTitle;
    wxStaticText* S_StaticTextC_Value5;
    wxStaticText* I_LabelMulTree;
    wxStaticText* U_LabelSubject;
    wxPanel* U_PanelStats;
    wxStaticText* T_LabelSettings;
    wxStaticText* U_LabelEmail;
    wxBitmapButton        *U_ImageButtonSwitchContent;
    wxStaticText* S_StaticTextC_Groups;
    wxMenuItem* MenuItem12;
    wxStaticText* G_LabelStats;
    wxStaticText* U_StaticTextName;
    wxListCtrl* U_ListUsembers;
    wxBitmapButton        *T_ImageButtonAdd;
    wxStaticText* U_StaticTextDate;
    wxStaticText* M_LabelStats;
    wxBitmapButton        *T_ImageButtonUsembers;
    wxStaticText* M_LabelUsembers;
    wxStaticText* S_LabelTitle;
    wxBitmapButton        *I_ImageButtonMulTree;
    wxStaticText* N_StaticTextValue2;
    wxBitmapButton        *U_ImageButtonSwitchList;
    wxBitmapButton        *M_ImageButtonGroups;
    wxPanel* PanelSettings;
    wxStaticText* T_LabelBin;
    wxStaticBox* I_InboxBorder;
    wxPanel* PanelMulTree;
    wxBitmapButton        *U_ImageButtonSearch;
    wxPanel* PanelGroups;
    wxStaticText* U_LabelGroup;
    wxBitmapButton        *T_ImageButtonGroups;
    wxStaticBitmap* BitmapBackgroundStatistics;
    wxStaticLine* T_StaticLineAddV;
    wxStaticText* U_LabelDelete;
    wxStaticText* T_LabelTxt;
    wxStaticLine* U_LineContentSeparator;
    wxBitmapButton        *T_ImageButtonMulTree;
    wxStaticText* S_StaticTextC_MaxEmailsInMonth;
    wxPanel* PanelStatistics;
    wxStaticText* I_LabelAdd;
    wxStaticText* T_LabelImport;
    wxStaticText* U_StaticTextGroup;
    wxBitmapButton        *T_ImageButtonLoad;
    wxStaticText* T_StaticTextTitle1;
    wxStaticText* S_StaticTextC_Value3;
    wxDirDialog* DirDialog;
    wxBitmapButton        *I_ImageButtonUsembers;
    wxBitmapButton        *S_ImageButtonInbox;
    wxStaticText* N_StaticTextOption1;
    wxStaticText* S_LabelMulTree;
    wxStaticText* U_LabelSearch;
    wxStaticText* S_StaticTextC_Emails;
    wxBitmapButton        *G_ImageButtonUsembers;
    wxStaticBitmap* BitmapBackgroundGroups;
    wxStaticText* T_StaticTextTitle2;
    wxStaticBox* S_BorderEPM;
    wxStaticText* U_LabelSwitchList;
    wxStaticText* U_LabelSettings;
    wxStaticText* S_StaticTextC_Value6;
    wxBitmapButton        *M_ImageButtonUsembers;
    wxStaticText* U_LabelTitle;
    wxStaticText* U_LabelFromTo;
    wxStaticText* U_LabelShowGroup;
    wxBitmapButton        *S_ImageButtonUsembers;
    wxBitmapButton        *G_ImageButtonTitle;
    wxStaticText* S_StaticTextC_Value7;
    wxStaticBox* S_BorderC;
    wxBitmapButton        *U_ImageButtonInbox;
    wxBitmapButton        *I_ImageButtonStats;
    wxStaticText* G_LabelTitle;
    wxStaticText* U_LabelSave;
    wxBitmapButton        *I_ImageButtonShowTree;
    wxStaticText* T_StaticTextTitle3;
    wxStaticText* I_LabelGroups;
    wxStaticLine* S_LineC_1;
    wxMenuItem* MenuItem3;
    wxStaticText* N_StaticTextValue1;
    wxStaticText* I_LabelSender;
    wxStaticLine* I_LineContentSeparator;
    wxMenuItem* MenuItem6;
    wxBitmapButton        *T_ImageButtonBin;
    wxStaticText* T_LabelInbox;
    wxBitmapButton        *I_ImageButtonSearch;
    wxBitmapButton        *I_ImageButtonGroups;
    wxStaticText* I_StaticTextDate;
    wxBitmapButton        *M_ImageButtonTitle;
    wxStaticBox* Set_BorderSettings;
    wxStaticBitmap* BitmapBackgroundTitle;
    wxStaticText* I_StaticTextSubject;
    wxStaticText* I_LabelTo;
    wxStaticText* T_LabelAdd;
    wxMenuItem* MenuItem10;
    wxStaticText* S_StaticTextC_EmailsPerMonth;
    wxStaticText* N_StaticTextOption2;
    wxStaticText* S_StaticTextC_Value8;
    wxBitmapButton        *T_ImageButtonInbox;
    wxStaticText* I_StaticTextFrom;
    wxStaticBox* N_Border;
    wxPanel* S_PanelEmailPerMonth;
    wxListCtrl* U_ListInbox;
    wxPanel* S_PanelCounters;
    wxMenu* Menu3;
    wxStaticText* I_LabelSettings;
    wxPanel* PanelInbox;
    wxStaticText* I_StaticTextTo;
    wxStaticText* M_LabelTitle;
    wxBitmapButton        *T_ImageButtonStats;
    wxStaticText* I_LabelDelete;
    wxBitmapButton        *M_ImageButtonStats;
    wxBitmapButton        *U_ImageButtonSettings;
    wxStaticText* I_LabelSave;
    wxStaticBitmap* U_BitmapUsember;
    wxBitmapButton        *G_ImageButtonInbox;
    wxHtmlWindow* U_HtmlContent;
    wxStaticBitmap* BitmapBackgroundUsembers;
    wxStaticText* S_StaticTextC_Title;
    wxStaticText* S_StaticTextC_AverageEmailLength;
    wxSearchCtrl* I_SearchCtrl;
    wxBitmapButton        *U_ImageButtonDelete;
    wxBitmapButton        *T_ImageButtonFolder;
    wxHtmlWindow* I_HtmlEmailContent;
    wxBitmapButton        *T_ImageButtonTxt;
    wxStaticBox* I_EmailContentBorder;
    wxPanel* PanelUsembers;
    wxStaticText* U_LabelName;
    wxStaticText* I_LabelFrom;
    wxStaticText* I_LabelReceiver;
    wxStaticLine* T_StaticLineOpenH;
    wxBitmapButton        *U_ImageButtonShowGroup;
    wxStaticLine* T_StaticLineAddH;
    wxStaticText* I_LabelUsembers;
    wxStaticText* T_LabelUsembers;
    wxStaticText* S_LabelInbox;
    wxStaticText* G_LabelInbox;
    wxStaticBox* U_StaticBoxUsembers;
    wxStaticText* I_LabelSubject;
    wxCheckBox* Set_CheckBoxRecursive;
    wxStaticText* G_LabelUsembers;
    wxStaticText* T_LabelFolder;
    wxBitmapButton        *T_ImageButtonFiles;
    wxBitmapButton        *I_ImageButtonDelete;
    wxStaticText* T_LabelMulTree;
    wxMenuItem* MenuItem9;
    wxMenuItem* MenuItem5;
    wxStaticText* S_StaticTextC_Usembers;
    wxStaticText* U_LabelDate;
    wxStaticText* I_LabelTitle;
    wxListCtrl* U_ListOutbox;
    wxBitmapButton        *T_ImageButtonSettings;
    wxStaticText* S_StaticTextC_EmailsPerDay;
    wxStaticText* S_StaticTextC_Value2;
    wxMenuItem* MenuItem7;
    wxBitmapButton        *U_ImageButtonStats;
    wxStaticText* T_LabelStats;
    wxSearchCtrl* U_SearchCtrl;
    wxStaticText* U_StaticTextSubject;
    wxBitmapButton        *I_ImageButtonSender;
    wxStaticText* U_LabelSwitchContent;
    wxBitmapButton        *U_ImageButtonSave;
    wxStaticBitmap* BitmapBackgroundTree;
    wxMenuItem* MenuItem11;
    wxPanel* PanelTitle;
    wxStaticText* U_LabelStats;
    wxStaticText* U_StaticTextEmail;
    wxStaticText* I_LabelStats;
    wxStaticLine* S_LineC_2;
    wxStaticText* T_LabelFiles;
    wxBitmapButton        *I_ImageButtonSettings;
    wxStaticBitmap* I_BitmapBackground;
    wxStaticText* T_LabelGroups;
    wxStaticText* U_LabelAdd;
    wxBitmapButton        *U_ImageButtonMulTree;
    wxStaticText* U_LabelGroups;
    wxListCtrl* I_ListInbox;
    wxStaticText* M_LabelInbox;
    wxMenuItem* MenuItem4;
    wxStaticText* S_StaticTextC_EmailsPerUsember;
    wxBitmapButton        *U_ImageButtonGroups;
    wxBitmapButton        *G_ImageButtonMulTree;
    wxStaticText* S_StaticTextC_Value4;
    wxStaticText* T_LabelLoad;
    wxPanel* U_PanelEmail;
    wxBitmapButton        *I_ImageButtonTitle;
    wxPanel* PanelMain;
    wxStaticText* U_LabelMulTree;
    wxBitmapButton        *I_ImageButtonReceiver;
    wxStaticText* I_LabelSearch;
    wxBitmapButton        *I_ImageButtonAdd;
    wxStaticText* G_LabelMulTree;
    wxStaticText* S_StaticTextC_Value1;
    wxBitmapButton        *G_ImageButtonStats;
    wxStaticBox* U_StaticBoxInfo;
    wxStaticText* U_StaticTextFromTo;
    wxBitmapButton        *U_ImageButtonAdd;
    //*)


    /** Wskaźniki na obiekty paneli, bazy oraz IO */
    PanelTitleMaintance* P_Title;
    PanelGroupsMaintance * P_Groups;
    PanelInboxMaintance * P_Inbox;
    PanelMulTreeMaintance * P_MulTree;
    PanelStatisticsMaintance * P_Stats ;
    PanelUsembersMaintance * P_Usembers ;
    PanelNotifyMaintance * P_Notify ;
    Database * database;
    IOInterface * iointerface;
    Statistics * statistics;
    DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
