#pragma once
#include <wx/wx.h>
#include "wxImagePanel.h"

class Fifteen : public wxFrame
{
    wxImagePanel* drawPane;

public:
    Fifteen(const wxString& title);
};