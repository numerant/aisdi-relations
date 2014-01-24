#pragma once
#include "../AisdiRelationsMain.h"

class PanelUsembersMaintance
{
    friend class AisdiRelationsFrame;

private:
    const static int COL_USEMBERS_COUNT = 3;
    const static int COL_EMAILS_COUNT = 6;
    bool panelEnabled = true;
    bool searchEnabled = false;
    bool addEnabled = false;
    bool saveEnabled = false;
    bool settingsEnabled = false;
    bool usembersListEnabled = true;
    bool emailContentEnabled = false;
    bool customSearch = false;
    string emailIdSelected = "";
    string adressUsemberSelected = "";

    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Mailbox"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("ShowWorkgroup"),  _("SwitchContent"),  _("SwitchList"),
        _("Title")
    };                               //ścieżki plików z grafikami do przycisków panelu

    const wxString months[12] =
    {
    _("Jan"), _("Feb"), _("Mar"), _("Apr"), _("May"), _("Jun"), _("Jul"), _("Aug"), _("Sep"), _("Oct"), _("Nov"), _("Dec")
    };

public:
    PanelUsembersMaintance();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetLabels(AisdiRelationsFrame* Frame);
    void SetUsembers (AisdiRelationsFrame * Frame);
    void SetEmails (AisdiRelationsFrame * Frame, int pos);
    void SwitchList(AisdiRelationsFrame * Frame);
    void SwitchContent(AisdiRelationsFrame * Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void ClearUsemberInfo (AisdiRelationsFrame * Frame);

    void SetSearchEnabled();
    void SetAddEnabled();
    void SetSaveEnabled();
    void SetSettingsEnabled();
    void SetUsembersListEnabled();
    void SetEmailContentEnabled();
    void SetUsemberViewed(AisdiRelationsFrame * Frame, const string usember);

    bool GetSearchEnabled();
    bool GetAddEnabled();
    bool GetSaveEnabled();
    bool GetSettingsEnabled();
    bool GetUsembersListEnabled();
    bool GetEmailContentEnabled();

    void EventButtonSearchClick (AisdiRelationsFrame* Frame);
    void EventButtonAddClick (AisdiRelationsFrame* Frame);
    void EventButtonSaveClick (AisdiRelationsFrame* Frame);
    void EventButtonSettingsClick (AisdiRelationsFrame* Frame);
    void EventButtonShowGroupClick (AisdiRelationsFrame* Frame);
    void EventButtonSwitchContentClick (AisdiRelationsFrame* Frame);
    void EventSearchCtrlTextEnter (AisdiRelationsFrame* Frame);
    void EventListUsembersItemSelect (AisdiRelationsFrame* Frame);
    void EventListUsembersColumnClick (AisdiRelationsFrame* Frame);
    void EventListOutboxItemSelect (AisdiRelationsFrame* Frame);
    void EventListOutboxColumnClick (AisdiRelationsFrame* Frame);
    void EventListInboxItemSelect (AisdiRelationsFrame* Frame);
    void EventListInboxColumnClick (AisdiRelationsFrame* Frame);
    void EventPanelStatsPaint (AisdiRelationsFrame * Frame);
};
