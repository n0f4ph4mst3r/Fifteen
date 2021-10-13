#include "FifteenApp.h"

FifteenApp::FifteenApp(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(528, 550))
{
    wxInitAllImageHandlers();

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(this, wxT("..\\res\\workspace.png"), wxBITMAP_TYPE_PNG);
    sizer->Add(drawPane, 1, wxEXPAND);

    this->SetSizer(sizer);

    SetIcon(wxICON(aaaaaaaa));

    Centre();
}