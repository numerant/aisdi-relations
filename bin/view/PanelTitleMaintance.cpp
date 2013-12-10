#include "PanelTitleMaintance.h"

PanelTitleMaintance::PanelTitleMaintance () {
    noData = true;
}

void PanelTitleMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelTitle->SetPosition(wxPoint(0,0));
    Frame->PanelTitle->Show();
}

void PanelTitleMaintance::SetIcons(AisdiRelationsFrame* Frame) {
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
    /*Frame->T_ImageButtonDelete->SetBitmapLabel(path+imagePaths[8]+format);
    Frame->T_ImageButtonShowGroup->SetBitmapLabel(path+imagePaths[9]+format);
    Frame->T_ImageButtonSwitchContent->SetBitmapLabel(path+imagePaths[10]+format);
    Frame->T_ImageButtonSwitchList->SetBitmapLabel(path+imagePaths[11]+format);*/
}
