#pragma once
#include "../AisdiRelationsMain.h"

class PanelTitleMaintance {
    friend class AisdiRelationsFrame;

    private:
        bool noData;
        const wxString imagePaths[8] = {
        _("Add"),  _("Import"),  _("FolderTree"),  _("Files"),  _("Folder"),  _("Bin"),
        _("Txt"),  _("Settings") //,  _("Remove"),  _("Showgroup"),  _("SwitchContent"),  _("SwitchList")
            };

    public:
        PanelTitleMaintance();
        void ShowPanel(AisdiRelationsFrame* Frame);
        void SetIcons(AisdiRelationsFrame* Frame);
};
