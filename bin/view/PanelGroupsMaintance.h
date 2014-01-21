#pragma once
#include "../AisdiRelationsMain.h"
#include <wx/treectrl.h>
#include <vector>

class PanelGroupsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool settingsEnabled = false;
    bool treeEnabled = false;           //TODO sprawdzić czy potrzebne
    wxTreeCtrl * Tree;
    vector <wxTreeItemId> treeNodes;

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
    void DrawGroups (AisdiRelationsFrame * Frame);

    bool GetPanelEnabled ();
    bool GetSettingsEnabled();

    void EventButtonSettingsClick(AisdiRelationsFrame* Frame);
};
