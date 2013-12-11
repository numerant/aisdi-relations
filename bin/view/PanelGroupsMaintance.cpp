#include "PanelGroupsMaintance.h"

PanelGroupsMaintance::PanelGroupsMaintance() {
	
}

void PanelGroupsMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelUsembers->Hide();
    Frame->PanelTitle->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelGroups->SetPosition(wxPoint(0,0));
    Frame->PanelGroups->Show();
}
