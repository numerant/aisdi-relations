#pragma once
#include "../AisdiRelationsMain.h"

class PanelGroupsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;

public:
    PanelGroupsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
