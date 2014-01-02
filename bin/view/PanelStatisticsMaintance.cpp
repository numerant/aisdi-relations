#include "PanelStatisticsMaintance.h"

PanelStatisticsMaintance::PanelStatisticsMaintance ()
{

}

void PanelStatisticsMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelGroups->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelTitle->Hide();
        Frame->PanelMulTree->Hide();

        Frame->PanelStatistics->SetPosition(wxPoint(0,0));
        Frame->PanelStatistics->Show();
    }
}

void PanelStatisticsMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->S_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->S_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->S_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->S_ImageButtonGroups->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->S_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[4]+format);
}

bool PanelStatisticsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

