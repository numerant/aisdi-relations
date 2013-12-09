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
        static const long ID_STATICBITMAP1;
        static const long ID_LISTCTRL1;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICBOX1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICBOX2;
        static const long ID_STATICLINE1;
        static const long ID_HTMLWINDOW1;
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
        wxListCtrl* Inbox;
        wxHtmlWindow* Text;
        wxStaticBitmap* BackgroundImage;
        wxMenuItem* MenuItem12;
        wxPanel* InboxPanel;
        wxMenu* Menu3;
        wxStaticText* StaticTextSubject;
        wxStaticText* StaticTextContent;
        wxStaticLine* LineContentSeparator;
        wxStaticText* LabelSubject;
        wxStaticText* LabelFrom;
        wxBitmap              *Image1_BMP;
        wxStaticText* LabelTo;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItem11;
        wxStaticBox* InboxBorder;
        wxImageList* ImageList1;
        wxMenuItem* MenuItem5;
        wxImage               *Image1;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem4;
        wxStaticText* StaticTextTo;
        wxStaticBox* EmailContentBorder;
        wxStaticText* StaticTextFrom;
        wxMenuItem* MenuItem8;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
