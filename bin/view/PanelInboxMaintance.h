#pragma once
#include "../AisdiRelationsMain.h"
#include "wx/msgdlg.h"

class PanelInboxMaintance
{
    friend class AisdiRelationsFrame;

private:
    bool panelEnabled = true;
    bool searchEnabled = false;
    const wxString imagePaths[13] =
    {
        _("Add"),  _("Floppy"),  _("Search"),  _("Settings"),  _("Usember"),  _("Workgroups"),
        _("Statistics"),  _("Tree"),  _("Remove"),  _("Sender"),  _("Receiver"),  _("ShowTree"),
        _("Title")
    };                               //ścieżki plików z grafikami do przycisków panelu

public:
    PanelInboxMaintance ();
    void ShowPanel(AisdiRelationsFrame* Frame);
    void SetLabels(AisdiRelationsFrame* Frame);
    void SetIcons(AisdiRelationsFrame* Frame);
    void SetEmails (AisdiRelationsFrame* Frame);
    void SetSearchEnabled();

    bool GetSearchEnabled();
};
