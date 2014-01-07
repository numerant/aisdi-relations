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

        Frame->PanelAdd->Hide();
        if (GetAddEnabled())
            SetAddEnabled();

        Frame->PanelSave->Hide();
        if (GetSaveEnabled())
            SetSaveEnabled();

        Frame->PanelSettings->Hide();
        if (GetSettingsEnabled())
            SetSettingsEnabled();

        Frame->U_SearchCtrl->Hide();
        if (GetSearchEnabled())
            SetSearchEnabled();

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

        Frame->PanelUsembers->SetPosition(wxPoint(0,0));
        Frame->PanelUsembers->Show();
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

void PanelUsembersMaintance::SetAddEnabled()
{
    addEnabled = !addEnabled;
}

void PanelUsembersMaintance::SetSaveEnabled()
{
    saveEnabled = !saveEnabled;
}

void PanelUsembersMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

void PanelUsembersMaintance::SetUsemberViewed(const string usember)
{

}

bool PanelUsembersMaintance::GetSearchEnabled()
{
    return searchEnabled;
}

bool PanelUsembersMaintance::GetAddEnabled()
{
    return addEnabled;
}

bool PanelUsembersMaintance::GetSaveEnabled()
{
    return saveEnabled;
}

bool PanelUsembersMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

void PanelUsembersMaintance::EventButtonSearchClick (AisdiRelationsFrame* Frame)
{
    if (Frame->P_Usembers->GetSearchEnabled())
        Frame->U_SearchCtrl->Hide();
    else
    {
        Frame->U_SearchCtrl->Show();
        if (GetAddEnabled())
        {
            Frame->PanelAdd->Hide();   //przy pokazaniu pola wyszukiwania schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->PanelSave->Hide();   //...Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->PanelSettings->Hide();   //...oraz Settings
            SetSettingsEnabled();
        }
    }
    Frame->P_Usembers->SetSearchEnabled();
}

void PanelUsembersMaintance::EventButtonAddClick (AisdiRelationsFrame * Frame)
{
    if (GetAddEnabled())
        Frame->PanelAdd->Hide();
    else
    {
        Frame->PanelAdd->Show();
        if (GetSaveEnabled())
        {
            Frame->PanelSave->Hide();   //przy pokazaniu panelu Add schowaj ewentualnie panele Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_SearchCtrl->Hide();   //...oraz pole Search
            SetSearchEnabled();
        }
    }
    SetAddEnabled();
}

void PanelUsembersMaintance::EventButtonSaveClick (AisdiRelationsFrame * Frame)
{
    if (GetSaveEnabled())
        Frame->PanelSave->Hide();
    else
    {
        Frame->PanelSave->Show();
        if (GetAddEnabled())
        {
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Save schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_SearchCtrl->Hide();   //...oraz pole Search
            SetSearchEnabled();
        }
    }
    SetSaveEnabled();
}

void PanelUsembersMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
    if (GetSettingsEnabled())
        Frame->PanelSettings->Hide();
    else
    {
        //TODO dodaj pozycjonowanie panelu Settings
        Frame->PanelSettings->Show();
        if (GetAddEnabled())
        {
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Settings schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->PanelSave->Hide();   //...Save
            SetSaveEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_SearchCtrl->Hide();   //...oraz pole Search
            SetSearchEnabled();
        }
    }
    SetSettingsEnabled();
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

void PanelUsembersMaintance::EventListOutboxItemSelect (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListInboxItemSelect (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListInboxColumnClick (AisdiRelationsFrame* Frame)
{

}
