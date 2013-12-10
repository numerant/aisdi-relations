#include "PanelUsembersMaintance.h"
#include <wx/msgdlg.h>

PanelUsembersMaintance::PanelUsembersMaintance() {
    usembersListEnabled = true;
    emailContentEnabled = true;
}

void PanelUsembersMaintance::ShowPanel(AisdiRelationsFrame* Frame) {
    Frame->PanelTitle->Hide();
    Frame->PanelGroups->Hide();
    Frame->PanelInbox->Hide();
    Frame->PanelStatistics->Hide();
    Frame->PanelMulTree->Hide();

    Frame->PanelUsembers->SetPosition(wxPoint(0,0));
    Frame->PanelUsembers->Show();

    if (usembersListEnabled) {
        Frame->U_ListUsembers->Show();
        Frame->U_ListInbox->Hide();
        Frame->U_ListOutbox->Hide();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Usembers  "));
    }
    else {
        Frame->U_ListUsembers->Hide();
        Frame->U_ListInbox->Show();
        Frame->U_ListOutbox->Show();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Odebrane/Wysłane Emaile  "));
    }
    if (emailContentEnabled) {
        Frame->U_PanelEmail->Show();
        Frame->U_PanelStats->Hide();
    }
    else {
        Frame->U_PanelEmail->Hide();
        Frame->U_PanelStats->Show();
    }
}

void PanelUsembersMaintance:: SetLabels(AisdiRelationsFrame* Frame) {
    wxListItem col;

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
    }
}

void PanelUsembersMaintance::SetIcons(AisdiRelationsFrame* Frame) {
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->U_ImageButtonInbox->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->U_ImageButtonGroups->SetBitmapLabel(path+imagePaths[5]+format);
    Frame->U_ImageButtonStats->SetBitmapLabel(path+imagePaths[6]+format);
    Frame->U_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[7]+format);
    Frame->U_ImageButtonDelete->SetBitmapLabel(path+imagePaths[8]+format);
    Frame->U_ImageButtonShowGroup->SetBitmapLabel(path+imagePaths[9]+format);
    Frame->U_ImageButtonSwitchContent->SetBitmapLabel(path+imagePaths[10]+format);
    Frame->U_ImageButtonSwitchList->SetBitmapLabel(path+imagePaths[11]+format);

}

void PanelUsembersMaintance:: SwitchList(AisdiRelationsFrame * Frame) {
    if (usembersListEnabled) {
        usembersListEnabled = false;
        Frame->U_ListUsembers->Hide();
        Frame->U_ListInbox->Show();
        Frame->U_ListOutbox->Show();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Odebrane/Wysłane Emaile  "));
    }
    else {
        usembersListEnabled = true;
        Frame->U_ListUsembers->Show();
        Frame->U_ListInbox->Hide();
        Frame->U_ListOutbox->Hide();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Usembers  "));
    }
}

void PanelUsembersMaintance::SwitchContent(AisdiRelationsFrame* Frame) {
     if (emailContentEnabled) {
        Frame->U_PanelEmail->Hide();
        Frame->U_PanelStats->Show();
    }
    else {
        Frame->U_PanelEmail->Show();
        Frame->U_PanelStats->Hide();
    }
}
