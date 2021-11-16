//declaration of class PuzzleApp
#pragma once
#include "wxImagePanel.h"
//build the application here
class FifteenApp : public wxFrame
{
    wxImagePanel* drawPane;

public:
    FifteenApp(const wxString& title);
};