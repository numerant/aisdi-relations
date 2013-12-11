#pragma once
#include "../AisdiRelationsMain.h"

class PanelGroupsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = false;

public:
    PanelGroupsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
};
