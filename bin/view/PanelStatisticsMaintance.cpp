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

bool PanelStatisticsMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}

void PanelStatisticsMaintance::EventPanelEmailPerMonthPaint (AisdiRelationsFrame * Frame)
{
    wxPaintDC dc(Frame->S_PanelEmailPerMonth);
    dc.SetPen(wxPen(wxColour(230,230,230)));
    dc.SetBrush(wxBrush(wxColour(230,230,230)));

    dc.SetTextForeground(wxColour(230,230,230));
    dc.SetFont(wxFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Ubuntu")));

    int emailsPerMonth[12];

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

    /*dc.SetPen(wxPen(wxColour(255, 255, 255)));
    dc.SetBrush(wxBrush(wxColour(255, 255, 255)));
    dc.DrawLine(x-13,y-2,26,4);
    dc.DrawLine(x-2,y-13,4,26);

    dc.SetPen(wxPen(wxColour(0, 255, 0)));
    dc.SetBrush(wxBrush(wxColour(0, 255, 0)));
    dc.DrawEllipse(x-17,y-5,10,10);
    dc.DrawEllipse(x+7,y-5,10,10);

    dc.SetPen(wxPen(wxColour(255, 0, 0)));
    dc.SetBrush(wxBrush(wxColour(255, 0, 0)));
    dc.DrawEllipse(x-5,y-17,10,10);
    dc.DrawEllipse(x-5,y+7,10,10);*/
}

