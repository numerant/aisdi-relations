#pragma once
#include "../AisdiRelationsMain.h"

class PanelTitleMaintance {
    friend class AisdiRelationsFrame;

    private:
        bool panelEnabled = true;
        bool noData;
        const wxString imagePaths[13] = {
        _("Add"),  _("Import"),  _("FolderTree"),  _("Files"),  _("Folder"),  _("Bin"),
        _("Txt"),  _("Settings"),  _("Add"),  _("Usember"),  _("Workgroups"),  _("Statistics"),
        _("Tree")
            };

    public:
        PanelTitleMaintance();
        void ShowPanel(AisdiRelationsFrame* Frame);
        void SetIcons(AisdiRelationsFrame* Frame);
        void SwitchIcons (AisdiRelationsFrame* Frame);
};
