#include "PanelUsembersMaintance.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>

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
    ClearUsemberInfo(Frame);
    int counterU;
    if(customSearch)
        counterU = Frame->database->countResultUsembers();
    else
        counterU = Frame->database->countUsembers();
    if (counterU > 0)     //TODO Zmienić wyświetlanie za pomocą Query
    {
        Frame->U_ListUsembers->DeleteAllItems();
        for (int i = 0; i < counterU; i++)
        {
            Usember* usember;
            if(customSearch)
                usember = Frame->database->getResultUsember(i);
            else
                usember = Frame->database->getUsember(i);
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
    else if (customSearch)
    {
        wxListItem item;
        item.SetId(0);
        Frame->U_ListUsembers->InsertItem( item );
        wxString wxNoResults = _("brak wyników wyszukiwania...");
        Frame->U_ListUsembers->SetItem(0,1, wxNoResults);
    }
    else
    {
        wxListItem item;
        item.SetId(0);
        Frame->U_ListUsembers->InsertItem( item );
        wxString wxNoEmails = _("brak użytkowników w bazie...");
        Frame->U_ListUsembers->SetItem(0,1, wxNoEmails);
    }
}

void PanelUsembersMaintance::SetEmails (AisdiRelationsFrame * Frame, int pos)
{
    if (pos == -1)
    {
        Frame->U_ListInbox->DeleteAllItems();       //usuń elementy
        Frame->U_ListOutbox->DeleteAllItems();

        wxListItem item;    //ustaw info o pustych listach
        item.SetId(0);
        Frame->U_ListOutbox->InsertItem( item );
        Frame->U_ListInbox->InsertItem( item );
        wxString wxNoResults = _("brak emaili wysłanych...");
        Frame->U_ListOutbox->SetItem(0,1, wxNoResults);
        wxNoResults = _("brak emaili odebranych...");
        Frame->U_ListInbox->SetItem(0,1, wxNoResults);

        return;
    }

    int counterU = Frame->database->countUsembers();
    if (counterU > 0)     //TODO Zmienić wyświetlanie za pomocą Query
    {
        Frame->U_ListInbox->DeleteAllItems();
        Frame->U_ListOutbox->DeleteAllItems();
        Usember * usember = Frame->database->getUsember(pos);

        //Przeleć maile odebrane
        int counterIn =  usember->receiveMailCount();
        if (counterIn > 0)
        {
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
        }
        else    //nie ma maili odebranych
        {
            wxListItem item;
            item.SetId(0);
            Frame->U_ListInbox->InsertItem( item );
            wxString wxNoResults = _("brak emaili odebranych...");
            Frame->U_ListInbox->SetItem(0,1, wxNoResults);
        }

        //przeleć maile wysłane
        int counterOut = usember->sendMailCount();
        if (counterOut  > 0)
        {
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
        else    //nie ma maili wysłanych
        {
            wxListItem item;
            item.SetId(0);
            Frame->U_ListOutbox->InsertItem( item );
            wxString wxNoResults = _("brak emaili wysłanych...");
            Frame->U_ListOutbox->SetItem(0,1, wxNoResults);
        }
    }
    else
    {
        wxListItem item;
        item.SetId(0);
        Frame->U_ListOutbox->InsertItem( item );
        Frame->U_ListInbox->InsertItem( item );
        wxString wxNoResults = _("brak emaili wysłanych...");
        Frame->U_ListOutbox->SetItem(0,1, wxNoResults);
        wxNoResults = _("brak emaili odebranych...");
        Frame->U_ListInbox->SetItem(0,1, wxNoResults);
    }

    //TODO Coś trzeba z tym zrobić, może jakiś Timer?
    EventPanelStatsPaint(Frame);
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
        SwitchContent(Frame);
        Frame->TimerRepaint.Start(100, wxTIMER_ONE_SHOT);
    }
    usembersListEnabled = !usembersListEnabled;
}

void PanelUsembersMaintance::SwitchContent(AisdiRelationsFrame* Frame)
{
    if (emailContentEnabled)
    {
        Frame->U_PanelEmail->Hide();
        Frame->U_PanelStats->Show();
        EventPanelStatsPaint(Frame);
    }
    else
    {
        Frame->U_PanelEmail->Show();
        Frame->U_PanelStats->Hide();
    }
    emailContentEnabled = !emailContentEnabled;
}

void PanelUsembersMaintance::ClearUsemberInfo (AisdiRelationsFrame * Frame)
{
    Frame->U_StaticTextName->SetLabel(_("-"));
    Frame->U_StaticTextEmail->SetLabel(_("-"));
    Frame->U_StaticTextGroup->SetLabel(_("-"));
    Frame->U_StaticTextDate->SetLabel(_("-"));
    Frame->U_StaticTextSent->SetLabel(_("-"));
    Frame->U_StaticTextReceived->SetLabel(_("-"));
    Frame->U_StaticTextSubject->SetLabel(_("-"));
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

void PanelUsembersMaintance::SetUsemberViewed(AisdiRelationsFrame * Frame, const string usember)
{
    string adress = "";
    int pos = usember.find("<",0)+1;
    adress = usember.substr(pos,usember.size()-pos-1);
    adressUsemberSelected = adress;

    int received = 0;
    int sent = 0;
    Usember * usemberPtr = Frame->database->getUsember(Frame->database->findUsember(adressUsemberSelected));
    if (usemberPtr != nullptr)
    {
        received = usemberPtr->receiveMailCount();
        sent = usemberPtr->sendMailCount();
    }

    ostringstream ss;
    ss << received;
    string strReceived = ss.str();
    ss.str("");
    ss << sent;
    string strSent = ss.str();
    Frame->U_StaticTextReceived->SetLabel(wxString(strReceived.c_str(),wxConvUTF8));
    Frame->U_StaticTextSent->SetLabel(wxString(strSent.c_str(),wxConvUTF8));

    string name = usemberPtr->getRealName();
    Frame->U_StaticTextName->SetLabel(wxString(name.c_str(),wxConvUTF8));
    Frame->U_StaticTextEmail->SetLabel(wxString(adressUsemberSelected.c_str(), wxConvUTF8));
    Frame->U_StaticTextGroup->SetLabel(_("temporary unavailable"));     //TODO dodać wyswietlanie grupy

    SetEmails(Frame, Frame->database->findUsember(adressUsemberSelected));
    if (GetUsembersListEnabled())
        SwitchList(Frame);
    if (GetEmailContentEnabled())
        SwitchContent(Frame);
    ShowPanel(Frame);
    EventPanelStatsPaint(Frame);
    Frame->TimerRepaint.Start(100, wxTIMER_ONE_SHOT);
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
        customSearch=true;
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
    if (adressUsemberSelected == "")
        return;
    if (Frame->database->countUsembers() == 0)
        return;

    Usember* usember = Frame->database->getUsember(Frame->database->findUsember(adressUsemberSelected));
    if (usember == nullptr)
    {
        //TODO rzuć wyjątkiem o ścianę
    }
    else
    {
        //usun maile from
        //usun maile to
        //usun usembera

        //albo najlepiej usuwaj maile przez funkcje panelu Inbox to usember sam sie usunie
    }
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
    wxString s = Frame->U_SearchCtrl->GetValue();
    string strQuery = (string) s.mb_str();
    if (strQuery != "")
    {
        wxMessageBox(_("OK!"));
        Frame->I_ImageButtonRestore->Show();
        Frame->I_LabelRestore->Show();

        if (customSearch)
        {
            wxMessageBox(_("OK2!"));
            UsemberQuery usemberQuery;
            StringCriteria stringCriteria(E_NAME, strQuery);
            usemberQuery.addStringCriteria(stringCriteria);
            Frame->database->select(usemberQuery);
            SetUsembers(Frame);
            if(Frame->database->countResultUsembers()==0)
                wxMessageBox(_("Brak wynikow!"));
            else
                wxMessageBox(_("Wyszukiwanie zakonczone"));
        }
    }
    else
    {
        wxMessageBox (_("Wpisz fraze do wyszukania."));
    }
}

void PanelUsembersMaintance::EventListUsembersItemSelect (AisdiRelationsFrame* Frame)
{
    if (Frame->database->countUsembers() == 0)
        return;

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

    int received = 0;
    int sent = 0;
    Usember * usember = Frame->database->getUsember(Frame->database->findUsember(adressUsemberSelected));
    if (usember != nullptr)
    {
        received = usember->receiveMailCount();
        sent = usember->sendMailCount();
    }

    ostringstream ss;
    ss << received;
    string strReceived = ss.str();
    ss.str("");
    ss << sent;
    string strSent = ss.str();
    Frame->U_StaticTextReceived->SetLabel(wxString(strReceived.c_str(),wxConvUTF8));
    Frame->U_StaticTextSent->SetLabel(wxString(strSent.c_str(),wxConvUTF8));

   SetEmails(Frame, Frame->database->findUsember(adressUsemberSelected));
   if (GetUsembersListEnabled())
        SwitchList(Frame);
    if (GetEmailContentEnabled())
        SwitchContent(Frame);
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

    if (contents[0] == _(""))
        return;

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

    if (contents[0] == _(""))
        return;

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

void PanelUsembersMaintance::EventPanelStatsPaint (AisdiRelationsFrame * Frame)
{
    wxColor ColorReceived = wxColor(252,69,33);
    wxColor ColorReceivedL = wxColor(255,100,70);
    wxColor ColorSent = wxColor(255,187,117);
    wxColor ColorSentL = wxColor(255,200,140);
    wxColor colorBackground = wxColor(48,48,48);
    wxColor colorText = wxColor (230,230,230);

    int height, width;
    Frame->U_PanelStats->GetSize(&width, & height);
    double pointSpace = (width-20)/12;
    double pointHeight = height-100;
    const int radiusGreen = 5;      //średnica punktu wykresu - raczej nie zmieniać
    const int radiusBlue = 3;
    int deltaY = -45;
    int valueLabelCorrection = height-pointHeight+deltaY-10;

    wxPaintDC dc(Frame->U_PanelStats);

    dc.SetBrush(wxBrush(colorBackground));
    dc.SetPen(wxPen(colorBackground));
    dc.DrawRectangle(wxPoint(5,32),wxSize(width-10,height-28-5));       //wyczyszczenie canvasu

    dc.SetTextForeground(colorText);
    dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _("Ubuntu")));

    int maxEmails = 0, prevX = 32, prevYS = height+deltaY, prevYR = height+deltaY;
    Usember * usember = Frame->database->getUsember(Frame->database->findUsember(adressUsemberSelected));
    if (usember != nullptr)
        maxEmails =  usember->getMaxEmailsInMonth();

    if (maxEmails)  //jeżeli jakikolwiek mail wczytany
    {
         for (int i = 0; i < 12; i++)    //Wypisanie nazw miesięcy u dołu
        {
            int posCorrection = 0, labelCorrection = 0, radiusCorrection = 0;
            if (i == 6)
                    posCorrection = 2;
            dc.SetTextForeground(colorText);
            dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu")));
            dc.DrawText(months[i], wxPoint(20+i*pointSpace+posCorrection, height-25));      //wypisz nazwę miesiąca

            dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _("Ubuntu")));
            int monthSent = 0, monthReceived = 0;
            monthSent =  usember->getEmailsSentInMonth(i);  //pobranie wartości z danego miesiąca
            monthReceived = usember->getEmailsReceivedInMonth(i);

            if (monthSent >= 100)           //zabawa mailami wysłanymi
            {
                 labelCorrection = -8;
                 radiusCorrection = 4;
            }
            else if (monthSent >= 10)
            {
                labelCorrection = -4;
                radiusCorrection = 2;
            }

            ostringstream ss;               //konwersja int -> string -> wxString
            ss << monthSent;
            string strMonthSent = ss.str();

            dc.SetPen(wxPen(ColorSent));
            dc.SetBrush(wxBrush(ColorSent));
            int currentPointHeight = 0;
            if (monthSent)  //jeżeli jest co rysować, to rysuj punkt i linię do poprzedniego
            {
                double step = 10*pointHeight/maxEmails;
                double d_pointHeight = step * monthSent;
                currentPointHeight = (int)(d_pointHeight/10);
            }
            dc.DrawEllipse(wxPoint(32+i*pointSpace-radiusGreen-radiusCorrection,height+deltaY-currentPointHeight-radiusGreen-radiusCorrection),wxSize(2*radiusGreen+2*radiusCorrection, 2*radiusGreen+2*radiusCorrection));
            dc.DrawLine(wxPoint(prevX,prevYS),wxPoint(32+i*pointSpace,height+deltaY-currentPointHeight));
            prevYS = height+deltaY-currentPointHeight;
            dc.SetTextForeground(ColorSentL);
            dc.DrawText(wxString(strMonthSent.c_str(), wxConvUTF8), wxPoint(34+i*pointSpace+radiusGreen+radiusCorrection, (int)(valueLabelCorrection+pointHeight-currentPointHeight-radiusGreen-radiusCorrection)));

             if (monthReceived >= 100)           //zabawa mailami wysłanymi
            {
                 labelCorrection = -8;
                 radiusCorrection = 20;
            }
            else if (monthReceived >= 10)
            {
                labelCorrection = -4;
                radiusCorrection = 10;
            }

            //konwersja int -> string -> wxString
            ss.str("");
            ss << monthReceived;
            string strMonthReceived= ss.str();

            dc.SetPen(wxPen(ColorReceived));
            dc.SetBrush(wxBrush(ColorReceived));
            currentPointHeight = 0;
            if (monthReceived)  //jeżeli jest co rysować, to rysuj punkt i linię do poprzedniego
            {
                double step = 10*pointHeight/maxEmails;
                double d_pointHeight = step * monthReceived;
                currentPointHeight = (int)(d_pointHeight/10);
            }
            dc.DrawEllipse(wxPoint(32+i*pointSpace-radiusBlue-radiusCorrection,height+deltaY-currentPointHeight-radiusBlue-radiusCorrection),wxSize(2*radiusBlue+2*radiusCorrection, 2*radiusBlue+2*radiusCorrection));
            dc.DrawLine(wxPoint(prevX,prevYR),wxPoint(32+i*pointSpace,height+deltaY-currentPointHeight));
            prevYR = height+deltaY-currentPointHeight;
            prevX = 32+i*pointSpace;
            dc.SetTextForeground(ColorReceivedL);
            dc.DrawText(wxString(strMonthReceived.c_str(), wxConvUTF8), wxPoint(21+i*pointSpace+labelCorrection-radiusBlue-radiusCorrection, (int)(valueLabelCorrection+pointHeight-currentPointHeight-radiusGreen-radiusCorrection)));
        }
    }
    dc.SetPen(wxPen(colorText));
    dc.DrawLine(wxPoint(10,height-30), wxPoint(width-10,height-30));
}
