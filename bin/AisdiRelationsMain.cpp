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
#include "view/PanelNotifyMaintance.h"

#include "AisdiRelationsMain.h"
#include <wx/msgdlg.h>
#include <wx/stattext.h>
#include <wx/dcclient.h>

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
const long AisdiRelationsFrame::ID_IMAGEBUTTON56 = wxNewId();
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
const long AisdiRelationsFrame::ID_STATICTEXT125 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT29 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT28 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT27 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT26 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT25 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT24 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL3 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT63 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT153 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT69 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT68 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT67 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT66 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON66 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON46 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON45 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON44 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON43 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON40 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT77 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT76 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT75 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT74 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT152 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT133 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT124 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT65 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON54 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON53 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON52 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON51 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON67 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON62 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON55 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON42 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX9 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT84 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT104 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT103 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT102 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT101 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT100 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT91 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT90 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT89 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT88 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT86 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT87 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT81 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT85 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE9 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT92 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT93 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT94 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT95 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT96 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT97 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT98 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT99 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT105 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT106 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT107 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT108 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT109 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL13 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX7 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT111 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL12 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX8 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE10 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT123 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT112 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT113 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT114 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT115 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT116 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT117 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT118 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT119 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT120 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT121 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT122 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL1 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL2 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL3 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL4 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL5 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL6 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL7 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL8 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL9 = wxNewId();
const long AisdiRelationsFrame::ID_HYPERLINKCTRL10 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL14 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBITMAP5 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT151 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT73 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT72 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT71 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT70 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT64 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON65 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON50 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON49 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON48 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON47 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON41 = wxNewId();
const long AisdiRelationsFrame::ID_LISTCTRL5 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL6 = wxNewId();
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
const long AisdiRelationsFrame::ID_STATICTEXT19 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT23 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT22 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT21 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT20 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT18 = wxNewId();
const long AisdiRelationsFrame::ID_HTMLWINDOW2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICLINE8 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL8 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT134 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT135 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT136 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT137 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL9 = wxNewId();
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
const long AisdiRelationsFrame::ID_STATICBITMAP1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT61 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT35 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT34 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT33 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT32 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT150 = wxNewId();
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
const long AisdiRelationsFrame::ID_IMAGEBUTTON64 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON21 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON20 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON38 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON19 = wxNewId();
const long AisdiRelationsFrame::ID_SEARCHCTRL1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX12 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT138 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT139 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT141 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT142 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT143 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT144 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT145 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT146 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT147 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT148 = wxNewId();
const long AisdiRelationsFrame::ID_TEXTCTRL1 = wxNewId();
const long AisdiRelationsFrame::ID_TEXTCTRL3 = wxNewId();
const long AisdiRelationsFrame::ID_TEXTCTRL4 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE1 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE2 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE3 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE4 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE5 = wxNewId();
const long AisdiRelationsFrame::ID_CHOICE6 = wxNewId();
const long AisdiRelationsFrame::ID_RADIOBOX1 = wxNewId();
const long AisdiRelationsFrame::ID_CHECKBOX4 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT149 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT140 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON63 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON68 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL16 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL2 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX6 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT78 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT79 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT80 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT129 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT83 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT82 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT130 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL11 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX5 = wxNewId();
const long AisdiRelationsFrame::ID_CHECKBOX1 = wxNewId();
const long AisdiRelationsFrame::ID_CHECKBOX2 = wxNewId();
const long AisdiRelationsFrame::ID_CHECKBOX3 = wxNewId();
const long AisdiRelationsFrame::ID_SLIDER1 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT110 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL10 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX10 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON57 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON58 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON59 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT126 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT127 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT128 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL15 = wxNewId();
const long AisdiRelationsFrame::ID_STATICBOX11 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON60 = wxNewId();
const long AisdiRelationsFrame::ID_IMAGEBUTTON61 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT131 = wxNewId();
const long AisdiRelationsFrame::ID_STATICTEXT132 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL17 = wxNewId();
const long AisdiRelationsFrame::ID_PANEL1 = wxNewId();
const long AisdiRelationsFrame::idMenuNew = wxNewId();
const long AisdiRelationsFrame::idMenuOpen = wxNewId();
const long AisdiRelationsFrame::idMenuOpenFolder = wxNewId();
const long AisdiRelationsFrame::idMenuSave = wxNewId();
const long AisdiRelationsFrame::idMenuQuit = wxNewId();
const long AisdiRelationsFrame::idMenuImportBin = wxNewId();
const long AisdiRelationsFrame::idMenuExportBin = wxNewId();
const long AisdiRelationsFrame::idMenuExportText = wxNewId();
const long AisdiRelationsFrame::idMenuRecursive = wxNewId();
const long AisdiRelationsFrame::idMenuDelConfirm = wxNewId();
const long AisdiRelationsFrame::idMenuDatabaseEncryption = wxNewId();
const long AisdiRelationsFrame::isMenuNTimeShort = wxNewId();
const long AisdiRelationsFrame::isMenuNTimeNormal = wxNewId();
const long AisdiRelationsFrame::isMenuNTimeLong = wxNewId();
const long AisdiRelationsFrame::ID_MENUITEM1 = wxNewId();
const long AisdiRelationsFrame::idMenuAbout = wxNewId();
const long AisdiRelationsFrame::idMenuHelp = wxNewId();
const long AisdiRelationsFrame::ID_TIMER1 = wxNewId();
const long AisdiRelationsFrame::ID_PASSWORDENTRYDIALOG1 = wxNewId();
const long AisdiRelationsFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AisdiRelationsFrame,wxFrame)
    //(*EventTable(AisdiRelationsFrame)
    //*)
END_EVENT_TABLE()

AisdiRelationsFrame::AisdiRelationsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(AisdiRelationsFrame)
    wxMenu* Menu1;
    wxMenu* Menu4;
    wxMenuItem* MenuItemQuit;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItemAbout;

    Create(parent, wxID_ANY, _("Analiza Relacji Biznesowych"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxVSCROLL|wxHSCROLL, _T("wxID_ANY"));
    SetClientSize(wxSize(1366,750));
    wxFont thisFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("resources/iconProgram.png"))));
    	SetIcon(FrameIcon);
    }
    PanelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    PanelMain->SetBackgroundColour(wxColour(0,0,0));
    PanelTitle = new wxPanel(PanelMain, ID_PANEL3, wxPoint(0,0), wxSize(1366,750), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
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
    T_ImageButtonSwitch = new wxBitmapButton(PanelTitle, ID_IMAGEBUTTON56, wxNullBitmap, wxPoint(1200,120), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON56"));
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
    T_LabelBin = new wxStaticText(PanelTitle, ID_STATICTEXT30, _("Zapisz bazę danych"), wxPoint(1115,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT30"));
    T_LabelBin->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelBinFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelBin->SetFont(T_LabelBinFont);
    T_LabelSettings = new wxStaticText(PanelTitle, ID_STATICTEXT31, _("Ustawienia"), wxPoint(1195,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT31"));
    T_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelSettings->SetFont(T_LabelSettingsFont);
    T_LabelSwitch = new wxStaticText(PanelTitle, ID_STATICTEXT125, _("Zmień menu"), wxPoint(1191,180), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT125"));
    T_LabelSwitch->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelSwitchFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelSwitch->SetFont(T_LabelSwitchFont);
    T_LabelTxt = new wxStaticText(PanelTitle, ID_STATICTEXT29, _("Wczytaj bazę danych"), wxPoint(1115,470), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT29"));
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
    T_LabelLoad = new wxStaticText(PanelTitle, ID_STATICTEXT26, _("Dodaj emaile"), wxPoint(448,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT26"));
    T_LabelLoad->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelLoadFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelLoad->SetFont(T_LabelLoadFont);
    T_LabelImport = new wxStaticText(PanelTitle, ID_STATICTEXT25, _("Baza danych"), wxPoint(745,610), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT25"));
    T_LabelImport->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelImportFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelImport->SetFont(T_LabelImportFont);
    T_LabelAdd = new wxStaticText(PanelTitle, ID_STATICTEXT24, _("Import/Export"), wxPoint(587,430), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    T_LabelAdd->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont T_LabelAddFont(14,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    T_LabelAdd->SetFont(T_LabelAddFont);
    PanelMulTree = new wxPanel(PanelMain, ID_PANEL7, wxPoint(1366,0), wxSize(1366,750), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BitmapBackgroundTree = new wxStaticBitmap(PanelMulTree, ID_STATICBITMAP6, wxBitmap(wxImage(_T("resources/background.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
    M_LabelTitle = new wxStaticText(PanelMulTree, ID_STATICTEXT63, _("Menu"), wxPoint(22,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT63"));
    M_LabelTitle->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelTitleFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelTitle->SetFont(M_LabelTitleFont);
    M_LabelSettings = new wxStaticText(PanelMulTree, ID_STATICTEXT153, _("Ustawienia"), wxPoint(94,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT153"));
    M_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelSettings->SetFont(M_LabelSettingsFont);
    M_LabelInbox = new wxStaticText(PanelMulTree, ID_STATICTEXT69, _("Skrzynka\nemaili"), wxPoint(910,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT69"));
    M_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelInboxFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelInbox->SetFont(M_LabelInboxFont);
    M_LabelUsembers = new wxStaticText(PanelMulTree, ID_STATICTEXT68, _("Usembers"), wxPoint(997,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT68"));
    M_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelUsembersFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelUsembers->SetFont(M_LabelUsembersFont);
    M_LabelGroups = new wxStaticText(PanelMulTree, ID_STATICTEXT67, _("Grupy"), wxPoint(1100,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT67"));
    M_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelGroups->SetFont(M_LabelGroupsFont);
    M_LabelStats = new wxStaticText(PanelMulTree, ID_STATICTEXT66, _("Statystyki"), wxPoint(1177,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT66"));
    M_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont M_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    M_LabelStats->SetFont(M_LabelStatsFont);
    M_ImageButtonSettings = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON66, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON66"));
    M_ImageButtonInbox = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON46, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON46"));
    M_ImageButtonUsembers = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON45, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON45"));
    M_ImageButtonGroups = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON44, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON44"));
    M_ImageButtonStats = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON43, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON43"));
    M_ImageButtonTitle = new wxBitmapButton(PanelMulTree, ID_IMAGEBUTTON40, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON40"));
    PanelStatistics = new wxPanel(PanelMain, ID_PANEL5, wxPoint(0,0), wxSize(1366,750), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    BitmapBackgroundStatistics = new wxStaticBitmap(PanelStatistics, ID_STATICBITMAP4, wxBitmap(wxImage(_T("resources/background.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
    S_LabelMulTree = new wxStaticText(PanelStatistics, ID_STATICTEXT77, _("Drzewo\nMulticastowe"), wxPoint(1166,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT77"));
    S_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelMulTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelMulTree->SetFont(S_LabelMulTreeFont);
    S_LabelGroups = new wxStaticText(PanelStatistics, ID_STATICTEXT76, _("Grupy"), wxPoint(1100,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT76"));
    S_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelGroups->SetFont(S_LabelGroupsFont);
    S_LabelUsembers = new wxStaticText(PanelStatistics, ID_STATICTEXT75, _("Usembers"), wxPoint(997,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT75"));
    S_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelUsembersFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelUsembers->SetFont(S_LabelUsembersFont);
    S_LabelInbox = new wxStaticText(PanelStatistics, ID_STATICTEXT74, _("Skrzynka\nemaili"), wxPoint(910,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT74"));
    S_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelInboxFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelInbox->SetFont(S_LabelInboxFont);
    S_LabelSettings = new wxStaticText(PanelStatistics, ID_STATICTEXT152, _("Ustawienia"), wxPoint(274,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT152"));
    S_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelSettings->SetFont(S_LabelSettingsFont);
    S_LabelSaveStats = new wxStaticText(PanelStatistics, ID_STATICTEXT133, _("Zapisz"), wxPoint(198,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT133"));
    S_LabelSaveStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelSaveStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelSaveStats->SetFont(S_LabelSaveStatsFont);
    S_LabelRefresh = new wxStaticText(PanelStatistics, ID_STATICTEXT124, _("Odśwież"), wxPoint(101,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT124"));
    S_LabelRefresh->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelRefreshFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelRefresh->SetFont(S_LabelRefreshFont);
    S_LabelTitle = new wxStaticText(PanelStatistics, ID_STATICTEXT65, _("Menu"), wxPoint(22,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT65"));
    S_LabelTitle->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont S_LabelTitleFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_LabelTitle->SetFont(S_LabelTitleFont);
    S_ImageButtonMulTree = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON54, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON54"));
    S_ImageButtonGroups = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON53, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON53"));
    S_ImageButtonUsembers = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON52, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON52"));
    S_ImageButtonInbox = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON51, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON51"));
    S_ImageButtonSettings = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON67, wxNullBitmap, wxPoint(280,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON67"));
    S_ImageButtonSaveStats = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON62, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON62"));
    S_ImageButtonRefresh = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON55, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON55"));
    S_ImageButtonTitle = new wxBitmapButton(PanelStatistics, ID_IMAGEBUTTON42, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON42"));
    S_PanelCounters = new wxPanel(PanelStatistics, ID_PANEL13, wxPoint(10,120), wxSize(320,600), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL13"));
    S_PanelCounters->SetBackgroundColour(wxColour(48,48,48));
    S_BorderC = new wxStaticBox(S_PanelCounters, ID_STATICBOX9, wxEmptyString, wxPoint(0,-10), wxSize(320,610), 0, _T("ID_STATICBOX9"));
    S_BorderC->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Title = new wxStaticText(S_PanelCounters, ID_STATICTEXT84, _("Trochę liczb..."), wxPoint(105,10), wxDefaultSize, 0, _T("ID_STATICTEXT84"));
    S_StaticTextC_Title->SetForegroundColour(wxColour(255,255,255));
    wxFont S_StaticTextC_TitleFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Title->SetFont(S_StaticTextC_TitleFont);
    S_StaticTextC_Duration = new wxStaticText(S_PanelCounters, ID_STATICTEXT104, _("Okres wysyłania emaili:\t\t\t    dni"), wxPoint(10,500), wxDefaultSize, 0, _T("ID_STATICTEXT104"));
    S_StaticTextC_Duration->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_DurationFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Duration->SetFont(S_StaticTextC_DurationFont);
    S_StaticTextC_Latest = new wxStaticText(S_PanelCounters, ID_STATICTEXT103, _("Najpóźniejszy email:"), wxPoint(80,440), wxDefaultSize, 0, _T("ID_STATICTEXT103"));
    S_StaticTextC_Latest->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_LatestFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Latest->SetFont(S_StaticTextC_LatestFont);
    S_StaticTextC_Earliest = new wxStaticText(S_PanelCounters, ID_STATICTEXT102, _("Najwcześniejszy email:"), wxPoint(70,380), wxDefaultSize, 0, _T("ID_STATICTEXT102"));
    S_StaticTextC_Earliest->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_EarliestFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Earliest->SetFont(S_StaticTextC_EarliestFont);
    S_StaticTextC_Replies = new wxStaticText(S_PanelCounters, ID_STATICTEXT101, _("Liczba odpowiedzi:"), wxPoint(10,335), wxDefaultSize, 0, _T("ID_STATICTEXT101"));
    S_StaticTextC_Replies->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_RepliesFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Replies->SetFont(S_StaticTextC_RepliesFont);
    S_StaticTextC_Forwards = new wxStaticText(S_PanelCounters, ID_STATICTEXT100, _("Liczba forwardów:"), wxPoint(10,305), wxDefaultSize, 0, _T("ID_STATICTEXT100"));
    S_StaticTextC_Forwards->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_ForwardsFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Forwards->SetFont(S_StaticTextC_ForwardsFont);
    S_StaticTextC_MaxEmailsInMonth = new wxStaticText(S_PanelCounters, ID_STATICTEXT91, _("Najwięcej emaili w miesiącu:"), wxPoint(10,275), wxDefaultSize, 0, _T("ID_STATICTEXT91"));
    S_StaticTextC_MaxEmailsInMonth->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_MaxEmailsInMonthFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_MaxEmailsInMonth->SetFont(S_StaticTextC_MaxEmailsInMonthFont);
    S_StaticTextC_AverageEmailLength = new wxStaticText(S_PanelCounters, ID_STATICTEXT90, _("Średnia dł. emaila:                \t   znaków"), wxPoint(10,245), wxDefaultSize, 0, _T("ID_STATICTEXT90"));
    S_StaticTextC_AverageEmailLength->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_AverageEmailLengthFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_AverageEmailLength->SetFont(S_StaticTextC_AverageEmailLengthFont);
    S_StaticTextC_EmailsPerUsember = new wxStaticText(S_PanelCounters, ID_STATICTEXT89, _("Średnio emaili/Usembera:"), wxPoint(10,200), wxDefaultSize, 0, _T("ID_STATICTEXT89"));
    S_StaticTextC_EmailsPerUsember->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_EmailsPerUsemberFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_EmailsPerUsember->SetFont(S_StaticTextC_EmailsPerUsemberFont);
    S_StaticTextC_EmailsPerDay = new wxStaticText(S_PanelCounters, ID_STATICTEXT88, _("Średnio emaili/dzień:"), wxPoint(10,170), wxDefaultSize, 0, _T("ID_STATICTEXT88"));
    S_StaticTextC_EmailsPerDay->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_EmailsPerDayFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_EmailsPerDay->SetFont(S_StaticTextC_EmailsPerDayFont);
    S_StaticTextC_EmailsPerMonth = new wxStaticText(S_PanelCounters, ID_STATICTEXT86, _("Średnio emaili/miesiąc:"), wxPoint(10,140), wxDefaultSize, 0, _T("ID_STATICTEXT86"));
    S_StaticTextC_EmailsPerMonth->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_EmailsPerMonthFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_EmailsPerMonth->SetFont(S_StaticTextC_EmailsPerMonthFont);
    S_StaticTextC_Groups = new wxStaticText(S_PanelCounters, ID_STATICTEXT87, _("Liczba Grup:"), wxPoint(10,95), wxDefaultSize, 0, _T("ID_STATICTEXT87"));
    S_StaticTextC_Groups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_GroupsFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Groups->SetFont(S_StaticTextC_GroupsFont);
    S_StaticTextC_Usembers = new wxStaticText(S_PanelCounters, ID_STATICTEXT81, _("Liczba Usemberów:"), wxPoint(10,65), wxDefaultSize, 0, _T("ID_STATICTEXT81"));
    S_StaticTextC_Usembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_UsembersFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Usembers->SetFont(S_StaticTextC_UsembersFont);
    S_StaticTextC_Emails = new wxStaticText(S_PanelCounters, ID_STATICTEXT85, _("Liczba Emaili:"), wxPoint(10,35), wxDefaultSize, 0, _T("ID_STATICTEXT85"));
    S_StaticTextC_Emails->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont S_StaticTextC_EmailsFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextC_Emails->SetFont(S_StaticTextC_EmailsFont);
    S_LineC_3 = new wxStaticLine(S_PanelCounters, ID_STATICLINE9, wxPoint(10,365), wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE9"));
    S_LineC_2 = new wxStaticLine(S_PanelCounters, ID_STATICLINE7, wxPoint(10,230), wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE7"));
    S_LineC_1 = new wxStaticLine(S_PanelCounters, ID_STATICLINE5, wxPoint(10,125), wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
    S_StaticTextC_Value1 = new wxStaticText(S_PanelCounters, ID_STATICTEXT92, _("-"), wxPoint(110,35), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT92"));
    S_StaticTextC_Value1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value2 = new wxStaticText(S_PanelCounters, ID_STATICTEXT93, _("-"), wxPoint(155,65), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT93"));
    S_StaticTextC_Value2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value3 = new wxStaticText(S_PanelCounters, ID_STATICTEXT94, _("-"), wxPoint(105,95), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT94"));
    S_StaticTextC_Value3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value4 = new wxStaticText(S_PanelCounters, ID_STATICTEXT95, _("-"), wxPoint(180,140), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT95"));
    S_StaticTextC_Value4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value5 = new wxStaticText(S_PanelCounters, ID_STATICTEXT96, _("-"), wxPoint(165,170), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT96"));
    S_StaticTextC_Value5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value6 = new wxStaticText(S_PanelCounters, ID_STATICTEXT97, _("-"), wxPoint(200,200), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT97"));
    S_StaticTextC_Value6->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value7 = new wxStaticText(S_PanelCounters, ID_STATICTEXT98, _("-"), wxPoint(165,245), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT98"));
    S_StaticTextC_Value7->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value8 = new wxStaticText(S_PanelCounters, ID_STATICTEXT99, _("-"), wxPoint(220,275), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT99"));
    S_StaticTextC_Value8->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value9 = new wxStaticText(S_PanelCounters, ID_STATICTEXT105, _("-"), wxPoint(147,305), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT105"));
    S_StaticTextC_Value9->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value10 = new wxStaticText(S_PanelCounters, ID_STATICTEXT106, _("-"), wxPoint(155,335), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT106"));
    S_StaticTextC_Value10->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value11 = new wxStaticText(S_PanelCounters, ID_STATICTEXT107, _("-"), wxPoint(115,410), wxSize(200,-1), wxST_NO_AUTORESIZE|wxALIGN_CENTRE|wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_STATICTEXT107"));
    S_StaticTextC_Value11->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value12 = new wxStaticText(S_PanelCounters, ID_STATICTEXT108, _("-"), wxPoint(115,470), wxSize(200,-1), wxST_NO_AUTORESIZE|wxALIGN_CENTRE|wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_STATICTEXT108"));
    S_StaticTextC_Value12->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextC_Value13 = new wxStaticText(S_PanelCounters, ID_STATICTEXT109, _("-"), wxPoint(210,500), wxSize(70,-1), wxST_NO_AUTORESIZE|wxALIGN_CENTRE|wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_STATICTEXT109"));
    S_StaticTextC_Value13->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_PanelEmailPerMonth = new wxPanel(PanelStatistics, ID_PANEL12, wxPoint(350,120), wxSize(890,410), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL12"));
    S_PanelEmailPerMonth->SetBackgroundColour(wxColour(48,48,48));
    S_BorderEPM = new wxStaticBox(S_PanelEmailPerMonth, ID_STATICBOX7, wxEmptyString, wxPoint(0,-10), wxSize(890,420), 0, _T("ID_STATICBOX7"));
    S_BorderEPM->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextEPM_Title = new wxStaticText(S_PanelEmailPerMonth, ID_STATICTEXT111, _("Wykres liczby emaili na miesiąc"), wxPoint(350,10), wxDefaultSize, 0, _T("ID_STATICTEXT111"));
    S_StaticTextEPM_Title->SetForegroundColour(wxColour(255,255,255));
    wxFont S_StaticTextEPM_TitleFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextEPM_Title->SetFont(S_StaticTextEPM_TitleFont);
    S_PanelTops = new wxPanel(PanelStatistics, ID_PANEL14, wxPoint(350,550), wxSize(890,170), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL14"));
    S_PanelTops->SetBackgroundColour(wxColour(48,48,48));
    S_BorderT = new wxStaticBox(S_PanelTops, ID_STATICBOX8, wxEmptyString, wxPoint(0,-10), wxSize(890,180), 0, _T("ID_STATICBOX8"));
    S_BorderT->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_LineT_1 = new wxStaticLine(S_PanelTops, ID_STATICLINE10, wxPoint(440,10), wxSize(2,150), wxLI_VERTICAL, _T("ID_STATICLINE10"));
    S_StaticTextT_TitleReceivers = new wxStaticText(S_PanelTops, ID_STATICTEXT123, _("Top 5 odbierających"), wxPoint(600,10), wxDefaultSize, 0, _T("ID_STATICTEXT123"));
    S_StaticTextT_TitleReceivers->SetForegroundColour(wxColour(255,255,255));
    wxFont S_StaticTextT_TitleReceiversFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextT_TitleReceivers->SetFont(S_StaticTextT_TitleReceiversFont);
    S_StaticTextT_TitleSenders = new wxStaticText(S_PanelTops, ID_STATICTEXT112, _("Top 5 wysyłających"), wxPoint(150,10), wxDefaultSize, 0, _T("ID_STATICTEXT112"));
    S_StaticTextT_TitleSenders->SetForegroundColour(wxColour(255,255,255));
    wxFont S_StaticTextT_TitleSendersFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_StaticTextT_TitleSenders->SetFont(S_StaticTextT_TitleSendersFont);
    S_StaticTextT_SendersPos1 = new wxStaticText(S_PanelTops, ID_STATICTEXT113, _("1."), wxPoint(15,40), wxDefaultSize, 0, _T("ID_STATICTEXT113"));
    S_StaticTextT_SendersPos1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextT_SendersPos2 = new wxStaticText(S_PanelTops, ID_STATICTEXT114, _("2."), wxPoint(15,65), wxDefaultSize, 0, _T("ID_STATICTEXT114"));
    S_StaticTextT_SendersPos2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_SendersPos3 = new wxStaticText(S_PanelTops, ID_STATICTEXT115, _("3."), wxPoint(15,90), wxDefaultSize, 0, _T("ID_STATICTEXT115"));
    S_StaticTextT_SendersPos3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_SendersPos4 = new wxStaticText(S_PanelTops, ID_STATICTEXT116, _("4."), wxPoint(15,115), wxDefaultSize, 0, _T("ID_STATICTEXT116"));
    S_StaticTextT_SendersPos4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_SendersPos5 = new wxStaticText(S_PanelTops, ID_STATICTEXT117, _("5."), wxPoint(15,140), wxDefaultSize, 0, _T("ID_STATICTEXT117"));
    S_StaticTextT_SendersPos5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_ReceiversPos1 = new wxStaticText(S_PanelTops, ID_STATICTEXT118, _("1."), wxPoint(460,40), wxDefaultSize, 0, _T("ID_STATICTEXT118"));
    S_StaticTextT_ReceiversPos1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_StaticTextT_ReceiversPos2 = new wxStaticText(S_PanelTops, ID_STATICTEXT119, _("2."), wxPoint(460,65), wxDefaultSize, 0, _T("ID_STATICTEXT119"));
    S_StaticTextT_ReceiversPos2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_ReceiversPos3 = new wxStaticText(S_PanelTops, ID_STATICTEXT120, _("3."), wxPoint(460,90), wxDefaultSize, 0, _T("ID_STATICTEXT120"));
    S_StaticTextT_ReceiversPos3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_ReceiversPos4 = new wxStaticText(S_PanelTops, ID_STATICTEXT121, _("4."), wxPoint(460,115), wxDefaultSize, 0, _T("ID_STATICTEXT121"));
    S_StaticTextT_ReceiversPos4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_StaticTextT_ReceiversPos5 = new wxStaticText(S_PanelTops, ID_STATICTEXT122, _("5."), wxPoint(460,140), wxDefaultSize, 0, _T("ID_STATICTEXT122"));
    S_StaticTextT_ReceiversPos5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos1 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL1, _("25 - Nick Fury <nfury@shield.gov>"), wxEmptyString, wxPoint(40,40), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL1"));
    S_HyperLinkT_SendersPos1->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_HyperLinkT_SendersPos1->SetHoverColour(wxColour(255,255,255));
    S_HyperLinkT_SendersPos1->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_HyperLinkT_SendersPos1->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_SendersPos1Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_SendersPos1->SetFont(S_HyperLinkT_SendersPos1Font);
    S_HyperLinkT_SendersPos2 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL2, _("(17) Natasha Romanov <nromanov@russia.ru>"), wxEmptyString, wxPoint(40,65), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL2"));
    S_HyperLinkT_SendersPos2->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos2->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_SendersPos2->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos2->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_SendersPos2Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_SendersPos2->SetFont(S_HyperLinkT_SendersPos2Font);
    S_HyperLinkT_SendersPos3 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL3, _("[11] - Tony Stark <ironman@starkindustries.com>"), wxEmptyString, wxPoint(40,90), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL3"));
    S_HyperLinkT_SendersPos3->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos3->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_SendersPos3->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos3->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_SendersPos3Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_SendersPos3->SetFont(S_HyperLinkT_SendersPos3Font);
    S_HyperLinkT_SendersPos4 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL4, _("Steve Rogers <cptamerica@army.gov>"), wxEmptyString, wxPoint(40,115), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL4"));
    S_HyperLinkT_SendersPos4->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos4->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_SendersPos4->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos4->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_SendersPos4Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_SendersPos4->SetFont(S_HyperLinkT_SendersPos4Font);
    S_HyperLinkT_SendersPos5 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL5, _("Clint Barton <hawkeye@avengers.com>"), wxEmptyString, wxPoint(40,140), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL5"));
    S_HyperLinkT_SendersPos5->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos5->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_SendersPos5->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_SendersPos5->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_SendersPos5Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_SendersPos5->SetFont(S_HyperLinkT_SendersPos5Font);
    S_HyperLinkT_ReceiverPos1 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL6, _("Superman <clarkkent@dailyplanet.com>"), wxEmptyString, wxPoint(485,40), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL6"));
    S_HyperLinkT_ReceiverPos1->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_HyperLinkT_ReceiverPos1->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_ReceiverPos1->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    S_HyperLinkT_ReceiverPos1->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_ReceiverPos1Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_ReceiverPos1->SetFont(S_HyperLinkT_ReceiverPos1Font);
    S_HyperLinkT_ReceiverPos2 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL7, _("Green Lantern <haljordan@willpower.com>"), wxEmptyString, wxPoint(485,65), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL7"));
    S_HyperLinkT_ReceiverPos2->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos2->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_ReceiverPos2->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos2->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_ReceiverPos2Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_ReceiverPos2->SetFont(S_HyperLinkT_ReceiverPos2Font);
    S_HyperLinkT_ReceiverPos3 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL8, _("Wonder Woman <diana@amazon.com>"), wxEmptyString, wxPoint(485,90), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL8"));
    S_HyperLinkT_ReceiverPos3->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos3->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_ReceiverPos3->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos3->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_ReceiverPos3Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_ReceiverPos3->SetFont(S_HyperLinkT_ReceiverPos3Font);
    S_HyperLinkT_ReceiverPos4 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL9, _("Flash <barryallen@paradox.com>"), wxEmptyString, wxPoint(485,115), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL9"));
    S_HyperLinkT_ReceiverPos4->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos4->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_ReceiverPos4->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos4->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_ReceiverPos4Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_ReceiverPos4->SetFont(S_HyperLinkT_ReceiverPos4Font);
    S_HyperLinkT_ReceiverPos5 = new wxHyperlinkCtrl(S_PanelTops, ID_HYPERLINKCTRL10, _("Batman <brucewayne@gotham.com>"), wxEmptyString, wxPoint(485,140), wxSize(400,-1), wxHL_ALIGN_LEFT|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_HYPERLINKCTRL10"));
    S_HyperLinkT_ReceiverPos5->SetNormalColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos5->SetHoverColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    S_HyperLinkT_ReceiverPos5->SetVisitedColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    S_HyperLinkT_ReceiverPos5->SetBackgroundColour(wxColour(48,48,48));
    wxFont S_HyperLinkT_ReceiverPos5Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    S_HyperLinkT_ReceiverPos5->SetFont(S_HyperLinkT_ReceiverPos5Font);
    PanelGroups = new wxPanel(PanelMain, ID_PANEL6, wxPoint(0,0), wxSize(1366,750), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BitmapBackgroundGroups = new wxStaticBitmap(PanelGroups, ID_STATICBITMAP5, wxBitmap(wxImage(_T("resources/background.jpg")).Rescale(wxSize(1366,768).GetWidth(),wxSize(1366,768).GetHeight())), wxPoint(0,0), wxSize(1366,768), wxSIMPLE_BORDER|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_STATICBITMAP5"));
    G_LabelSettings = new wxStaticText(PanelGroups, ID_STATICTEXT151, _("Ustawienia"), wxPoint(94,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT151"));
    G_LabelSettings->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelSettingsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelSettings->SetFont(G_LabelSettingsFont);
    G_LabelMulTree = new wxStaticText(PanelGroups, ID_STATICTEXT73, _("Drzewo\nMulticastowe"), wxPoint(1166,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT73"));
    G_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelMulTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelMulTree->SetFont(G_LabelMulTreeFont);
    G_LabelStats = new wxStaticText(PanelGroups, ID_STATICTEXT72, _("Statystyki"), wxPoint(1087,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT72"));
    G_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelStats->SetFont(G_LabelStatsFont);
    G_LabelUsembers = new wxStaticText(PanelGroups, ID_STATICTEXT71, _("Usembers"), wxPoint(997,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT71"));
    G_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelUsembersFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelUsembers->SetFont(G_LabelUsembersFont);
    G_LabelInbox = new wxStaticText(PanelGroups, ID_STATICTEXT70, _("Skrzynka\nemaili"), wxPoint(910,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT70"));
    G_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelInboxFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelInbox->SetFont(G_LabelInboxFont);
    G_LabelTitle = new wxStaticText(PanelGroups, ID_STATICTEXT64, _("Menu"), wxPoint(22,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT64"));
    G_LabelTitle->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont G_LabelTitleFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_LabelTitle->SetFont(G_LabelTitleFont);
    G_ImageButtonSettings = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON65, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON65"));
    G_ImageButtonMulTree = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON50, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON50"));
    G_ImageButtonStats = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON49, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON49"));
    G_ImageButtonUsembers = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON48, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON48"));
    G_ImageButtonInbox = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON47, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON47"));
    G_ImageButtonTitle = new wxBitmapButton(PanelGroups, ID_IMAGEBUTTON41, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON41"));
    G_ListGroups = new wxListCtrl(PanelGroups, ID_LISTCTRL5, wxPoint(25,130), wxSize(630,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL5"));
    G_ListGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    G_ListGroups->SetBackgroundColour(wxColour(20,20,20));
    wxFont G_ListGroupsFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    G_ListGroups->SetFont(G_ListGroupsFont);
    PanelUsembers = new wxPanel(PanelMain, ID_PANEL4, wxPoint(1366,0), wxSize(1366,750), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BitmapBackgroundUsembers = new wxStaticBitmap(PanelUsembers, ID_STATICBITMAP3, wxBitmap(wxImage(_T("resources/background.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
    U_LabelSwitchContent = new wxStaticText(PanelUsembers, ID_STATICTEXT54, _("Przełącz\nzawartość"), wxPoint(1188,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT54"));
    U_LabelSwitchContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSwitchContentFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSwitchContent->SetFont(U_LabelSwitchContentFont);
    U_LabelSwitchList = new wxStaticText(PanelUsembers, ID_STATICTEXT55, _("Przełącz\nlistę"), wxPoint(603,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT55"));
    U_LabelSwitchList->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelSwitchListFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSwitchList->SetFont(U_LabelSwitchListFont);
    U_LabelShowGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT53, _("Pokaż\ngrupę"), wxPoint(800,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT53"));
    U_LabelShowGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelShowGroupFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelShowGroup->SetFont(U_LabelShowGroupFont);
    U_LabelDelete = new wxStaticText(PanelUsembers, ID_STATICTEXT52, _("Usuń"), wxPoint(713,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT52"));
    U_LabelDelete->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelDeleteFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelDelete->SetFont(U_LabelDeleteFont);
    U_LabelInbox = new wxStaticText(PanelUsembers, ID_STATICTEXT51, _("Skrzynka\nemaili"), wxPoint(910,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT51"));
    U_LabelInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelInboxFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelInbox->SetFont(U_LabelInboxFont);
    U_LabelGroups = new wxStaticText(PanelUsembers, ID_STATICTEXT50, _("Grupy"), wxPoint(1010,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT50"));
    U_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelGroups->SetFont(U_LabelGroupsFont);
    U_LabelStats = new wxStaticText(PanelUsembers, ID_STATICTEXT49, _("Statystyki"), wxPoint(1087,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT49"));
    U_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont U_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelStats->SetFont(U_LabelStatsFont);
    U_LabelMulTree = new wxStaticText(PanelUsembers, ID_STATICTEXT48, _("Drzewo\nMulticastowe"), wxPoint(1166,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT48"));
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
    U_StaticBoxUsembers = new wxStaticBox(PanelUsembers, ID_STATICBOX3, _("  Usembers  "), wxPoint(15,100), wxSize(650,610), 0, _T("ID_STATICBOX3"));
    U_StaticBoxUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_StaticBoxUsembers->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont U_StaticBoxUsembersFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticBoxUsembers->SetFont(U_StaticBoxUsembersFont);
    U_StaticBoxInfo = new wxStaticBox(PanelUsembers, ID_STATICBOX4, wxEmptyString, wxPoint(700,103), wxSize(550,500), 0, _T("ID_STATICBOX4"));
    U_StaticBoxInfo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_StaticBoxInfo->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_BitmapUsember = new wxStaticBitmap(PanelUsembers, ID_STATICBITMAP7, wxBitmap(wxImage(_T("resources/iconsBig/iconUsember.png")).Rescale(wxSize(100,100).GetWidth(),wxSize(100,100).GetHeight())), wxPoint(720,135), wxSize(100,100), wxSIMPLE_BORDER, _T("ID_STATICBITMAP7"));
    U_ListUsembers = new wxListCtrl(PanelUsembers, ID_LISTCTRL2, wxPoint(25,130), wxSize(630,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    U_ListUsembers->Hide();
    U_ListUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListUsembers->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListUsembersFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListUsembers->SetFont(U_ListUsembersFont);
    U_ListOutbox = new wxListCtrl(PanelUsembers, ID_LISTCTRL4, wxPoint(25,425), wxSize(630,275), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL4"));
    U_ListOutbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListOutbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListOutboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListOutbox->SetFont(U_ListOutboxFont);
    U_ListInbox = new wxListCtrl(PanelUsembers, ID_LISTCTRL3, wxPoint(25,130), wxSize(630,275), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL3"));
    U_ListInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_ListInbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont U_ListInboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_ListInbox->SetFont(U_ListInboxFont);
    U_StaticTextGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT17, wxEmptyString, wxPoint(895,185), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    U_StaticTextGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextGroupFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextGroup->SetFont(U_StaticTextGroupFont);
    U_StaticTextEmail = new wxStaticText(PanelUsembers, ID_STATICTEXT16, wxEmptyString, wxPoint(895,160), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    U_StaticTextEmail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextEmailFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextEmail->SetFont(U_StaticTextEmailFont);
    U_StaticTextName = new wxStaticText(PanelUsembers, ID_STATICTEXT15, wxEmptyString, wxPoint(895,135), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    U_StaticTextName->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextNameFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextName->SetFont(U_StaticTextNameFont);
    U_LabelEmail = new wxStaticText(PanelUsembers, ID_STATICTEXT13, _("Email:"), wxPoint(830,160), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    U_LabelEmail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelEmailFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelEmail->SetFont(U_LabelEmailFont);
    U_LabelGroup = new wxStaticText(PanelUsembers, ID_STATICTEXT14, _("Grupa:"), wxPoint(830,185), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    U_LabelGroup->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelGroupFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelGroup->SetFont(U_LabelGroupFont);
    U_LabelName = new wxStaticText(PanelUsembers, ID_STATICTEXT12, _("Nazwa:"), wxPoint(830,135), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    U_LabelName->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelNameFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelName->SetFont(U_LabelNameFont);
    U_PanelEmail = new wxPanel(PanelUsembers, ID_PANEL8, wxPoint(720,245), wxSize(510,345), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL8"));
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
    U_StaticTextDate = new wxStaticText(U_PanelEmail, ID_STATICTEXT21, wxEmptyString, wxPoint(400,15), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    U_StaticTextDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont U_StaticTextDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextDate->SetFont(U_StaticTextDateFont);
    U_LabelDate = new wxStaticText(U_PanelEmail, ID_STATICTEXT20, _("Data:"), wxPoint(345,15), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    U_LabelDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelDate->SetFont(U_LabelDateFont);
    U_LabelFromTo = new wxStaticText(U_PanelEmail, ID_STATICTEXT18, _("Od:"), wxPoint(15,15), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    U_LabelFromTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont U_LabelFromToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelFromTo->SetFont(U_LabelFromToFont);
    U_HtmlContent = new wxHtmlWindow(U_PanelEmail, ID_HTMLWINDOW2, wxPoint(15,80), wxSize(480,255), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW2"));
    U_HtmlContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    U_HtmlContent->SetBackgroundColour(wxColour(32,32,32));
    wxFont U_HtmlContentFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_HtmlContent->SetFont(U_HtmlContentFont);
    U_LineContentSeparator = new wxStaticLine(U_PanelEmail, ID_STATICLINE8, wxPoint(20,60), wxSize(470,15), wxLI_HORIZONTAL, _T("ID_STATICLINE8"));
    U_LineContentSeparator->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    U_PanelStats = new wxPanel(PanelUsembers, ID_PANEL9, wxPoint(720,245), wxSize(510,345), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL9"));
    U_PanelStats->SetBackgroundColour(wxColour(48,48,48));
    U_LabelSent = new wxStaticText(U_PanelStats, ID_STATICTEXT134, _("Emaile wysłane: "), wxPoint(250,10), wxDefaultSize, 0, _T("ID_STATICTEXT134"));
    U_LabelSent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont U_LabelSentFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelSent->SetFont(U_LabelSentFont);
    U_LabelReceived = new wxStaticText(U_PanelStats, ID_STATICTEXT135, _("Emaile odebrane: "), wxPoint(10,10), wxDefaultSize, 0, _T("ID_STATICTEXT135"));
    U_LabelReceived->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    wxFont U_LabelReceivedFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_LabelReceived->SetFont(U_LabelReceivedFont);
    U_StaticTextSent = new wxStaticText(U_PanelStats, ID_STATICTEXT136, _("123"), wxPoint(390,10), wxDefaultSize, 0, _T("ID_STATICTEXT136"));
    U_StaticTextSent->SetForegroundColour(wxColour(255,187,117));
    wxFont U_StaticTextSentFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextSent->SetFont(U_StaticTextSentFont);
    U_StaticTextReceived = new wxStaticText(U_PanelStats, ID_STATICTEXT137, _("123"), wxPoint(160,10), wxDefaultSize, 0, _T("ID_STATICTEXT137"));
    U_StaticTextReceived->SetForegroundColour(wxColour(252,69,33));
    wxFont U_StaticTextReceivedFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    U_StaticTextReceived->SetFont(U_StaticTextReceivedFont);
    U_ImageButtonSwitchList = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON10, wxNullBitmap, wxPoint(600,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON10"));
    U_ImageButtonSwitchContent = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON11, wxNullBitmap, wxPoint(1190,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON11"));
    U_ImageButtonShowGroup = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON9, wxNullBitmap, wxPoint(790,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON9"));
    U_ImageButtonDelete = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON8, wxNullBitmap, wxPoint(700,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON8"));
    U_ImageButtonMulTree = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON7, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON7"));
    U_ImageButtonStats = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON6, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON6"));
    U_ImageButtonGroups = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON5, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON5"));
    U_ImageButtonInbox = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON4, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON4"));
    U_ImageButtonSettings = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON31, wxNullBitmap, wxPoint(370,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON31"));
    U_ImageButtonSearch = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON3, wxNullBitmap, wxPoint(280,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON3"));
    U_ImageButtonSave = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON2, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON2"));
    U_ImageButtonAdd = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON1, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON1"));
    U_ImageButtonTitle = new wxBitmapButton(PanelUsembers, ID_IMAGEBUTTON39, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON39"));
    U_SearchCtrl = new wxSearchCtrl(PanelUsembers, ID_SEARCHCTRL2, wxEmptyString, wxPoint(25,130), wxSize(630,25), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHCTRL2"));
    U_SearchCtrl->Hide();
    U_SearchCtrl->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    PanelInbox = new wxPanel(PanelMain, ID_PANEL2, wxPoint(1366,0), wxSize(1366,750), wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxVSCROLL|wxHSCROLL, _T("ID_PANEL2"));
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
    I_LabelRestore = new wxStaticText(PanelInbox, ID_STATICTEXT150, _("Pokaż wszystko"), wxPoint(560,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT150"));
    I_LabelRestore->Hide();
    I_LabelRestore->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelRestoreFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelRestore->SetFont(I_LabelRestoreFont);
    I_LabelMulTree = new wxStaticText(PanelInbox, ID_STATICTEXT39, _("Drzewo\nMulticastowe"), wxPoint(1166,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT39"));
    I_LabelMulTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelMulTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelMulTree->SetFont(I_LabelMulTreeFont);
    I_LabelStats = new wxStaticText(PanelInbox, ID_STATICTEXT38, _("Statystyki"), wxPoint(1087,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT38"));
    I_LabelStats->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelStatsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelStats->SetFont(I_LabelStatsFont);
    I_LabelGroups = new wxStaticText(PanelInbox, ID_STATICTEXT37, _("Grupy"), wxPoint(1010,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT37"));
    I_LabelGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelGroupsFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelGroups->SetFont(I_LabelGroupsFont);
    I_LabelUsembers = new wxStaticText(PanelInbox, ID_STATICTEXT36, _("Usembers"), wxPoint(905,70), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT36"));
    I_LabelUsembers->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelUsembersFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelUsembers->SetFont(I_LabelUsembersFont);
    I_LabelShowTree = new wxStaticText(PanelInbox, ID_STATICTEXT43, _("Utwórz\ndrzewo"), wxPoint(975,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT43"));
    I_LabelShowTree->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelShowTreeFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelShowTree->SetFont(I_LabelShowTreeFont);
    I_LabelReceiver = new wxStaticText(PanelInbox, ID_STATICTEXT42, _("Pokaż\nodbiorcę"), wxPoint(880,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT42"));
    I_LabelReceiver->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelReceiverFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelReceiver->SetFont(I_LabelReceiverFont);
    I_LabelSender = new wxStaticText(PanelInbox, ID_STATICTEXT41, _("Pokaż\nnadawcę"), wxPoint(790,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT41"));
    I_LabelSender->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelSenderFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSender->SetFont(I_LabelSenderFont);
    I_LabelDelete = new wxStaticText(PanelInbox, ID_STATICTEXT40, _("Usuń"), wxPoint(713,685), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT40"));
    I_LabelDelete->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_LabelDeleteFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelDelete->SetFont(I_LabelDeleteFont);
    I_InboxBorder = new wxStaticBox(PanelInbox, ID_STATICBOX1, _("  Skrzynka Email  "), wxPoint(15,100), wxSize(650,610), 0, _T("ID_STATICBOX1"));
    I_InboxBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_InboxBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont I_InboxBorderFont(16,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_InboxBorder->SetFont(I_InboxBorderFont);
    I_ListInbox = new wxListCtrl(PanelInbox, ID_LISTCTRL1, wxPoint(25,130), wxSize(630,570), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    I_ListInbox->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_ListInbox->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_ListInboxFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_ListInbox->SetFont(I_ListInboxFont);
    I_EmailContentBorder = new wxStaticBox(PanelInbox, ID_STATICBOX2, wxEmptyString, wxPoint(700,103), wxSize(550,500), 0, _T("ID_STATICBOX2"));
    I_EmailContentBorder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_EmailContentBorder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_LabelFrom = new wxStaticText(PanelInbox, ID_STATICTEXT1, _("Od: "), wxPoint(720,130), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    I_LabelFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelFrom->SetFont(I_LabelFromFont);
    I_LabelTo = new wxStaticText(PanelInbox, ID_STATICTEXT2, _("Do:"), wxPoint(720,155), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    I_LabelTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelTo->SetFont(I_LabelToFont);
    I_LabelSubject = new wxStaticText(PanelInbox, ID_STATICTEXT5, _("Temat:"), wxPoint(720,180), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    I_LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelSubject->SetFont(I_LabelSubjectFont);
    I_LineContentSeparator = new wxStaticLine(PanelInbox, ID_STATICLINE1, wxPoint(715,220), wxSize(510,10), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    I_HtmlEmailContent = new wxHtmlWindow(PanelInbox, ID_HTMLWINDOW1, wxPoint(720,240), wxSize(510,350), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_HTMLWINDOW1"));
    I_HtmlEmailContent->SetPage(_("<p align=\"justify\"><font color=\"lightgray\"></font></p>"));
    I_HtmlEmailContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    I_HtmlEmailContent->SetBackgroundColour(wxColour(20,20,20));
    wxFont I_HtmlEmailContentFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_HtmlEmailContent->SetFont(I_HtmlEmailContentFont);
    I_StaticTextSubject = new wxStaticText(PanelInbox, ID_STATICTEXT6, wxEmptyString, wxPoint(785,180), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    I_StaticTextSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont I_StaticTextSubjectFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextSubject->SetFont(I_StaticTextSubjectFont);
    I_StaticTextTo = new wxStaticText(PanelInbox, ID_STATICTEXT4, wxEmptyString, wxPoint(760,155), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    I_StaticTextTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextToFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextTo->SetFont(I_StaticTextToFont);
    I_StaticTextFrom = new wxStaticText(PanelInbox, ID_STATICTEXT3, wxEmptyString, wxPoint(760,130), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    I_StaticTextFrom->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextFromFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextFrom->SetFont(I_StaticTextFromFont);
    I_StaticTextDate = new wxStaticText(PanelInbox, ID_STATICTEXT8, _("25.12.2013"), wxPoint(1135,130), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    I_StaticTextDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    wxFont I_StaticTextDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_StaticTextDate->SetFont(I_StaticTextDateFont);
    I_LabelDate = new wxStaticText(PanelInbox, ID_STATICTEXT7, _("Data:"), wxPoint(1085,130), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    I_LabelDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont I_LabelDateFont(13,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_LabelDate->SetFont(I_LabelDateFont);
    I_ImageButtonShowTree = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON29, wxNullBitmap, wxPoint(970,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON29"));
    I_ImageButtonReceiver = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON28, wxNullBitmap, wxPoint(880,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON28"));
    I_ImageButtonSender = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON27, wxNullBitmap, wxPoint(790,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON27"));
    I_ImageButtonDelete = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON26, wxNullBitmap, wxPoint(700,620), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON26"));
    I_ImageButtonMulTree = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON25, wxNullBitmap, wxPoint(1180,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON25"));
    I_ImageButtonStats = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON24, wxNullBitmap, wxPoint(1090,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON24"));
    I_ImageButtonGroups = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON23, wxNullBitmap, wxPoint(1000,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON23"));
    I_ImageButtonUsembers = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON22, wxNullBitmap, wxPoint(910,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON22"));
    I_ImageButtonSettings = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON30, wxNullBitmap, wxPoint(370,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON30"));
    I_ImageButtonRestore = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON64, wxNullBitmap, wxPoint(582,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON64"));
    I_ImageButtonRestore->Hide();
    I_ImageButtonSearch = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON21, wxNullBitmap, wxPoint(280,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON21"));
    I_ImageButtonSave = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON20, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON20"));
    I_ImageButtonTitle = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON38, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON38"));
    I_ImageButtonAdd = new wxBitmapButton(PanelInbox, ID_IMAGEBUTTON19, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_IMAGEBUTTON19"));
    I_SearchCtrl = new wxSearchCtrl(PanelInbox, ID_SEARCHCTRL1, wxEmptyString, wxPoint(25,130), wxSize(630,25), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    I_SearchCtrl->Hide();
    I_SearchCtrl->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    I_PanelAdvSearch = new wxPanel(PanelInbox, ID_PANEL16, wxPoint(670,113), wxSize(315,460), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("ID_PANEL16"));
    I_PanelAdvSearch->SetBackgroundColour(wxColour(48,48,48));
    I_Adv_Border = new wxStaticBox(I_PanelAdvSearch, ID_STATICBOX12, wxEmptyString, wxPoint(0,-10), wxSize(315,470), 0, _T("ID_STATICBOX12"));
    I_Adv_Border->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_Adv_Title = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT138, _("Wyszukiwanie zaawasowane"), wxPoint(42,10), wxDefaultSize, 0, _T("ID_STATICTEXT138"));
    I_Adv_Title->SetForegroundColour(wxColour(240,240,240));
    I_Adv_LabelSubject = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT139, _("Temat:"), wxPoint(10,40), wxDefaultSize, 0, _T("ID_STATICTEXT139"));
    I_Adv_LabelSubject->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_LabelEmail = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT141, _("Email:"), wxPoint(10,75), wxDefaultSize, 0, _T("ID_STATICTEXT141"));
    I_Adv_LabelEmail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_LabelContent = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT142, _("Treść:"), wxPoint(10,110), wxDefaultSize, 0, _T("ID_STATICTEXT142"));
    I_Adv_LabelContent->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_LabelDay = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT143, _("Dzień"), wxPoint(32,185), wxDefaultSize, 0, _T("ID_STATICTEXT143"));
    I_Adv_LabelDay->SetForegroundColour(wxColour(225,225,225));
    I_Adv_LabelMonth = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT144, _("Miesiąc"), wxPoint(103,185), wxDefaultSize, 0, _T("ID_STATICTEXT144"));
    I_Adv_LabelMonth->SetForegroundColour(wxColour(225,225,225));
    I_Adv_LabelYear = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT145, _("Rok"), wxPoint(205,185), wxDefaultSize, 0, _T("ID_STATICTEXT145"));
    I_Adv_LabelYear->SetForegroundColour(wxColour(225,225,225));
    I_Adv_LabelDayTo = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT146, _("Dzień"), wxPoint(32,280), wxDefaultSize, 0, _T("ID_STATICTEXT146"));
    I_Adv_LabelDayTo->Disable();
    I_Adv_LabelDayTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_LabelMonthTo = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT147, _("Miesiąc"), wxPoint(103,280), wxDefaultSize, 0, _T("ID_STATICTEXT147"));
    I_Adv_LabelMonthTo->Disable();
    I_Adv_LabelMonthTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_LabelYearTo = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT148, _("Rok"), wxPoint(205,280), wxDefaultSize, 0, _T("ID_STATICTEXT148"));
    I_Adv_LabelYearTo->Disable();
    I_Adv_LabelYearTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_TextCtrlSubject = new wxTextCtrl(I_PanelAdvSearch, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,37), wxSize(200,25), wxTE_NO_VSCROLL|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    I_Adv_TextCtrlSubject->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_TextCtrlEmail = new wxTextCtrl(I_PanelAdvSearch, ID_TEXTCTRL3, wxEmptyString, wxPoint(80,72), wxSize(200,25), wxTE_NO_VSCROLL|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    I_Adv_TextCtrlEmail->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_TextCtrlContent = new wxTextCtrl(I_PanelAdvSearch, ID_TEXTCTRL4, wxEmptyString, wxPoint(82,107), wxSize(196,60), wxTE_MULTILINE|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    I_Adv_TextCtrlContent->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceDay = new wxChoice(I_PanelAdvSearch, ID_CHOICE1, wxPoint(25,210), wxSize(60,30), 0, 0, wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE1"));
    I_Adv_ChoiceDay->Append(wxEmptyString);
    I_Adv_ChoiceDay->Append(_("01"));
    I_Adv_ChoiceDay->Append(_("02"));
    I_Adv_ChoiceDay->Append(_("03"));
    I_Adv_ChoiceDay->Append(_("04"));
    I_Adv_ChoiceDay->Append(_("05"));
    I_Adv_ChoiceDay->Append(_("06"));
    I_Adv_ChoiceDay->Append(_("07"));
    I_Adv_ChoiceDay->Append(_("08"));
    I_Adv_ChoiceDay->Append(_("09"));
    I_Adv_ChoiceDay->Append(_("10"));
    I_Adv_ChoiceDay->Append(_("11"));
    I_Adv_ChoiceDay->Append(_("12"));
    I_Adv_ChoiceDay->Append(_("13"));
    I_Adv_ChoiceDay->Append(_("14"));
    I_Adv_ChoiceDay->Append(_("15"));
    I_Adv_ChoiceDay->Append(_("16"));
    I_Adv_ChoiceDay->Append(_("17"));
    I_Adv_ChoiceDay->Append(_("18"));
    I_Adv_ChoiceDay->Append(_("19"));
    I_Adv_ChoiceDay->Append(_("20"));
    I_Adv_ChoiceDay->Append(_("21"));
    I_Adv_ChoiceDay->Append(_("22"));
    I_Adv_ChoiceDay->Append(_("23"));
    I_Adv_ChoiceDay->Append(_("24"));
    I_Adv_ChoiceDay->Append(_("25"));
    I_Adv_ChoiceDay->Append(_("26"));
    I_Adv_ChoiceDay->Append(_("27"));
    I_Adv_ChoiceDay->Append(_("28"));
    I_Adv_ChoiceDay->Append(_("29"));
    I_Adv_ChoiceDay->Append(_("30"));
    I_Adv_ChoiceDay->Append(_("31"));
    I_Adv_ChoiceDay->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceDay->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceMonth = new wxChoice(I_PanelAdvSearch, ID_CHOICE2, wxPoint(100,210), wxSize(60,30), 0, 0, wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE2"));
    I_Adv_ChoiceMonth->Append(wxEmptyString);
    I_Adv_ChoiceMonth->Append(_("Jan"));
    I_Adv_ChoiceMonth->Append(_("Feb"));
    I_Adv_ChoiceMonth->Append(_("Mar"));
    I_Adv_ChoiceMonth->Append(_("Apr"));
    I_Adv_ChoiceMonth->Append(_("May"));
    I_Adv_ChoiceMonth->Append(_("Jun"));
    I_Adv_ChoiceMonth->Append(_("Jul"));
    I_Adv_ChoiceMonth->Append(_("Aug"));
    I_Adv_ChoiceMonth->Append(_("Sep"));
    I_Adv_ChoiceMonth->Append(_("Oct"));
    I_Adv_ChoiceMonth->Append(_("Nov"));
    I_Adv_ChoiceMonth->Append(_("Dec"));
    I_Adv_ChoiceMonth->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceMonth->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceYear = new wxChoice(I_PanelAdvSearch, ID_CHOICE3, wxPoint(180,210), wxSize(90,30), 0, 0, wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE3"));
    I_Adv_ChoiceYear->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceYear->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceDayTo = new wxChoice(I_PanelAdvSearch, ID_CHOICE4, wxPoint(25,305), wxSize(60,30), 0, 0, wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE4"));
    I_Adv_ChoiceDayTo->Append(wxEmptyString);
    I_Adv_ChoiceDayTo->Append(_("01"));
    I_Adv_ChoiceDayTo->Append(_("02"));
    I_Adv_ChoiceDayTo->Append(_("03"));
    I_Adv_ChoiceDayTo->Append(_("04"));
    I_Adv_ChoiceDayTo->Append(_("05"));
    I_Adv_ChoiceDayTo->Append(_("06"));
    I_Adv_ChoiceDayTo->Append(_("07"));
    I_Adv_ChoiceDayTo->Append(_("08"));
    I_Adv_ChoiceDayTo->Append(_("09"));
    I_Adv_ChoiceDayTo->Append(_("10"));
    I_Adv_ChoiceDayTo->Append(_("11"));
    I_Adv_ChoiceDayTo->Append(_("12"));
    I_Adv_ChoiceDayTo->Append(_("13"));
    I_Adv_ChoiceDayTo->Append(_("14"));
    I_Adv_ChoiceDayTo->Append(_("15"));
    I_Adv_ChoiceDayTo->Append(_("16"));
    I_Adv_ChoiceDayTo->Append(_("17"));
    I_Adv_ChoiceDayTo->Append(_("18"));
    I_Adv_ChoiceDayTo->Append(_("19"));
    I_Adv_ChoiceDayTo->Append(_("20"));
    I_Adv_ChoiceDayTo->Append(_("21"));
    I_Adv_ChoiceDayTo->Append(_("22"));
    I_Adv_ChoiceDayTo->Append(_("23"));
    I_Adv_ChoiceDayTo->Append(_("24"));
    I_Adv_ChoiceDayTo->Append(_("25"));
    I_Adv_ChoiceDayTo->Append(_("26"));
    I_Adv_ChoiceDayTo->Append(_("27"));
    I_Adv_ChoiceDayTo->Append(_("28"));
    I_Adv_ChoiceDayTo->Append(_("29"));
    I_Adv_ChoiceDayTo->Append(_("30"));
    I_Adv_ChoiceDayTo->Append(_("31"));
    I_Adv_ChoiceDayTo->Disable();
    I_Adv_ChoiceDayTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceDayTo->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceMonthTo = new wxChoice(I_PanelAdvSearch, ID_CHOICE5, wxPoint(100,305), wxSize(60,30), 0, 0, wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE5"));
    I_Adv_ChoiceMonthTo->Append(wxEmptyString);
    I_Adv_ChoiceMonthTo->Append(_("Jan"));
    I_Adv_ChoiceMonthTo->Append(_("Feb"));
    I_Adv_ChoiceMonthTo->Append(_("Mar"));
    I_Adv_ChoiceMonthTo->Append(_("Apr"));
    I_Adv_ChoiceMonthTo->Append(_("May"));
    I_Adv_ChoiceMonthTo->Append(_("Jun"));
    I_Adv_ChoiceMonthTo->Append(_("Jul"));
    I_Adv_ChoiceMonthTo->Append(_("Aug"));
    I_Adv_ChoiceMonthTo->Append(_("Sep"));
    I_Adv_ChoiceMonthTo->Append(_("Oct"));
    I_Adv_ChoiceMonthTo->Append(_("Nov"));
    I_Adv_ChoiceMonthTo->Append(_("Dec"));
    I_Adv_ChoiceMonthTo->Disable();
    I_Adv_ChoiceMonthTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceMonthTo->SetBackgroundColour(wxColour(230,230,230));
    I_Adv_ChoiceYearTo = new wxChoice(I_PanelAdvSearch, ID_CHOICE6, wxPoint(180,305), wxSize(90,30), 0, 0, wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_CHOICE6"));
    I_Adv_ChoiceYearTo->Disable();
    I_Adv_ChoiceYearTo->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    I_Adv_ChoiceYearTo->SetBackgroundColour(wxColour(230,230,230));
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Wszystkie"),
    	_("RE"),
    	_("FWD")
    };
    I_Adv_RadioBoxType = new wxRadioBox(I_PanelAdvSearch, ID_RADIOBOX1, _("         Typ"), wxPoint(15,350), wxDefaultSize, 3, __wxRadioBoxChoices_1, 3, wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_RADIOBOX1"));
    I_Adv_RadioBoxType->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    I_Adv_RadioBoxType->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    wxFont I_Adv_RadioBoxTypeFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_Adv_RadioBoxType->SetFont(I_Adv_RadioBoxTypeFont);
    I_Adv_CheckBoxDate = new wxCheckBox(I_PanelAdvSearch, ID_CHECKBOX4, _("Wyszukiwanie \'Od Do\'"), wxPoint(50,245), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    I_Adv_CheckBoxDate->SetValue(false);
    I_Adv_CheckBoxDate->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    I_Adv_CheckBoxDate->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    I_Adv_LabelSearch = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT149, _("Szukaj"), wxPoint(235,432), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT149"));
    I_Adv_LabelSearch->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont I_Adv_LabelSearchFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    I_Adv_LabelSearch->SetFont(I_Adv_LabelSearchFont);
    StaticText1 = new wxStaticText(I_PanelAdvSearch, ID_STATICTEXT140, _("Wyczyść pola"), wxPoint(123,432), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT140"));
    StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont StaticText1Font(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    I_Adv_ImageButtonSearch = new wxBitmapButton(I_PanelAdvSearch, ID_IMAGEBUTTON63, wxNullBitmap, wxPoint(225,370), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON63"));
    I_Adv_ImageButtonReset = new wxBitmapButton(I_PanelAdvSearch, ID_IMAGEBUTTON68, wxNullBitmap, wxPoint(135,370), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON68"));
    PanelNotify = new wxPanel(PanelMain, ID_PANEL11, wxPoint(10,10), wxSize(350,120), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    PanelNotify->Hide();
    PanelNotify->SetBackgroundColour(wxColour(48,48,48));
    N_Border = new wxStaticBox(PanelNotify, ID_STATICBOX6, wxEmptyString, wxPoint(0,-10), wxSize(350,130), 0, _T("ID_STATICBOX6"));
    N_Border->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    N_StaticTextTitle = new wxStaticText(PanelNotify, ID_STATICTEXT78, _("Zakończono wczytywanie"), wxPoint(10,10), wxDefaultSize, 0, _T("ID_STATICTEXT78"));
    N_StaticTextTitle->SetForegroundColour(wxColour(255,255,255));
    wxFont N_StaticTextTitleFont(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    N_StaticTextTitle->SetFont(N_StaticTextTitleFont);
    N_StaticTextOption1 = new wxStaticText(PanelNotify, ID_STATICTEXT79, _("Wczytano poprawnie:"), wxPoint(10,35), wxDefaultSize, 0, _T("ID_STATICTEXT79"));
    N_StaticTextOption1->SetForegroundColour(wxColour(192,192,192));
    wxFont N_StaticTextOption1Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    N_StaticTextOption1->SetFont(N_StaticTextOption1Font);
    N_StaticTextOption2 = new wxStaticText(PanelNotify, ID_STATICTEXT80, _("Emaile niepoprawne:"), wxPoint(10,60), wxDefaultSize, 0, _T("ID_STATICTEXT80"));
    N_StaticTextOption2->SetForegroundColour(wxColour(192,192,192));
    wxFont N_StaticTextOption2Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    N_StaticTextOption2->SetFont(N_StaticTextOption2Font);
    N_StaticTextOption3 = new wxStaticText(PanelNotify, ID_STATICTEXT129, _("Emaile powtórzone:"), wxPoint(10,85), wxDefaultSize, 0, _T("ID_STATICTEXT129"));
    N_StaticTextOption3->SetForegroundColour(wxColour(192,192,192));
    wxFont N_StaticTextOption3Font(12,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    N_StaticTextOption3->SetFont(N_StaticTextOption3Font);
    N_StaticTextValue1 = new wxStaticText(PanelNotify, ID_STATICTEXT83, _("0"), wxPoint(270,35), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT83"));
    N_StaticTextValue1->SetForegroundColour(wxColour(16,178,31));
    N_StaticTextValue2 = new wxStaticText(PanelNotify, ID_STATICTEXT82, _("0"), wxPoint(270,60), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT82"));
    N_StaticTextValue2->SetForegroundColour(wxColour(255,18,0));
    N_StaticTextValue3 = new wxStaticText(PanelNotify, ID_STATICTEXT130, _("0"), wxPoint(270,85), wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT130"));
    N_StaticTextValue3->SetForegroundColour(wxColour(123,75,254));
    PanelSettings = new wxPanel(PanelMain, ID_PANEL10, wxPoint(860,20), wxSize(300,185), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    PanelSettings->Hide();
    PanelSettings->SetBackgroundColour(wxColour(50,50,50));
    Set_Border = new wxStaticBox(PanelSettings, ID_STATICBOX5, wxEmptyString, wxPoint(0,-10), wxSize(300,195), 0, _T("ID_STATICBOX5"));
    Set_Border->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Set_CheckBoxRecursive = new wxCheckBox(PanelSettings, ID_CHECKBOX1, _("Wczytywanie rekursywne folderów"), wxPoint(10,10), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    Set_CheckBoxRecursive->SetValue(false);
    Set_CheckBoxRecursive->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Set_CheckBoxRecursive->SetBackgroundColour(wxColour(160,160,160));
    wxFont Set_CheckBoxRecursiveFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Set_CheckBoxRecursive->SetFont(Set_CheckBoxRecursiveFont);
    Set_CheckBoxDeleteConfirm = new wxCheckBox(PanelSettings, ID_CHECKBOX2, _("Potwierdzenie usuwania"), wxPoint(10,35), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    Set_CheckBoxDeleteConfirm->SetValue(true);
    Set_CheckBoxDeleteConfirm->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Set_CheckBoxDeleteConfirm->SetBackgroundColour(wxColour(160,160,160));
    wxFont Set_CheckBoxDeleteConfirmFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Set_CheckBoxDeleteConfirm->SetFont(Set_CheckBoxDeleteConfirmFont);
    Set_CheckBoxDatabaseEncryption = new wxCheckBox(PanelSettings, ID_CHECKBOX3, _("Szyfrowanie bazy danych"), wxPoint(10,60), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    Set_CheckBoxDatabaseEncryption->SetValue(false);
    Set_CheckBoxDatabaseEncryption->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Set_CheckBoxDatabaseEncryption->SetBackgroundColour(wxColour(160,160,160));
    wxFont Set_CheckBoxDatabaseEncryptionFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Set_CheckBoxDatabaseEncryption->SetFont(Set_CheckBoxDatabaseEncryptionFont);
    Set_SliderNotifyTime = new wxSlider(PanelSettings, ID_SLIDER1, 3, 1, 10, wxPoint(20,110), wxSize(260,50), wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
    Set_SliderNotifyTime->SetLineSize(10);
    Set_SliderNotifyTime->SetThumbLength(10);
    Set_SliderNotifyTime->SetTick(1);
    Set_SliderNotifyTime->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    Set_LabelNotify = new wxStaticText(PanelSettings, ID_STATICTEXT110, _("Czas wyświetlania powiadomień [s]"), wxPoint(30,90), wxDefaultSize, 0, _T("ID_STATICTEXT110"));
    Set_LabelNotify->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    wxFont Set_LabelNotifyFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Set_LabelNotify->SetFont(Set_LabelNotifyFont);
    PanelAdd = new wxPanel(PanelMain, ID_PANEL15, wxPoint(100,100), wxSize(260,110), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    PanelAdd->SetBackgroundColour(wxColour(48,48,48));
    A_Border = new wxStaticBox(PanelAdd, ID_STATICBOX10, wxEmptyString, wxPoint(0,-10), wxSize(260,120), 0, _T("ID_STATICBOX10"));
    A_Border->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    A_ImageButtonFiles = new wxBitmapButton(PanelAdd, ID_IMAGEBUTTON57, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON57"));
    A_ImageButtonFolder = new wxBitmapButton(PanelAdd, ID_IMAGEBUTTON58, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON58"));
    A_ImageButtonBin = new wxBitmapButton(PanelAdd, ID_IMAGEBUTTON59, wxNullBitmap, wxPoint(190,10), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON59"));
    A_LabelFiles = new wxStaticText(PanelAdd, ID_STATICTEXT126, _("Pliki"), wxPoint(23,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT126"));
    A_LabelFiles->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont A_LabelFilesFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    A_LabelFiles->SetFont(A_LabelFilesFont);
    A_LabelFolder = new wxStaticText(PanelAdd, ID_STATICTEXT127, _("Folder"), wxPoint(108,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT127"));
    A_LabelFolder->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont A_LabelFolderFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    A_LabelFolder->SetFont(A_LabelFolderFont);
    A_LabelBin = new wxStaticText(PanelAdd, ID_STATICTEXT128, _("Plik .bin"), wxPoint(194,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT128"));
    A_LabelBin->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont A_LabelBinFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    A_LabelBin->SetFont(A_LabelBinFont);
    PanelSave = new wxPanel(PanelMain, ID_PANEL17, wxPoint(180,100), wxSize(170,110), wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    PanelSave->SetBackgroundColour(wxColour(48,48,48));
    Sav_Border = new wxStaticBox(PanelSave, ID_STATICBOX11, wxEmptyString, wxPoint(0,-10), wxSize(170,120), 0, _T("ID_STATICBOX11"));
    Sav_Border->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    Sav_ImageButtonBin = new wxBitmapButton(PanelSave, ID_IMAGEBUTTON60, wxNullBitmap, wxPoint(10,10), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON60"));
    Sav_ImageButtonTxt = new wxBitmapButton(PanelSave, ID_IMAGEBUTTON61, wxNullBitmap, wxPoint(100,10), wxSize(60,60), wxBU_AUTODRAW|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_IMAGEBUTTON61"));
    Sav_StaticTextBin = new wxStaticText(PanelSave, ID_STATICTEXT131, _("Plik .bin"), wxPoint(14,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT131"));
    Sav_StaticTextBin->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont Sav_StaticTextBinFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Sav_StaticTextBin->SetFont(Sav_StaticTextBinFont);
    Sav_StaticTextTxt = new wxStaticText(PanelSave, ID_STATICTEXT132, _("Plik .txt"), wxPoint(104,75), wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT132"));
    Sav_StaticTextTxt->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont Sav_StaticTextTxtFont(11,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Sav_StaticTextTxt->SetFont(Sav_StaticTextTxtFont);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, idMenuNew, _("New\tCTRL+N"), _("Creates an empty database"), wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    Menu1->AppendSeparator();
    MenuItemOpen = new wxMenuItem(Menu1, idMenuOpen, _("Open files\tCTRL+O"), _("Open file/s"), wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemOpenFolder = new wxMenuItem(Menu1, idMenuOpenFolder, _("Open folder\tCTRL+SHIFT+O"), _("Open all files in a folder"), wxITEM_NORMAL);
    Menu1->Append(MenuItemOpenFolder);
    Menu1->AppendSeparator();
    MenuItemSave = new wxMenuItem(Menu1, idMenuSave, _("Save\tCTRL+S"), _("Save your work"), wxITEM_NORMAL);
    Menu1->Append(MenuItemSave);
    Menu1->AppendSeparator();
    MenuItemQuit = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItemQuit);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItemImportBin = new wxMenuItem(Menu2, idMenuImportBin, _("Import from binary"), _("Load database from a binary file"), wxITEM_NORMAL);
    Menu2->Append(MenuItemImportBin);
    Menu2->AppendSeparator();
    MenuItemExportBin = new wxMenuItem(Menu2, idMenuExportBin, _("Export to bin"), _("Stores databse in a binary file"), wxITEM_NORMAL);
    Menu2->Append(MenuItemExportBin);
    MenuItemExportTxt = new wxMenuItem(Menu2, idMenuExportText, _("Export to text"), _("Copy database to a text file"), wxITEM_NORMAL);
    Menu2->Append(MenuItemExportTxt);
    MenuBar1->Append(Menu2, _("&Import/Export"));
    Menu3 = new wxMenu();
    MenuItemRecursive = new wxMenuItem(Menu3, idMenuRecursive, _("Recursive loading\tCTRL+SHIFT+R"), _("On/off recursive folder loading"), wxITEM_CHECK);
    Menu3->Append(MenuItemRecursive);
    MenuItemConfirm = new wxMenuItem(Menu3, idMenuDelConfirm, _("Delete confirmation\tCTRL+SHIFT+C"), _("On/off confirmation prompt when trying to delete a record"), wxITEM_CHECK);
    Menu3->Append(MenuItemConfirm);
    MenuItemConfirm->Check(true);
    MenuItemEncryption = new wxMenuItem(Menu3, idMenuDatabaseEncryption, _("Database encryption\tCTRL+SHIFT+E"), _("On/off database encyption"), wxITEM_CHECK);
    Menu3->Append(MenuItemEncryption);
    MenuItem4 = new wxMenu();
    MenuItemNTimeShort = new wxMenuItem(MenuItem4, isMenuNTimeShort, _("Short (2s)"), wxEmptyString, wxITEM_RADIO);
    MenuItem4->Append(MenuItemNTimeShort);
    MenuItemNTimeNormal = new wxMenuItem(MenuItem4, isMenuNTimeNormal, _("Normal (5s)"), wxEmptyString, wxITEM_RADIO);
    MenuItem4->Append(MenuItemNTimeNormal);
    MenuItemNTimeLong = new wxMenuItem(MenuItem4, isMenuNTimeLong, _("Long (8s)"), wxEmptyString, wxITEM_RADIO);
    MenuItem4->Append(MenuItemNTimeLong);
    Menu3->Append(ID_MENUITEM1, _("Notification time"), MenuItem4, wxEmptyString);
    MenuBar1->Append(Menu3, _("Properties"));
    Menu4 = new wxMenu();
    MenuItemAbout = new wxMenuItem(Menu4, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu4->Append(MenuItemAbout);
    MenuItemHelp = new wxMenuItem(Menu4, idMenuHelp, _("Help\tF2"), _("General application manual"), wxITEM_NORMAL);
    Menu4->Append(MenuItemHelp);
    MenuBar1->Append(Menu4, _("Help"));
    SetMenuBar(MenuBar1);
    DirDialog = new wxDirDialog(this, _("Wybierz folder"), _("./"), wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FileDialog = new wxFileDialog(this, _("Wybierz pliki:"), _("~/"), wxEmptyString, _("*.eml"), wxFD_OPEN|wxFD_MULTIPLE|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Timer1.SetOwner(this, ID_TIMER1);
    FileDialogDatabaseImport = new wxFileDialog(this, _("Wybierz plik:"), _("~/"), wxEmptyString, _("*.bin"), wxFD_OPEN|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialogDatabaseExport = new wxFileDialog(this, _("Zapisz plik:"), _("./"), wxEmptyString, _("*.bin"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialogStatisticsExport = new wxFileDialog(this, _("Zapisz plik:"), _("./"), wxEmptyString, _("*.txt"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    PasswordEntryDialog = new wxPasswordEntryDialog(this, _("Wpisz hasło [x-y znaków, a-z, A-Z, 0-9]"), _("Hasło do szyfracji bazy danych"), wxEmptyString, wxCANCEL|wxCENTRE|wxOK, wxDefaultPosition);
    MessageDialogConfirmation = new wxMessageDialog(this, _("Dotychczasowe dane zostaną utracone. Czy chcesz kontynuować\?"), _("Potwierdzenie nadpisania bazy"), wxCANCEL|wxYES_NO|wxNO_DEFAULT|wxICON_EXCLAMATION, wxDefaultPosition);
    Center();

    Connect(ID_IMAGEBUTTON37,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonMulTreeClick);
    Connect(ID_IMAGEBUTTON36,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonStatsClick);
    Connect(ID_IMAGEBUTTON35,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonGroupsClick);
    Connect(ID_IMAGEBUTTON34,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON33,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON32,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON56,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonSwitchClick);
    Connect(ID_IMAGEBUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonBinClick);
    Connect(ID_IMAGEBUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonTxtClick);
    Connect(ID_IMAGEBUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFolderClick);
    Connect(ID_IMAGEBUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFilesClick);
    Connect(ID_IMAGEBUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonLoadClick);
    Connect(ID_IMAGEBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonImportClick);
    Connect(ID_IMAGEBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonAddClick);
    Connect(ID_IMAGEBUTTON66,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON46,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON45,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON44,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonGroupsClick);
    Connect(ID_IMAGEBUTTON43,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonStatsClick);
    Connect(ID_IMAGEBUTTON40,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnM_ImageButtonTitleClick);
    Connect(ID_IMAGEBUTTON54,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonMulTreeClick);
    Connect(ID_IMAGEBUTTON53,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonGroupsClick);
    Connect(ID_IMAGEBUTTON52,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON51,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON67,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON62,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonSaveStatsClick);
    Connect(ID_IMAGEBUTTON55,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonRefreshClick);
    Connect(ID_IMAGEBUTTON42,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_ImageButtonTitleClick);
    S_PanelEmailPerMonth->Connect(wxEVT_PAINT,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_PanelEmailPerMonthPaint,0,this);
    Connect(ID_HYPERLINKCTRL1,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL2,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL3,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL4,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL5,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL6,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL7,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL8,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL9,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_HYPERLINKCTRL10,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click);
    Connect(ID_IMAGEBUTTON65,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON50,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonMulTreeClick);
    Connect(ID_IMAGEBUTTON49,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonStatsClick);
    Connect(ID_IMAGEBUTTON48,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON47,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON41,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ImageButtonTitleClick);
    Connect(ID_LISTCTRL5,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnG_ListGroupsItemSelect);
    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListUsembersItemSelect);
    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListUsembersColumnClick);
    Connect(ID_LISTCTRL4,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListOutboxItemSelect);
    Connect(ID_LISTCTRL4,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListOutboxColumnClick);
    Connect(ID_LISTCTRL3,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListInboxItemSelect);
    Connect(ID_LISTCTRL3,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ListInboxColumnClick);
    Connect(ID_IMAGEBUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSwitchListClick);
    Connect(ID_IMAGEBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSwitchContentClick);
    Connect(ID_IMAGEBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonShowGroupClick);
    Connect(ID_IMAGEBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonDeleteClick);
    Connect(ID_IMAGEBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonMulTreeClick);
    Connect(ID_IMAGEBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonStatsClick);
    Connect(ID_IMAGEBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonGroupsClick);
    Connect(ID_IMAGEBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonInboxClick);
    Connect(ID_IMAGEBUTTON31,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSearchClick);
    Connect(ID_IMAGEBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonSaveClick);
    Connect(ID_IMAGEBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonAddClick);
    Connect(ID_IMAGEBUTTON39,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_ImageButtonTitleClick);
    Connect(ID_SEARCHCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&AisdiRelationsFrame::OnU_SearchCtrlTextEnter);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ListInboxItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ListInboxColumnClick);
    Connect(ID_IMAGEBUTTON29,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonShowTreeClick);
    Connect(ID_IMAGEBUTTON28,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonReceiverClick);
    Connect(ID_IMAGEBUTTON27,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonSenderClick);
    Connect(ID_IMAGEBUTTON26,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonDeleteClick);
    Connect(ID_IMAGEBUTTON25,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonMulTreeClick);
    Connect(ID_IMAGEBUTTON24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonStatsClick);
    Connect(ID_IMAGEBUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonGroupsClick);
    Connect(ID_IMAGEBUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonUsembersClick);
    Connect(ID_IMAGEBUTTON30,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonSettingsClick);
    Connect(ID_IMAGEBUTTON64,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonRestoreClick);
    Connect(ID_IMAGEBUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonSearchClick);
    Connect(ID_IMAGEBUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonSaveClick);
    Connect(ID_IMAGEBUTTON38,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonTitleClick);
    Connect(ID_IMAGEBUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_ImageButtonAddClick);
    Connect(ID_SEARCHCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_SearchCtrlTextEnter);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_ImageButtonSearchClick);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_ImageButtonSearchClick);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_ImageButtonSearchClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_CheckBoxDateClick);
    Connect(ID_IMAGEBUTTON63,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_ImageButtonSearchClick);
    Connect(ID_IMAGEBUTTON68,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnI_Adv_ImageButtonResetClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_CheckBoxRecursiveClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnSet_CheckBoxDeleteConfirmClick);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnSet_CheckBoxDatabaseEncryptionClick);
    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&AisdiRelationsFrame::OnSet_SliderNotifyTimeCmdScrollChanged);
    Connect(ID_IMAGEBUTTON57,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFilesClick);
    Connect(ID_IMAGEBUTTON58,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFolderClick);
    Connect(ID_IMAGEBUTTON59,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonBinClick);
    Connect(ID_IMAGEBUTTON60,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonTxtClick);
    Connect(ID_IMAGEBUTTON61,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AisdiRelationsFrame::OnSav_ImageButtonTxtClick);
    Connect(idMenuNew,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemNewSelected);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFilesClick);
    Connect(idMenuOpenFolder,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonFolderClick);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemSaveSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnQuit);
    Connect(idMenuImportBin,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonBinClick);
    Connect(idMenuExportBin,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnT_ImageButtonTxtClick);
    Connect(idMenuExportText,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnSav_ImageButtonTxtClick);
    Connect(idMenuRecursive,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemRecursiveSelected);
    Connect(idMenuDelConfirm,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemConfirmSelected);
    Connect(idMenuDatabaseEncryption,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemEncryptionSelected);
    Connect(isMenuNTimeShort,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemNTimeShortSelected);
    Connect(isMenuNTimeNormal,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemNTimeNormalSelected);
    Connect(isMenuNTimeLong,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemNTimeLongSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnAbout);
    Connect(idMenuHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AisdiRelationsFrame::OnMenuItemHelpSelected);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&AisdiRelationsFrame::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&AisdiRelationsFrame::OnClose);
    //*)

    /** Alokacja pamięci dla obiektów zarządzających panelami */
    P_Title = new PanelTitleMaintance();
    P_Groups = new PanelGroupsMaintance();
    P_Inbox = new PanelInboxMaintance();
    P_MulTree = new PanelMulTreeMaintance();
    P_Stats = new PanelStatisticsMaintance();
    P_Usembers = new PanelUsembersMaintance();
    P_Notify = new PanelNotifyMaintance();

    /** Alokacja głównych obiektów programu dla zarządania mailami i usemberami */
    database = new Database();
    iointerface = new IOInterface();
    iointerface->setDatabasePointer(database);
    statistics = new Statistics(database);

    ShowTitle();
}

/** PODSTAWOWE FUNKCJE PROGRAMU */

void AisdiRelationsFrame::ShowTitle (void )
{
    P_Title->SetIcons(this);                //inicjalizacja ikon oraz etykiet w panelach
    P_Usembers->SetLabels(this);
    P_Usembers->SetIcons(this);
    P_Usembers->ClearUsemberInfo(this);
    P_Usembers->SetEmails(this, -1);
    P_Usembers->SetUsembers(this);
    P_Inbox->SetIcons(this);
    P_Inbox->SetLabels(this);
    P_Groups->SetIcons(this);
    P_Groups->SetLabels(this);
    P_Groups->SetGroups(this);
    P_Stats->SetIcons(this);
    P_MulTree->SetIcons(this);
    PanelNotify->Hide();
    PanelAdd->Hide();
    PanelSave->Hide();
    PanelSettings->Hide();

    if (! P_MulTree->GetPanelEnabled())     //wyłączenie funkcjonowania panelu Multicast Tree
    {
        T_ImageButtonMulTree->Disable();
        I_ImageButtonMulTree->Disable();
        I_ImageButtonShowTree->Disable();
        U_ImageButtonMulTree->Disable();
        S_ImageButtonMulTree->Disable();
        G_ImageButtonMulTree->Disable();
    }

    if (! P_Stats->GetPanelEnabled())       //wyłączenie funcjonowania panelu Statistics
    {
        T_ImageButtonStats->Disable();
        I_ImageButtonStats->Disable();
        U_ImageButtonStats->Disable();
        U_ImageButtonSwitchContent->Disable();
        G_ImageButtonStats->Disable();
        M_ImageButtonStats->Disable();
    }

    if (! P_Groups->GetPanelEnabled())       //wyłączenie funcjonowania panelu Groups
    {
        T_ImageButtonGroups->Disable();
        I_ImageButtonGroups->Disable();
        U_ImageButtonGroups->Disable();
        U_ImageButtonShowGroup->Disable();
        S_ImageButtonGroups->Disable();
        M_ImageButtonGroups->Disable();
    }

    if (! this->settingsEnabled)
    {
        T_ImageButtonSettings->Disable();
        I_ImageButtonSettings->Disable();
        U_ImageButtonSettings->Disable();
        S_ImageButtonSettings->Disable();
        M_ImageButtonSettings->Disable();
        G_ImageButtonSettings->Disable();
    }

    /** Sprawdź, czy nie istnieje plik tymczasowego zapisu */
    char* tempFIle = (char*)"sav_tmp.bin";
    if (ifstream(tempFIle))
        P_Title->LoadAutoSave(this);

    P_Title->ShowPanel(this);
    P_Title->SwitchIcons(this);
}

int AisdiRelationsFrame::GetNotifyTime(void)
{
    return notifyTime;
}

AisdiRelationsFrame::~AisdiRelationsFrame()
{
    //(*Destroy(AisdiRelationsFrame)
    //*)
}

void AisdiRelationsFrame::OnQuit(wxCommandEvent& event)
{
    P_Title->DeleteAutoSave(this);

    /** Zwolnienie pamięci obiektów obsługujących panele */
    delete (P_Groups);
    delete (P_Inbox);
    delete (P_MulTree);
    delete (P_Stats);
    delete (P_Title);
    delete (P_Usembers);
    delete (P_Notify);

    /** Zwolnienie obiektów klas projektu */
    delete iointerface;
    delete statistics;
    delete database;
    delete relations;

    Close();
}

void AisdiRelationsFrame::OnClose(wxCloseEvent& event)
{
    P_Title->DeleteAutoSave(this);

    /** Zwolnienie pamięci obiektów obsługujących panele */
    delete (P_Inbox);
    delete (P_MulTree);
    delete (P_Stats);
    delete (P_Title);
    delete (P_Usembers);
    delete (P_Notify);
    delete (P_Groups);

    /** Zwolnienie obiektów klas projektu */
    delete iointerface;
    delete statistics;
    delete database;
    if (relations != nullptr)
        delete relations;

    Close();
}

/** Informacje o autorach i wersji aplikacji */
void AisdiRelationsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = _("Autorzy:\n  Maciej Gańko\n  Paweł Kaczyński\n  Krzysztof Lisocki\n  Patryk Łucka\n  Jakub Maleszewski\n  Maciej Safarzyński\n  Michał Żołyniak\n\n");
    msg += _("---------------------------------------------------\nVersion:  1.9.2");
    wxMessageBox(msg, _("About"));
}


/** ============= Eventy panelu TITLE ============= */
void AisdiRelationsFrame::OnT_ImageButtonAddClick(wxCommandEvent& event)
{
    P_Title->EventButtonAddClick(this);
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

void AisdiRelationsFrame::OnT_ImageButtonFolderClick(wxCommandEvent& event)
{
    P_Title->EventButtonFolderClick(this);
}

void AisdiRelationsFrame::OnT_ImageButtonFilesClick(wxCommandEvent& event)
{
    P_Title->EventButtonFilesClick(this);
}

void AisdiRelationsFrame::OnT_ImageButtonMulTreeClick(wxCommandEvent& event)
{
    P_MulTree->ShowPanel(this);
}

void AisdiRelationsFrame::OnT_ImageButtonStatsClick(wxCommandEvent& event)
{
    P_Stats->ShowPanel(this);
}

void AisdiRelationsFrame::OnT_ImageButtonGroupsClick(wxCommandEvent& event)
{
    P_Groups->ShowPanel(this);
}

void AisdiRelationsFrame::OnT_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_Title->EventButtonSettingsClick(this);
}

void AisdiRelationsFrame::OnT_ImageButtonTxtClick(wxCommandEvent& event)
{
    P_Title->EventButtonTxtClick(this);         //Tak naprawdę to jest zapis bazy do pliku bin, ale za dużo zamieszania z zamianą
}

void AisdiRelationsFrame::OnT_ImageButtonBinClick(wxCommandEvent& event)
{
    P_Title->EventButtonBinClick(this);
}

void AisdiRelationsFrame::OnT_ImageButtonSwitchClick(wxCommandEvent& event)
{
    P_Title->EventButtonSwitchClick(this);
}

void AisdiRelationsFrame::OnT_CheckBoxRecursiveClick(wxCommandEvent& event)
{
    P_Title->SetRecursiveLoad(Set_CheckBoxRecursive->GetValue());
    if (MenuItemRecursive->IsCheckable())
        MenuItemRecursive->Check(Set_CheckBoxRecursive->GetValue());
}

/** ============= Eventy panelu INBOX ============= */
void AisdiRelationsFrame::OnI_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonAddClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonAddClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonSaveClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonSaveClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonSearchClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonSearchClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonSettingsClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonMulTreeClick(wxCommandEvent& event)
{
    P_MulTree->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonStatsClick(wxCommandEvent& event)
{
    P_Stats->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonGroupsClick(wxCommandEvent& event)
{
    P_Groups->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnI_ImageButtonDeleteClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonDeleteClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonSenderClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonSenderClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonReceiverClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonReceiverClick(this);
}

void AisdiRelationsFrame::OnI_ImageButtonShowTreeClick(wxCommandEvent& event)
{
    P_Inbox->EventButtonShowTreeClick(this);
}

void AisdiRelationsFrame::OnI_ListInboxItemSelect(wxListEvent& event)
{
    P_Inbox->EventListInboxItemSelect(this);    //TODO w funkcji dodać sprawdzenie, czy w ogóle jakieś maile są
}

void AisdiRelationsFrame::OnI_SearchCtrlTextEnter(wxCommandEvent& event)
{
    P_Inbox->Search(this);
}

void AisdiRelationsFrame::OnI_ListInboxColumnClick(wxListEvent& event)
{
    P_Inbox->EventListInboxColumnClick(this);
}

/** ============= Eventy panelu USEMBERS ============= */
void AisdiRelationsFrame::OnU_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonAddClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonAddClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonSaveClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonSaveClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonSearchClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonSearchClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonSettingsClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonSwitchListClick(wxCommandEvent& event)
{
    P_Usembers->SwitchList(this);
}

void AisdiRelationsFrame::OnU_ImageButtonMulTreeClick(wxCommandEvent& event)
{
    P_MulTree->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonStatsClick(wxCommandEvent& event)
{
    P_Stats->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonGroupsClick(wxCommandEvent& event)
{
    P_Groups->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnU_ImageButtonDeleteClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonDeleteClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonShowGroupClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonShowGroupClick(this);
}

void AisdiRelationsFrame::OnU_ImageButtonSwitchContentClick(wxCommandEvent& event)
{
    P_Usembers->EventButtonSwitchContentClick(this);
}

void AisdiRelationsFrame::OnU_SearchCtrlTextEnter(wxCommandEvent& event)
{
    P_Usembers->EventSearchCtrlTextEnter(this);
}

void AisdiRelationsFrame::OnU_ListUsembersItemSelect(wxListEvent& event)
{
    P_Usembers->EventListUsembersItemSelect(this);
}

void AisdiRelationsFrame::OnU_ListUsembersColumnClick(wxListEvent& event)
{
    P_Usembers->EventListUsembersColumnClick(this);
}

void AisdiRelationsFrame::OnU_ListOutboxItemSelect(wxListEvent& event)
{
    P_Usembers->EventListOutboxItemSelect(this);
}

void AisdiRelationsFrame::OnU_ListOutboxColumnClick(wxListEvent& event)
{
    P_Usembers->EventListOutboxColumnClick(this);
}

void AisdiRelationsFrame::OnU_ListInboxItemSelect(wxListEvent& event)
{
    P_Usembers->EventListInboxItemSelect(this);
}

void AisdiRelationsFrame::OnU_ListInboxColumnClick(wxListEvent& event)
{
    P_Usembers->EventListInboxColumnClick(this);
}


/** ============= Eventy panelu GROUPS ============= */

void AisdiRelationsFrame::OnG_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnG_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnG_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnG_ImageButtonStatsClick(wxCommandEvent& event)
{
    P_Stats->ShowPanel(this);
}

void AisdiRelationsFrame::OnG_ImageButtonMulTreeClick(wxCommandEvent& event)
{
    P_MulTree->ShowPanel(this);
}

void AisdiRelationsFrame::OnG_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_Groups->EventButtonSettingsClick(this);
}


/** ============= Eventy panelu STATS ============= */

void AisdiRelationsFrame::OnS_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnS_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnS_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnS_ImageButtonGroupsClick(wxCommandEvent& event)
{
    P_Groups->ShowPanel(this);
}

void AisdiRelationsFrame::OnS_ImageButtonMulTreeClick(wxCommandEvent& event)
{
    P_MulTree->ShowPanel(this);
}

void AisdiRelationsFrame::OnS_PanelEmailPerMonthPaint(wxPaintEvent& event)
{
    P_Stats->EventPanelEmailPerMonthPaint(this);
}

void AisdiRelationsFrame::OnS_HyperLinkT_SendersPos1Click(wxCommandEvent& event)
{
    long idCurrent = event.GetId();
    long idMain = AisdiRelationsFrame::ID_HYPERLINKCTRL1;
    P_Stats->EventHyperLinkClick(this, idCurrent - idMain);
}

void AisdiRelationsFrame::OnS_ImageButtonRefreshClick(wxCommandEvent& event)
{
    P_Stats->EventButtonRefreshClick(this);
}

void AisdiRelationsFrame::OnS_ImageButtonSaveStatsClick(wxCommandEvent& event)
{
    P_Stats->EventButtonSaveStatsClick(this);
}

void AisdiRelationsFrame::OnS_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_Stats->EventButtonSettingsClick(this);
}


/** ============= Eventy panelu MULTREE ============= */

void AisdiRelationsFrame::OnM_ImageButtonTitleClick(wxCommandEvent& event)
{
    P_Title->ShowPanel(this);
}

void AisdiRelationsFrame::OnM_ImageButtonStatsClick(wxCommandEvent& event)
{
    P_Stats->ShowPanel(this);
}

void AisdiRelationsFrame::OnM_ImageButtonGroupsClick(wxCommandEvent& event)
{
    P_Groups->ShowPanel(this);
}

void AisdiRelationsFrame::OnM_ImageButtonUsembersClick(wxCommandEvent& event)
{
    P_Usembers->ShowPanel(this);
}

void AisdiRelationsFrame::OnM_ImageButtonInboxClick(wxCommandEvent& event)
{
    P_Inbox->ShowPanel(this);
}

void AisdiRelationsFrame::OnM_ImageButtonSettingsClick(wxCommandEvent& event)
{
    P_MulTree->EventButtonSettingsClick(this);
}


/** ============= Event TIMERA ============= */

void AisdiRelationsFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    PanelNotify->Hide();
}


/** ============= Eventy SETTINGS ============= */
void AisdiRelationsFrame::OnSet_SliderNotifyTimeCmdScrollChanged(wxScrollEvent& event)
{
    notifyTime = Set_SliderNotifyTime->GetValue();
}

void AisdiRelationsFrame::OnSet_CheckBoxDeleteConfirmClick(wxCommandEvent& event)
{
    P_Title->SetDeleteConfirm(Set_CheckBoxDeleteConfirm->GetValue());
    if (MenuItemConfirm->IsCheckable())
        MenuItemConfirm->Check(Set_CheckBoxDeleteConfirm->GetValue());
}

void AisdiRelationsFrame::OnSet_CheckBoxDatabaseEncryptionClick(wxCommandEvent& event)
{
    P_Title->SetDatabaseEncryption(Set_CheckBoxDatabaseEncryption->GetValue());
    if (MenuItemEncryption->IsCheckable())
        MenuItemEncryption->Check(Set_CheckBoxDatabaseEncryption->GetValue());
}

/** ============= Event TXT ============= */
void AisdiRelationsFrame::OnSav_ImageButtonTxtClick(wxCommandEvent& event)
{
    //Zapisywanie pliku tekstowego zaimplementowana (bo najszybciej) w panelu Title (jak pozostałe fukncje import/export)
    P_Title->EventButtonSavTxtClick(this);
}

/** ============= Eventy MENU ============= */
void AisdiRelationsFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    P_Title->NewProgramInstance(this);
}

void AisdiRelationsFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    P_Title->AutoSave(this);
}

void AisdiRelationsFrame::OnMenuItemRecursiveSelected(wxCommandEvent& event)
{
    if (MenuItemRecursive->IsCheckable())
        P_Title->SetRecursiveLoad(MenuItemRecursive->IsChecked());
    Set_CheckBoxRecursive->SetValue(MenuItemRecursive->IsChecked());
}

void AisdiRelationsFrame::OnMenuItemConfirmSelected(wxCommandEvent& event)
{
    if (MenuItemConfirm->IsCheckable())
        P_Title->SetDeleteConfirm(MenuItemConfirm->IsChecked());
    Set_CheckBoxDeleteConfirm->SetValue(MenuItemConfirm->IsChecked());
}

void AisdiRelationsFrame::OnMenuItemEncryptionSelected(wxCommandEvent& event)
{
    if (MenuItemEncryption->IsCheckable())
        P_Title->SetDatabaseEncryption(MenuItemEncryption->IsChecked());
    Set_CheckBoxDatabaseEncryption->SetValue(MenuItemEncryption->IsChecked());
}

void AisdiRelationsFrame::OnMenuItemNTimeShortSelected(wxCommandEvent& event)
{
    this->notifyTime = 2;
    Set_SliderNotifyTime->SetValue(notifyTime);
}

void AisdiRelationsFrame::OnMenuItemNTimeNormalSelected(wxCommandEvent& event)
{
    this->notifyTime = 5;
    Set_SliderNotifyTime->SetValue(notifyTime);
}

void AisdiRelationsFrame::OnMenuItemNTimeLongSelected(wxCommandEvent& event)
{
    this->notifyTime = 8;
    Set_SliderNotifyTime->SetValue(notifyTime);
}

void AisdiRelationsFrame::OnMenuItemHelpSelected(wxCommandEvent& event)
{
    //TODO dodać wyświetlanie HELP'a
}

/** ============= Eventy INBOX ADV. SEARCH ============= */
void AisdiRelationsFrame::OnI_Adv_CheckBoxDateClick(wxCommandEvent& event)
{
    P_Inbox->EventCheckBoxDate(this, I_Adv_CheckBoxDate->GetValue());
}

void AisdiRelationsFrame::OnI_Adv_ImageButtonSearchClick(wxCommandEvent& event)
{
    P_Inbox->AdvancedSearch(this);
}

void AisdiRelationsFrame::OnI_ImageButtonRestoreClick(wxCommandEvent& event)
{
    P_Inbox->EventImageButtonRestoreClick(this);
}

void AisdiRelationsFrame::OnI_Adv_ImageButtonResetClick(wxCommandEvent& event)
{
    P_Inbox->ResetSearchField(this);
}

void AisdiRelationsFrame::OnG_ListGroupsItemSelect(wxListEvent& event)
{
}
