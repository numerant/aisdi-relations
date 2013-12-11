#pragma once
#include "../AisdiRelationsMain.h"

class PanelStatisticsMaintance {
    friend class AisdiRelationsFrame;

    private:
    	bool panelEnabled = false;

    public:
    	PanelStatisticsMaintance ();
        void ShowPanel(AisdiRelationsFrame* Frame);
};
