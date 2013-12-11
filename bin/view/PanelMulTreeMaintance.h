#pragma once
#include "../AisdiRelationsMain.h"

class PanelMulTreeMaintance {
    friend class AisdiRelationsFrame;
    
    private:
    	bool panelEnabled = false;

    public:
    	PanelMulTreeMaintance ();
        void ShowPanel(AisdiRelationsFrame* Frame);
};
