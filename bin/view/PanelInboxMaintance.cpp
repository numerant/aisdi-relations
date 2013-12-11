#include "PanelInboxMaintance.h"

PanelInboxMaintance::PanelInboxMaintance(){

}

void PanelInboxMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelUsembers->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelTitle->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelInbox->SetPosition(wxPoint(0,0));
    Frame->PanelInbox->Show();
}

void PanelInboxMaintance::SetLabels(AisdiRelationsFrame* Frame) {
    /*wxListItem col;

    wxString labels1[3] = {_("Nazwa:"), _("Email:"), _("Grupa:")};    //etykiety do przypasowania liście usemberów
    wxString labels2[4] = {_("Data:"), _("Tytuł:"), _("Od:"), _("Do:")};    //oraz skrzynkom emailowym
    int width[3] = {80, 290, 180};

    for (int i = 0; i < 3; i++) {       //przypisujemy etykiety do kolumn w pętli
        col.SetId(i);
        col.SetText(labels1[i]);
        i < 2 ? col.SetWidth(200) : col.SetWidth(150);
        Frame->U_ListUsembers->InsertColumn(i, col);
    }

     for (int i = 0; i < 3; i++) {       //tak samo dla skrzynek
        col.SetId(i);
        col.SetText(labels2[i]);
        col.SetWidth(width[i]);
        Frame->U_ListInbox->InsertColumn(i, col);
        if (i == 2)
            col.SetText(labels2[i+1]);
        Frame->U_ListOutbox->InsertColumn(i, col);
    }*/
}

void PanelInboxMaintance::SetIcons(AisdiRelationsFrame* Frame) {
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->I_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->I_ImageButtonGroups->SetBitmapLabel(path+imagePaths[5]+format);
    Frame->I_ImageButtonStats->SetBitmapLabel(path+imagePaths[6]+format);
    Frame->I_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[7]+format);
    Frame->I_ImageButtonDelete->SetBitmapLabel(path+imagePaths[8]+format);
    Frame->I_ImageButtonSender->SetBitmapLabel(path+imagePaths[9]+format);
    Frame->I_ImageButtonReceiver->SetBitmapLabel(path+imagePaths[10]+format);
    Frame->I_ImageButtonShowTree->SetBitmapLabel(path+imagePaths[11]+format);

}
