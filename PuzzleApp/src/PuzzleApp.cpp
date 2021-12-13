//implemetation of class PuzzleApp
#include "PuzzleApp.h"

#if defined(__WXDFB__) || defined(__WXGTK__) || defined(__WXMAC__) || defined(__WXMOTIFF__) || defined(__WX11__) || defined(__WXQT__)
#include "aaaaaaaa_logo.XPM"
#endif

#if !(defined(__WINDOWS__) && wxUSE_WXDIB) && !defined(__WXOSX__)
#include "BACKGROUND.h"
#endif

PuzzleApp::PuzzleApp(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title) {
    wxInitAllImageHandlers();

    this->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(this, new wxBitmap(wxBITMAP_PNG(BACKGROUND)));
    sizer->Add(drawPane, 1, wxEXPAND);

    SetSizerAndFit(sizer);

    SetIcon(wxICON(aaaaaaaa_logo));

    Centre();
}