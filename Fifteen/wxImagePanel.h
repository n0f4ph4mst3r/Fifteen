#pragma once
#include <wx/dcbuffer.h>
#include "Puzzle.h"

//wxPanel for render
class wxImagePanel : public wxPanel
{
	wxTimer renderTimer;
	Fifteen* fifteen;
	Block *movingblock, *emptyblock;
public:
	
	wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
	
	void paintEvent(wxPaintEvent& evt);
	void mouseDown(wxMouseEvent& event);
	void RenderTimer(wxTimerEvent& event);
	
	void render(wxDC& dc);

	DECLARE_EVENT_TABLE();
};