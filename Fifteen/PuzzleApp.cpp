//implemetation of class PuzzleApp
#include "PuzzleApp.h"

FifteenApp::FifteenApp(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(528, 550)) {
    wxInitAllImageHandlers();

    this->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(this, wxT("..\\res\\workspace.png"), wxBITMAP_TYPE_PNG);
    sizer->Add(drawPane, 1, wxEXPAND);

    this->SetSizer(sizer);

    SetIcon(wxICON(aaaaaaaa));

    Centre();
}