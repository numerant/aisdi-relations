#pragma once
#include "../AisdiRelationsMain.h"

class PanelMulTreeMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    const wxString imagePaths[5] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Statistics")
    };              //ścieżki plików z grafikami do przycisków panelu
                     
public:
    PanelMulTreeMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
