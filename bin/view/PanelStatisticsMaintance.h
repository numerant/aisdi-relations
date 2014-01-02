#pragma once
#include "../AisdiRelationsMain.h"

class PanelStatisticsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    const wxString imagePaths[5] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Tree")
    };              //ścieżki plików z grafikami do przycisków panelu
                     
public:
    PanelStatisticsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
