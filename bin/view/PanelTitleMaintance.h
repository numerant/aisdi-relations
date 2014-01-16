#pragma once
#include "../AisdiRelationsMain.h"
#include <wx/msgdlg.h>
#include "PanelInboxMaintance.h"
#include "PanelNotifyMaintance.h"
#include "PanelStatisticsMaintance.h"

class PanelTitleMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;       //dostępność panelu
    bool noData = true;             //czy dane zostały już zaimportowane (wtedy nie pokazuje ikonek dodawania)
    bool recursiveLoad = false;		//wczytywanie rekursywne maili z podanego folderu
    bool deleteConfirm = true;      //prośba o potwierdzenie przy usuwaniu
    bool databaseEncryption = false; //szyfrowanie danych bazy przy eksporcie do pliku
    bool clickedAdd = false;            //dostępność poszczególnych przycisków dodawania danych;
    bool clickedLoad = false;
    bool clickedImport = false;
    bool clickedSettings = false;

    wxString pathBig = (_("resources/iconsBig/icon"));
    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString imagePaths[17] =
    {
        _("DatabaseIO"),  _("Database"),  _("FolderTree"),  _("Files"),  _("Folder"),  _("Export"),
        _("Import"),  _("Settings"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Statistics"),
        _("Tree"), _("SwitchMenu"), _("Bin"), _("Txt"), _("Add")
    };                                  //ścieżki plików z grafikami do przycisków panelu

public:
    PanelTitleMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SwitchIcons (AisdiRelationsFrame* Frame);
    void UpdateLoadingIcons (AisdiRelationsFrame* Frame);

    void SetNoData (bool value);
    void SetRecursiveLoad (bool value);
    void SetDeleteConfirm (bool value);
    void SetDatabaseEncryption (bool value);
    void SetClickedAdd (void);
    void SetClickedLoad (void);
    void SetClickedImport (void);
    void SetClickedSettings (void);
    void SetLoadingGaugeValues (int value);

    bool GetNoData (void);
    bool GetRecursiveLoad (void);
    bool GetDeleteConfirm (void);
    bool GetDatabaseEncryption (void);
    bool GetClickedAdd (void);
    bool GetClickedLoad (void);
    bool GetClickedImport (void);
    bool GetClickedSettings (void);

    void EventButtonAddClick (AisdiRelationsFrame* Frame);
    void EventButtonFolderClick (AisdiRelationsFrame* Frame);
    void EventButtonFilesClick (AisdiRelationsFrame* Frame);
    void EventButtonSettingsClick (AisdiRelationsFrame * Frame);
    void EventButtonSwitchClick (AisdiRelationsFrame * Frame);
    void EventButtonTxtClick (AisdiRelationsFrame * Frame);
    void EventButtonSavTxtClick(AisdiRelationsFrame * Frame);
    void EventButtonBinClick (AisdiRelationsFrame* Frame);
};
