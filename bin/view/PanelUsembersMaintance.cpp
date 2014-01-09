#include "PanelUsembersMaintance.h"
#include <wx/msgdlg.h>

PanelUsembersMaintance::PanelUsembersMaintance()
{

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

        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
        Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
        Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
        Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);

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

void PanelUsembersMaintance::SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;

    wxString labels1[COL_USEMBERS_COUNT] = {_("Nazwa:"), _("Email:"), _("Grupa:")};    //etykiety do przypasowania liście usemberów
    wxString labels2[COL_EMAILS_COUNT] = {_("Data:"), _("Temat:"), _("Od:"), _("Do:"), _("Treść"), _("ID")};    //oraz skrzynkom emailowym
    int width[COL_EMAILS_COUNT] = {90, 290, 250, 1, 1, 1};

    for (int i = 0; i < COL_USEMBERS_COUNT; i++)         //przypisujemy etykiety dla Usemberów do kolumn w pętli
    {
        col.SetId(i);
        col.SetText(labels1[i]);
        i < 2 ? col.SetWidth(215) : col.SetWidth(200);
        Frame->U_ListUsembers->InsertColumn(i, col);
    }

    for (int i = 0; i < COL_EMAILS_COUNT; i++)         //tak samo dla skrzynek
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

void PanelUsembersMaintance::SetUsembers(AisdiRelationsFrame * Frame)
{
    int counterU = Frame->database->countUsembers();
    if (counterU > 0)     //TODO Zmienić wyświetlanie za pomocą Query
    {
        Frame->U_ListUsembers->DeleteAllItems();
        for (int i = 0; i < counterU; i++)
        {
            Usember * usember = Frame->database->getUsember(i);
            wxListItem item;
            item.SetId(i);
            if (i % 2 == 0)
                item.SetTextColour(wxColor(200,200,200));
            Frame->U_ListUsembers->InsertItem( item );

            string sourceString = usember->getRealName();
            wxString wxName (sourceString.c_str(), wxConvUTF8);
            Frame->U_ListUsembers->SetItem(i,0, wxName);

            sourceString = usember->getAddress();
            wxString wxAdress (sourceString.c_str(), wxConvUTF8);
            Frame->U_ListUsembers->SetItem(i,1, wxAdress );

            //Group * group = usember->getGroup();      //TODO odkomentować po zrobieniu grup
            int iGroup = i;                        //group->getID();
            ostringstream ssGroup;
            ssGroup << iGroup;
            sourceString = ssGroup.str();
            wxString wxGroup (sourceString.c_str(), wxConvUTF8);
            Frame->U_ListUsembers->SetItem(i,2,wxGroup);
        }
    }
}

void PanelUsembersMaintance::SetEmails (AisdiRelationsFrame * Frame, int pos)
{
    int counterU = Frame->database->countUsembers();
    if (counterU > 0)     //TODO Zmienić wyświetlanie za pomocą Query
    {
        Frame->U_ListInbox->DeleteAllItems();
        Frame->U_ListOutbox->DeleteAllItems();
        Usember * usember = Frame->database->getUsember(pos);
        int counterIn =  usember->receiveMailCount();
        if (counterIn > 0)
            for (int i = 0; i < counterIn; i++)
            {
                Email * email = usember->getEmailReceived(i);

                wxListItem item;
                item.SetId(i);
                if (i % 2 == 0)
                    item.SetTextColour(wxColor(200,200,200));
                Frame->U_ListInbox->InsertItem( item );

                string sourceString = email->getContent();
                wxString content(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListInbox->SetItem(i,4, content);

                sourceString = email->getID();
                wxString wxId(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListInbox->SetItem(i,5, wxId);

                sourceString = email->getSubject();
                wxString subject(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListInbox->SetItem(i,1,subject);

                Date date = email->getDate();
                int day =date.getDay();
                string month = date.getMonth();
                int year = date.getYear();
                ostringstream ssday;
                ssday << day;
                string strdate = ssday.str();
                strdate+= " "+month+" ";
                ostringstream ssyear;
                ssyear << year;
                strdate += ssyear.str();

                sourceString = strdate;
                wxString wxdate(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListInbox->SetItem(i,0,wxdate);

                Usember* from = email->getFrom();
                sourceString = from->getAddress();
                wxString wxfrom(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListInbox->SetItem(i,2,wxfrom);
            }

         if (int counterOut = usember->sendMailCount() > 0)
            for (int i = 0; i < counterOut; i++)
            {
                Email * email = usember->getEmailSent(i);

                wxListItem item;
                item.SetId(i);
                if (i % 2 == 0)
                    item.SetTextColour(wxColor(200,200,200));
                Frame->U_ListOutbox->InsertItem( item );

                string sourceString = email->getContent();
                wxString content(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListOutbox->SetItem(i,4, content);

                sourceString = email->getID();
                wxString wxId(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListOutbox->SetItem(i,5, wxId);

                sourceString = email->getSubject();
                wxString subject(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListOutbox->SetItem(i,1,subject);

                Date date = email->getDate();
                int day =date.getDay();
                string month = date.getMonth();
                int year = date.getYear();
                ostringstream ssday;
                ssday << day;
                string strdate = ssday.str();
                strdate+= " "+month+" ";
                ostringstream ssyear;
                ssyear << year;
                strdate += ssyear.str();

                sourceString = strdate;
                wxString wxdate(sourceString.c_str(), wxConvUTF8);
                Frame->U_ListOutbox->SetItem(i,0,wxdate);

                Usember* to = email->getTo();
                sourceString = to->getAddress();
                wxString wxto (sourceString.c_str(), wxConvUTF8);
                Frame->U_ListOutbox->SetItem(i,2,wxto);
            }
    }
}

void PanelUsembersMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
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

void PanelUsembersMaintance::SwitchList(AisdiRelationsFrame * Frame)
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
    emailContentEnabled = !emailContentEnabled;
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

void PanelUsembersMaintance::SetUsembersListEnabled()
{
    usembersListEnabled = !usembersListEnabled;
}

void PanelUsembersMaintance::SetEmailContentEnabled()
{
    emailContentEnabled = !emailContentEnabled;
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

bool PanelUsembersMaintance::GetUsembersListEnabled()
{
    return usembersListEnabled;
}

bool PanelUsembersMaintance::GetEmailContentEnabled()
{
    return emailContentEnabled;
}

void PanelUsembersMaintance::EventButtonSearchClick (AisdiRelationsFrame* Frame)
{
    if (Frame->P_Usembers->GetSearchEnabled())
    {
        Frame->U_SearchCtrl->Hide();
        Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
    }
    else
    {
        Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+formatNeg);
        Frame->U_SearchCtrl->SetFocus();
        Frame->U_SearchCtrl->Show();
        if (GetAddEnabled())
        {
            Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu pola wyszukiwania schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //...Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...oraz Settings
            SetSettingsEnabled();
        }
    }
    Frame->P_Usembers->SetSearchEnabled();
}

void PanelUsembersMaintance::EventButtonAddClick (AisdiRelationsFrame * Frame)
{
    if (GetAddEnabled())
    {
        Frame->PanelAdd->Hide();
        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
    }
    else
    {
        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+formatNeg);
        Frame->PanelAdd->Show();
        if (GetSaveEnabled())
        {
            Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //przy pokazaniu panelu Add schowaj ewentualnie panele Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->U_SearchCtrl->Hide();   //...oraz pole Search
            SetSearchEnabled();
        }
    }
    SetAddEnabled();
}

void PanelUsembersMaintance::EventButtonSaveClick (AisdiRelationsFrame * Frame)
{
    if (GetSaveEnabled())
    {
        Frame->PanelSave->Hide();
        Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
    }
    else
    {
        Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+formatNeg);
        Frame->PanelSave->Show();
        if (GetAddEnabled())
        {
            Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Save schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->U_SearchCtrl->Hide();   //...oraz pole Search
            SetSearchEnabled();
        }
    }
    SetSaveEnabled();
}

void PanelUsembersMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
    if (GetSettingsEnabled())
    {
        Frame->PanelSettings->Hide();
        Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
    }
    else
    {
        Frame->U_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+formatNeg);
        Frame->PanelSettings->SetPosition(wxPoint(370,100));
        Frame->PanelSettings->Show();
        if (GetAddEnabled())
        {
            Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Settings schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->U_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //...Save
            SetSaveEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->U_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
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
    SwitchContent(Frame);
}

void PanelUsembersMaintance::EventSearchCtrlTextEnter (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListUsembersItemSelect (AisdiRelationsFrame* Frame)
{
    long itemIndex = -1;
    itemIndex = Frame->U_ListUsembers->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    wxListItem item;
    wxString contents[COL_USEMBERS_COUNT];
    wxString pOpen = _("<p align=\"justify\"><font color=\"lightgray\">");
    wxString pClose = _("</font></p>");
    item.m_itemId = itemIndex;
    item.m_mask = wxLIST_MASK_TEXT;

    for (int i = 0; i < COL_USEMBERS_COUNT; i++)
    {
        item.m_col = i;
        Frame->U_ListUsembers->GetItem( item );
        contents[i] = item.m_text;
    }
    Frame->U_StaticTextName->SetLabel(contents[0]);
    Frame->U_StaticTextEmail->SetLabel(contents[1]);
    Frame->U_StaticTextGroup->SetLabel(contents[2]);

   adressUsemberSelected = contents[1].mb_str();
   SetEmails(Frame, Frame->database->findUsember(adressUsemberSelected));
   if (GetUsembersListEnabled())
        SwitchList(Frame);
}

void PanelUsembersMaintance::EventListUsembersColumnClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListOutboxColumnClick (AisdiRelationsFrame* Frame)
{

}

void PanelUsembersMaintance::EventListOutboxItemSelect (AisdiRelationsFrame* Frame)
{
    long itemIndex = -1;
    itemIndex = Frame->U_ListOutbox->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    wxListItem item;
    wxString contents[COL_EMAILS_COUNT];
    wxString pOpen = _("<p align=\"justify\"><font color=\"lightgray\">");
    wxString pClose = _("</font></p>");
    item.m_itemId = itemIndex;
    item.m_mask = wxLIST_MASK_TEXT;

    for (int i = 0; i < COL_EMAILS_COUNT; i++)
    {
        item.m_col = i;
        Frame->U_ListOutbox->GetItem( item );
        contents[i] = item.m_text;
    }
    Frame->U_StaticTextDate->SetLabel(contents[0]);
    Frame->U_StaticTextSubject->SetLabel(contents[1]);
    Frame->U_StaticTextFromTo->SetLabel(contents[2]);

    emailIdSelected = contents[5].mb_str();

    const string search = "\n";
    const string replace = "<br>";
    string content = string (contents[4].mb_str());
    string htmlContent = Frame->iointerface->strSequenceReplace("\n", "<br>", content);

    wxString pContent (htmlContent.c_str(), wxConvUTF8 );
    Frame->U_HtmlContent->SetPage(pOpen+pContent+pClose);
    Frame->U_HtmlContent->SetBackgroundColour(wxColor(20,20,20));
    Frame->U_LabelFromTo->SetLabel(_("Do:"));
    if (!GetEmailContentEnabled())
        SwitchContent(Frame);
}

void PanelUsembersMaintance::EventListInboxItemSelect (AisdiRelationsFrame* Frame)
{
    long itemIndex = -1;
    itemIndex = Frame->U_ListInbox->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    wxListItem item;
    wxString contents[COL_EMAILS_COUNT];
    wxString pOpen = _("<p align=\"justify\"><font color=\"lightgray\">");
    wxString pClose = _("</font></p>");
    item.m_itemId = itemIndex;
    item.m_mask = wxLIST_MASK_TEXT;

    for (int i = 0; i < COL_EMAILS_COUNT; i++)
    {
        item.m_col = i;
        Frame->U_ListInbox->GetItem( item );
        contents[i] = item.m_text;
    }
    Frame->U_StaticTextDate->SetLabel(contents[0]);
    Frame->U_StaticTextSubject->SetLabel(contents[1]);
    Frame->U_StaticTextFromTo->SetLabel(contents[2]);

    emailIdSelected = contents[5].mb_str();

    const string search = "\n";
    const string replace = "<br>";
    string content = string (contents[4].mb_str());
    string htmlContent = Frame->iointerface->strSequenceReplace("\n", "<br>", content);

    wxString pContent (htmlContent.c_str(), wxConvUTF8 );
    Frame->U_HtmlContent->SetPage(pOpen+pContent+pClose);
    Frame->U_HtmlContent->SetBackgroundColour(wxColor(20,20,20));
    Frame->U_LabelFromTo->SetLabel(_("Od:"));
     if (!GetEmailContentEnabled())
        SwitchContent(Frame);
}

void PanelUsembersMaintance::EventListInboxColumnClick (AisdiRelationsFrame* Frame)
{

}
