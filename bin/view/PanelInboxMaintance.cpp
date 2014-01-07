#include "PanelInboxMaintance.h"
#include "PanelNotifyMaintance.h"

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
        
        Frame->PanelInbox->SetPosition(wxPoint(0,0));
        Frame->PanelInbox->Show();
    }
}

void PanelInboxMaintance::SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;     //obiekt reprezentujący etykietę
    const int COLUMN_COUNT = 5;   //liczba kolumns

    wxString labels[COLUMN_COUNT] = {_("Data:"), _("Temat:"), _("Od:"), _("Do:"), _("Treść")};      //etykiety
    int width[COLUMN_COUNT] = {90, 220, 160, 160, 1};      //szerokości kolumn, sumuje się do 630px

    for (int i = 0; i < COLUMN_COUNT; i++)         //przypisujemy w pętli etykiety do kolumn listy
    {
        col.SetId(i);
        col.SetText(labels[i]);
        col.SetWidth(width[i]);
        Frame->I_ListInbox->InsertColumn(i, col);
    }
}

void PanelInboxMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
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
    Frame->I_ImageButtonTitle->SetBitmapLabel(path+imagePaths[12]+format);
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

            string sourceString = email->getContent();
            wxString content(sourceString.c_str(), wxConvUTF8);
            Frame->I_ListInbox->SetItem(i,4, content);

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
}

void PanelInboxMaintance::SetSearchEnabled()
{
    searchEnabled = !searchEnabled;
}

void PanelInboxMaintance::SetAddEnabled()
{
    addEnabled = !addEnabled;
}

bool PanelInboxMaintance::GetSearchEnabled()
{
    return searchEnabled;
}

bool PanelInboxMaintance::GetAddEnabled()
{
    return addEnabled;
}

void PanelInboxMaintance::EventButtonSearchClick (AisdiRelationsFrame* Frame)
{
    if (Frame->P_Inbox->GetSearchEnabled())
        Frame->I_SearchCtrl->Hide();
    else
        Frame->I_SearchCtrl->Show();
    Frame->P_Inbox->SetSearchEnabled();
}

void PanelInboxMaintance::EventListInboxItemSelect (AisdiRelationsFrame* Frame)
{
    const int COL_COUNT = 5;	//TODO wrzucić to do private
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

    const string search = "\n";
    const string replace = "<br>";
    string subject = string (contents[4].mb_str());
    string htmlContent = Frame->iointerface->strSequenceReplace("\n", "<br>", subject);

    wxString pContent (htmlContent.c_str(), wxConvUTF8 );
    Frame->I_HtmlEmailContent->SetPage(pOpen+pContent+pClose);
    Frame->I_HtmlEmailContent->SetBackgroundColour(wxColor(20,20,20));
}

void PanelInboxMaintance::EventButtonAddClick (AisdiRelationsFrame * Frame)
{
    if (GetAddEnabled())
        Frame->PanelAdd->Hide();
    else
        Frame->PanelAdd->Show();
    SetAddEnabled();
}

void PanelInboxMaintance::EventButtonSaveClick (AisdiRelationsFrame * Frame)
{
    if (Frame->FileDialogDatabaseExport->ShowModal() == wxID_OK)      //uruchomienie panelu wybierania folderu
    {
        wxString path, filename;
        path = Frame->FileDialogDatabaseExport->GetPath();
        filename = Frame->FileDialogDatabaseExport->GetFilename();

        std::string strPath, strFilename;
        strPath = path.mb_str();
        strFilename = filename.mb_str();

        if (strFilename != "")
        {
            if (strPath.substr(strPath.size()-4, 4) != ".bin")
                strPath = strPath+".bin";

            std::ofstream ofs(strPath);
            boost::archive::text_oarchive oa(ofs);
            oa << Frame->database;

            Frame->P_Notify->SetLabels(Frame, "Zapisano plik bazy.", "Nazwa pliku: ");
            Frame->P_Notify->SetValues(Frame, strFilename);
            Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
        }
    }
}

void PanelInboxMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventButtonDeleteClick (AisdiRelationsFrame * Frame)
{

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

void PanelInboxMaintance::EventSearchCtrlTextEnter (AisdiRelationsFrame * Frame)
{

}

void PanelInboxMaintance::EventListInboxColumnClick (AisdiRelationsFrame * Frame)
{

}
