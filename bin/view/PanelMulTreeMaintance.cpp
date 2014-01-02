#include "PanelMulTreeMaintance.h"

PanelMulTreeMaintance::PanelMulTreeMaintance()
{

}

void PanelMulTreeMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelGroups->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelStatistics->Hide();
        Frame->PanelTitle->Hide();

        Frame->PanelMulTree->SetPosition(wxPoint(0,0));
        Frame->PanelMulTree->Show();
    }
}

void PanelMulTreeMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->M_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->M_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->M_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->M_ImageButtonGroups->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->M_ImageButtonStats->SetBitmapLabel(path+imagePaths[4]+format);
}

bool PanelMulTreeMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}
