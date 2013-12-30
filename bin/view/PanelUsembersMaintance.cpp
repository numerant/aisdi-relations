#include "PanelUsembersMaintance.h"
#include <wx/msgdlg.h>

PanelUsembersMaintance::PanelUsembersMaintance()
{
    usembersListEnabled = true;
    emailContentEnabled = true;
}

void PanelUsembersMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelTitle->Hide();
        Frame->PanelGroups->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelStatistics->Hide();
        Frame->PanelMulTree->Hide();

        Frame->PanelUsembers->SetPosition(wxPoint(0,0));
        Frame->PanelUsembers->Show();

        if (usembersListEnabled)
        {
            Frame->U_ListUsembers->Show();
            Frame->U_ListInbox->Hide();
            Frame->U_ListOutbox->Hide();
            Frame->U_StaticBoxUsembers->SetLabel(_("  Usembers  "));
        }
        else
        {
            Frame->U_ListUsembers->Hide();
            Frame->U_ListInbox->Show();
            Frame->U_ListOutbox->Show();
            Frame->U_StaticBoxUsembers->SetLabel(_("  Odebrane/Wysłane Emaile  "));
        }
        if (emailContentEnabled)
        {
            Frame->U_PanelEmail->Show();
            Frame->U_PanelStats->Hide();
        }
        else
        {
            Frame->U_PanelEmail->Hide();
            Frame->U_PanelStats->Show();
        }
    }
}

void PanelUsembersMaintance:: SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;

    wxString labels1[3] = {_("Nazwa:"), _("Email:"), _("Grupa:")};    //etykiety do przypasowania liście usemberów
    wxString labels2[5] = {_("Data:"), _("Temat:"), _("Od:"), _("Do:"), _("Treść")};    //oraz skrzynkom emailowym
    int width[4] = {90, 290, 250, 1};

    for (int i = 0; i < 3; i++)         //przypisujemy etykiety dla Usemberów do kolumn w pętli
    {
        col.SetId(i);
        col.SetText(labels1[i]);
        i < 2 ? col.SetWidth(215) : col.SetWidth(200);
        Frame->U_ListUsembers->InsertColumn(i, col);
    }

    for (int i = 0; i < 3; i++)         //tak samo dla skrzynek
    {
        col.SetId(i);
        col.SetText(labels2[i]);
        col.SetWidth(width[i]);
        Frame->U_ListInbox->InsertColumn(i, col);
        if (i == 2)
            col.SetText(labels2[i+1]);
        Frame->U_ListOutbox->InsertColumn(i, col);
    }
}

void PanelUsembersMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
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
    Frame->U_ImageButtonTitle->SetBitmapLabel(path+imagePaths[12]+format);

}

void PanelUsembersMaintance:: SwitchList(AisdiRelationsFrame * Frame)
{
    if (usembersListEnabled)
    {
        Frame->U_ListUsembers->Hide();
        Frame->U_ListInbox->Show();
        Frame->U_ListOutbox->Show();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Odebrane/Wysłane Emaile  "));
    }
    else
    {
        Frame->U_ListUsembers->Show();
        Frame->U_ListInbox->Hide();
        Frame->U_ListOutbox->Hide();
        Frame->U_StaticBoxUsembers->SetLabel(_("  Usembers  "));
    }
    usembersListEnabled = !usembersListEnabled;
}

void PanelUsembersMaintance::SwitchContent(AisdiRelationsFrame* Frame)
{
    if (emailContentEnabled)
    {
        Frame->U_PanelEmail->Hide();
        Frame->U_PanelStats->Show();
    }
    else
    {
        Frame->U_PanelEmail->Show();
        Frame->U_PanelStats->Hide();
    }
}

void PanelUsembersMaintance::SetSearchEnabled()
{
    searchEnabled = !searchEnabled;
}

bool PanelUsembersMaintance::GetSearchEnabled()
{
    return searchEnabled;
}

void PanelUsembersMaintance::EventButtonSearchClick (AisdiRelationsFrame* Frame)
{
    if (Frame->P_Usembers->GetSearchEnabled())
        Frame->U_SearchCtrl->Hide();
    else
        Frame->U_SearchCtrl->Show();
    Frame->P_Usembers->SetSearchEnabled();
}

void PanelUsembersMaintance::EventButtonAddClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventButtonSaveClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventButtonSettingsClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventButtonDeleteClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventButtonShowGroupClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventButtonSwitchContentClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventSearchCtrlTextEnter (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListUsembersItemSelect (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListUsembersColumnClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListOutboxColumnClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListInboxItemSelect (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListInboxColumnClick (AisdiRelationsFrame* Frame)
{

}
