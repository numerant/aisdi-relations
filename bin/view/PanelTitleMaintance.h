#pragma once
#include "../AisdiRelationsMain.h"

class PanelTitleMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;       //dostępność panelu
    bool noData = true;                 //czy dane zostały już zaimportowane (wtedy nie pokazuje ikonek dodawania)
    bool clickedAdd = false;                    //dostępność poszczególnych przycisków dodawania danych;
    bool clickedLoad = false;
    bool clickedImport = false;
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Import"),  _("FolderTree"),  _("Files"),  _("Folder"),  _("Bin"),
        _("Txt"),  _("Settings"),  _("Add"),  _("Usember"),  _("Workgroups"),  _("Statistics"),
        _("Tree")
    };                                  //ścieżki plików z grafikami do przycisków panelu

public:
    PanelTitleMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SwitchIcons (AisdiRelationsFrame* Frame);
    void UpdateLoadingIcons (AisdiRelationsFrame* Frame);
    void SetNoData (bool value);
    void SetClickedAdd (void);
    void SetClickedLoad (void);
    void SetClickedImport (void);

    bool GetNoData (void);
    bool GetClickedAdd (void);
    bool GetClickedLoad (void);
    bool GetClickedImport (void);
};
