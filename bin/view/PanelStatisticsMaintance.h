#pragma once
#include "../AisdiRelationsMain.h"
#include <sstream>

class PanelStatisticsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool isUpdated = false;
    const wxString imagePaths[5] =
    {
        _("Title"),  _("Mailbox"),  _("Usember"),  _("Workgroups"),  _("Tree")
    };              //ścieżki plików z grafikami do przycisków panelu

     const wxString months[12] =
     {
        _("Jan"), _("Feb"), _("Mar"), _("Apr"), _("May"), _("Jun"), _("Jul"), _("Aug"), _("Sep"), _("Oct"), _("Nov"), _("Dec")
     };

public:
    PanelStatisticsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetIsUpdated();

    bool GetPanelEnabled ();
    bool GetIsUpdated ();

    void EventPanelEmailPerMonthPaint (AisdiRelationsFrame * Frame);
    void EventPanelCountersPaint (AisdiRelationsFrame * Frame);
};
