#pragma once
#include "wxImagePanel.h"

class FifteenApp : public wxFrame
{
    wxImagePanel* drawPane;

public:
    FifteenApp(const wxString& title);
};