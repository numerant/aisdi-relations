#pragma once
#include "../AisdiRelationsMain.h"
#include <wx/msgdlg.h>
#include "PanelInboxMaintance.h"

class PanelTitleMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;       //dostępność panelu
    bool noData = true;             //czy dane zostały już zaimportowane (wtedy nie pokazuje ikonek dodawania)
    bool recursiveLoad = true;		//wczytywanie rekursywne maili z podanego folderu
    bool clickedAdd = false;            //dostępność poszczególnych przycisków dodawania danych;
    bool clickedLoad = false;
    bool clickedImport = false;
    bool clickedSettings = false;
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Import"),  _("FolderTree"),  _("Files"),  _("Folder"),  _("Bin"),
        _("Txt"),  _("Settings"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Statistics"),
        _("Tree")
    };                                  //ścieżki plików z grafikami do przycisków panelu

public:
    PanelTitleMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SwitchIcons (AisdiRelationsFrame* Frame);
    void UpdateLoadingIcons (AisdiRelationsFrame* Frame);
    void SetNoData (bool value);
    void SetRecursiveLoad (bool value);
    void SetClickedAdd (void);
    void SetClickedLoad (void);
    void SetClickedImport (void);
    void SetClickedSettings (void);

    bool GetNoData (void);
    bool GetRecursiveLoad (void);
    bool GetClickedAdd (void);
    bool GetClickedLoad (void);
    bool GetClickedImport (void);
    bool GetClickedSettings (void);

    void EventButtonAddClick (AisdiRelationsFrame* Frame);
    void EventButtonFolderClick (AisdiRelationsFrame* Frame);
    void EventButtonFilesClick (AisdiRelationsFrame* Frame);
    void EventButtonSettingsClick (AisdiRelationsFrame * Frame);
};
