#include "PanelTitleMaintance.h"

PanelTitleMaintance::PanelTitleMaintance ()
{

}

void PanelTitleMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();       //przywrócenie widoczności panelu i ukrycie pozostałych
        Frame->PanelGroups->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelStatistics->Hide();
        Frame->PanelMulTree->Hide();

        Frame->PanelTitle->SetPosition(wxPoint(0,0));
        Frame->PanelTitle->Show();

        Frame->T_PanelSettings->Hide();	//ukrycie panelu opcji wraz z obramowaniem
        Frame->T_BorderSettings->Hide();

        Frame->P_Title->SetNoData( ! (Frame->P_Title->GetNoData() ) ); //Zmień ikony, ale z zanegowaną wartością parametru
        Frame->P_Title->SwitchIcons(Frame);                            //Więc de facto tylko je wyświetl
    }
}

void PanelTitleMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
    wxString pathBig(_("resources/iconsBig/icon"));
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->T_ImageButtonAdd->SetBitmapLabel(pathBig+imagePaths[0]+format);      //załadowanie grafik pod przyciski
    Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+format);
    Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+format);
    Frame->T_ImageButtonFiles->SetBitmapLabel(pathBig+imagePaths[3]+format);
    Frame->T_ImageButtonFolder->SetBitmapLabel(pathBig+imagePaths[4]+format);
    Frame->T_ImageButtonBin->SetBitmapLabel(pathBig+imagePaths[5]+format);
    Frame->T_ImageButtonTxt->SetBitmapLabel(pathBig+imagePaths[6]+format);
    Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);
    Frame->T_ImageButtonInbox->SetBitmapLabel(pathBig+imagePaths[8]+format);
    Frame->T_ImageButtonUsembers->SetBitmapLabel(pathBig+imagePaths[9]+format);
    Frame->T_ImageButtonGroups->SetBitmapLabel(pathBig+imagePaths[10]+format);
    Frame->T_ImageButtonStats->SetBitmapLabel(pathBig+imagePaths[11]+format);
    Frame->T_ImageButtonMulTree->SetBitmapLabel(pathBig+imagePaths[12]+format);
}

void PanelTitleMaintance::SwitchIcons (AisdiRelationsFrame* Frame)
{
    if (noData)
    {
        Frame->T_ImageButtonAdd->Hide();            //ukryj przyciski dodawania maili
        Frame->T_ImageButtonImport->Hide();
        Frame->T_ImageButtonTxt->Hide();
        Frame->T_ImageButtonBin->Hide();
        Frame->T_ImageButtonLoad->Hide();
        Frame->T_ImageButtonFolder->Hide();
        Frame->T_ImageButtonFiles->Hide();
        Frame->T_LabelAdd->Hide();
        Frame->T_LabelImport->Hide();
        Frame->T_LabelTxt->Hide();
        Frame->T_LabelBin->Hide();
        Frame->T_LabelLoad->Hide();
        Frame->T_LabelFolder->Hide();
        Frame->T_LabelFiles->Hide();
        Frame->T_StaticLineAddH->Hide();
        Frame->T_StaticLineAddV->Hide();
        Frame->T_StaticLineImportH->Hide();
        Frame->T_StaticLineOpenH->Hide();

        Frame->T_ImageButtonInbox->Show();          //pokaż przycisku menu
        Frame->T_ImageButtonGroups->Show();
        Frame->T_ImageButtonUsembers->Show();
        Frame->T_ImageButtonStats->Show();
        Frame->T_ImageButtonMulTree->Show();
        Frame->T_LabelInbox->Show();
        Frame->T_LabelGroups->Show();
        Frame->T_LabelUsembers->Show();
        Frame->T_LabelStats->Show();
        Frame->T_LabelMulTree->Show();
        if (Frame->P_Title->GetClickedSettings())
        {
            Frame->P_Title->SetClickedSettings();
            Frame->T_PanelSettings->Hide();
            Frame->T_BorderSettings->Hide();
        }

    }
    else
    {
        UpdateLoadingIcons(Frame);      //pokaż, ale tylko te które były poprzednio aktywne

        Frame->T_ImageButtonInbox->Hide();          //ukryj przyciski menu
        Frame->T_ImageButtonGroups->Hide();
        Frame->T_ImageButtonUsembers->Hide();
        Frame->T_ImageButtonStats->Hide();
        Frame->T_ImageButtonMulTree->Hide();
        Frame->T_LabelInbox->Hide();
        Frame->T_LabelGroups->Hide();
        Frame->T_LabelUsembers->Hide();
        Frame->T_LabelStats->Hide();
        Frame->T_LabelMulTree->Hide();
    }

    noData = !noData;
}

void PanelTitleMaintance::UpdateLoadingIcons (AisdiRelationsFrame* Frame)
{
    Frame->T_ImageButtonAdd->Show();  //ten przycisk jest zawsze dla  noData == true
    Frame->T_LabelAdd->Show();

    if ( !clickedAdd )
    {
        //ukryj przyciski dodawania maili
        Frame->T_ImageButtonImport->Hide();
        Frame->T_ImageButtonTxt->Hide();
        Frame->T_ImageButtonBin->Hide();
        Frame->T_ImageButtonLoad->Hide();
        Frame->T_ImageButtonFolder->Hide();
        Frame->T_ImageButtonFiles->Hide();
        Frame->T_LabelImport->Hide();
        Frame->T_LabelTxt->Hide();
        Frame->T_LabelBin->Hide();
        Frame->T_LabelLoad->Hide();
        Frame->T_LabelFolder->Hide();
        Frame->T_LabelFiles->Hide();
        Frame->T_StaticLineAddH->Hide();
        Frame->T_StaticLineAddV->Hide();
        Frame->T_StaticLineImportH->Hide();
        Frame->T_StaticLineOpenH->Hide();
    }
    else if ( (clickedAdd) && ( !clickedImport) && ( !clickedLoad) )
    {
        Frame->T_ImageButtonImport->Show();
        Frame->T_ImageButtonLoad->Show();
        Frame->T_LabelImport->Show();
        Frame->T_LabelLoad->Show();
        Frame->T_StaticLineAddH->Show();
        Frame->T_StaticLineAddV->Show();

        Frame->T_ImageButtonTxt->Hide();
        Frame->T_ImageButtonBin->Hide();
        Frame->T_ImageButtonFolder->Hide();
        Frame->T_ImageButtonFiles->Hide();
        Frame->T_LabelTxt->Hide();
        Frame->T_LabelBin->Hide();
        Frame->T_LabelFolder->Hide();
        Frame->T_LabelFiles->Hide();
        Frame->T_StaticLineImportH->Hide();
        Frame->T_StaticLineOpenH->Hide();
    }
    else if ( (clickedAdd) && (!clickedImport) && ( clickedLoad) )
    {
        Frame->T_ImageButtonImport->Show();
        Frame->T_ImageButtonLoad->Show();
        Frame->T_ImageButtonFolder->Show();
        Frame->T_ImageButtonFiles->Show();
        Frame->T_LabelImport->Show();
        Frame->T_LabelLoad->Show();
        Frame->T_LabelFolder->Show();
        Frame->T_LabelFiles->Show();
        Frame->T_StaticLineAddH->Show();
        Frame->T_StaticLineAddV->Show();
        Frame->T_StaticLineOpenH->Show();

        Frame->T_ImageButtonTxt->Hide();
        Frame->T_ImageButtonBin->Hide();
        Frame->T_LabelTxt->Hide();
        Frame->T_LabelBin->Hide();
        Frame->T_StaticLineImportH->Hide();
    }
    else if ( (clickedAdd) && ( clickedImport) && ( !clickedLoad) )
    {
        Frame->T_ImageButtonImport->Show();
        Frame->T_ImageButtonLoad->Show();
        Frame->T_ImageButtonTxt->Show();
        Frame->T_ImageButtonBin->Show();
        Frame->T_LabelLoad->Show();
        Frame->T_LabelImport->Show();
        Frame->T_LabelTxt->Show();
        Frame->T_LabelBin->Show();
        Frame->T_StaticLineAddH->Show();
        Frame->T_StaticLineAddV->Show();
        Frame->T_StaticLineImportH->Show();

        Frame->T_ImageButtonFolder->Hide();
        Frame->T_ImageButtonFiles->Hide();
        Frame->T_LabelFolder->Hide();
        Frame->T_LabelFiles->Hide();
        Frame->T_StaticLineOpenH->Hide();
    }
}

void PanelTitleMaintance::SetNoData (bool value)
{
    noData = value;
}

void PanelTitleMaintance::SetRecursiveLoad (bool value)
{
    recursiveLoad = value;
}

void PanelTitleMaintance::SetClickedAdd (void)
{
    clickedAdd = !clickedAdd;
}

void PanelTitleMaintance::SetClickedLoad (void)
{
    clickedLoad = !clickedLoad;
    if (clickedLoad)
        clickedImport = false;
}

void PanelTitleMaintance::SetClickedImport (void)
{
    clickedImport = !clickedImport;
    if (clickedImport)
        clickedLoad = false;
}

void PanelTitleMaintance::SetClickedSettings (void)
{
    clickedSettings = !clickedSettings;
}

bool PanelTitleMaintance::GetNoData (void)
{
    return noData;
}

bool PanelTitleMaintance::GetRecursiveLoad (void)
{
    return recursiveLoad;
}

bool PanelTitleMaintance::GetClickedAdd (void)
{
    return clickedAdd;
}

bool PanelTitleMaintance::GetClickedLoad (void)
{
    return clickedLoad;
}

bool PanelTitleMaintance::GetClickedImport (void)
{
    return clickedImport;
}

bool PanelTitleMaintance::GetClickedSettings (void)
{
    return clickedSettings;
}

void PanelTitleMaintance::EventButtonAddClick (AisdiRelationsFrame* Frame)
{
    Frame->P_Title->SetClickedAdd();
    if (! Frame->P_Title->GetClickedAdd())
    {
        if ( Frame->P_Title->GetClickedLoad() )
            Frame->P_Title->SetClickedLoad();
        if ( Frame->P_Title->GetClickedImport() )
            Frame->P_Title->SetClickedImport();
    }
    Frame->P_Title->UpdateLoadingIcons(Frame);
}

void PanelTitleMaintance::EventButtonFolderClick (AisdiRelationsFrame* Frame)
{
    if (Frame->DirDialog->ShowModal() == wxID_OK)		//uruchomienie panelu wybierania folderu
    {													//jeśli wybrano folder:
        MailParameters * param = new MailParameters();	//nowe parametry wczytywania maili
        wxString str = Frame->DirDialog->GetPath();		//weź ścieżkę do folderu z Directory Dialog
        param->path = str.mb_str();
        param->isDirectory = true;
        param->recursiveImport = GetRecursiveLoad();

        IOInterface::ImportStats stats;					//statystyki wczytania
        Frame->iointerface->importMail(param);
        stats = Frame->iointerface->getImportStats();
        Frame->iointerface->clearImportStats();

        Frame->P_Inbox->SetEmails(Frame);				//załadowanie listy maili do komponentu T_ListInbox
        if (stats.successCount > 0)
        {
            Frame->P_Title->SwitchIcons(Frame);
            wxMessageBox(_("Pomyślnie wczytano!"));     //TODO Zamienić na wyświetlanie raportu
        }
    }
}

void PanelTitleMaintance::EventButtonFilesClick (AisdiRelationsFrame* Frame)
{
    if (Frame->FileDialog->ShowModal() == wxID_OK)		//uruchomienie panelu wybierania folderu
    {													//jeśli wybrano pliki:
        wxArrayString paths;							//tablica plików do wczytania
        Frame->FileDialog->GetPaths(paths);
        MailParameters * param = new MailParameters();
        param->path = paths[0].mb_str();				//TODO Zmienić, bo na razie bierze tylko pierwszy z tablicy
        param->isDirectory = false;						//Tutaj domyślne opcje na 'false' (bo wybieramy pliki, nie folder)
        param->recursiveImport = false;

        IOInterface::ImportStats stats;					//statystyki importu maili
        Frame->iointerface->importMail(param);
        stats = Frame->iointerface->getImportStats();
        Frame->iointerface->clearImportStats();

        Frame->P_Inbox->SetEmails(Frame);				//załadowanie listy Emaili z bazy
        if (stats.successCount > 0)
        {
            Frame->P_Title->SwitchIcons(Frame);
            wxMessageBox(_("Pomyślnie wczytano!"));		//TODO zmienić na wyświetlanie raportu wczytania
        }
    }
}

void PanelTitleMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
	if (GetClickedSettings())
	{
		Frame->T_PanelSettings->Hide();
		Frame->T_BorderSettings->Hide();
	}
	else
	{
		Frame->T_PanelSettings->Show();
		Frame->T_BorderSettings->Show();
	}
	SetClickedSettings();
}

void PanelTitleMaintance::TxtImport ()
{

}

void PanelTitleMaintance::BinImport ()
{

}
