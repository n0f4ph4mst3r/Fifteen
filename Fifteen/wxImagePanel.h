//declaration of class wxImagePanel
//this panel using for render
#pragma once
#include <wx/dcbuffer.h>
#include "Puzzle.h"

class wxImagePanel : public wxPanel {
	wxTimer renderTimer;
	Puzzle* fifteen;
	Block *movingblock, *emptyblock;

	void paintEvent(wxPaintEvent& evt);
	void mouseDown(wxMouseEvent& event);
	void RenderTimer(wxTimerEvent& event);

	void render(wxDC& dc);

	DECLARE_EVENT_TABLE();

public:
	wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
};