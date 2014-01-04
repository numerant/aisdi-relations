#include "PanelStatisticsMaintance.h"
#include <wx/dcclient.h>

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

        Frame->PanelStatistics->SetPosition(wxPoint(0,0));
        if (!GetIsUpdated())    //jeżeli był jakiś update w międzyczasie
        {
            Frame->S_PanelEmailPerMonth->Refresh();     //uaktualnij statystyki
            Frame->S_PanelCounters->Refresh();
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
    wxPaintDC dc(Frame->S_PanelEmailPerMonth);
    dc.SetPen(wxPen(wxColour(230,230,230)));
    dc.SetBrush(wxBrush(wxColour(230,230,230)));

    dc.SetTextForeground(wxColour(230,230,230));
    dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu")));

    for (int i = 0; i < 12; i++)    //Wypisanie nazw miesięcy u dołu
    {
        dc.DrawText(months[i], wxPoint(i*40+20, 270));
        int month = Frame->statistics->getEmailsCountInMonth(i+1);  //pobranie wartości z danego miesiąca
        if (month)
        {
            ostringstream ss;               //konwersja int -> string -> wxString
            ss << month;
            string strMonth = ss.str();
            dc.DrawText(wxString(strMonth.c_str(), wxConvUTF8), wxPoint(i*40+20, 200));
        }
    }

    dc.DrawLine(wxPoint(10,260), wxPoint(490,260));
}

void PanelStatisticsMaintance::EventPanelCountersPaint (AisdiRelationsFrame * Frame)
{
    int iCounter;
    double dCounter;
    string sCounter;
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

    /* iCounter = Frame->statistics->getMaxEmailsInMonth();      //maksymalna liczba emaili w miesiącu
    ss << iCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value8->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    iCounter = Frame->statistics->getForwards();        //TODO Zmienić nazwy funkcji (chyba że pasują)
    ss << iCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value9->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    iCounter = Frame->statistics->getReplies();
    ss << iCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value10->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    iCounter = Frame->statistics->getDuration();
    ss << iCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value13,,->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");  */

    /** === Rzeczywiste === */
    dCounter = Frame->statistics->getEmailsPerMonth();
    ss << dCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value4->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    dCounter = Frame->statistics->getEmailsPerDay();
    ss << dCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value5->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    dCounter = Frame->statistics->getEmailsPerUser();
    ss << dCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value6->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    dCounter = Frame->statistics->getAverageEmailLength();
    ss << dCounter;
    sCounter = ss.str();
    Frame->S_StaticTextC_Value7->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));
    ss.str("");

    /** === Tekstowe === */
    /*sCounter = Frame->statistics->getEarliest();
    Frame->S_StaticTextC_Value11->SetLabel(wxString(sCounter.c_str(), wxConvUTF8));

    sCounter = Frame->statistics->getLatest();
    Frame->S_StaticTextC_Value12->SetLabel(wxString(sCounter.c_str(), wxConvUTF8)); */
}
