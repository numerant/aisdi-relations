#include "PanelGroupsMaintance.h"
#include <cstdlib>

PanelGroupsMaintance::PanelGroupsMaintance()
{

}

void PanelGroupsMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelTitle->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelStatistics->Hide();
        Frame->PanelMulTree->Hide();

        Frame->PanelSettings->Hide();
        if (GetSettingsEnabled())
            SetSettingsEnabled();

        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);

        if (!relationsConstructed && Frame->database->countEmails() != 0)
        {
            if (Frame->relations != nullptr)
                delete Frame->relations;
            else
                Frame->relations = new Relations(Frame->database);

            relationsConstructed = true;
        }
        if (Frame->relations != nullptr)
            Frame->relations->runAlgorithm();  //TODO podpiąć to pod dodawanie emaili

        SetGroups(Frame);

        Frame->PanelGroups->SetPosition(wxPoint(0,0));
        Frame->PanelGroups->Show();

    }
}

void PanelGroupsMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    Frame->G_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->G_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->G_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->G_ImageButtonStats->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->G_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
}

void PanelGroupsMaintance::SetLabels(AisdiRelationsFrame* Frame)
{
    wxListItem col;     //obiekt reprezentujący etykietę

    col.SetId(0);       //tylko jedna kolumna
    col.SetText(_("Grupy robocze"));
    col.SetWidth(630);
    Frame->G_ListGroups->InsertColumn(0, col);

    SetGroups(Frame);
}

void PanelGroupsMaintance::SetGroups (AisdiRelationsFrame * Frame)
{
    Frame->G_ListGroups->DeleteAllItems();

    if (Frame->database->countEmails() == 0)
    {
        wxListItem item;
        item.SetId(0);
        Frame->G_ListGroups->InsertItem( item );
        wxString wxNoResults = _("            brak grup roboczych...");
        Frame->G_ListGroups->SetItem(0,0, wxNoResults);
        return;
    }

    //Frame->relations->saveGroupsInDatabase();
    vector<int> levels;//= {0,1,2,3,1,2,1};
    //char* tmp;
    //sprintf(tmp, "%d", Frame->database->countGroups());
    //string s = to_string(Frame->database->countGroups());
    vector<string> labels; //= {s,"G1_1","C1", "Lol", "Lol2","LOl3","ROFL"};

    Frame->relations->prepareForPrint(&levels, &labels, Frame->relations->getGroup(Frame->relations->getFinalGroupsSize()-1));

    Frame->G_ListGroups->DeleteAllItems();
    //Jeżeli grupy są już wygenerowane algorytmem
    //if (Frame->database->countGroups() != 0)
    if (Frame->relations->getFinalGroupsSize() != 0)//Frame->database->countGroups() != 0)      //TODO zmienić warunek
    {
        int groupCount = Frame->relations->getFinalGroupsSize();     //temp <- zmień na rzeczywistą liczbę grup (równą liczbie pól wektorów przy okazji)
        for (unsigned int i = 0; i < levels.size(); i++)
        {
            //wstawienie elementu
            wxListItem item;
            item.SetId(i);
            if (levels[i] % 2 == 0)
                item.SetTextColour(wxColor(200,200,200));
            Frame->G_ListGroups->InsertItem( item );

            //zmiane jego wartości
            string nazwa = "";
            for (int k = 0; k < levels[i]; k++)
                nazwa+="         ";

            nazwa+=labels[i];
            wxString nazwaWx (nazwa.c_str(), wxConvUTF8);
            Frame->G_ListGroups->SetItem(i,0, nazwaWx);
        }
    }
    else
    {
        wxListItem item;
        item.SetId(0);
        Frame->G_ListGroups->InsertItem( item );
        wxString wxNoResults = _("            brak grup roboczych...");
        Frame->G_ListGroups->SetItem(0,0, wxNoResults);
    }
}

void PanelGroupsMaintance::SetRelationsConstructed (bool value)
{
    relationsConstructed = value;
}

void PanelGroupsMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

bool PanelGroupsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

bool PanelGroupsMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

void PanelGroupsMaintance::EventButtonSettingsClick(AisdiRelationsFrame* Frame)
{
    if (GetSettingsEnabled())
    {
        Frame->PanelSettings->Hide();
        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+format);
    }
    else
    {
        Frame->G_ImageButtonSettings->SetBitmapLabel(path+imagePaths[5]+formatNeg);
        Frame->PanelSettings->SetPosition(wxPoint(100,100));
        Frame->PanelSettings->Show();
    }
    SetSettingsEnabled();
}
