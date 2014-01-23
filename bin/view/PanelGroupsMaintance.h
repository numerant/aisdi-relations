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
    bool relationsConstructed = false;
    int groupSelectedId = -1;
    string usemberSelectedAdress = "";

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
    void SetLabels(AisdiRelationsFrame* Frame);
    void SetGroups (AisdiRelationsFrame * Frame);
    void SetMembers (AisdiRelationsFrame* Frame);
    void SetRelationsConstructed (bool value);
    void SetSettingsEnabled();

    bool GetPanelEnabled ();
    bool GetSettingsEnabled();

    void EventButtonSettingsClick(AisdiRelationsFrame* Frame);
    void EventListGroupsItemSelect(AisdiRelationsFrame* Frame);
};
