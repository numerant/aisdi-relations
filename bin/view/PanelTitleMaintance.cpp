#include "PanelTitleMaintance.h"

void PanelTitleMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelTitle->SetPosition(wxPoint(0,0));
    Frame->PanelTitle->Show();
}
