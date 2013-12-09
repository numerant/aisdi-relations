#include "PanelInboxMaintance.h"

void PanelInboxMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelTitle->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelInbox->SetPosition(wxPoint(0,0));
    Frame->PanelInbox->Show();
}
