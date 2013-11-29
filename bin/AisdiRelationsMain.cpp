/***************************************************************
 * Name:      AisdiRelationsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

#include "AisdiRelationsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(AisdiRelationsFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
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
const long AisdiRelationsFrame::ID_STATICTEXT1 = wxNewId();
const long AisdiRelationsFrame::ID_BUTTON1 = wxNewId();
const long AisdiRelationsFrame::ID_SEARCHCTRL1 = wxNewId();
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

    Create(parent, id, _("Analiza Relacji Biznesowych"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("id"));
    SetClientSize(wxSize(1300,700));
    Move(wxPoint(0,0));
    wxFont thisFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/panda/Pobrane/mail.png"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(440,232), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(0,0,0));
    MainTitle = new wxStaticText(Panel1, ID_STATICTEXT1, _("Analiza Relacji Biznesowych"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    MainTitle->SetForegroundColour(wxColour(224,224,224));
    wxFont MainTitleFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    MainTitle->SetFont(MainTitleFont);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Buton"), wxPoint(24,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    SearchCtrl1 = new wxSearchCtrl(Panel1, ID_SEARCHCTRL1, wxEmptyString, wxPoint(24,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
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
    Center();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnAbout);
    //*)
}

AisdiRelationsFrame::~AisdiRelationsFrame()
{
    //(*Destroy(AisdiRelationsFrame)
    //*)
}

void AisdiRelationsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void AisdiRelationsFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxString msg = _("Autorzy:\n  Maciej Gańko\n  Krzysztof Lisocki\n  Patryk Łucka\n  Jakub Maleszewski\n  Paweł Kaczyński\n  Maciej Safarzyński\n  Michał Żołyniak\n\n");
    msg += _("---------------------------------------------------\nVersion:  0.1");
    wxMessageBox(msg, _("About"));
}
