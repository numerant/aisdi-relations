/***************************************************************
 * Name:      AisdiRelationsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

#include "AisdiRelationsMain.h"
#include "view/TitleScreen.h"
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
const long AisdiRelationsFrame::ID_STATICBITMAP1 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE1 = wxNewId();
const long AisdiRelationsFrame::ID_HTMLWINDOW1 = wxNewId();
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
    InboxPanel = new wxPanel(this, ID_PANEL1, wxPoint(440,232), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    InboxPanel->SetBackgroundColour(wxColour(0,0,0));
    BackgroundImage = new wxStaticBitmap(InboxPanel, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/panda/aisdi-relations/bin/resources/background3.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(-5,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    Inbox = new wxListCtrl(InboxPanel, ID_LISTCTRL1, wxPoint(35,120), wxSize(550,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Inbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Inbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont InboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Inbox->SetFont(InboxFont);
    StaticTextTo = new wxStaticText(InboxPanel, ID_STATICTEXT4, wxEmptyString, wxPoint(680,145), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticTextTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont StaticTextToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticTextTo->SetFont(StaticTextToFont);
    StaticTextFrom = new wxStaticText(InboxPanel, ID_STATICTEXT3, wxEmptyString, wxPoint(680,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticTextFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont StaticTextFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticTextFrom->SetFont(StaticTextFromFont);
    LabelFrom = new wxStaticText(InboxPanel, ID_STATICTEXT1, _("Od: "), wxPoint(640,120), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    LabelFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont LabelFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    LabelFrom->SetFont(LabelFromFont);
    LabelTo = new wxStaticText(InboxPanel, ID_STATICTEXT2, _("Do:"), wxPoint(640,145), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    LabelTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont LabelToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    LabelTo->SetFont(LabelToFont);
    InboxBorder = new wxStaticBox(InboxPanel, ID_STATICBOX1, _("  Skrzynka Email  "), wxPoint(25,90), wxSize(570,610), 0, _T("ID_STATICBOX1"));
    InboxBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    InboxBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont InboxBorderFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    InboxBorder->SetFont(InboxBorderFont);
    LabelSubject = new wxStaticText(InboxPanel, ID_STATICTEXT5, _("Temat:"), wxPoint(640,170), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont LabelSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    LabelSubject->SetFont(LabelSubjectFont);
    StaticTextSubject = new wxStaticText(InboxPanel, ID_STATICTEXT6, wxEmptyString, wxPoint(705,170), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticTextSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticTextSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticTextSubject->SetFont(StaticTextSubjectFont);
    StaticTextContent = new wxStaticText(InboxPanel, ID_STATICTEXT7, _("ssss"), wxPoint(645,220), wxSize(560,370), wxST_NO_AUTORESIZE|wxALIGN_LEFT|wxTAB_TRAVERSAL|wxVSCROLL, _T("ID_STATICTEXT7"));
    StaticTextContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxFont StaticTextContentFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticTextContent->SetFont(StaticTextContentFont);
    EmailContentBorder = new wxStaticBox(InboxPanel, ID_STATICBOX2, wxEmptyString, wxPoint(620,93), wxSize(600,500), 0, _T("ID_STATICBOX2"));
    EmailContentBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    EmailContentBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    LineContentSeparator = new wxStaticLine(InboxPanel, ID_STATICLINE1, wxPoint(640,200), wxSize(560,10), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Text = new wxHtmlWindow(InboxPanel, ID_HTMLWINDOW1, wxPoint(640,225), wxSize(560,350), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW1"));
    Text->SetPage(_("<p align=\"justify\"><font color=\"white\">Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.</font></p>"));
    Text->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Text->SetBackgroundColour(wxColour(20,20,20));
    wxFont TextFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Text->SetFont(TextFont);
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
     wxFont font (60, wxFONTFAMILY_DEFAULT , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu"));
     wxStaticText*  Title1 = new wxStaticText(InboxPanel, 100, _("Analiza"), wxPoint(400,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
     wxStaticText*  Title2 = new wxStaticText(InboxPanel, 101, _("Relacji"), wxPoint(500,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
     wxStaticText*  Title3 = new wxStaticText(InboxPanel, 102, _("Biznesowych"), wxPoint(450,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
     Title1->SetFont(font);
     Title2->SetFont(font);
     Title3->SetFont(font);
     Title1->SetForegroundColour(wxColor(200,200,200));
     Title2->SetForegroundColour(wxColor(160,160,160));
     Title3->SetForegroundColour(wxColor(120,120,120));
     Title3->Hide();
     Title2->Hide();
     Title1->Hide();

    //Testowe wyświetlanie pól listy (inbox)
      wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Data:") );
        col0.SetWidth(80);
        Inbox->InsertColumn(0, col0);
      wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Tytuł:") );
        col1.SetWidth(210);
        Inbox->InsertColumn(1, col1);
    wxListItem col2;
        col2.SetId(2);
        col2.SetText( _("Od:") );
        col2.SetWidth(130);
        Inbox->InsertColumn(2, col2);
        wxListItem col3;
        col3.SetId(3);
        col3.SetText( _("Do:") );
        col3.SetWidth(130);
        Inbox->InsertColumn(3, col3);
         wxListItem item;
            item.SetId(10);
            item.SetText( _("25.12.2013") );
        Inbox->InsertItem( item );
        Inbox->SetItem(0,1, wxT("RE: Bowling meeting on Sunday"));
        Inbox->SetItem(0,2, wxT("billee@ms.com"));
        Inbox->SetItem(0,3, wxT("stevee@apple.com"));

        StaticTextFrom->SetLabel(_("billee@ms.com"));
        StaticTextTo->SetLabel(_("stevee@apple.com"));
        StaticTextSubject->SetLabel(_("RE: Bowling meeting on Sunday"));
        //StaticTextContent->SetLabel(_("Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit."));
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
    wxGrid* Grid2 = new wxGrid(InboxPanel, 100, wxPoint(100,55), wxSize(500,400), 0, _T("ID_GRID1"));
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
