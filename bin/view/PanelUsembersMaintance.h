#pragma once
#include "../AisdiRelationsMain.h"

class PanelUsembersMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool usembersListEnabled;
    bool emailContentEnabled;
    const wxString imagePaths[12] =
    {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Mailbox"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("ShowWorkgroup"),  _("SwitchContent"),  _("SwitchList")
    };

public:
    PanelUsembersMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetLabels(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SwitchList(AisdiRelationsFrame * Frame);
    void SwitchContent(AisdiRelationsFrame * Frame);
};
