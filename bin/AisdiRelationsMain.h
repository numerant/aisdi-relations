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


//(*Headers(AisdiRelationsFrame)
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/image.h>
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

        /** Dopisane metody */
        void  ShowTitle(void);

    private:

        //(*Handlers(AisdiRelationsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(AisdiRelationsFrame)
        static const long ID_STATICBITMAP2;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICLINE2;
        static const long ID_STATICLINE3;
        static const long ID_STATICLINE5;
        static const long ID_STATICLINE4;
        static const long ID_STATICLINE7;
        static const long ID_STATICLINE6;
        static const long ID_PANEL3;
        static const long ID_STATICBITMAP3;
        static const long ID_LISTCTRL2;
        static const long ID_PANEL4;
        static const long ID_STATICBITMAP4;
        static const long ID_PANEL5;
        static const long ID_STATICBITMAP5;
        static const long ID_PANEL6;
        static const long ID_STATICBITMAP6;
        static const long ID_PANEL7;
        static const long ID_STATICBITMAP1;
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
        wxStaticText* I_LabelFrom;
        wxPanel* PanelStatistics;
        wxStaticText* I_StaticTextTo;
        wxListCtrl* U_ListUsembers;
        wxStaticText* I_LabelSubject;
        wxMenuItem* MenuItem12;
        wxStaticText* I_StaticTextDate;
        wxStaticBitmap* BitmapBackgroundGroups;
        wxStaticBitmap* I_BitmapBackground;
        wxPanel* PanelGroups;
        wxMenu* Menu3;
        wxStaticLine* T_StaticLineOpenV;
        wxStaticLine* T_StaticLineImportV;
        wxStaticText* I_LabelTo;
        wxBitmap              *Image1_BMP;
        wxStaticLine* T_StaticLineOpenH;
        wxStaticText* I_StaticTextFrom;
        wxStaticLine* T_StaticLineImportH;
        wxPanel* PanelMain;
        wxMenuItem* MenuItem3;
        wxStaticLine* I_LineContentSeparator;
        wxStaticBitmap* BitmapBackgroundUsembers;
        wxStaticBox* I_EmailContentBorder;
        wxHtmlWindow* I_HtmlEmailContent;
        wxStaticBitmap* BitmapBackgroundTree;
        wxMenuItem* MenuItem9;
        wxStaticBox* I_InboxBorder;
        wxMenuItem* MenuItem11;
        wxPanel* PanelMulTree;
        wxStaticText* I_LabelDate;
        wxListCtrl* I_ListInbox;
        wxImageList* ImageList1;
        wxPanel* PanelInbox;
        wxMenuItem* MenuItem5;
        wxStaticLine* T_StaticLineAddH;
        wxImage               *Image1;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem4;
        wxPanel* PanelTitle;
        wxStaticText* I_StaticTextSubject;
        wxStaticLine* T_StaticLineAddV;
        wxPanel* PanelUsembers;
        wxStaticText* T_StaticTextTitle2;
        wxMenuItem* MenuItem8;
        wxStaticBitmap* BitmapBackgroundStatistics;
        wxStaticText* T_StaticTextTitle1;
        wxStaticText* T_StaticTextTitle3;
        //*)

        PanelTitleMaintance* P_Title;
        DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
