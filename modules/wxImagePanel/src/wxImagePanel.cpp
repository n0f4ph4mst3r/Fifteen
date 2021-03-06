//implementation of class wxImagePanel
#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::mouseDown)
    EVT_PAINT(wxImagePanel::paintEvent)
    EVT_TIMER(-1, wxImagePanel::RenderTimer)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, wxBitmap* background) :
    wxPanel(parent, -1, wxDefaultPosition, wxSize(512, 512)), renderTimer(this, -1) {
       fifteen = std::make_unique<Puzzle>(*background);
}

void wxImagePanel::mouseDown(wxMouseEvent& event) {
    if (!renderTimer.IsRunning()) {
        const wxPoint pt = wxGetMousePosition();
        const int &size = fifteen->BlockSize();

        int x = (pt.x - this->GetScreenPosition().x) / size;
        int y = (pt.y - this->GetScreenPosition().y) / size;

        int dx, dy;
        dx = dy = 0;

        const PuzzleGrid &grid = fifteen->Grid();
        //setting offset
        if (x != fifteen->Size() - 1)
            if (grid[x + 1][y]->id == 16)dx = 1;

        if (x != 0)
            if (grid[x - 1][y]->id == 16)dx = -1;

        if (y != fifteen->Size() - 1)
            if (grid[x][y + 1]->id == 16)dy = 1;

        if (y != 0)
            if (grid[x][y - 1]->id == 16)dy = -1;

        if (dx != 0 || dy != 0) {
            grid[x + dx][y + dy]->positionX = grid[x][y]->positionX;
            grid[x + dx][y + dy]->positionY = grid[x][y]->positionY;

            std::swap(*grid[x][y], *grid[x + dx][y + dy]);
            movingblock = grid[x + dx][y + dy]; //after the previous step, the pointers were swapped, so this block is now empty
            movingblock->offset.x = dx;
            movingblock->offset.y = dy;

            renderTimer.Start(10);
        }
    }
}

void wxImagePanel::paintEvent(wxPaintEvent& evt) {
    wxPaintDC dc(this);
    render(dc);
}

void wxImagePanel::render(wxDC& dc) {
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
        
        for (int i = 0; i < fifteen->Size(); i++)
            for (int j = 0; j < fifteen->Size(); j++) {
                if (fifteen->Grid()[i][j]->id != 16) //empty block can be painted over a movable one if drawn later(need fix)
                dc.DrawBitmap(wxBitmap(fifteen->Grid()[i][j]->blockImage), fifteen->Grid()[i][j]->positionX, fifteen->Grid()[i][j]->positionY, false);
            }
}

void wxImagePanel::RenderTimer(wxTimerEvent& event) {
    static int x_begin;
    static int x_end;
    static int y_begin;
    static int y_end;
    static bool movementStarted = false;

    int &x_pos = movingblock->positionX;
    int &y_pos = movingblock->positionY;
    int &offsetX = movingblock->offset.x;
    int &offsetY = movingblock->offset.y;

    if (movementStarted == false) {
        const int &w = movingblock->blockImage.GetWidth();
        const int &h = movingblock->blockImage.GetHeight();

        x_begin = x_pos;
        if (offsetX > 0) x_end = x_pos + w;
        else if (offsetX < 0) x_end = x_pos - w;
        else x_end = x_begin;

        y_begin = y_pos;
        if (offsetY > 0)  y_end = y_pos + h;
        else if (offsetY < 0) y_end = y_pos - h;
        else y_end = y_begin;

        movementStarted = true;
    }

    static int speed = 25;
    x_pos += offsetX * speed;
    y_pos += offsetY * speed;

    if ((x_pos > x_end && offsetX > 0) || (x_pos < x_end && offsetX < 0) || (x_pos != 0 && offsetX == 0))
        x_pos = x_end;

    if ((y_pos > y_end && offsetY > 0) || (y_pos < y_end && offsetY < 0) || (y_pos != 0 && offsetY == 0))
        y_pos = y_end;

    wxClientDC client(this);
    wxBufferedDC dc(&client, wxNullBitmap, wxBUFFER_CLIENT_AREA);
    render(dc);

    if (x_pos == x_end && y_pos == y_end) {
        movementStarted = false;
        movingblock->offset = wxPoint(0,0);

        renderTimer.Stop();
    }
}