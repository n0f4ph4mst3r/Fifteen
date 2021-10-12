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
        x1 = x;
        x2 = x + dx;
        y1 = y;
        y2 = y + dy;

        x_pos = x * w;
        y_pos = y * w;

        this->dx = dx;
        this->dy = dy;

    n = grid[x][y];
    renderTimer.Start(10);
    }
}

void wxImagePanel::paintEvent(wxPaintEvent& evt)
{
    wxBufferedPaintDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC& dc)
{
    static bool IsFirstRender = true;
    if (IsFirstRender)
    {
        dc.SetBackground(*wxWHITE_BRUSH);
        dc.DrawBitmap(source, 0, 0, false);
        IsFirstRender = false;
    }
    else
    {
        int speed_x = (x2 - x1) * 25;
        int speed_y = (y2 - y1) * 25;

        int k = grid[x2][y2];

        dc.DrawBitmap(blocks[k - 1], x_pos, y_pos, false);

        x_pos += speed_x;
        if ((x_pos > x2 * w && dx == 1) || (x_pos < x2*w && dx == -1))
        {
            x_pos = x2 * w;
        }

        y_pos += speed_y;
        if ((y_pos > y2 * w && dy == 1) || (y_pos < y2*w && dy == -1))
        {
            y_pos = y2 * w;
        }

        dc.DrawBitmap(blocks[n-1], x_pos, y_pos, false);

        if (x_pos == x2*w && y_pos == y2*w)
        {
            grid[x1][y1] = 16;
            grid[x2][y2] = n;
            renderTimer.Stop();
        }
    }
}

void wxImagePanel::RenderTimer(wxTimerEvent& event)
{
    wxClientDC dc_Client(this);
    wxClientDC* Client;
    Client = &dc_Client;
    wxBufferedDC dc(Client, wxNullBitmap, wxBUFFER_CLIENT_AREA);
    render(dc);
}
 /*
 for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                n = grid[i][j] - 1;
                dc.DrawBitmap(blocks[n], w * i, w * j, false);
            }
 */