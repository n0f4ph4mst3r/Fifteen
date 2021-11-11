#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>

class wxImagePanel : public wxPanel
{
	wxBitmap source;
	int n;
	const int w = 128;
	int grid[4][4] = { 0 };
	std::vector<wxBitmap> blocks;
	wxTimer renderTimer;

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