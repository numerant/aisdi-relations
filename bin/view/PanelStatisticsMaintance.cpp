#include "PanelStatisticsMaintance.h"
#include "PanelUsembersMaintance.h"
#include <wx/dcclient.h>
#include <iomanip>

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
    wxPaintDC dc(Frame->S_PanelEmailPerMonth);
    dc.SetPen(wxPen(wxColour(230,230,230)));

    dc.SetTextForeground(wxColour(230,230,230));
    dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu")));

    int maxHeight = Frame->statistics->getMaxEmailsInMonth();
    if (maxHeight)  //jeżeli jakikolwiek mail wczytany
    {
         for (int i = 0; i < 12; i++)    //Wypisanie nazw miesięcy u dołu
        {
            int posCorrection = 0;
            int labelCorrection = 0;
            if (i == 6)
                    posCorrection = 2;
            dc.DrawText(months[i], wxPoint(i*40+20+posCorrection, 270));      //wypisz nazwę miesiąca

            int month = Frame->statistics->getEmailsCountInMonth(i+1);  //pobranie wartości z danego miesiąca
            if (month >= 100)
                labelCorrection = -8;
            else if (month >= 10)
                labelCorrection = -4;

            ostringstream ss;               //konwersja int -> string -> wxString
            ss << month;
            string strMonth = ss.str();

            if (month)  //jeżeli jest co rysować, to rysuj prostokąt o zmiennym wypełnieniu
            {
                dc.SetBrush(wxBrush(wxColour(red+(int)(255-red-month*(255-red)/maxHeight),green+(int)(255-green-month*(255-green)/maxHeight),blue+(int)(255-blue-month*(255-blue)/maxHeight))));      //ustal kolor słupka
                dc.DrawRectangle(wxPoint(17+i*40,250),wxSize(32, (int)-month*(200/maxHeight)));
            }
            //a potem wypisz tekst, nawet dla zera
            dc.DrawText(wxString(strMonth.c_str(), wxConvUTF8), wxPoint(i*40+28+labelCorrection, (int)250-month*(200/maxHeight)-20));
        }
    }
    dc.DrawLine(wxPoint(10,260), wxPoint(490,260));
}

void PanelStatisticsMaintance::EventPanelCountersPaint (AisdiRelationsFrame * Frame)
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
    Frame->P_Usembers->SetUsemberViewed(usember);
    Frame->P_Usembers->ShowPanel(Frame);
}

void PanelStatisticsMaintance::EventButtonRefreshClick (AisdiRelationsFrame * Frame)
{
    Frame->statistics->update();
    Frame->P_Stats->EventPanelEmailPerMonthPaint(Frame);
    Frame->P_Stats->EventPanelCountersPaint(Frame);
}

