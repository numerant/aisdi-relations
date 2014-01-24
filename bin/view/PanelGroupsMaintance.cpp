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

       
            if (Frame->relations != nullptr)
                delete Frame->relations;

            Frame->relations = new Relations(Frame->database);

          
        if (Frame->relations != nullptr)
            Frame->relations->runAlgorithm();  

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
    col.SetWidth(600);
    Frame->G_ListGroups->InsertColumn(0, col);

    col.SetId(1);
    col.SetText(_("Id"));
    col.SetWidth(1);
    Frame->G_ListGroups->InsertColumn(1, col);

    col.SetId(0);
    col.SetText(_("Członkowie grupy"));
    col.SetWidth(580);
    Frame->G_ListMembers->InsertColumn(0, col);

    col.SetId(1);
    col.SetText(_("Email"));
    col.SetWidth(1);
    Frame->G_ListMembers->InsertColumn(1, col);

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
        groupSelectedId = -1;
        usemberSelectedAdress = "";
        return;
    }

    groupSelectedId = 0;

    vector<int> levels;
    vector<int> ids;
    
    vector<string> labels;
    vector<string> addresses;

    Frame->relations->prepareForPrint(&levels, &labels, &ids, &addresses, Frame->relations->getGroup(Frame->relations->getFinalGroupsSize()-1));

    Frame->G_ListGroups->DeleteAllItems();
    
    if (Frame->relations->getFinalGroupsSize() != 0)
    {
        int groupCount = Frame->relations->getFinalGroupsSize();
        for (unsigned int i = 0; i < levels.size(); i++)
        {
            //wstawienie elementu
            wxListItem item;
            item.SetId(i);
            if (levels[i] % 2 == 0)
                item.SetTextColour(wxColor(200,200,200));
            Frame->G_ListGroups->InsertItem( item );

            //zmiana jego wartości
            string nazwa = "";
            for (int k = 0; k < levels[i]; k++)
                nazwa+="         ";

            nazwa+=labels[i];
            wxString nazwaWx (nazwa.c_str(), wxConvUTF8);
            Frame->G_ListGroups->SetItem(i,0, nazwaWx);

            //nadanie id do pola
            if(addresses[i] == "brak")
            {
            int id = ids[i];     
            ostringstream ss;
            ss << id;
            string strID = ss.str();
            wxString idWx (strID.c_str(), wxConvUTF8);
            Frame->G_ListGroups->SetItem(i,1, idWx);
            }
            else
            {
            wxString idWx (addresses[i].c_str(), wxConvUTF8);
            Frame->G_ListGroups->SetItem(i,1, idWx);
             }               
        }
    }
    else
    {
        wxListItem item;
        item.SetId(0);
        Frame->G_ListGroups->InsertItem( item );
        wxString wxNoResults = _("            brak grup roboczych...");
        Frame->G_ListGroups->SetItem(0,0, wxNoResults);
        groupSelectedId = -1;
        usemberSelectedAdress = "";
    }
}

void PanelGroupsMaintance::SetMembers (AisdiRelationsFrame* Frame)
{

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

void PanelGroupsMaintance::EventListGroupsItemSelect(AisdiRelationsFrame * Frame)
{
    if (groupSelectedId == -1 && usemberSelectedAdress == "")
        return;

    Frame->PanelSettings->Hide();
    if (GetSettingsEnabled())
        SetSettingsEnabled();

    long itemIndex = -1;
    itemIndex = Frame->G_ListGroups->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    wxListItem item;
    item.m_itemId = itemIndex;
    item.m_mask = wxLIST_MASK_TEXT;
    item.m_col = 1;
    Frame->G_ListGroups->GetItem( item );

    wxString idWx = item.m_text;
    string idStr = (string) idWx.mb_str();
    string pattern = "-0123456789";
    if (pattern.find(idStr[0]) == std::string::npos)
    {
        //znaleziono adres usembera
        Usember * usember = Frame->database->getUsember(Frame->database->findUsember(idStr));
        if (usember != nullptr)
        {
            groupSelectedId = -1;
            usemberSelectedAdress = usember->getAddress();
            string s(usember->getGroup()->getName() + to_string(Frame->relations->level - usember->getGroup()->getLevel()));
            Frame->G_StaticTextName->SetLabel(wxString(s.c_str(), wxConvUTF8));
            Frame->G_StaticTextBoss->SetLabel(wxString(usember->getRealName().c_str(), wxConvUTF8));
            int emailCount = usember->sendMailCount() + usember->receiveMailCount();
            ostringstream ss;
            ss << emailCount;
            string strCount = ss.str();
            Frame->G_StaticTextCount->SetLabel(wxString(strCount.c_str(), wxConvUTF8));
        }
    }
    else
    {
        //znaleziono id grupy
        stringstream ss;
        ss.str(idStr);
        int id;
        ss >> id;

        Group * group = Frame->database->getGroup(Frame->database->findGroup(id));
        if (group != nullptr)
        {
            groupSelectedId = id;
            usemberSelectedAdress = "";
        }
        else
            return;

        string s(group->getName() + to_string(Frame->relations->level - group->getLevel()));
        Frame->G_StaticTextName->SetLabel(wxString(s.c_str(), wxConvUTF8));
        Frame->G_StaticTextBoss->SetLabel(wxString(group->getLeader()->getRealName().c_str(), wxConvUTF8));
        int count = group->getEmailsCount(Frame->database);
        ss.str("");
        ss << count;
        string strCount = ss.str();
        Frame->G_StaticTextCount->SetLabel(wxString(strCount.c_str(), wxConvUTF8));
        SetMembers(Frame);
    }
}
