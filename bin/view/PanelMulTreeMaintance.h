#pragma once
#include "../AisdiRelationsMain.h"
#include "../../src/MulticastTree.h"

class PanelMulTreeMaintance
{
    friend class AisdiRelationsFrame;

private:
    MulticastTree * tree = nullptr;
    bool panelEnabled = true;
    bool settingsEnabled = false;

    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString imagePaths[6] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Statistics"),
        _("Settings")
    };              //ścieżki plików z grafikami do przycisków panelu
                     
public:
    PanelMulTreeMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetSettingsEnabled();
    void SetTree (Email* emailFWD);

    bool GetPanelEnabled ();
    bool GetSettingsEnabled();

    void EventButtonSettingsClick (AisdiRelationsFrame * Frame);
};
