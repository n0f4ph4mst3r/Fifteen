//implemetation of class PuzzleApp
#include "PuzzleApp.h"

PuzzleApp::PuzzleApp(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(528, 550)) {
    wxInitAllImageHandlers();

    this->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(this, wxT("C:\\Users\\Пользователь\\source\\repos\\n0f4ph4mst3r\\FifteenCmake\\PuzzleApp\\res\\images\\workspace.png"), wxBITMAP_TYPE_PNG);
    sizer->Add(drawPane, 1, wxEXPAND);

    this->SetSizer(sizer);

    SetIcon(wxICON(aaaaaaaa));

    Centre();
}