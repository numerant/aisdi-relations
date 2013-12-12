#pragma once
#include "../AisdiRelationsMain.h"

class PanelUsembersMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool searchEnabled = false;
    bool usembersListEnabled = true;
    bool emailContentEnabled = true;
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Mailbox"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("ShowWorkgroup"),  _("SwitchContent"),  _("SwitchList"),
        _("Title")
    };                               //ścieżki plików z grafikami do przycisków panelu

public:
    PanelUsembersMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetLabels(AisdiRelationsFrame* Frame);
    void SwitchList(AisdiRelationsFrame * Frame);
    void SwitchContent(AisdiRelationsFrame * Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetSearchEnabled();

    bool GetSearchEnabled();
};
