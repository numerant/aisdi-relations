#include "PanelMulTreeMaintance.h"

PanelMulTreeMaintance::PanelMulTreeMaintance()
{

}

void PanelMulTreeMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelTitle->Hide();

    Frame->PanelMulTree->SetPosition(wxPoint(0,0));
    Frame->PanelMulTree->Show();
}
