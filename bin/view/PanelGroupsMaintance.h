#pragma once
#include "../AisdiRelationsMain.h"

class PanelGroupsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool settingsEnabled = false;
    
    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString imagePaths[6] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Statistics"),  _("Tree"),
        _("Settings")
    };              //ścieżki plików z grafikami do przycisków panelu
                     
public:
    PanelGroupsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetSettingsEnabled();

    bool GetPanelEnabled ();
    bool GetSettingsEnabled();

    void EventButtonSettingsClick(AisdiRelationsFrame* Frame);
};