#pragma once
#include "../AisdiRelationsMain.h"
#include <sstream>

class PanelNotifyMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
                     
public:
    PanelNotifyMaintance ();
    void ShowPanel(AisdiRelationsFrame * Frame, int time = 1000);

    void SetLabels (AisdiRelationsFrame * Frame, string title = "", string option1 = "", string option2 = "", string option3 = "");
    void SetValues (AisdiRelationsFrame * Frame, int value1 = 0, int value2 = 0, int value3 = 0);
    void SetValues (AisdiRelationsFrame * Frame, string value1 = "", string value2 = "", string value3 = "");

    bool GetPanelEnabled ();
};
