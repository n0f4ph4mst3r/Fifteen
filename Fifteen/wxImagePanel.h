#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/dcbuffer.h>
#include <vector>

class wxImagePanel : public wxPanel
{
	wxBitmap source;
	int n;
	const int w = 128;
	int grid[4][4] = { 0 };
	std::vector<wxBitmap> blocks;
	wxTimer renderTimer;

	int x1, y1, x2, y2;
	int x_pos, y_pos;
	int dx, dy;
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