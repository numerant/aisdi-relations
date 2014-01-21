#include "PanelGroupsMaintance.h"

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

        Frame->relations->makeGroups();  //TODO podpiąć to pod dodawanie emaili
        DrawGroups(Frame);

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

void PanelGroupsMaintance::SetSettingsEnabled()
{
    settingsEnabled = !settingsEnabled;
}

void PanelGroupsMaintance::DrawGroups (AisdiRelationsFrame* Frame)
{
    //Dostęp do relacji  Frame->realations->
    //Dostęp do bazy  Frame->database->


    /** NIE DZIAŁA */

    /*if (treeEnabled)
    {
        delete Tree;
        DeleteNodes(Frame);
        treeEnabled = false;
    }

    Tree = new wxTreeCtrl(Frame->PanelGroups, 1000, wxPoint(15,100), wxSize(300,600), wxTR_FULL_ROW_HIGHLIGHT|wxTR_MULTIPLE|wxTR_EXTENDED|wxTR_DEFAULT_STYLE|wxNO_BORDER|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _("TREEID"));
    Tree->SetForegroundColour(wxColour(48,48,48));
    Tree->SetBackgroundColour(wxColour(144,144,144));
    wxFont TreeFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Ubuntu"),wxFONTENCODING_DEFAULT);
    Tree->SetFont(TreeFont);
    wxTreeItemId root = Tree->AddRoot(_T("root"));
    AddNode(root);  //zapisz roota (adres 0) jednorazowo

    //Ustawianie pól
    wxTreeItemId item =  Tree->AppendItem(root, _T("yep1"));     //pierwsza, najwyższa grupa
    AddNode(item);  //pamiętamy node'a  (adres 1)
    item =  Tree->AppendItem(GetNode(1), _T("yepyep1"));     //element pierwszej grupy (też może być grupą)
    AddNode(item);  //pamiętamy node'a  (adres 2)
    item =  Tree->AppendItem(GetNode(0), _T("yep2"));    //druga, najwyższa grupa
    AddNode(item);  //pamiętamy node'a  (adres 3)       itd....
    item =  Tree->AppendItem(GetNode(3), _T("yepyep2"));
    AddNode(item);
    item =  Tree->AppendItem(GetNode(4), _T("yepyepyep2"));
    AddNode(item);

    //Wyświetl wszystko
    Tree->ExpandAll();
    treeEnabled = true; */
}

void PanelGroupsMaintance::AddNode (wxTreeItemId id)
{
    treeNodes.push_back (id);
}

void PanelGroupsMaintance::DeleteNodes(AisdiRelationsFrame * Frame)
{
    if (treeNodes.size() != 0)
    {
        unsigned int counter = treeNodes.size();
        for (unsigned int i = 0; i < counter - 1; i++)
            treeNodes.pop_back();
    }
}

bool PanelGroupsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

bool PanelGroupsMaintance::GetSettingsEnabled()
{
    return settingsEnabled;
}

wxTreeItemId PanelGroupsMaintance::GetNode (unsigned int position)
{
    //TODO Rzuć wyjątkiem o ścianę, jak podadzą Ci zły position
    return treeNodes[position];
}

unsigned int PanelGroupsMaintance::GetTreeNodesSize()
{

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
