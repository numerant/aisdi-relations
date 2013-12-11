#pragma once
#include "../AisdiRelationsMain.h"

class PanelInboxMaintance {
    friend class AisdiRelationsFrame;

    private:
        bool panelEnabled = true;
        const wxString imagePaths[12] = {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Usember"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("Sender"),  _("Receiver"),  _("ShowTree")
            };

    public:
        PanelInboxMaintance ();
        void ShowPanel(AisdiRelationsFrame* Frame);
        void SetLabels(AisdiRelationsFrame* Frame);
        void SetIcons(AisdiRelationsFrame* Frame);
};
