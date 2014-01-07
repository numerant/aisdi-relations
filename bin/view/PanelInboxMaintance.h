#pragma once
#include "../AisdiRelationsMain.h"
#include "wx/msgdlg.h"
#include <sstream>

class PanelInboxMaintance
{
    friend class AisdiRelationsFrame;

private:
    const static int COL_COUNT = 6;
    bool panelEnabled = true;
    bool searchEnabled = false;
    bool addEnabled = false;
    bool saveEnabled = false;
    bool settingsEnabled = false;
    string emailIdSelected = "";

    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Usember"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("Sender"),  _("Receiver"),  _("ShowTree"),
        _("Title")
    };                               //ścieżki plików z grafikami do przycisków panelu

public:
    PanelInboxMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetLabels(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetEmails (AisdiRelationsFrame* Frame);
    void SetSearchEnabled();
    void SetAddEnabled();
    void SetSaveEnabled();
    void SetSettingsEnabled();

    bool GetSearchEnabled();
    bool GetAddEnabled();
    bool GetSaveEnabled();
    bool GetSettingsEnabled();

    void EventButtonSearchClick (AisdiRelationsFrame* Frame);
    void EventListInboxItemSelect (AisdiRelationsFrame* Frame);
    void EventButtonAddClick (AisdiRelationsFrame * Frame);
    void EventButtonSaveClick (AisdiRelationsFrame * Frame);
    void EventButtonSettingsClick (AisdiRelationsFrame * Frame);
    void EventButtonDeleteClick (AisdiRelationsFrame * Frame);
    void EventButtonSenderClick (AisdiRelationsFrame * Frame);
    void EventButtonReceiverClick (AisdiRelationsFrame * Frame);
    void EventButtonShowTreeClick (AisdiRelationsFrame * Frame);
    void EventSearchCtrlTextEnter (AisdiRelationsFrame * Frame);
    void EventListInboxColumnClick (AisdiRelationsFrame * Frame);
};
