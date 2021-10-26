#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>

class wxImagePanel : public wxPanel
{
	wxBitmap source;
	int n;
	const int w = 128;
	int grid[4][4] = { 0 };
	std::vector<wxBitmap> blocks;

public:
	wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void render(wxDC& dc);

	void mouseDown(wxMouseEvent& event);

	DECLARE_EVENT_TABLE();
};