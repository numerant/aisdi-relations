#include "PanelTitleMaintance.h"

PanelTitleMaintance::PanelTitleMaintance ()
{
    noData = false;
}

void PanelTitleMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelTitle->SetPosition(wxPoint(0,0));
    Frame->PanelTitle->Show();
}

void PanelTitleMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
    wxString pathBig(_("resources/iconsBig/icon"));
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->T_ImageButtonAdd->SetBitmapLabel(pathBig+imagePaths[0]+format);
    Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+format);
    Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+format);
    Frame->T_ImageButtonFiles->SetBitmapLabel(pathBig+imagePaths[3]+format);
    Frame->T_ImageButtonFolder->SetBitmapLabel(pathBig+imagePaths[4]+format);
    Frame->T_ImageButtonBin->SetBitmapLabel(pathBig+imagePaths[5]+format);
    Frame->T_ImageButtonTxt->SetBitmapLabel(pathBig+imagePaths[6]+format);
    Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);
    Frame->T_ImageButtonInbox->SetBitmapLabel(pathBig+imagePaths[8]+format);
    Frame->T_ImageButtonUsembers->SetBitmapLabel(pathBig+imagePaths[9]+format);
    Frame->T_ImageButtonGroups->SetBitmapLabel(pathBig+imagePaths[10]+format);
    Frame->T_ImageButtonStats->SetBitmapLabel(pathBig+imagePaths[11]+format);
    Frame->T_ImageButtonMulTree->SetBitmapLabel(pathBig+imagePaths[12]+format);
}

void PanelTitleMaintance::SwitchIcons (AisdiRelationsFrame* Frame)
{
    if (noData)
    {
        Frame->T_ImageButtonAdd->Hide();
        Frame->T_ImageButtonImport->Hide();
        Frame->T_ImageButtonTxt->Hide();
        Frame->T_ImageButtonBin->Hide();
        Frame->T_ImageButtonLoad->Hide();
        Frame->T_ImageButtonFolder->Hide();
        Frame->T_ImageButtonFiles->Hide();

        Frame->T_ImageButtonInbox->Show();
        Frame->T_ImageButtonGroups->Show();
        Frame->T_ImageButtonUsembers->Show();
        Frame->T_ImageButtonStats->Show();
        Frame->T_ImageButtonMulTree->Show();
    }
    else
    {
        Frame->T_ImageButtonAdd->Show();
        Frame->T_ImageButtonImport->Show();
        Frame->T_ImageButtonTxt->Show();
        Frame->T_ImageButtonBin->Show();
        Frame->T_ImageButtonLoad->Show();
        Frame->T_ImageButtonFolder->Show();
        Frame->T_ImageButtonFiles->Show();

        Frame->T_ImageButtonInbox->Hide();
        Frame->T_ImageButtonGroups->Hide();
        Frame->T_ImageButtonUsembers->Hide();
        Frame->T_ImageButtonStats->Hide();
        Frame->T_ImageButtonMulTree->Hide();
    }

    noData = !noData;
}
