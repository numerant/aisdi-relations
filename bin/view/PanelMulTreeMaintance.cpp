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

        Frame->PanelSettings->Hide();
        if (GetSettingsEnabled())
            SetSettingsEnabled();

        Frame->M_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);

        DrawTree (Frame);

        Frame->PanelMulTree->SetPosition(wxPoint(0,0));
        Frame->PanelMulTree->Show();
    }
}

void PanelMulTreeMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    Frame->M_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->M_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->M_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->M_ImageButtonGroups->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->M_ImageButtonStats->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->M_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
}

void PanelMulTreeMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

void PanelMulTreeMaintance::SetTree (Email* emailFWD)
{
    if (! emailFWD->getIsForwarded())   //nie jest to email typu FWD
        return;

    if (treeImplemented)
        tree = new MulticastTree (emailFWD);
    else
        wxMessageBox(_("Wyświetlanie drzewa multicastowego nie jest zaimplementowane w tej wersji programu."));
}

void PanelMulTreeMaintance::DrawTree (AisdiRelationsFrame* Frame)
{

}

bool PanelMulTreeMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

bool PanelMulTreeMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

void PanelMulTreeMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
    if (GetSettingsEnabled())
    {
        Frame->PanelSettings->Hide();
        Frame->M_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
    }
    else
    {
        Frame->M_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+formatNeg);
        Frame->PanelSettings->SetPosition(wxPoint(100,100));
        Frame->PanelSettings->Show();
    }
    SetSettingsEnabled();
}
