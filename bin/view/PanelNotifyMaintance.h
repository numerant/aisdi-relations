#pragma once
#include "../AisdiRelationsMain.h"

class PanelNotifyMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
                     
public:
    PanelNotifyMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
