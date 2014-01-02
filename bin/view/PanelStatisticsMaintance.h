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

     const wxString months[12] =
     {
        _("Jan"), _("Feb"), _("Mar"), _("Apr"), _("May"), _("Jun"), _("Jul"), _("Aug"), _("Sep"), _("Oct"), _("Nov"), _("Dec")
     };

public:
    PanelStatisticsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();

    void EventPanelEmailPerMonthPaint (AisdiRelationsFrame * Frame);
};
