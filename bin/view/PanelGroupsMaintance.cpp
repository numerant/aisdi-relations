#include "PanelGroupsMaintance.h"

PanelGroupsMaintance::PanelGroupsMaintance()
{

}

void PanelGroupsMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelTitle->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelStatistics->Hide();
        Frame->PanelMulTree->Hide();

        Frame->PanelSettings->Hide();
        if (GetSettingsEnabled())
            SetSettingsEnabled();

        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);

        Frame->PanelGroups->SetPosition(wxPoint(0,0));
        Frame->PanelGroups->Show();
    }
}

void PanelGroupsMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    Frame->G_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->G_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->G_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->G_ImageButtonStats->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->G_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
}

void PanelGroupsMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

bool PanelGroupsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

bool PanelGroupsMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

void PanelGroupsMaintance::EventButtonSettingsClick(AisdiRelationsFrame* Frame)
{
    if (GetSettingsEnabled())
    {
        Frame->PanelSettings->Hide();
        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
    }
    else
    {
        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+formatNeg);
        Frame->PanelSettings->SetPosition(wxPoint(100,100));
        Frame->PanelSettings->Show();
    }
    SetSettingsEnabled();
}
