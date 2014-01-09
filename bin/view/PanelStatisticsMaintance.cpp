#include "PanelStatisticsMaintance.h"

PanelStatisticsMaintance::PanelStatisticsMaintance ()
{

}

void PanelStatisticsMaintance::ShowPanel(AisdiRelationsFrame* Frame)
{
    if (panelEnabled)
    {
        Frame->PanelUsembers->Hide();
        Frame->PanelGroups->Hide();
        Frame->PanelInbox->Hide();
        Frame->PanelTitle->Hide();
        Frame->PanelMulTree->Hide();
        Frame->PanelAdd->Hide();

        Frame->PanelStatistics->SetPosition(wxPoint(0,0));
        if (!GetIsUpdated())    //jeżeli był jakiś update w międzyczasie
        {
            Frame->S_PanelEmailPerMonth->Refresh();     //uaktualnij statystyki
            Frame->P_Stats->EventPanelCountersPaint(Frame);
            Frame->P_Stats->EventPanelTopsPaint(Frame);
            Frame->P_Stats->SetIsUpdated();
        }

        Frame->PanelStatistics->Show();
    }
}

void PanelStatisticsMaintance::SetIcons(AisdiRelationsFrame * Frame)
{
    wxString path(_("resources/icons/icon"));
    wxString format (_(".png"));

    Frame->S_ImageButtonTitle->SetBitmapLabel(path+imagePaths[0]+format);
    Frame->S_ImageButtonInbox->SetBitmapLabel(path+imagePaths[1]+format);
    Frame->S_ImageButtonUsembers->SetBitmapLabel(path+imagePaths[2]+format);
    Frame->S_ImageButtonGroups->SetBitmapLabel(path+imagePaths[3]+format);
    Frame->S_ImageButtonMulTree->SetBitmapLabel(path+imagePaths[4]+format);
    Frame->S_ImageButtonRefresh->SetBitmapLabel(path+imagePaths[5]+format);
    Frame->S_ImageButtonSaveStats->SetBitmapLabel(path+imagePaths[6]+format);
}

void PanelStatisticsMaintance::SetIsUpdated()
{
    isUpdated = !isUpdated;
}

bool PanelStatisticsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

bool PanelStatisticsMaintance::GetIsUpdated ()
{
    return isUpdated;
}

void PanelStatisticsMaintance::EventPanelEmailPerMonthPaint (AisdiRelationsFrame * Frame)
{
    const int red = 240;
    const int green = 70;
    const int blue = 30;
    int height, width;
    Frame->S_PanelEmailPerMonth->GetSize(&width, & height);
    double barSpace = 20;
    double barWidth = (width-20-11*barSpace)/12;
    int barHeight = (height - 90);
    int valueLabelCorrection = height-barHeight-55;

    wxPaintDC dc(Frame->S_PanelEmailPerMonth);

    dc.SetBrush(wxBrush(wxColour(48,48,48)));
    dc.SetPen(wxPen(wxColour(48,48,48)));
    dc.DrawRectangle(wxPoint(5,28),wxSize(width-10,height-28-5));       //wyczyszczenie canvasu

    dc.SetPen(wxPen(wxColour(150,150,150)));
    dc.SetTextForeground(wxColour(230,230,230));
    dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu")));

    int maxMonth = Frame->statistics->getMaxEmailsInMonth();
    if (maxMonth)  //jeżeli jakikolwiek mail wczytany
    {
         for (int i = 0; i < 12; i++)    //Wypisanie nazw miesięcy u dołu
        {
            int posCorrection = 0;
            int labelCorrection = 0;
            if (i == 6)
                    posCorrection = 2;
            dc.DrawText(months[i], wxPoint(10+barWidth/2-12+i*(barWidth+barSpace)+posCorrection, height-25));      //wypisz nazwę miesiąca

            int month = 0;
            month = Frame->statistics->getEmailsCountInMonth(i+1);  //pobranie wartości z danego miesiąca
            if (month >= 100)
                labelCorrection = -8;
            else if (month >= 10)
                labelCorrection = -4;

            ostringstream ss;               //konwersja int -> string -> wxString
            ss << month;
            string strMonth = ss.str();

            int currentBarHeight = 0;
            if (month)  //jeżeli jest co rysować, to rysuj prostokąt o zmiennym wypełnieniu
            {
                double step = 10*barHeight/maxMonth;
                double d_barHeight = step * month;
                currentBarHeight = (int)(d_barHeight/10);
                dc.SetBrush(wxBrush(wxColour(red+(int)(255-red-(255-red)*currentBarHeight/barHeight),green+(int)(255-green-(255-green)*currentBarHeight/barHeight),blue+(int)(255-blue-(255-blue)*currentBarHeight/barHeight))));      //ustal kolor słupka
                dc.DrawRectangle(wxPoint(10+(int)(i*(barWidth+barSpace)),height-35),wxSize(barWidth, -currentBarHeight));
            }
            //a potem wypisz tekst, nawet dla zera
            dc.DrawText(wxString(strMonth.c_str(), wxConvUTF8), wxPoint(10+barWidth/2-5+(int)(i*(barWidth+barSpace))+labelCorrection, (int)(valueLabelCorrection+barHeight-currentBarHeight)));
        }
    }
    dc.DrawLine(wxPoint(10,height-30), wxPoint(width-10,height-30));
}

void PanelStatisticsMaintance::EventPanelCountersPaint (AisdiRelationsFrame * Frame)
{
    if (Frame->database->countEmails() > 0)
    {
        int iCounter;
        double dCounter;
        string sCounter;
        Date * date;
        ostringstream ss;

        /** === Całkowite === */
        iCounter = Frame->statistics->getEmails();      //liczba wszystkich maili
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value1->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getUsembers();    //liczba wszystkich Usemberów
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value2->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getGroups();      //liczba wszystkich Grup
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value3->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getMaxEmailsInMonth();      //maksymalna liczba emaili w miesiącu
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value8->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getForwards();
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value9->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getReplies();
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value10->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        iCounter = Frame->statistics->getDuration();        //okres wysyłania maili (w dniach)
        ss << iCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value13->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        /** === Rzeczywiste === */
        dCounter = Frame->statistics->getEmailsPerMonth();
        ss << std::fixed << std::setprecision(1) << dCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value4->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        dCounter = Frame->statistics->getEmailsPerDay();
        ss << std::fixed << std::setprecision(1) << dCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value5->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        dCounter = Frame->statistics->getEmailsPerUser();
        ss << std::fixed << std::setprecision(1) << dCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value6->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        dCounter = Frame->statistics->getAverageEmailLength();
        ss << std::fixed << std::setprecision(1) << dCounter;
        sCounter = ss.str();
        Frame->S_StaticTextC_Value7->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        /** === Tekstowe === */
        date = Frame->statistics->getEarliest();
        ss << date->getDay() << "-" << date->getMonth() << "-" << date->getYear();
        sCounter = ss.str();
        Frame->S_StaticTextC_Value11->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");

        date= Frame->statistics->getLatest();
        ss << date->getDay() << "-" << date->getMonth() << "-" << date->getYear();
        sCounter = ss.str();
        Frame->S_StaticTextC_Value12->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
        ss.str("");
    }
}

void PanelStatisticsMaintance::EventPanelTopsPaint (AisdiRelationsFrame * Frame)
{
        string names[10] = "", adresses[10] = "", strValues[10] = "";
        int values[10] = {0};
        ostringstream ss;
        for (int i = 0; i < 5; i++)
        {
            if (Frame->statistics->getTopReceiver(i) != nullptr)
            {
                 values[i] = Frame->statistics->getTopReceiver(i)->receiveMailCount();
                 if (values[i] == 0)
                        continue;
            }
            else
                continue;

            names[i] = Frame->statistics->getTopReceiver(i)->getRealName();
            adresses[i] = Frame->statistics->getTopReceiver(i)->getAddress();
            adresses[i] = " <"+adresses[i]+">";
            ss << values [i];
            strValues[i] = ss.str();
            ss.str("");
        }

        for(int i = 0; i < 5; i++)
        {
            if (Frame->statistics->getTopSender(i) != nullptr)
            {
                    values[i+5] = Frame->statistics->getTopSender(i)->sendMailCount();
                    if (values[i+5] == 0)
                        continue;
            }
            else
                continue;

            names[i+5] = Frame->statistics->getTopSender(i)->getRealName();
            adresses[i+5] = Frame->statistics->getTopSender(i)->getAddress();
            adresses[i+5] = " <"+adresses[i+5]+">";
            ss << values[i+5];
            strValues[i+5] = ss.str();
            ss.str("");
        }
        string open = "", close = " - ";
        Frame->S_HyperLinkT_ReceiverPos1->SetLabel(wxString((open+strValues[0]+close+names[0]+adresses[0]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_ReceiverPos2->SetLabel(wxString((open+strValues[1]+close+names[1]+adresses[1]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_ReceiverPos3->SetLabel(wxString((open+strValues[2]+close+names[2]+adresses[2]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_ReceiverPos4->SetLabel(wxString((open+strValues[3]+close+names[3]+adresses[3]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_ReceiverPos5->SetLabel(wxString((open+strValues[4]+close+names[4]+adresses[4]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_SendersPos1->SetLabel(wxString((open+strValues[5]+close+names[5]+adresses[5]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_SendersPos2->SetLabel(wxString((open+strValues[6]+close+names[6]+adresses[6]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_SendersPos3->SetLabel(wxString((open+strValues[7]+close+names[7]+adresses[7]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_SendersPos4->SetLabel(wxString((open+strValues[8]+close+names[8]+adresses[8]).c_str(),wxConvUTF8));
        Frame->S_HyperLinkT_SendersPos5->SetLabel(wxString((open+strValues[9]+close+names[9]+adresses[9]).c_str(),wxConvUTF8));
}

void PanelStatisticsMaintance::EventHyperLinkClick(AisdiRelationsFrame * Frame, const long id)
{
    string usember;
    wxString wxStr;
    switch (id)
    {
        case 0: wxStr = Frame->S_HyperLinkT_SendersPos1->GetLabel(); break;
        case 1: wxStr = Frame->S_HyperLinkT_SendersPos2->GetLabel(); break;
        case 2: wxStr = Frame->S_HyperLinkT_SendersPos3->GetLabel(); break;
        case 3: wxStr = Frame->S_HyperLinkT_SendersPos4->GetLabel(); break;
        case 4: wxStr = Frame->S_HyperLinkT_SendersPos5->GetLabel(); break;
        case 5: wxStr = Frame->S_HyperLinkT_ReceiverPos1->GetLabel(); break;
        case 6: wxStr = Frame->S_HyperLinkT_ReceiverPos2->GetLabel(); break;
        case 7: wxStr = Frame->S_HyperLinkT_ReceiverPos3->GetLabel(); break;
        case 8: wxStr = Frame->S_HyperLinkT_ReceiverPos4->GetLabel(); break;
        case 9: wxStr = Frame->S_HyperLinkT_ReceiverPos5->GetLabel(); break;
        default: break;
    }
    usember = wxStr.mb_str();
    Frame->P_Usembers->SetUsemberViewed(Frame, usember);
}

void PanelStatisticsMaintance::EventButtonRefreshClick (AisdiRelationsFrame * Frame)
{
    Frame->statistics->update();
    Frame->P_Stats->EventPanelEmailPerMonthPaint(Frame);
    Frame->P_Stats->EventPanelCountersPaint(Frame);
    Frame->P_Stats->EventPanelTopsPaint(Frame);
}

void PanelStatisticsMaintance::EventButtonSaveStatsClick (AisdiRelationsFrame * Frame)
{
    if (Frame->statistics->getEmails() == 0)
        wxMessageBox(_("Statystyki są puste."));
    else if (Frame->FileDialogStatisticsExport->ShowModal() == wxID_OK)      //uruchomienie panelu wybierania folderu
    {
        wxString path, filename;
        path = Frame->FileDialogStatisticsExport->GetPath();
        filename = Frame->FileDialogStatisticsExport->GetFilename();

        std::string strPath, strFilename;
        strPath = path.mb_str();
        strFilename = filename.mb_str();

        if (strFilename != "")
        {
            if (strPath.substr(strPath.size()-4, 4) != ".txt")
            {
                strPath = strPath+".txt";
                strFilename = strFilename+".txt";
            }

            Frame->iointerface->exportDatabaseReport(strPath, Frame->statistics);
            Frame->P_Notify->SetLabels(Frame, "Zapisano statystyki.", "Nazwa pliku: ");
            Frame->P_Notify->SetValues(Frame, strFilename);
            Frame->P_Notify->ShowPanel(Frame, Frame->GetNotifyTime());
        }
    }
}

