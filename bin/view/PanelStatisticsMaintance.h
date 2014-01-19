#pragma once
#include "../AisdiRelationsMain.h"
#include "PanelNotifyMaintance.h"
#include "PanelUsembersMaintance.h"
#include <wx/dcclient.h>
#include <wx/msgdlg.h>
#include <iomanip>
#include <sstream>

class PanelStatisticsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool isUpdated = false;
    bool settingsEnabled = false;
    const wxString imagePaths[8] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Tree"), _("Refresh"),
        _("StatisticsSave"), _("Settings")
    };              //ścieżki plików z grafikami do przycisków panelu

    wxString path = (_("resources/icons/icon"));
    wxString format =  (_(".png"));
    wxString formatNeg = (_("Negative.png"));
    const wxString months[12] =
    {
    _("Jan"), _("Feb"), _("Mar"), _("Apr"), _("May"), _("Jun"), _("Jul"), _("Aug"), _("Sep"), _("Oct"), _("Nov"), _("Dec")
    };

public:
    PanelStatisticsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetIsUpdated();
    void SetSettingsEnabled();

    bool GetPanelEnabled ();
    bool GetIsUpdated ();
    bool GetSettingsEnabled();

    void EventPanelEmailPerMonthPaint (AisdiRelationsFrame * Frame);
    void EventPanelCountersPaint (AisdiRelationsFrame * Frame);
    void EventPanelTopsPaint (AisdiRelationsFrame * Frame);
    void EventHyperLinkClick(AisdiRelationsFrame * Frame, const long id);
    void EventButtonRefreshClick (AisdiRelationsFrame * Frame);
    void EventButtonSaveStatsClick (AisdiRelationsFrame * Frame);
    void EventButtonSettingsClick (AisdiRelationsFrame * Frame);
};
