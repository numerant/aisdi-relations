/***************************************************************
 * Name:      AisdiRelationsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

/** Klasy projektu */
/*#include "../src/Date.h"
#include "../src/Email.h"
#include "../src/Usember.h"*/



/** Pliki klas widoku (paneli) */
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
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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
const long AisdiRelationsFrame::ID_IMAGEBUTTON37 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON36 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON35 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON34 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON33 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON32 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON18 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON17 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON16 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON15 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON14 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON13 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON12 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT60 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT59 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT58 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT57 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT56 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT30 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT31 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT29 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT28 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT27 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT26 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT25 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT24 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT54 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT55 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT53 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT52 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT51 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT50 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT49 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT48 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT47 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT46 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT45 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT62 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT44 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP7 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL2 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL4 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT17 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT16 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT15 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT13 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT14 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT12 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL9 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT19 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT23 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT22 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT21 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT20 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT18 = wxNewId();
const long AisdiRelationsFrame::ID_HTMLWINDOW2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE8 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL8 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON10 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON11 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON9 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON8 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON7 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON6 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON5 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON4 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON31 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON3 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON2 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON1 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON39 = wxNewId();
const long AisdiRelationsFrame::ID_SEARCHCTRL2 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP4 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP5 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP6 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT61 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT35 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT34 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT33 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT32 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT39 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT38 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT37 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT36 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT43 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT42 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT41 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT40 = wxNewId();
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
const long AisdiRelationsFrame::ID_IMAGEBUTTON29 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON28 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON27 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON26 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON25 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON24 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON23 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON22 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON30 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON21 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON20 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON38 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON19 = wxNewId();
const long AisdiRelationsFrame::ID_SEARCHCTRL1 = wxNewId();
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
    SetClientSize(wxSize(1366,768));
    Move(wxPoint(0,0));
    wxFont thisFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("resources/iconProgram.png"))));
    	SetIcon(FrameIcon);
    }
    PanelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    PanelMain->SetBackgroundColour(wxColour(0,0,0));
    PanelTitle = new wxPanel(PanelMain, ID_PANEL3, wxPoint(0,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BitmapBackgroundTitle = new wxStaticBitmap(PanelTitle, ID_STATICBITMAP2, wxBitmap(wxImage(_T("resources/background.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
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
    T_ImageButtonMulTree = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON37, wxNullBitmap, wxPoint(700,450), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON37"));
    T_ImageButtonStats = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON36, wxNullBitmap, wxPoint(500,450), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON36"));
    T_ImageButtonGroups = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON35, wxNullBitmap, wxPoint(800,300), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON35"));
    T_ImageButtonUsembers = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON34, wxNullBitmap, wxPoint(600,300), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON34"));
    T_ImageButtonInbox = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON33, wxNullBitmap, wxPoint(400,300), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON33"));
    T_ImageButtonSettings = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON32, wxNullBitmap, wxPoint(1200,15), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON32"));
    T_ImageButtonTxt = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON18, wxNullBitmap, wxPoint(990,424), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON18"));
    T_ImageButtonBin = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON17, wxNullBitmap, wxPoint(990,564), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON17"));
    T_ImageButtonFolder = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON16, wxNullBitmap, wxPoint(200,564), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON16"));
    T_ImageButtonFiles = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON15, wxNullBitmap, wxPoint(200,424), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON15"));
    T_ImageButtonLoad = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON14, wxNullBitmap, wxPoint(445,494), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON14"));
    T_ImageButtonImport = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON13, wxNullBitmap, wxPoint(740,494), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON13"));
    T_ImageButtonAdd = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON12, wxNullBitmap, wxPoint(592,315), wxSize(112,112), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON12"));
    T_StaticLineAddV = new wxStaticLine(PanelTitle, ID_STATICLINE2, wxPoint(647,460), wxSize(3,90), wxLI_VERTICAL, _T("ID_STATICLINE2"));
    T_StaticLineAddV->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddV->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddH = new wxStaticLine(PanelTitle, ID_STATICLINE3, wxPoint(573,547), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    T_StaticLineAddH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineAddH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportH = new wxStaticLine(PanelTitle, ID_STATICLINE4, wxPoint(871,547), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    T_StaticLineImportH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineImportH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenH = new wxStaticLine(PanelTitle, ID_STATICLINE6, wxPoint(280,547), wxSize(150,5), wxLI_HORIZONTAL, _T("ID_STATICLINE6"));
    T_StaticLineOpenH->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_StaticLineOpenH->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    T_LabelMulTree = new wxStaticText(PanelTitle, ID_STATICTEXT60, _("Drzewo\nMulticastowe"), wxPoint(700,565), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT60"));
    T_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelMulTreeFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelMulTree->SetFont(T_LabelMulTreeFont);
    T_LabelStats = new wxStaticText(PanelTitle, ID_STATICTEXT59, _("Statystyki"), wxPoint(515,565), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT59"));
    T_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelStatsFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelStats->SetFont(T_LabelStatsFont);
    T_LabelGroups = new wxStaticText(PanelTitle, ID_STATICTEXT58, _("Grupy"), wxPoint(830,415), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT58"));
    T_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelGroupsFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelGroups->SetFont(T_LabelGroupsFont);
    T_LabelUsembers = new wxStaticText(PanelTitle, ID_STATICTEXT57, _("Usembers"), wxPoint(615,415), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT57"));
    T_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelUsembersFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelUsembers->SetFont(T_LabelUsembersFont);
    T_LabelInbox = new wxStaticText(PanelTitle, ID_STATICTEXT56, _("Skrzynka\nEmaili"), wxPoint(420,415), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT56"));
    T_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelInboxFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelInbox->SetFont(T_LabelInboxFont);
    T_LabelBin = new wxStaticText(PanelTitle, ID_STATICTEXT30, _("Importuj plik BIN"), wxPoint(1115,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT30"));
    T_LabelBin->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelBinFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelBin->SetFont(T_LabelBinFont);
    T_LabelSettings = new wxStaticText(PanelTitle, ID_STATICTEXT31, _("Ustawienia"), wxPoint(1195,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT31"));
    T_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelSettings->SetFont(T_LabelSettingsFont);
    T_LabelTxt = new wxStaticText(PanelTitle, ID_STATICTEXT29, _("Importuj plik TXT"), wxPoint(1115,470), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT29"));
    T_LabelTxt->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelTxtFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelTxt->SetFont(T_LabelTxtFont);
    T_LabelFolder = new wxStaticText(PanelTitle, ID_STATICTEXT28, _("Dodaj folder"), wxPoint(85,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT28"));
    T_LabelFolder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelFolderFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelFolder->SetFont(T_LabelFolderFont);
    T_LabelFiles = new wxStaticText(PanelTitle, ID_STATICTEXT27, _("Dodaj pliki"), wxPoint(95,470), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT27"));
    T_LabelFiles->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelFilesFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelFiles->SetFont(T_LabelFilesFont);
    T_LabelLoad = new wxStaticText(PanelTitle, ID_STATICTEXT26, _("Wczytaj z dysku"), wxPoint(435,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT26"));
    T_LabelLoad->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelLoadFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelLoad->SetFont(T_LabelLoadFont);
    T_LabelImport = new wxStaticText(PanelTitle, ID_STATICTEXT25, _("Importuj dane"), wxPoint(735,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT25"));
    T_LabelImport->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelImportFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelImport->SetFont(T_LabelImportFont);
    T_LabelAdd = new wxStaticText(PanelTitle, ID_STATICTEXT24, _("Dodaj Emaile"), wxPoint(595,430), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    T_LabelAdd->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelAddFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelAdd->SetFont(T_LabelAddFont);
    PanelUsembers = new wxPanel(PanelMain, ID_PANEL4, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BitmapBackgroundUsembers = new wxStaticBitmap(PanelUsembers, ID_STATICBITMAP3, wxBitmap(wxImage(_T("resources/background.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
    U_LabelSwitchContent = new wxStaticText(PanelUsembers, ID_STATICTEXT54, _("Przełącz\nzawartość"), wxPoint(1188,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT54"));
    U_LabelSwitchContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSwitchContentFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSwitchContent->SetFont(U_LabelSwitchContentFont);
    U_LabelSwitchList = new wxStaticText(PanelUsembers, ID_STATICTEXT55, _("Przełącz\nlistę"), wxPoint(523,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT55"));
    U_LabelSwitchList->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSwitchListFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSwitchList->SetFont(U_LabelSwitchListFont);
    U_LabelShowGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT53, _("Pokaż\ngrupę"), wxPoint(750,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT53"));
    U_LabelShowGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelShowGroupFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelShowGroup->SetFont(U_LabelShowGroupFont);
    U_LabelDelete = new wxStaticText(PanelUsembers, ID_STATICTEXT52, _("Usuń"), wxPoint(663,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT52"));
    U_LabelDelete->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelDeleteFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelDelete->SetFont(U_LabelDeleteFont);
    U_LabelInbox = new wxStaticText(PanelUsembers, ID_STATICTEXT51, _("Skrzynka\nemaili"), wxPoint(1180,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT51"));
    U_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelInboxFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelInbox->SetFont(U_LabelInboxFont);
    U_LabelGroups = new wxStaticText(PanelUsembers, ID_STATICTEXT50, _("Grupy"), wxPoint(1100,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT50"));
    U_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelGroups->SetFont(U_LabelGroupsFont);
    U_LabelStats = new wxStaticText(PanelUsembers, ID_STATICTEXT49, _("Statystyki"), wxPoint(998,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT49"));
    U_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelStats->SetFont(U_LabelStatsFont);
    U_LabelMulTree = new wxStaticText(PanelUsembers, ID_STATICTEXT48, _("Drzewo\nMulticastowe"), wxPoint(895,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT48"));
    U_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelMulTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelMulTree->SetFont(U_LabelMulTreeFont);
    U_LabelSettings = new wxStaticText(PanelUsembers, ID_STATICTEXT47, _("Ustawienia"), wxPoint(365,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT47"));
    U_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSettings->SetFont(U_LabelSettingsFont);
    U_LabelSearch = new wxStaticText(PanelUsembers, ID_STATICTEXT46, _("Wyszukaj"), wxPoint(280,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT46"));
    U_LabelSearch->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSearchFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSearch->SetFont(U_LabelSearchFont);
    U_LabelSave = new wxStaticText(PanelUsembers, ID_STATICTEXT45, _("Zapisz"), wxPoint(198,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT45"));
    U_LabelSave->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSaveFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSave->SetFont(U_LabelSaveFont);
    U_LabelTitle = new wxStaticText(PanelUsembers, ID_STATICTEXT62, _("Menu"), wxPoint(22,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT62"));
    U_LabelTitle->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelTitleFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelTitle->SetFont(U_LabelTitleFont);
    U_LabelAdd = new wxStaticText(PanelUsembers, ID_STATICTEXT44, _("Dodaj"), wxPoint(110,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT44"));
    U_LabelAdd->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelAddFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelAdd->SetFont(U_LabelAddFont);
    U_StaticBoxUsembers = new wxStaticBox(PanelUsembers, ID_STATICBOX3, _("  Usembers  "), wxPoint(15,100), wxSize(570,610), 0, _T("ID_STATICBOX3"));
    U_StaticBoxUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_StaticBoxUsembers->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont U_StaticBoxUsembersFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticBoxUsembers->SetFont(U_StaticBoxUsembersFont);
    U_StaticBoxInfo = new wxStaticBox(PanelUsembers, ID_STATICBOX4, wxEmptyString, wxPoint(650,103), wxSize(600,500), 0, _T("ID_STATICBOX4"));
    U_StaticBoxInfo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_StaticBoxInfo->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_BitmapUsember = new wxStaticBitmap(PanelUsembers, ID_STATICBITMAP7, wxBitmap(wxImage(_T("resources/iconsBig/iconUsember.png")).Rescale(wxSize(100,100).GetWidth(),wxSize(100,100).GetHeight())), wxPoint(670,135), wxSize(100,100), wxSIMPLE_BORDER, _T("ID_STATICBITMAP7"));
    U_ListUsembers = new wxListCtrl(PanelUsembers, ID_LISTCTRL2, wxPoint(25,130), wxSize(550,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    U_ListUsembers->Hide();
    U_ListUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListUsembers->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListUsembersFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListUsembers->SetFont(U_ListUsembersFont);
    U_ListOutbox = new wxListCtrl(PanelUsembers, ID_LISTCTRL4, wxPoint(25,425), wxSize(550,275), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL4"));
    U_ListOutbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListOutbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListOutboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListOutbox->SetFont(U_ListOutboxFont);
    U_ListInbox = new wxListCtrl(PanelUsembers, ID_LISTCTRL3, wxPoint(25,130), wxSize(550,275), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL3"));
    U_ListInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListInbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListInboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListInbox->SetFont(U_ListInboxFont);
    U_StaticTextGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT17, wxEmptyString, wxPoint(845,185), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    U_StaticTextGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextGroupFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextGroup->SetFont(U_StaticTextGroupFont);
    U_StaticTextEmail = new wxStaticText(PanelUsembers, ID_STATICTEXT16, wxEmptyString, wxPoint(845,160), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    U_StaticTextEmail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextEmailFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextEmail->SetFont(U_StaticTextEmailFont);
    U_StaticTextName = new wxStaticText(PanelUsembers, ID_STATICTEXT15, wxEmptyString, wxPoint(845,135), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    U_StaticTextName->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextNameFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextName->SetFont(U_StaticTextNameFont);
    U_LabelEmail = new wxStaticText(PanelUsembers, ID_STATICTEXT13, _("Email:"), wxPoint(780,160), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    U_LabelEmail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelEmailFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelEmail->SetFont(U_LabelEmailFont);
    U_LabelGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT14, _("Grupa:"), wxPoint(780,185), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    U_LabelGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelGroupFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelGroup->SetFont(U_LabelGroupFont);
    U_LabelName = new wxStaticText(PanelUsembers, ID_STATICTEXT12, _("Nazwa:"), wxPoint(780,135), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    U_LabelName->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelNameFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelName->SetFont(U_LabelNameFont);
    U_PanelStats = new wxPanel(PanelUsembers, ID_PANEL9, wxPoint(670,245), wxSize(560,345), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    U_PanelStats->SetBackgroundColour(wxColour(32,32,32));
    U_PanelEmail = new wxPanel(PanelUsembers, ID_PANEL8, wxPoint(670,245), wxSize(560,345), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    U_PanelEmail->SetBackgroundColour(wxColour(32,32,32));
    U_LabelSubject = new wxStaticText(U_PanelEmail, ID_STATICTEXT19, _("Temat:"), wxPoint(15,35), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    U_LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSubject->SetFont(U_LabelSubjectFont);
    U_StaticTextSubject = new wxStaticText(U_PanelEmail, ID_STATICTEXT23, wxEmptyString, wxPoint(75,35), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    U_StaticTextSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextSubject->SetFont(U_StaticTextSubjectFont);
    U_StaticTextFromTo = new wxStaticText(U_PanelEmail, ID_STATICTEXT22, wxEmptyString, wxPoint(55,15), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    U_StaticTextFromTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextFromToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextFromTo->SetFont(U_StaticTextFromToFont);
    U_StaticTextDate = new wxStaticText(U_PanelEmail, ID_STATICTEXT21, wxEmptyString, wxPoint(460,20), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    U_StaticTextDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextDate->SetFont(U_StaticTextDateFont);
    U_LabelDate = new wxStaticText(U_PanelEmail, ID_STATICTEXT20, _("Data:"), wxPoint(410,20), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    U_LabelDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelDate->SetFont(U_LabelDateFont);
    U_LabelFromTo = new wxStaticText(U_PanelEmail, ID_STATICTEXT18, _("Od:"), wxPoint(15,15), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    U_LabelFromTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelFromToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelFromTo->SetFont(U_LabelFromToFont);
    U_HtmlContent = new wxHtmlWindow(U_PanelEmail, ID_HTMLWINDOW2, wxPoint(15,80), wxSize(530,255), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW2"));
    U_HtmlContent->SetPage(_("<p align=\"justify\"><font color=\"lightgray\">Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.</font></p>"));
    U_HtmlContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    U_HtmlContent->SetBackgroundColour(wxColour(32,32,32));
    wxFont U_HtmlContentFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_HtmlContent->SetFont(U_HtmlContentFont);
    U_LineContentSeparator = new wxStaticLine(U_PanelEmail, ID_STATICLINE8, wxPoint(20,60), wxSize(520,15), wxLI_HORIZONTAL, _T("ID_STATICLINE8"));
    U_LineContentSeparator->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ImageButtonSwitchList = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON10, wxNullBitmap, wxPoint(520,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON10"));
    U_ImageButtonSwitchContent = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON11, wxNullBitmap, wxPoint(1190,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON11"));
    U_ImageButtonShowGroup = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON9, wxNullBitmap, wxPoint(740,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON9"));
    U_ImageButtonDelete = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON8, wxNullBitmap, wxPoint(650,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON8"));
    U_ImageButtonMulTree = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON7, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON7"));
    U_ImageButtonStats = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON6, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON6"));
    U_ImageButtonGroups = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON5, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON5"));
    U_ImageButtonInbox = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON4, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON4"));
    U_ImageButtonSettings = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON31, wxNullBitmap, wxPoint(370,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON31"));
    U_ImageButtonSearch = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON3, wxNullBitmap, wxPoint(280,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON3"));
    U_ImageButtonSave = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON2, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON2"));
    U_ImageButtonAdd = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON1, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON1"));
    U_ImageButtonTitle = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON39, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON39"));
    U_SearchCtrl = new wxSearchCtrl(PanelUsembers, ID_SEARCHCTRL2, wxEmptyString, wxPoint(25,130), wxSize(550,25), 0, wxDefaultValidator, _T("ID_SEARCHCTRL2"));
    U_SearchCtrl->Hide();
    U_SearchCtrl->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    PanelStatistics = new wxPanel(PanelMain, ID_PANEL5, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    PanelStatistics->Hide();
    BitmapBackgroundStatistics = new wxStaticBitmap(PanelStatistics, ID_STATICBITMAP4, wxBitmap(wxImage(_T("resources/background.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
    PanelGroups = new wxPanel(PanelMain, ID_PANEL6, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    PanelGroups->Hide();
    BitmapBackgroundGroups = new wxStaticBitmap(PanelGroups, ID_STATICBITMAP5, wxBitmap(wxImage(_T("resources/background.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP5"));
    PanelMulTree = new wxPanel(PanelMain, ID_PANEL7, wxPoint(1366,0), wxSize(1366,768), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    PanelMulTree->Hide();
    BitmapBackgroundTree = new wxStaticBitmap(PanelMulTree, ID_STATICBITMAP6, wxBitmap(wxImage(_T("resources/background.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
    PanelInbox = new wxPanel(PanelMain, ID_PANEL2, wxPoint(1366,0), wxSize(1366,768), wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    I_BitmapBackground = new wxStaticBitmap(PanelInbox, ID_STATICBITMAP1, wxBitmap(wxImage(_T("resources/background.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    I_LabelTitle = new wxStaticText(PanelInbox, ID_STATICTEXT61, _("Menu"), wxPoint(22,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT61"));
    I_LabelTitle->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelTitleFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelTitle->SetFont(I_LabelTitleFont);
    I_LabelAdd = new wxStaticText(PanelInbox, ID_STATICTEXT35, _("Dodaj"), wxPoint(110,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT35"));
    I_LabelAdd->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelAddFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelAdd->SetFont(I_LabelAddFont);
    I_LabelSave = new wxStaticText(PanelInbox, ID_STATICTEXT34, _("Zapisz"), wxPoint(198,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT34"));
    I_LabelSave->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelSaveFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSave->SetFont(I_LabelSaveFont);
    I_LabelSearch = new wxStaticText(PanelInbox, ID_STATICTEXT33, _("Wyszukaj"), wxPoint(280,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT33"));
    I_LabelSearch->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelSearchFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSearch->SetFont(I_LabelSearchFont);
    I_LabelSettings = new wxStaticText(PanelInbox, ID_STATICTEXT32, _("Ustawienia"), wxPoint(365,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT32"));
    I_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSettings->SetFont(I_LabelSettingsFont);
    I_LabelMulTree = new wxStaticText(PanelInbox, ID_STATICTEXT39, _("Drzewo\nMulticastowe"), wxPoint(895,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT39"));
    I_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelMulTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelMulTree->SetFont(I_LabelMulTreeFont);
    I_LabelStats = new wxStaticText(PanelInbox, ID_STATICTEXT38, _("Statystyki"), wxPoint(998,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT38"));
    I_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelStats->SetFont(I_LabelStatsFont);
    I_LabelGroups = new wxStaticText(PanelInbox, ID_STATICTEXT37, _("Grupy"), wxPoint(1100,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT37"));
    I_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelGroups->SetFont(I_LabelGroupsFont);
    I_LabelUsembers = new wxStaticText(PanelInbox, ID_STATICTEXT36, _("Usembers"), wxPoint(1177,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT36"));
    I_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelUsembersFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelUsembers->SetFont(I_LabelUsembersFont);
    I_LabelShowTree = new wxStaticText(PanelInbox, ID_STATICTEXT43, _("Utwórz\ndrzewo"), wxPoint(925,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT43"));
    I_LabelShowTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelShowTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelShowTree->SetFont(I_LabelShowTreeFont);
    I_LabelReceiver = new wxStaticText(PanelInbox, ID_STATICTEXT42, _("Pokaż\nodbiorcę"), wxPoint(830,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT42"));
    I_LabelReceiver->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelReceiverFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelReceiver->SetFont(I_LabelReceiverFont);
    I_LabelSender = new wxStaticText(PanelInbox, ID_STATICTEXT41, _("Pokaż\nnadawcę"), wxPoint(740,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT41"));
    I_LabelSender->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelSenderFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSender->SetFont(I_LabelSenderFont);
    I_LabelDelete = new wxStaticText(PanelInbox, ID_STATICTEXT40, _("Usuń"), wxPoint(663,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT40"));
    I_LabelDelete->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelDeleteFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelDelete->SetFont(I_LabelDeleteFont);
    I_InboxBorder = new wxStaticBox(PanelInbox, ID_STATICBOX1, _("  Skrzynka Email  "), wxPoint(15,100), wxSize(570,610), 0, _T("ID_STATICBOX1"));
    I_InboxBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_InboxBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont I_InboxBorderFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_InboxBorder->SetFont(I_InboxBorderFont);
    I_ListInbox = new wxListCtrl(PanelInbox, ID_LISTCTRL1, wxPoint(25,130), wxSize(550,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    I_ListInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_ListInbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_ListInboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_ListInbox->SetFont(I_ListInboxFont);
    I_EmailContentBorder = new wxStaticBox(PanelInbox, ID_STATICBOX2, wxEmptyString, wxPoint(650,103), wxSize(600,500), 0, _T("ID_STATICBOX2"));
    I_EmailContentBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_EmailContentBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_LabelFrom = new wxStaticText(PanelInbox, ID_STATICTEXT1, _("Od: "), wxPoint(670,130), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    I_LabelFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelFrom->SetFont(I_LabelFromFont);
    I_LabelTo = new wxStaticText(PanelInbox, ID_STATICTEXT2, _("Do:"), wxPoint(670,155), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    I_LabelTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelTo->SetFont(I_LabelToFont);
    I_LabelSubject = new wxStaticText(PanelInbox, ID_STATICTEXT5, _("Temat:"), wxPoint(670,180), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    I_LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSubject->SetFont(I_LabelSubjectFont);
    I_LineContentSeparator = new wxStaticLine(PanelInbox, ID_STATICLINE1, wxPoint(665,220), wxSize(560,10), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    I_HtmlEmailContent = new wxHtmlWindow(PanelInbox, ID_HTMLWINDOW1, wxPoint(670,240), wxSize(560,350), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW1"));
    I_HtmlEmailContent->SetPage(_("<p align=\"justify\"><font color=\"lightgray\">Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.Donec pretium velit nisi, id euismod libero mattis sit amet. Quisque eu volutpat lectus. Nam lacus urna, tincidunt vitae convallis ut, commodo eget augue. Phasellus ornare lacus sapien, sit amet hendrerit neque scelerisque a. Praesent dapibus massa magna, vitae rhoncus turpis malesuada et. Nulla vel suscipit nunc. Integer metus turpis, consectetur non lacinia et, molestie sit amet velit.</font></p>"));
    I_HtmlEmailContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    I_HtmlEmailContent->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_HtmlEmailContentFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_HtmlEmailContent->SetFont(I_HtmlEmailContentFont);
    I_StaticTextSubject = new wxStaticText(PanelInbox, ID_STATICTEXT6, wxEmptyString, wxPoint(735,180), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    I_StaticTextSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont I_StaticTextSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextSubject->SetFont(I_StaticTextSubjectFont);
    I_StaticTextTo = new wxStaticText(PanelInbox, ID_STATICTEXT4, wxEmptyString, wxPoint(710,155), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    I_StaticTextTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextTo->SetFont(I_StaticTextToFont);
    I_StaticTextFrom = new wxStaticText(PanelInbox, ID_STATICTEXT3, wxEmptyString, wxPoint(710,130), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    I_StaticTextFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextFrom->SetFont(I_StaticTextFromFont);
    I_StaticTextDate = new wxStaticText(PanelInbox, ID_STATICTEXT8, _("25.12.2013"), wxPoint(1150,130), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    I_StaticTextDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextDate->SetFont(I_StaticTextDateFont);
    I_LabelDate = new wxStaticText(PanelInbox, ID_STATICTEXT7, _("Data:"), wxPoint(1100,130), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    I_LabelDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelDate->SetFont(I_LabelDateFont);
    I_ImageButtonShowTree = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON29, wxNullBitmap, wxPoint(920,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON29"));
    I_ImageButtonReceiver = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON28, wxNullBitmap, wxPoint(830,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON28"));
    I_ImageButtonSender = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON27, wxNullBitmap, wxPoint(740,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON27"));
    I_ImageButtonDelete = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON26, wxNullBitmap, wxPoint(650,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON26"));
    I_ImageButtonMulTree = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON25, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON25"));
    I_ImageButtonStats = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON24, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON24"));
    I_ImageButtonGroups = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON23, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON23"));
    I_ImageButtonUsembers = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON22, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON22"));
    I_ImageButtonSettings = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON30, wxNullBitmap, wxPoint(370,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON30"));
    I_ImageButtonSearch = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON21, wxNullBitmap, wxPoint(280,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON21"));
    I_ImageButtonSave = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON20, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON20"));
    I_ImageButtonTitle = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON38, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON38"));
    I_ImageButtonAdd = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON19, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON19"));
    I_SearchCtrl = new wxSearchCtrl(PanelInbox, ID_SEARCHCTRL1, wxEmptyString, wxPoint(25,130), wxSize(550,25), 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    I_SearchCtrl->Hide();
    I_SearchCtrl->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
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
    DirDialog = new wxDirDialog(this, _("Wybierz folder"), _("~/"), wxDD_CHANGE_DIR, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FileDialog = new wxFileDialog(this, _("Wybierz pliki:"), _("~/"), wxEmptyString, _("*.eml"), wxFD_OPEN|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Center();

    Connect(ID_IMAGEBUTTON34,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON33,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFolderClick);
    Connect(ID_IMAGEBUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFilesClick);
    Connect(ID_IMAGEBUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonLoadClick);
    Connect(ID_IMAGEBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonImportClick);
    Connect(ID_IMAGEBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonAddClick);
    Connect(ID_IMAGEBUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSwitchListClick);
    Connect(ID_IMAGEBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSearchClick);
    Connect(ID_IMAGEBUTTON39,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonTitleClick);
    Connect(ID_IMAGEBUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonSearchClick);
    Connect(ID_IMAGEBUTTON38,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonTitleClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnAbout);
    //*)

    /** Alokacja pamięci dla obiektów zarządzających panelami */
    P_Title = new PanelTitleMaintance();
    P_Groups = new PanelGroupsMaintance();
    P_Inbox = new PanelInboxMaintance();
    P_MulTree = new PanelMulTreeMaintance();
    P_Stats = new PanelStatisticsMaintance();
    P_Usembers = new PanelUsembersMaintance();

    /** Alokacja głównych obiektów programu dla zarządania mailami i usemberami */
    database = new Database();
    iointerface = new IOInterface();
    iointerface->setDatabasePointer(database);

    ShowTitle();
}

/** PODSTAWOWE FUNKCJE PROGRAMU */

void AisdiRelationsFrame::ShowTitle (void )
{
    P_Usembers->SetLabels(this);        //inicjalizacja ikon oraz etykiet w panelach
    P_Usembers->SetIcons(this);
    P_Inbox->SetIcons(this);
    P_Inbox->SetLabels(this);
    P_Title->SetIcons(this);

    if (! P_MulTree->GetPanelEnabled())     //wyłączenie funkcjonowania panelu Multicast Tree
    {
        T_ImageButtonMulTree->Disable();
        I_ImageButtonMulTree->Disable();
        I_ImageButtonShowTree->Disable();
        U_ImageButtonMulTree->Disable();
        //S_ImageButtonMulTree->Disable();        // TODO odkomentować po zrobieniu panelu Stats (poniżej też)
        //G_ImageButtonMulTree->Disable();        // TODO odkomentować po zrobieniu panelu Groups (poniżej też)
    }

    if (! P_Stats->GetPanelEnabled())       //wyłączenie funcjonowania panelu Statistics
    {
        T_ImageButtonStats->Disable();
        I_ImageButtonStats->Disable();
        U_ImageButtonStats->Disable();
        U_ImageButtonSwitchContent->Disable();
        //G_ImageButtonStats->Disable();
        //M_ImageButtonStats->Disable();        // TODO odkomentować po zrobieniu panelu MulTree (poniżej też)
    }

    if (! P_Groups->GetPanelEnabled())       //wyłączenie funcjonowania panelu Groups
    {
        T_ImageButtonGroups->Disable();
        I_ImageButtonGroups->Disable();
        U_ImageButtonGroups->Disable();
        U_ImageButtonShowGroup->Disable();
        //S_ImageButtonGroups->Disable();
        //M_ImageButtonGroups->Disable();
    }

    if (! settingsEnabled)
    {
        T_ImageButtonSettings->Disable();
        I_ImageButtonSettings->Disable();
        U_ImageButtonSettings->Disable();
        //S_ImageButtonSettings->Disable();
        //M_ImageButtonSettings->Disable();
        //G_ImageButtonSettings->Disable();
    }

    P_Title->ShowPanel(this);
}

AisdiRelationsFrame::~AisdiRelationsFrame()
{
    //(*Destroy(AisdiRelationsFrame)
    //*)

    /** Zwolnienie pamięci obiektów obsługujących panele */
    delete (P_Groups);
    delete (P_Inbox);
    delete (P_MulTree);
    delete (P_Stats);
    delete (P_Title);
    delete (P_Usembers);
}

void AisdiRelationsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/** Informacje o autorach i wersji aplikacji */
void AisdiRelationsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = _("Autorzy:\n  Maciej Gańko\n  Paweł Kaczyński\n  Krzysztof Lisocki\n  Patryk Łucka\n  Jakub Maleszewski\n  Maciej Safarzyński\n  Michał Żołyniak\n\n");
    msg += _("---------------------------------------------------\nVersion:  0.8");
    wxMessageBox(msg, _("About"));
}

//Testowe wyświetlanie pól listy (inbox)
/*wxListItem col0;
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
  I_StaticTextDate->SetLabel(_("25.12.2013"));*/

void AisdiRelationsFrame::OnT_ImageButtonAddClick(wxCommandEvent& event)
{
    P_Title->SetClickedAdd();
    if (! P_Title->GetClickedAdd())         //TODO napraw
    {
        if ( P_Title->GetClickedLoad() )
            P_Title->SetClickedLoad();
        if ( P_Title->GetClickedImport() )
            P_Title->SetClickedImport();
    }
    P_Title->UpdateLoadingIcons(this);
}

void AisdiRelationsFrame::OnT_ImageButtonImportClick(wxCommandEvent& event)
{
    P_Title->SetClickedImport();
    P_Title->UpdateLoadingIcons(this);
}

void AisdiRelationsFrame::OnT_ImageButtonLoadClick(wxCommandEvent& event)
{
    P_Title->SetClickedLoad();
    P_Title->UpdateLoadingIcons(this);
}

void AisdiRelationsFrame::OnT_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnT_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonSearchClick(wxCommandEvent& event)
{
    if (P_Inbox->GetSearchEnabled())
        I_SearchCtrl->Hide();
    else
        I_SearchCtrl->Show();
    P_Inbox->SetSearchEnabled();
}

void AisdiRelationsFrame::OnU_ImageButtonSearchClick(wxCommandEvent& event)
{
    if (P_Usembers->GetSearchEnabled())
        U_SearchCtrl->Hide();
    else
        U_SearchCtrl->Show();
    P_Usembers->SetSearchEnabled();
}

void AisdiRelationsFrame::OnU_ImageButtonSwitchListClick(wxCommandEvent& event)
{
    P_Usembers->SwitchList(this);
}

void AisdiRelationsFrame::OnT_ImageButtonFolderClick(wxCommandEvent& event)
{
    if (DirDialog->ShowModal() == wxID_OK)
    {
        MailParameters * param = new MailParameters();
        wxString str = DirDialog->GetPath();
        param->path = str.To8BitData();
        param->isDirectory = true;
        param->recursiveImport = false;

        IOInterface::ImportStats stats;
        stats = iointerface->importMail(param);
    }
}

void AisdiRelationsFrame::OnT_ImageButtonFilesClick(wxCommandEvent& event)
{
    if (FileDialog->ShowModal() == wxID_OK)
    {
        wxArrayString paths;
        FileDialog->GetPaths(paths);
        for (unsigned int i = 0; i < paths.GetCount(); i++ )
            wxMessageBox(paths[i]);
    }
}
