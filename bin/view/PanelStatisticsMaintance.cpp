#include "PanelStatisticsMaintance.h"

PanelStatisticsMaintance::PanelStatisticsMaintance ()
{

}

void PanelStatisticsMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelTitle->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelStatistics->SetPosition(wxPoint(0,0));
    Frame->PanelStatistics->Show();
}
