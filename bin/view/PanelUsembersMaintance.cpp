#include "PanelUsembersMaintance.h"

void PanelUsembersMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelTitle->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelUsembers->SetPosition(wxPoint(0,0));
    Frame->PanelUsembers->Show();
}
