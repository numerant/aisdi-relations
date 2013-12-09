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
        static const long ID_PANEL3;
        static const long ID_STATICBITMAP3;
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
        wxListCtrl* Inbox;
        wxPanel* PanelStatistics;
        wxHtmlWindow* HtmlEmailContent;
        wxMenuItem* MenuItem12;
        wxStaticBitmap* BitmapBackgroundGroups;
        wxPanel* PanelGroups;
        wxMenu* Menu3;
        wxStaticText* StaticTextSubject;
        wxStaticLine* LineContentSeparator;
        wxStaticText* LabelSubject;
        wxStaticText* LabelFrom;
        wxPanel* PanelTree;
        wxBitmap              *Image1_BMP;
        wxStaticText* LabelTo;
        wxPanel* PanelMain;
        wxMenuItem* MenuItem3;
        wxStaticBitmap* BitmapBackgroundUsembers;
        wxStaticBitmap* BitmapBackgroundTree;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItem11;
        wxStaticBox* InboxBorder;
        wxImageList* ImageList1;
        wxPanel* PanelInbox;
        wxMenuItem* MenuItem5;
        wxImage               *Image1;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem4;
        wxStaticText* StaticTextTo;
        wxPanel* PanelTitle;
        wxStaticBitmap* BitmapBackgroundInbox;
        wxStaticBox* EmailContentBorder;
        wxPanel* PanelUsembers;
        wxStaticText* StaticTextFrom;
        wxMenuItem* MenuItem8;
        wxStaticBitmap* BitmapBackgroundStatistics;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
