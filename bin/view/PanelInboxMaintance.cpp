#include "PanelInboxMaintance.h"
#include "PanelNotifyMaintance.h"
#include "PanelStatisticsMaintance.h"

// TEMP - serializacja!
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/tmpdir.hpp>
#include <fstream>
#include "../../src/Serialization.h"

PanelInboxMaintance::PanelInboxMaintance()
{

}

void PanelInboxMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelGroups->Hide();
        Frame->PanelTitle->Hide();
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

        Frame->I_SearchCtrl->Hide();
        Frame->I_PanelAdvSearch->Hide();
        if (GetSearchEnabled())
            SetSearchEnabled();

        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
        Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
        Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
        Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);

        Frame->PanelInbox->SetPosition(wxPoint(0,0));
        Frame->PanelInbox->Show();
    }
}

void PanelInboxMaintance::SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;     //obiekt reprezentujący etykietę

    wxString labels[COL_COUNT] = {_("Data:"), _("Temat:"), _("Od:"), _("Do:"), _("ID")};      //etykiety
    int width[COL_COUNT] = {90, 220, 160, 160, 1};      //szerokości kolumn, sumuje się do 630px

    for (int i = 0; i < COL_COUNT; i++)         //przypisujemy w pętli etykiety do kolumn listy
    {
        col.SetId(i);
        col.SetText(labels[i]);
        col.SetWidth(width[i]);
        Frame->I_ListInbox->InsertColumn(i, col);
    }
}

void PanelInboxMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
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
    Frame->I_ImageButtonTitle->SetBitmapLabel(path+imagePaths[12]+format);
    Frame->I_Adv_ImageButtonSearch->SetBitmapLabel(path+imagePaths[13]+format);
    Frame->I_ImageButtonRestore->SetBitmapLabel(path+imagePaths[14]+format);
}

void PanelInboxMaintance::SetEmails (AisdiRelationsFrame* Frame)
{
    if (Frame->database->countEmails() > 0)     //TODO Zmienić wyświetlanie za pomocą Query
    {
        Frame->I_ListInbox->DeleteAllItems();
        for (int i = 0; i < Frame->database->countEmails(); i++)
        {
            Email * email = Frame->database->getEmail(i);
            wxListItem item;
            item.SetId(i);
            if (i % 2 == 0)
                item.SetTextColour(wxColor(200,200,200));
            Frame->I_ListInbox->InsertItem( item );

            string sourceString = email->getID();
            wxString wxId(sourceString.c_str(), wxConvUTF8);
            Frame->I_ListInbox->SetItem(i,4, wxId);

            sourceString = email->getSubject();
            wxString subject(sourceString.c_str(), wxConvUTF8);
            Frame->I_ListInbox->SetItem(i,1,subject);

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
            Frame->I_ListInbox->SetItem(i,0,wxdate);

            Usember* from = email->getFrom();
            sourceString = from->getAddress();
            wxString wxfrom(sourceString.c_str(), wxConvUTF8);
            Frame->I_ListInbox->SetItem(i,2,wxfrom);

            Usember* to = email->getTo();
            sourceString = to->getAddress();
            wxString wxto(sourceString.c_str(), wxConvUTF8);
            Frame->I_ListInbox->SetItem(i,3,wxto);
        }
    }
    else
    {
        if (customSearch)
        {
            //TODO Wyświetl 'brak wyników wyszukiwania'
        }
        else
        {
            //TODO Wyświetl 'brak emaili'
        }
    }
}

void PanelInboxMaintance::SetAdvSearchDate (AisdiRelationsFrame* Frame)
{
    for (int i = 0; i < Frame->I_Adv_ChoiceYear->GetCount(); i++)
    {
        Frame->I_Adv_ChoiceYear->Delete(i);
        Frame->I_Adv_ChoiceYearTo->Delete(i);
    }

    Date* dateL = Frame->statistics->getLatest();
    Date* dateE = Frame->statistics->getEarliest();
    ostringstream ss;

    wxString empty = _("");
    Frame->I_Adv_ChoiceYear->Append(empty);
    Frame->I_Adv_ChoiceYearTo->Append(empty);
    for (int i = dateE->getYear(); i <= dateL->getYear(); i++)
    {
         ss << i;
         string str = ss.str();
         ss.str("");
         Frame->I_Adv_ChoiceYear->Append(wxString(str.c_str(), wxConvUTF8));
         Frame->I_Adv_ChoiceYearTo->Append(wxString(str.c_str(), wxConvUTF8));
    }
}

void PanelInboxMaintance::Search (AisdiRelationsFrame* Frame)
{
    wxString s = Frame->I_SearchCtrl->GetValue();
    string strQuery = (string) s.mb_str();

    //TODO zapytanie ogólne
}

void PanelInboxMaintance::AdvancedSearch (AisdiRelationsFrame* Frame)
{
    //TODO Obsługa przycisku DatabaseRestore
    wxString field;
    string name, subject, email, content, dayFrom, monthFrom, yearFrom;
    name = subject = email = content = dayFrom = monthFrom = yearFrom = "";

    name = Frame->I_Adv_TextCtrlName->GetValue().mb_str();    //Pola tekstowe
    email = Frame->I_Adv_TextCtrlEmail->GetValue().mb_str();
    content = Frame->I_Adv_TextCtrlContent->GetValue().mb_str();
    subject = Frame->I_Adv_TextCtrlSubject->GetValue().mb_str();

    int pos = Frame->I_Adv_ChoiceDay->GetSelection();   //Pola wyboru daty (pierwszej, 'od')
    if (pos != wxNOT_FOUND)
        dayFrom = Frame->I_Adv_ChoiceDay->GetString(pos).mb_str();

    pos = Frame->I_Adv_ChoiceMonth->GetSelection();
    if (pos != wxNOT_FOUND)
        monthFrom = Frame->I_Adv_ChoiceMonth->GetString(pos).mb_str();

    pos = Frame->I_Adv_ChoiceYear->GetSelection();
    if (pos != wxNOT_FOUND)
        yearFrom = Frame->I_Adv_ChoiceYear->GetString(pos).mb_str();

    if (name == "" && subject == "" && email == "" && content == "" && dayFrom == "" && monthFrom == "" && yearFrom == "")
    {
        wxMessageBox(_("Niepoprawne kryteria wyszukiwania!"));
    }
    else
    {
        Frame->I_ImageButtonRestore->Show();
        Frame->I_LabelRestore->Show();
        if (! GetCustomSearch())
            SetCustomSearch();
        wxMessageBox(_("Zapytanko!"));
         //TODO zrobić zapytanie
    }
}

void PanelInboxMaintance::SetSearchEnabled()
{
    searchEnabled = !searchEnabled;
}

void PanelInboxMaintance::SetAddEnabled()
{
    addEnabled = !addEnabled;
}

void PanelInboxMaintance::SetSaveEnabled()
{
    saveEnabled = !saveEnabled;
}

void PanelInboxMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

void PanelInboxMaintance::SetCustomSearch()
{
    customSearch = !customSearch;
}

bool PanelInboxMaintance::GetSearchEnabled()
{
    return searchEnabled;
}

bool PanelInboxMaintance::GetAddEnabled()
{
    return addEnabled;
}

bool PanelInboxMaintance::GetSaveEnabled()
{
    return saveEnabled;
}

bool PanelInboxMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

bool PanelInboxMaintance::GetCustomSearch()
{
    return customSearch;
}

void PanelInboxMaintance::EventButtonSearchClick (AisdiRelationsFrame* Frame)
{
    if (Frame->P_Inbox->GetSearchEnabled())
    {
        Frame->I_SearchCtrl->Hide();
        Frame->I_PanelAdvSearch->Hide();
        Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
    }
    else
    {
        Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+formatNeg);
        Frame->I_SearchCtrl->Show();
        Frame->I_PanelAdvSearch->Show();
        Frame->I_SearchCtrl->SetFocus();
        //TODO wyczyscic pola wyszukiwania zaawansowanego
        if (GetAddEnabled())
        {
            Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu pola wyszukiwania schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //...Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...oraz Settings
            SetSettingsEnabled();
        }
    }
    Frame->P_Inbox->SetSearchEnabled();
}

void PanelInboxMaintance::EventListInboxItemSelect (AisdiRelationsFrame* Frame)
{
    Frame->PanelAdd->Hide();
    if (GetAddEnabled())
        SetAddEnabled();

    Frame->PanelSave->Hide();
    if (GetSaveEnabled())
        SetSaveEnabled();

    Frame->PanelSettings->Hide();
    if (GetSettingsEnabled())
        SetSettingsEnabled();

    Frame->I_SearchCtrl->Hide();
    Frame->I_PanelAdvSearch->Hide();
    if (GetSearchEnabled())
        SetSearchEnabled();

    long itemIndex = -1;
    itemIndex = Frame->I_ListInbox->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    wxListItem item;
    wxString contents[COL_COUNT];
    wxString pOpen = _("<p align=\"justify\"><font color=\"lightgray\">");
    wxString pClose = _("</font></p>");
    item.m_itemId = itemIndex;
    item.m_mask = wxLIST_MASK_TEXT;

    for (int i = 0; i < COL_COUNT; i++)
    {
        item.m_col = i;
        Frame->I_ListInbox->GetItem( item );
        contents[i] = item.m_text;
    }
    Frame->I_StaticTextDate->SetLabel(contents[0]);
    Frame->I_StaticTextSubject->SetLabel(contents[1]);
    Frame->I_StaticTextFrom->SetLabel(contents[2]);
    Frame->I_StaticTextTo->SetLabel(contents[3]);

    emailIdSelected = contents[4].mb_str();
    Email * email = Frame->database->getEmail(Frame->database->findEmail(emailIdSelected));


    const string search = "\n";
    const string replace = "<br>";
    string strContent = email->getContent();
    string htmlContent = Frame->iointerface->strSequenceReplace("\n", "<br>", strContent);

    wxString pContent (htmlContent.c_str(), wxConvUTF8 );
    Frame->I_HtmlEmailContent->SetPage(pOpen+pContent+pClose);
    Frame->I_HtmlEmailContent->SetBackgroundColour(wxColor(20,20,20));
}

void PanelInboxMaintance::EventButtonAddClick (AisdiRelationsFrame * Frame)
{
    if (GetAddEnabled())
    {
        Frame->PanelAdd->Hide();
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
    }
    else
    {
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+formatNeg);
        Frame->PanelAdd->Show();
        if (GetSaveEnabled())
        {
            Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //przy pokazaniu panelu Add schowaj ewentualnie panele Save...
            SetSaveEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->I_SearchCtrl->Hide();     //...oraz pole Search
            Frame->I_PanelAdvSearch->Hide();
            SetSearchEnabled();
        }
    }
    SetAddEnabled();
}

void PanelInboxMaintance::EventButtonSaveClick (AisdiRelationsFrame * Frame)
{
    if (GetSaveEnabled())
    {
        Frame->PanelSave->Hide();
        Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
    }
    else
    {
        Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+formatNeg);
        Frame->PanelSave->Show();
        if (GetAddEnabled())
        {
            Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Save schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSettingsEnabled())
        {
            Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
            Frame->PanelSettings->Hide();   //...Settings...
            SetSettingsEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->I_SearchCtrl->Hide();     //...oraz pole Search
            Frame->I_PanelAdvSearch->Hide();
            SetSearchEnabled();
        }
    }
    SetSaveEnabled();
}

void PanelInboxMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
    if (GetSettingsEnabled())
    {
        Frame->PanelSettings->Hide();
        Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
    }
    else
    {
        Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+formatNeg);
        Frame->PanelSettings->SetPosition(wxPoint(370,100));
        Frame->PanelSettings->Show();
        if (GetAddEnabled())
        {
            Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
            Frame->PanelAdd->Hide();   //przy pokazaniu panelu Settings schowaj ewentualnie panele Add...
            SetAddEnabled();
        }
        if (GetSaveEnabled())
        {
            Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
            Frame->PanelSave->Hide();   //...Save...
            SetSaveEnabled();
        }
        if (GetSearchEnabled())
        {
            Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
            Frame->I_SearchCtrl->Hide();     //...oraz pole Search
            Frame->I_PanelAdvSearch->Hide();
            SetSearchEnabled();
        }
    }
    SetSettingsEnabled();
}

void PanelInboxMaintance::EventButtonDeleteClick (AisdiRelationsFrame * Frame)
{
    //TODO dodać prompta o potwierdzenie
    //TODO dodać sprawdzenie czy baza ma maile
    //TODO dodąć sprawdzenie, czy emailIdSelected != ""
    Frame->database->deleteEmail(Frame->database->getEmail(Frame->database->findEmail(emailIdSelected)));
    Frame->P_Inbox->SetEmails(Frame);
    Frame->statistics->update();
    Frame->P_Inbox->SetAdvSearchDate(Frame);
    if (Frame->P_Stats->GetIsUpdated())
        Frame->P_Stats->SetIsUpdated();
}

void PanelInboxMaintance::EventButtonSenderClick (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventButtonReceiverClick (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventButtonShowTreeClick (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventListInboxColumnClick (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventCheckBoxDate (AisdiRelationsFrame * Frame, bool value)
{
    if (value)
    {
        Frame->I_Adv_ChoiceDayTo->Enable();
        Frame->I_Adv_ChoiceMonthTo->Enable();
        Frame->I_Adv_ChoiceYearTo->Enable();
        Frame->I_Adv_LabelDayTo->Enable();
        Frame->I_Adv_LabelMonthTo->Enable();
        Frame->I_Adv_LabelYearTo->Enable();
    }
    else
    {
        Frame->I_Adv_ChoiceDayTo->Disable();
        Frame->I_Adv_ChoiceMonthTo->Disable();
        Frame->I_Adv_ChoiceYearTo->Disable();
        Frame->I_Adv_LabelDayTo->Disable();
        Frame->I_Adv_LabelMonthTo->Disable();
        Frame->I_Adv_LabelYearTo->Disable();
    }
}

void PanelInboxMaintance::EventImageButtonRestoreClick (AisdiRelationsFrame* Frame)
{
    //TODO odkomentować
    //Frame->database->restoreDatabase();

    if (GetSaveEnabled())
    {
        Frame->I_ImageButtonSave->SetBitmapLabel(path+imagePaths[1]+format);
        Frame->PanelSave->Hide();
        SetSaveEnabled();
    }
    if (GetSettingsEnabled())
    {
        Frame->I_ImageButtonSettings->SetBitmapLabel(path+imagePaths[3]+format);
        Frame->PanelSettings->Hide();
        SetSettingsEnabled();
    }
    if (GetSearchEnabled())
    {
        Frame->I_ImageButtonSearch->SetBitmapLabel(path+imagePaths[2]+format);
        Frame->I_SearchCtrl->Hide();
        Frame->I_PanelAdvSearch->Hide();
        SetSearchEnabled();
    }
    if (GetAddEnabled())
    {
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[0]+format);
        Frame->PanelAdd->Hide();
        SetAddEnabled();
    }

    Frame->I_ImageButtonRestore->Hide();
    Frame->I_LabelRestore->Hide();
}
