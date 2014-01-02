#include "PanelNotifyMaintance.h"

PanelNotifyMaintance::PanelNotifyMaintance()
{

}

void PanelNotifyMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelNotify->SetPosition(wxPoint(0,0));
        Frame->PanelNotify->Show();
    }
}

bool PanelNotifyMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}
