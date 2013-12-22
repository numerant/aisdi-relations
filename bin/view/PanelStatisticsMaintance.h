#pragma once
#include "../AisdiRelationsMain.h"

class PanelStatisticsMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;

public:
    PanelStatisticsMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
