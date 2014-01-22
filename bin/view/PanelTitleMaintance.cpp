#include "PanelTitleMaintance.h"
#include "PanelUsembersMaintance.h"

// TEMP - serializacja!
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/tmpdir.hpp>
#include <fstream>
#include "../../src/Serialization.h"

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

        if (GetClickedSettings())
            SetClickedSettings();
        Frame->PanelSettings->Hide();	//ukrycie panelu opcji
        Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);  //przywrócenie prawidłowej grafiki przyciskowi settings

        if (!GetNoData())
        {
            if (GetClickedAdd())
                SetClickedAdd();
            if (GetClickedImport())
                SetClickedImport();
            if (GetClickedLoad())
                SetClickedLoad();
            SetNoData(true);
        }

        Frame->P_Title->SwitchIcons(Frame);

        Frame->PanelTitle->SetPosition(wxPoint(0,0));
        Frame->PanelTitle->Show();
    }
}

void PanelTitleMaintance::SetIcons(AisdiRelationsFrame* Frame)
{
    Frame->T_ImageButtonAdd->SetBitmapLabel(pathBig+imagePaths[0]+format);      //załadowanie grafik pod przyciski panelu Title
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
    Frame->T_ImageButtonSwitch->SetBitmapLabel(path+imagePaths[13]+format);

    Frame->A_ImageButtonFiles->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->A_ImageButtonFolder->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->A_ImageButtonBin->SetBitmapLabel(path+imagePaths[14]+format);

    Frame->Sav_ImageButtonBin->SetBitmapLabel(path+imagePaths[14]+format);
    Frame->Sav_ImageButtonTxt->SetBitmapLabel(path+imagePaths[15]+format);
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
            Frame->PanelSettings->Hide();
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

    if (GetClickedSettings())
        SetClickedSettings();
    Frame->PanelSettings->Hide();
    Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);

    if ( !clickedAdd )
    {
        Frame->T_ImageButtonAdd->SetBitmapLabel(pathBig+imagePaths[0]+format);
        Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+format);
        Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+format);

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
        Frame->T_ImageButtonAdd->SetBitmapLabel(pathBig+imagePaths[0]+formatNeg);
        Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+format);
        Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+format);

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
        Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+formatNeg);
        Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+format);

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
        Frame->T_ImageButtonImport->SetBitmapLabel(pathBig+imagePaths[1]+formatNeg);
        Frame->T_ImageButtonLoad->SetBitmapLabel(pathBig+imagePaths[2]+format);

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

void PanelTitleMaintance::NewProgramInstance (AisdiRelationsFrame* Frame)
{
    Frame->P_Title->ShowPanel(Frame);

    delete Frame->iointerface;      //usuń stare dane
    delete Frame->statistics;
    if (Frame->relations != nullptr)
    {
        delete Frame->relations;
        Frame->P_Groups->SetRelationsConstructed(false);
        Frame->relations = nullptr;
    }
    delete Frame->database;

    delete Frame->P_Groups;
    delete Frame->P_Inbox;
    delete Frame->P_MulTree;
    delete Frame->P_Stats;
    delete Frame->P_Usembers;
    delete Frame->P_Notify;

    Frame->database = new Database();      //zaalokuj nowe obiekty
    Frame->iointerface = new IOInterface();
    Frame->iointerface->setDatabasePointer(Frame->database);
    Frame->statistics = new Statistics(Frame->database);

    Frame->P_Groups = new PanelGroupsMaintance();
    Frame->P_Inbox = new PanelInboxMaintance();
    Frame->P_MulTree = new PanelMulTreeMaintance();
    Frame->P_Stats = new PanelStatisticsMaintance();
    Frame->P_Usembers = new PanelUsembersMaintance();
    Frame->P_Notify = new PanelNotifyMaintance();

     //inicjalizacja ikon oraz etykiet w panelach
    Frame->U_ListUsembers->DeleteAllItems();
    Frame->U_ListInbox->DeleteAllItems();
    Frame->U_ListOutbox->DeleteAllItems();
    Frame->P_Usembers->ClearUsemberInfo(Frame);
    Frame->P_Usembers->SetEmails(Frame, -1);
    Frame->P_Usembers->SetUsembers(Frame);

    Frame->I_ListInbox->DeleteAllItems();
    Frame->P_Inbox->SetEmails(Frame);

    Frame->PanelNotify->Hide();
    Frame->PanelAdd->Hide();
    Frame->PanelSave->Hide();
    Frame->PanelSettings->Hide();

    DeleteAutoSave(Frame);
}

void PanelTitleMaintance::AutoSave (AisdiRelationsFrame* Frame)
{
    DbParameters exportParameters;
    if (Frame->database->countEmails() == 0)
    {
        Frame->P_Notify->SetLabels(Frame, "Baza jest pusta.");
        Frame->P_Notify->SetValues(Frame, "");
        Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
        return;
    }

    exportParameters.password = "";
    exportParameters.isPasswordProtected = false;

    string strPath = "./sav_tmp.bin";

    Frame->iointerface->exportDatabase(strPath, &exportParameters);

    Frame->P_Notify->SetLabels(Frame, "Zapisano plik tymczasowy", "  Nazwa pliku:", "    sav_tmp.bin");
    Frame->P_Notify->SetValues(Frame, "");
    Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
}

void PanelTitleMaintance::LoadAutoSave (AisdiRelationsFrame* Frame)
{
    DbParameters importParameters;
    importParameters.password = "";
    importParameters.isPasswordProtected = false;
    string strPath = "./sav_tmp.bin";

    try
    {
        Frame->iointerface->isImportedFileProtected(strPath);
        Frame->database = Frame->iointerface->importDatabase(&importParameters);     // po wczytaniu zmienia się wartość wskaźnika na bazę danych!

        delete Frame->statistics;
        Frame->statistics = new Statistics(Frame->database);

        Frame->P_Inbox->SetEmails(Frame);               //załadowanie listy maili i usemberów z bazy
        Frame->P_Usembers->SetUsembers(Frame);

        if (GetNoData())
            Frame->P_Title->SwitchIcons(Frame);
        Frame->statistics->update();
        Frame->P_Inbox->SetAdvSearchDate(Frame);
        if (Frame->P_Stats->GetIsUpdated())
            Frame->P_Stats->SetIsUpdated();

        if (! Frame->P_Usembers->GetUsembersListEnabled())
            Frame->P_Usembers->SetUsembersListEnabled();

        Frame->P_Usembers->SetEmails(Frame, -1);        //usuń maile From i To z komponentu
        if (Frame->P_Usembers->GetEmailContentEnabled())
            Frame->P_Usembers->SetEmailContentEnabled();

        Frame->P_Usembers->ClearUsemberInfo(Frame);

        Frame->P_Notify->SetLabels(Frame, "Odzyskano plik zapisu", "Status:");
        Frame->P_Notify->SetValues(Frame, "Wczytano");
        Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
    }
    catch(UnableToOpenFile exception)
    {
        Frame->P_Notify->SetLabels(Frame, "Odzyskiwanie pliku zapisu", "Nie można otworzyć pliku!");
        Frame->P_Notify->SetValues(Frame, "", "     Błąd!");
        Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
    }
    catch(InvalidFile exception)
    {
        Frame->P_Notify->SetLabels(Frame, "Odzyskiwanie pliku zapisu", "Plik nie jest poprawny!");
        Frame->P_Notify->SetValues(Frame, "", "     Błąd!");
        Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
    }
}

void PanelTitleMaintance::DeleteAutoSave (AisdiRelationsFrame* Frame)
{
    std::remove("sav_tmp.bin");
}

void PanelTitleMaintance::SetNoData (bool value)
{
    noData = value;
}

void PanelTitleMaintance::SetRecursiveLoad (bool value)
{
    recursiveLoad = value;
}

void PanelTitleMaintance::SetDeleteConfirm (bool value)
{
    deleteConfirm = value;
}

void PanelTitleMaintance::SetDatabaseEncryption (bool value)
{
    databaseEncryption = value;
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

bool PanelTitleMaintance::GetDeleteConfirm (void)
{
    return deleteConfirm;
}

bool PanelTitleMaintance::GetDatabaseEncryption (void)
{
    return databaseEncryption;
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

        /* Schowanie PanelAdd i zmiana grafik przycisków dodawania na domyślne */
        if (Frame->P_Inbox->GetAddEnabled())
            Frame->P_Inbox->SetAddEnabled();
        if (Frame->P_Usembers->GetAddEnabled())
            Frame->P_Usembers->SetAddEnabled();
        Frame->PanelAdd->Hide();
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);
        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);

        MailParameters * param = new MailParameters();	//nowe parametry wczytywania maili
        wxString str = Frame->DirDialog->GetPath();		//weź ścieżkę do folderu z Directory Dialog
        param->path = str.mb_str();
        param->isDirectory = true;
        param->recursiveImport = GetRecursiveLoad();

        IOInterface::ImportStats stats;					//statystyki wczytania
        Frame->iointerface->importMail(param);
        stats = Frame->iointerface->getImportStats();
        Frame->iointerface->clearImportStats();
        delete param;

        if (stats.successCount > 0)
        {
            Frame->P_Inbox->SetEmails(Frame);               //załadowanie listy maili i usemberów z bazy
            Frame->P_Usembers->SetUsembers(Frame);

            if (GetNoData())
                Frame->P_Title->SwitchIcons(Frame);

            Frame->P_Notify->SetLabels(Frame, "Zakończono wczytywanie!", "Wczytano poprawnie:", "Niepoprawne emaile:", "Powtórzone rekordy:");
            Frame->P_Notify->SetValues(Frame, stats.successCount, stats.failCount, stats.existingCount);
            Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            Frame->statistics->update();
            Frame->P_Inbox->SetAdvSearchDate(Frame);
            if (Frame->P_Stats->GetIsUpdated())
                Frame->P_Stats->SetIsUpdated();

            if (! Frame->P_Usembers->GetUsembersListEnabled())
                Frame->P_Usembers->SetUsembersListEnabled();

            Frame->P_Usembers->SetEmails(Frame, -1);        //usuń maile From i To z komponentu
            if (Frame->P_Usembers->GetEmailContentEnabled())
                Frame->P_Usembers->SetEmailContentEnabled();

            Frame->P_Usembers->ClearUsemberInfo(Frame);
        }
    }
}

void PanelTitleMaintance::EventButtonFilesClick (AisdiRelationsFrame* Frame)
{
    if (Frame->FileDialog->ShowModal() == wxID_OK)		//uruchomienie panelu wybierania folderu
    {													//jeśli wybrano pliki:

        /* Schowanie PanelAdd i zmiana grafik przycisków dodawania na domyślne */
        if (Frame->P_Inbox->GetAddEnabled())
            Frame->P_Inbox->SetAddEnabled();
        if (Frame->P_Usembers->GetAddEnabled())
            Frame->P_Usembers->SetAddEnabled();
        Frame->PanelAdd->Hide();
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);
        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);

        wxArrayString paths;							//tablica plików do wczytania
        Frame->FileDialog->GetPaths(paths);
        MailParameters * param = new MailParameters();
        IOInterface::ImportStats stats;					//statystyki importu maili

        param->isDirectory = false;						//Tutaj domyślne opcje na 'false' (bo wybieramy pliki, nie folder)
        param->recursiveImport = false;

        if (paths.size() > 0)
        {
            for (unsigned int i = 0; i < paths.size(); i++)       //Wczytujemy w pętli pliki
            {
                param->path = paths[i].mb_str();
                Frame->iointerface->importMail(param);
            }
        }
        delete param;
        stats = Frame->iointerface->getImportStats();
        Frame->iointerface->clearImportStats();

        if (stats.successCount > 0)
        {
            Frame->P_Inbox->SetEmails(Frame);               //załadowanie listy maili i usemberów z bazy
            Frame->P_Usembers->SetUsembers(Frame);

            if (GetNoData())
                Frame->P_Title->SwitchIcons(Frame);
            Frame->P_Notify->SetLabels(Frame, "Zakończono wczytywanie!", "Wczytano poprawnie:", "Niepoprawne emaile:", "Powtórzone rekordy:");
            Frame->P_Notify->SetValues(Frame, stats.successCount, stats.failCount, stats.existingCount);
            Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            Frame->statistics->update();
            Frame->P_Inbox->SetAdvSearchDate(Frame);
            if (Frame->P_Stats->GetIsUpdated())
                Frame->P_Stats->SetIsUpdated();

            if (! Frame->P_Usembers->GetUsembersListEnabled())
                Frame->P_Usembers->SetUsembersListEnabled();

            Frame->P_Usembers->SetEmails(Frame, -1);        //usuń maile From i To z komponentu
            if (Frame->P_Usembers->GetEmailContentEnabled())
                Frame->P_Usembers->SetEmailContentEnabled();

            Frame->P_Usembers->ClearUsemberInfo(Frame);
        }
    }
}

void PanelTitleMaintance::EventButtonBinClick(AisdiRelationsFrame* Frame)
{
    if (Frame->FileDialogDatabaseImport->ShowModal() == wxID_OK)
    {
        /* Schowanie PanelAdd i zmiana grafik przycisków dodawania na domyślne */
        if (Frame->P_Inbox->GetAddEnabled())
            Frame->P_Inbox->SetAddEnabled();
        if (Frame->P_Usembers->GetAddEnabled())
            Frame->P_Usembers->SetAddEnabled();
        Frame->PanelAdd->Hide();
        Frame->I_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);
        Frame->U_ImageButtonAdd->SetBitmapLabel(path+imagePaths[16]+format);

        //potwierdzenie nadpisania bazy danych
        bool deleteConfirm = false;
        if (Frame->database->countEmails() == 0)    //nie ma maili, nie ma potwierdzenia
            deleteConfirm = true;
        else
        {
            wxMessageDialog * confirmPrompt = new wxMessageDialog(Frame, _("Bieżące dane zostaną utracone. Czy chcesz kontynuować\?"), _("Potwierdzenie nadpisania bazy danych"), wxCANCEL|wxYES_NO|wxNO_DEFAULT|wxICON_EXCLAMATION, wxDefaultPosition);
            if (confirmPrompt->ShowModal() == wxID_YES)
                deleteConfirm = true;
            delete confirmPrompt;
        }

        if (deleteConfirm)
        {
            DbParameters importParameters;
            importParameters.password = "";
            importParameters.isPasswordProtected = false;

            bool passWordEntry = false;
            wxString password = _("");

            wxArrayString paths;
            Frame->FileDialogDatabaseImport->GetPaths(paths);

            try
            {
                if ( Frame->iointerface->isImportedFileProtected( (string)paths[0].mb_str() ) )
                {
                    do
                    {
                        if (Frame->PasswordEntryDialog->ShowModal() == wxID_OK)
                        {
                            password = Frame->PasswordEntryDialog->GetValue();
                            Frame->PasswordEntryDialog->SetValue(_(""));
                            if (password != _(""))
                            {
                                importParameters.password = password.mb_str();
                                importParameters.isPasswordProtected = true;
                                passWordEntry = true;
                            }
                            else
                            {
                                importParameters.password = "";
                                importParameters.isPasswordProtected = false;
                            }
                        }
                        else
                        {
                            wxMessageBox(_("Nie podano hasła!"));
                            return;
                        }
                    } while (!passWordEntry);
                }
                Frame->database = Frame->iointerface->importDatabase(&importParameters);     // po wczytaniu zmienia się wartość wskaźnika na bazę danych!

                delete Frame->statistics;
                Frame->statistics = new Statistics(Frame->database);

                Frame->P_Inbox->SetEmails(Frame);               //załadowanie listy maili i usemberów z bazy
                Frame->P_Usembers->SetUsembers(Frame);

                if (GetNoData())
                    Frame->P_Title->SwitchIcons(Frame);
                Frame->statistics->update();
                Frame->P_Inbox->SetAdvSearchDate(Frame);
                if (Frame->P_Stats->GetIsUpdated())
                    Frame->P_Stats->SetIsUpdated();

                if (! Frame->P_Usembers->GetUsembersListEnabled())
                    Frame->P_Usembers->SetUsembersListEnabled();

                Frame->P_Usembers->SetEmails(Frame, -1);        //usuń maile From i To z komponentu
                if (Frame->P_Usembers->GetEmailContentEnabled())
                    Frame->P_Usembers->SetEmailContentEnabled();

                Frame->P_Usembers->ClearUsemberInfo(Frame);

                Frame->P_Notify->SetLabels(Frame, "Wczytywanie pliku bazy danych", "Status");
                Frame->P_Notify->SetValues(Frame, "        OK");
                Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            }
            catch(UnableToOpenFile exception)
            {
                Frame->P_Notify->SetLabels(Frame, "Wczytywanie pliku bazy danych", "Nie można otworzyć tego pliku!");
                Frame->P_Notify->SetValues(Frame, "", "       Błąd!");
                Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            }
            catch(InvalidFile exception)
            {
                Frame->P_Notify->SetLabels(Frame, "Wczytywanie pliku bazy danych", "Plik nie jest poprawny!");
                Frame->P_Notify->SetValues(Frame, "", "       Błąd!");
                Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            }
            catch(InvalidPassword exception)
            {
                Frame->P_Notify->SetLabels(Frame, "Wczytywanie pliku bazy danych", "Niepoprawne hasło!");
                Frame->P_Notify->SetValues(Frame, "", "       Błąd!");
                Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
            }
        }
    }
}

void PanelTitleMaintance::EventButtonSettingsClick (AisdiRelationsFrame * Frame)
{
	if (GetClickedSettings())
    {
		Frame->PanelSettings->Hide();
        Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);
    }
	else
	{
        Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+formatNeg);
	    Frame->PanelSettings->SetPosition(wxPoint(870,20));
		Frame->PanelSettings->Show();
	}
	SetClickedSettings();
}

void PanelTitleMaintance::EventButtonSwitchClick (AisdiRelationsFrame * Frame)
{
    if (!GetNoData())
    {
        if (GetClickedAdd())
            SetClickedAdd();
        if (GetClickedImport())
            SetClickedImport();
        if (GetClickedLoad())
            SetClickedLoad();
    }
    Frame->P_Title->SwitchIcons(Frame);

    if (GetClickedSettings())
        SetClickedSettings();
    Frame->PanelSettings->Hide();
    Frame->T_ImageButtonSettings->SetBitmapLabel(path+imagePaths[7]+format);
}

void PanelTitleMaintance::EventButtonTxtClick(AisdiRelationsFrame * Frame)
{
    //Tak naprawdę jest to zapis pliku binarnego bazy

    if (Frame->database->countEmails() == 0)
        wxMessageBox(_("Baza danych jest pusta."));
    else if (Frame->FileDialogDatabaseExport->ShowModal() == wxID_OK)      //uruchomienie panelu wybierania folderu
    {
        DbParameters exportParameters;
        wxString password = _("");
        if (Frame->P_Title->GetDatabaseEncryption())
        {
            if (Frame->PasswordEntryDialog->ShowModal() == wxID_OK)
            {
                password = Frame->PasswordEntryDialog->GetValue();
                if (password != _(""))
                {
                    exportParameters.password = password.mb_str();
                    exportParameters.isPasswordProtected = true;
                }
                else
                {
                    exportParameters.password = "";
                    exportParameters.isPasswordProtected = false;
                }
            }
            Frame->PasswordEntryDialog->SetValue(_(""));
        }
        else
        {
            exportParameters.password = "";
            exportParameters.isPasswordProtected = false;
        }

        wxString path, filename;
        path = Frame->FileDialogDatabaseExport->GetPath();
        filename = Frame->FileDialogDatabaseExport->GetFilename();

        std::string strPath, strFilename;
        strPath = path.mb_str();
        strFilename = filename.mb_str();

        if (strFilename != "")
        {
            if (strPath.substr(strPath.size()-4, 4) != ".bin")
            {
                strPath = strPath+".bin";
                strFilename = strFilename+".bin";
            }

            Frame->iointerface->exportDatabase(strPath, &exportParameters);

            Frame->P_Notify->SetLabels(Frame, "Zapisano plik bazy.", "  Nazwa pliku: ", "    "+strFilename);
            Frame->P_Notify->SetValues(Frame, "");
            Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
        }
    }
}

void PanelTitleMaintance::EventButtonSavTxtClick(AisdiRelationsFrame * Frame)
{
    //Zapisywanie bazy do pliku tekstowego

    if (Frame->database->countEmails() == 0)
        wxMessageBox(_("Baza danych jest pusta."));
    else if (Frame->DirDialog->ShowModal() == wxID_OK)		//uruchomienie panelu wybierania folderu
    {													//jeśli wybrano folder:
        wxString path;
        path = Frame->DirDialog->GetPath();

        string strPath;
        strPath = path.mb_str();

        Frame->iointerface->exportDatabaseToTxt(strPath);
        Frame->P_Notify->SetLabels(Frame, "Zapisano bazę danych.", "Lokalizacja:", strPath);
        Frame->P_Notify->SetValues(Frame, "");
        Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
    }
}
