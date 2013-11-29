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
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class AisdiRelationsFrame: public wxFrame
{
    public:

        AisdiRelationsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~AisdiRelationsFrame();

    private:

        //(*Handlers(AisdiRelationsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(AisdiRelationsFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_SEARCHCTRL1;
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
        wxStaticText* MainTitle;
        wxPanel* Panel1;
        wxMenuItem* MenuItem12;
        wxMenu* Menu3;
        wxButton* Button1;
        wxSearchCtrl* SearchCtrl1;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem8;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AISDIRELATIONSMAIN_H
