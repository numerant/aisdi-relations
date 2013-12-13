#include "PanelInboxMaintance.h"

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

        Frame->PanelInbox->SetPosition(wxPoint(0,0));
        Frame->PanelInbox->Show();
    }
}

void PanelInboxMaintance::SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;     //obiekt reprezentujący etykietę
    const int COLUMN_COUNT = 5;   //liczba kolumns

    wxString labels[COLUMN_COUNT] = {_("Data:"), _("Temat:"), _("Od:"), _("Do:"), _("Treść")};      //etykiety
    int width[COLUMN_COUNT] = {80, 220, 125, 125, 1};      //szerokości kolumn, sumuje się do 550px

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
    if (Frame->database->countEmails() > 0)
    {
        //Frame->I_ListInbox->ClearAll();
        for (int i = 0; i < Frame->database->countEmails(); i++)
        {
            Email * email = Frame->database->getEmail(i);
            wxListItem item;
            item.SetId(i);
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
            ostringstream ss;
            ss << day;
            string strdate = ss.str();
        }
    }
}

void PanelInboxMaintance::SetSearchEnabled()
{
    searchEnabled = !searchEnabled;
}

bool PanelInboxMaintance::GetSearchEnabled()
{
    return searchEnabled;
}
