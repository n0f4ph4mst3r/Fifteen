#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::mouseDown)
    EVT_PAINT(wxImagePanel::paintEvent)
    EVT_TIMER(-1, wxImagePanel::RenderTimer)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
    wxPanel(parent), renderTimer(this, -1)
{
    source.LoadFile(file, format);

    n = 1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            blocks.push_back(source.GetSubBitmap(wxRect(w * i, w * j, w, w)));
            grid[i][j] = n;
            n++;
        }
}

void wxImagePanel::mouseDown(wxMouseEvent& event) 
{
    wxPoint pt = wxGetMousePosition();

    int x = (pt.x - this->GetScreenPosition().x) / w;
    int y = (pt.y - this->GetScreenPosition().y) / w;

    int dx, dy;
    dx = dy = 0;

    if (grid[x + 1][y] == 16)dx = 1;
    if (grid[x - 1][y] == 16)dx = -1;
    if (grid[x][y + 1] == 16)dy = 1;
    if (grid[x][y - 1] == 16)dy = -1;

    if (dx != 0 || dy != 0)
    {
    n = grid[x][y];
    grid[x][y] = 16;
    grid[x + dx][y + dy] = n;
    renderTimer.Start(10);
    }
}

void wxImagePanel::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC& dc)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) 
        {
            n = grid[i][j] - 1;
            dc.DrawBitmap(blocks[n], w*i, w*j, false);
        }
    renderTimer.Stop();
}

void wxImagePanel::RenderTimer(wxTimerEvent& event)
{
    wxClientDC dc(this);
    render(dc);
}
