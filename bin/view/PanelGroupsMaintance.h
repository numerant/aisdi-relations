#pragma once
#include "../AisdiRelationsMain.h"

class PanelGroupsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    const wxString imagePaths[5] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Statistics"),  _("Tree")
    };              //ścieżki plików z grafikami do przycisków panelu
                     
public:
    PanelGroupsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};