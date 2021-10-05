#include <wx/wx.h>
#include <wx/sizer.h>
#include "wxImagePanel.h"
#include <vector>

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::mouseDown)
    EVT_PAINT(wxImagePanel::paintEvent)
END_EVENT_TABLE()

void wxImagePanel::mouseDown(wxMouseEvent& event) 
{
}

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
    wxPanel(parent)
{
    source.LoadFile(file, format);

    w = 128;
    n = 0;
    //заполняем сетку
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            blocks.push_back(source.GetSubBitmap(wxRect(w*i, w*j, w, w)));
            grid[i + 1][j+1] = n;
            n++;
        }
}

void wxImagePanel::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void wxImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC& dc)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) 
        {
            n = grid[i + 1][j + 1];
            dc.DrawBitmap(blocks[n], w*i, w*j, false);
        }
}