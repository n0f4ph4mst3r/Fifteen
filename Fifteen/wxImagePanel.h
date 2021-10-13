#pragma once
#include <wx/dcbuffer.h>
#include "Fifteen.h"

class wxImagePanel : public wxPanel
{
	wxTimer renderTimer;
	Fifteen* fifteen;
	Block *movingblock, *emptyblock;
public:
	//constructor
	wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
	//events
	void paintEvent(wxPaintEvent& evt);
	void mouseDown(wxMouseEvent& event);
	void RenderTimer(wxTimerEvent& event);
	//func&method
	void render(wxDC& dc);

	DECLARE_EVENT_TABLE();
};