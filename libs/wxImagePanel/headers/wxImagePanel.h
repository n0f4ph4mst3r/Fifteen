//declaration of class wxImagePanel
//this panel using for render
#pragma once
#include <wx/dcbuffer.h>
#include "Puzzle.h"


class wxImagePanel : public wxPanel {
	std::unique_ptr<Puzzle> fifteen;
	BlockPtr movingblock;
	wxTimer renderTimer;

	void paintEvent(wxPaintEvent& evt);
	void mouseDown(wxMouseEvent& event);
	void RenderTimer(wxTimerEvent& event);

	void render(wxDC& dc);

	DECLARE_EVENT_TABLE();

public:
	wxImagePanel(wxFrame* parent, wxBitmap* background);
};