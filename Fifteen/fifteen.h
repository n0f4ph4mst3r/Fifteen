#pragma once
#include "wxImagePanel.h"

class Fifteen : public wxFrame
{
    wxImagePanel* drawPane;

public:
    Fifteen(const wxString& title);
};