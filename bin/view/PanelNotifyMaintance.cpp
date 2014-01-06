#include "PanelNotifyMaintance.h"
#include <sstream>

PanelNotifyMaintance::PanelNotifyMaintance()
{

}

void PanelNotifyMaintance::ShowPanel(AisdiRelationsFrame* Frame, int time)
{
        Frame->PanelNotify->SetPosition(wxPoint(20,20));
        Frame->PanelNotify->Show();
        Frame->Timer1.Start(time*1000, wxTIMER_ONE_SHOT);
}

 void PanelNotifyMaintance::SetLabels (AisdiRelationsFrame * Frame, string title, string option1, string option2)
 {
 	Frame->N_StaticTextTitle->SetLabel(wxString(title.c_str(), wxConvUTF8));
 	Frame->N_StaticTextOption1->SetLabel(wxString(option1.c_str(), wxConvUTF8));
 	Frame->N_StaticTextOption2->SetLabel(wxString(option2.c_str(), wxConvUTF8));
 }

 void PanelNotifyMaintance::SetValues (AisdiRelationsFrame * Frame, int value1, int value2)
 {
 	 ostringstream ssValue1, ssValue2;
     ssValue1 << value1;
     string strValue1 = ssValue1.str();
     ssValue2 << value2;
     string strValue2 = ssValue2.str();

 	 Frame->N_StaticTextValue1->SetLabel(wxString(strValue1.c_str(), wxConvUTF8));
 	 Frame->N_StaticTextValue2->SetLabel(wxString(strValue2.c_str(), wxConvUTF8));
 }

 void PanelNotifyMaintance::SetValues (AisdiRelationsFrame * Frame, string value1, string value2)
 {
 	 Frame->N_StaticTextValue1->SetLabel(wxString(value1.c_str(), wxConvUTF8));
 	 Frame->N_StaticTextValue2->SetLabel(wxString(value2.c_str(), wxConvUTF8));
 }

bool PanelNotifyMaintance::GetPanelEnabled ()
{
    return panelEnabled;
}
