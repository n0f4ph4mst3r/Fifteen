//declaration of class PuzzleApp
#pragma once
#include "wxImagePanel.h"
//build the application here
class PuzzleApp : public wxFrame
{
    wxImagePanel* drawPane;

public:
    PuzzleApp(const wxString& title);
};