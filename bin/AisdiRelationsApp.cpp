/***************************************************************
 * Name:      AisdiRelationsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Paweł Kaczyński ()
 * Created:   2013-11-29
 * Copyright: Paweł Kaczyński ()
 * License:
 **************************************************************/

#include "AisdiRelationsApp.h"

/**  Pliki nagłówkowe klas projektu */
/**#include "../src/Database.h"
#include "../src/EmailQuery.h"
#include "../src/IOInterface.h"
#include "../src/Query.h"
#include "../src/Report.h"
#include "../src/Usember.h"
#include "../src/UsemberQuery.h"
#include "../src/WorkgroupQuery.h" */

/** Pliki  zarządzające widokiem (panelami) */
//#include "view/PanelTitleMaintance.h"

//(*AppHeaders
#include "AisdiRelationsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(AisdiRelationsApp);

bool AisdiRelationsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        AisdiRelationsFrame* Frame = new AisdiRelationsFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)

    return wxsOK;

}
