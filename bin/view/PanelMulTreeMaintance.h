#pragma once
#include "../AisdiRelationsMain.h"

class PanelMulTreeMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;

public:
    PanelMulTreeMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);

    bool GetPanelEnabled ();
};
