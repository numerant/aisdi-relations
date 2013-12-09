/***************************************************************
 * Name:      AisdiRelationsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

/** Pliki klas wdoku (paneli) */
#include "view/PanelTitleMaintance.h"
#include "view/PanelInboxMaintance.h"
#include "view/PanelUsembersMaintance.h"
#include "view/PanelGroupsMaintance.h"
#include "view/PanelStatisticsMaintance.h"
#include "view/PanelMulTreeMaintance.h"

#include "AisdiRelationsMain.h"
#include <wx/msgdlg.h>
#include <wx/stattext.h>

//(*InternalHeaders(AisdiRelationsFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/icon.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(AisdiRelationsFrame)
const long AisdiRelationsFrame::ID_STATICBITMAP2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT9 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT10 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT11 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE6 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP3 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL2 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP4 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP5 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP6 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX1 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE1 = wxNewId();
const long AisdiRelationsFrame::ID_HTMLWINDOW1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT8 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT7 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL2 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL1 = wxNewId();
const long AisdiRelationsFrame::idMenuNew = wxNewId();
const long AisdiRelationsFrame::idMenuOpen = wxNewId();
const long AisdiRelationsFrame::idMenuOpenFolder = wxNewId();
const long AisdiRelationsFrame::idMenuSave = wxNewId();
const long AisdiRelationsFrame::idMenuProperties = wxNewId();
const long AisdiRelationsFrame::idMenuQuit = wxNewId();
const long AisdiRelationsFrame::idMenuImportText = wxNewId();
const long AisdiRelationsFrame::idMenuImportBin = wxNewId();
const long AisdiRelationsFrame::idMenuExportText = wxNewId();
const long AisdiRelationsFrame::idMenuExportBin = wxNewId();
const long AisdiRelationsFrame::idMenuAbout = wxNewId();
const long AisdiRelationsFrame::idMenuHelp = wxNewId();
//*)

BEGIN_EVENT_TABLE(AisdiRelationsFrame,wxFrame)
    //(*EventTable(AisdiRelationsFrame)
    //*)
END_EVENT_TABLE()

AisdiRelationsFrame::AisdiRelationsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(AisdiRelationsFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Analiza Relacji Biznesowych"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(1300,700));
    Move(wxPoint(0,0));
    wxFont thisFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/panda/Pobrane/mail.ico"))));
    	SetIcon(FrameIcon);
    }
    PanelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    PanelMain->SetBackgroundColour(wxColour(0,0,0));
    PanelTitle = new wxPanel(PanelMain, ID_PANEL3, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    PanelTitle->Hide();
    BitmapBackgroundTitle = new wxStaticBitmap(PanelTitle, ID_STATICBITMAP2, wxBitmap(wxImage(_T("/home/panda/aisdi-relations2/bin/resources/background3.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
    T_StaticTextTitle1 = new wxStaticText(PanelTitle, ID_STATICTEXT9, _("Analiza"), wxPoint(400,40), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    T_StaticTextTitle1->SetForegroundColour(wxColour(200,200,200));
    wxFont T_StaticTextTitle1Font(60,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_StaticTextTitle1->SetFont(T_StaticTextTitle1Font);
    T_StaticTextTitle2 = new wxStaticText(PanelTitle, ID_STATICTEXT10, _("Relacji"), wxPoint(500,120), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    T_StaticTextTitle2->SetForegroundColour(wxColour(160,160,160));
    wxFont T_StaticTextTitle2Font(60,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_StaticTextTitle2->SetFont(T_StaticTextTitle2Font);
    T_StaticTextTitle3 = new wxStaticText(PanelTitle, ID_STATICTEXT11, _("Biznesowych"), wxPoint(450,200), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    T_StaticTextTitle3->SetForegroundColour(wxColour(120,120,120));
    wxFont T_StaticTextTitle3Font(60,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_StaticTextTitle3->SetFont(T_StaticTextTitle3Font);
    T_StaticLineAddV = new wxStaticLine(PanelTitle, ID_STATICLINE2, wxPoint(647,450), wxSize(3,150), wxLI_VERTICAL, _T("ID_STATICLINE2"));
    T_StaticLineAddV->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddV->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddH = new wxStaticLine(PanelTitle, ID_STATICLINE3, wxPoint(573,597), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    T_StaticLineAddH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportV = new wxStaticLine(PanelTitle, ID_STATICLINE5, wxPoint(1000,562), wxSize(3,75), wxLI_VERTICAL, _T("ID_STATICLINE5"));
    T_StaticLineImportV->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportV->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportH = new wxStaticLine(PanelTitle, ID_STATICLINE4, wxPoint(851,597), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    T_StaticLineImportH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenV = new wxStaticLine(PanelTitle, ID_STATICLINE7, wxPoint(300,562), wxSize(3,75), wxLI_VERTICAL, _T("ID_STATICLINE7"));
    T_StaticLineOpenV->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenV->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenH = new wxStaticLine(PanelTitle, ID_STATICLINE6, wxPoint(300,597), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE6"));
    T_StaticLineOpenH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    PanelUsembers = new wxPanel(PanelMain, ID_PANEL4, wxPoint(0,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BitmapBackgroundUsembers = new wxStaticBitmap(PanelUsembers, ID_STATICBITMAP3, wxBitmap(wxImage(_T("/home/panda/aisdi-relations2/bin/resources/background3.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
    U_ListUsembers = new wxListCtrl(PanelUsembers, ID_LISTCTRL2, wxPoint(25,120), wxSize(550,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    U_ListUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListUsembers->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListUsembersFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListUsembers->SetFont(U_ListUsembersFont);
    PanelStatistics = new wxPanel(PanelMain, ID_PANEL5, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    PanelStatistics->Hide();
    BitmapBackgroundStatistics = new wxStaticBitmap(PanelStatistics, ID_STATICBITMAP4, wxBitmap(wxImage(_T("/home/panda/aisdi-relations2/bin/resources/background3.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
    PanelGroups = new wxPanel(PanelMain, ID_PANEL6, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    PanelGroups->Hide();
    BitmapBackgroundGroups = new wxStaticBitmap(PanelGroups, ID_STATICBITMAP5, wxBitmap(wxImage(_T("/home/panda/aisdi-relations2/bin/resources/background3.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP5"));
    PanelMulTree = new wxPanel(PanelMain, ID_PANEL7, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    PanelMulTree->Hide();
    BitmapBackgroundTree = new wxStaticBitmap(PanelMulTree, ID_STATICBITMAP6, wxBitmap(wxImage(_T("/home/panda/aisdi-relations2/bin/resources/background3.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
    PanelInbox = new wxPanel(PanelMain, ID_PANEL2, wxPoint(1366,0), wxSize(1366,768), wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    PanelInbox->Hide();
    I_BitmapBackground = new wxStaticBitmap(PanelInbox, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/panda/aisdi-relations/bin/resources/background3.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    I_InboxBorder = new wxStaticBox(PanelInbox, ID_STATICBOX1, _("  Skrzynka Email  "), wxPoint(15,90), wxSize(570,610), 0, _T("ID_STATICBOX1"));
    I_InboxBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_InboxBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont I_InboxBorderFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_InboxBorder->SetFont(I_InboxBorderFont);
    I_ListInbox = new wxListCtrl(PanelInbox, ID_LISTCTRL1, wxPoint(25,120), wxSize(550,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    I_ListInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_ListInbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_ListInboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_ListInbox->SetFont(I_ListInboxFont);
    I_EmailContentBorder = new wxStaticBox(PanelInbox, ID_STATICBOX2, wxEmptyString, wxPoint(650,93), wxSize(600,500), 0, _T("ID_STATICBOX2"));
    I_EmailContentBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_EmailContentBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_LabelFrom = new wxStaticText(PanelInbox, ID_STATICTEXT1, _("Od: "), wxPoint(670,120), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    I_LabelFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelFrom->SetFont(I_LabelFromFont);
    I_LabelTo = new wxStaticText(PanelInbox, ID_STATICTEXT2, _("Do:"), wxPoint(670,145), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    I_LabelTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelTo->SetFont(I_LabelToFont);
    I_LabelSubject = new wxStaticText(PanelInbox, ID_STATICTEXT5, _("Temat:"), wxPoint(670,170), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    I_LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSubject->SetFont(I_LabelSubjectFont);
    I_LineContentSeparator = new wxStaticLine(PanelInbox, ID_STATICLINE1, wxPoint(665,210), wxSize(560,10), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    I_HtmlEmailContent = new wxHtmlWindow(PanelInbox, ID_HTMLWINDOW1, wxPoint(670,230), wxSize(560,350), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW1"));
    I_HtmlEmailContent->SetPage(_("<p align=\"justify\"><font color=\"white\">Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.</font></p>"));
    I_HtmlEmailContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    I_HtmlEmailContent->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_HtmlEmailContentFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_HtmlEmailContent->SetFont(I_HtmlEmailContentFont);
    I_StaticTextSubject = new wxStaticText(PanelInbox, ID_STATICTEXT6, wxEmptyString, wxPoint(735,170), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    I_StaticTextSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont I_StaticTextSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextSubject->SetFont(I_StaticTextSubjectFont);
    I_StaticTextTo = new wxStaticText(PanelInbox, ID_STATICTEXT4, wxEmptyString, wxPoint(710,145), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    I_StaticTextTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextTo->SetFont(I_StaticTextToFont);
    I_StaticTextFrom = new wxStaticText(PanelInbox, ID_STATICTEXT3, wxEmptyString, wxPoint(710,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    I_StaticTextFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextFrom->SetFont(I_StaticTextFromFont);
    I_StaticTextDate = new wxStaticText(PanelInbox, ID_STATICTEXT8, _("25.12.2013"), wxPoint(1150,120), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    I_StaticTextDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextDate->SetFont(I_StaticTextDateFont);
    I_LabelDate = new wxStaticText(PanelInbox, ID_STATICTEXT7, _("Data:"), wxPoint(1100,120), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    I_LabelDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelDate->SetFont(I_LabelDateFont);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu1, idMenuNew, _("New\tCTRL+N"), _("Creates an empty database"), wxITEM_NORMAL);
    Menu1->Append(MenuItem8);
    Menu1->AppendSeparator();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("Open\tCTRL+O"), _("Open file/s"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuOpenFolder, _("Open folder\tCTRL+SHIFT+O"), _("Open all files in a folder"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem5 = new wxMenuItem(Menu1, idMenuSave, _("Save\tCTRL+S"), _("Save your work"), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    Menu1->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu1, idMenuProperties, _("Properties\tCTRL+P"), _("Program settings"), wxITEM_NORMAL);
    Menu1->Append(MenuItem9);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu3, idMenuImportText, _("Import from text"), _("Load a database from a text file"), wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuItem10 = new wxMenuItem(Menu3, idMenuImportBin, _("Import from binary"), _("Load database from a binary file"), wxITEM_NORMAL);
    Menu3->Append(MenuItem10);
    Menu3->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu3, idMenuExportText, _("Export to text"), _("Copy database to a text file"), wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem11 = new wxMenuItem(Menu3, idMenuExportBin, _("Export to bin"), _("Stores databse in a binary file"), wxITEM_NORMAL);
    Menu3->Append(MenuItem11);
    MenuBar1->Append(Menu3, _("&Import/Export"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem12 = new wxMenuItem(Menu2, idMenuHelp, _("Help\tF2"), _("General application manual"), wxITEM_NORMAL);
    Menu2->Append(MenuItem12);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Image1 = new wxImage();
    Image1_BMP = new wxBitmap();
    ImageList1 = new wxImageList(16, 16, 1);
    Center();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnAbout);
    //*)

    ShowTitle();
}

/** PODSTAWOWE FUNKCJE PROGRAMU */

void AisdiRelationsFrame::ShowTitle (void ) {

    // Wyświetlenie tytułu aplikacji na głównym ekranie (w 3 częściach)
    /* wxFont font (60, wxFONTFAMILY_DEFAULT , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu"));
     wxStaticText*  Title1 = new wxStaticText(PanelTitle, 100, _("Analiza"), wxPoint(400,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
     wxStaticText*  Title2 = new wxStaticText(PanelTitle, 101, _("Relacji"), wxPoint(500,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
     wxStaticText*  Title3 = new wxStaticText(PanelTitle, 102, _("Biznesowych"), wxPoint(450,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
     Title1->SetFont(font);
     Title2->SetFont(font);
     Title3->SetFont(font);
     Title1->SetForegroundColour(wxColor(200,200,200));
     Title2->SetForegroundColour(wxColor(160,160,160));
     Title3->SetForegroundColour(wxColor(120,120,120));*/

    //Testowe wyświetlanie pól listy (inbox)
      wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Data:") );
        col0.SetWidth(80);
        I_ListInbox->InsertColumn(0, col0);
      wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Tytuł:") );
        col1.SetWidth(210);
        I_ListInbox->InsertColumn(1, col1);
    wxListItem col2;
        col2.SetId(2);
        col2.SetText( _("Od:") );
        col2.SetWidth(130);
        I_ListInbox->InsertColumn(2, col2);
        wxListItem col3;
        col3.SetId(3);
        col3.SetText( _("Do:") );
        col3.SetWidth(130);
        I_ListInbox->InsertColumn(3, col3);
         wxListItem item;
            item.SetId(10);
            item.SetText( _("25.12.2013") );
        I_ListInbox->InsertItem( item );
        I_ListInbox->SetItem(0,1, wxT("RE: Bowling meeting on Sunday"));
        I_ListInbox->SetItem(0,2, wxT("billee@ms.com"));
        I_ListInbox->SetItem(0,3, wxT("stevee@apple.com"));

        I_StaticTextFrom->SetLabel(_("billee@ms.com"));
        I_StaticTextTo->SetLabel(_("stevee@apple.com"));
        I_StaticTextSubject->SetLabel(_("RE: Bowling meeting on Sunday"));
        I_StaticTextDate->SetLabel(_("25.12.2013"));

        //Testowa zabawa Panelami
        P_Title->ShowPanel(this);
}

AisdiRelationsFrame::~AisdiRelationsFrame()
{
    //(*Destroy(AisdiRelationsFrame)
    //*)

    //delete (Title1);
}

void AisdiRelationsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/** Informacje o autorach i wersji aplikacji */
void AisdiRelationsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = _("Autorzy:\n  Maciej Gańko\n  Krzysztof Lisocki\n  Patryk Łucka\n  Jakub Maleszewski\n  Paweł Kaczyński\n  Maciej Safarzyński\n  Michał Żołyniak\n\n");
    msg += _("---------------------------------------------------\nVersion:  0.1");
    wxMessageBox(msg, _("About"));
}

/*void AisdiRelationsFrame::OnButton1Click1(wxCommandEvent& event)
{
    Grid1->AutoSizeRows();
    Grid1->AutoSizeColumns();
    wxGrid* Grid2 = new wxGrid(PanelInbox, 100, wxPoint(100,55), wxSize(500,400), 0, _T("ID_GRID1"));
    Grid2->CreateGrid(2,3);
    Grid2->Show(true);
}*/

/*void AisdiRelationsFrame::OnButton1Click(wxCommandEvent& event)
{
    if (Image1->LoadFile(_("resources/emailButton.png"), wxBITMAP_TYPE_PNG, -1))
        wxMessageBox(_("Udalo sie"));
    wxBitmap newB (_("resources/background.jpg"));
    BackgroundImage->SetBitmap(newB);
    BackgroundImage->Refresh();
}*/
