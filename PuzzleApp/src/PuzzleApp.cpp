//implemetation of class PuzzleApp
#include "PuzzleApp.h"

PuzzleApp::PuzzleApp(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(528, 550)) {
    wxInitAllImageHandlers();

    this->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(this, new wxBitmap(wxBITMAP_PNG(BACKGROUND)));
    sizer->Add(drawPane, 1, wxEXPAND);

    this->SetSizer(sizer);

    SetIcon(wxICON(aaaaaaaa));

    Centre();
}