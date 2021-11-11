#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_LEFT_DOWN(wxImagePanel::mouseDown)
    EVT_PAINT(wxImagePanel::paintEvent)
    EVT_TIMER(-1, wxImagePanel::RenderTimer)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
    wxPanel(parent), renderTimer(this, -1) {
       fifteen = new Fifteen(file, format, 4);
}

void wxImagePanel::mouseDown(wxMouseEvent& event) {
    if (!renderTimer.IsRunning()) {
        const wxPoint pt = wxGetMousePosition();
        int size = fifteen->BlockSize();

        int x = (pt.x - this->GetScreenPosition().x) / size;
        int y = (pt.y - this->GetScreenPosition().y) / size;

        int dx, dy;
        dx = dy = 0;

        std::vector <std::vector<Block*>> grid = fifteen->Grid();
        //setting offset
        if (x != fifteen->Size() - 1)
            if (grid[x + 1][y]->ID() == 16)dx = 1;

        if (x != 0)
            if (grid[x - 1][y]->ID() == 16)dx = -1;

        if (y != fifteen->Size() - 1)
            if (grid[x][y + 1]->ID() == 16)dy = 1;

        if (y != 0)
            if (grid[x][y - 1]->ID() == 16)dy = -1;

        if (dx != 0 || dy != 0) {
            fifteen->Swap(grid[x][y], grid[x + dx][y + dy]);
            emptyblock = grid[x][y]; //after the previous step, the pointers were swapped, so this block is now empty
            emptyblock->SetOffset(-dx * size, -dy * size);
            while (emptyblock->IsMoving) emptyblock->Move();

            int speed = 25;
            movingblock = fifteen->Grid()[x + dx][y + dy];
            movingblock->SetOffset(dx * speed, dy * speed);

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
                if (fifteen->Grid()[i][j]->ID() == 16) continue; //empty block can be painted over a movable one if drawn later(need fix)
                dc.DrawBitmap(fifteen->Grid()[i][j]->Bitmap(), fifteen->Grid()[i][j]->GetX(), fifteen->Grid()[i][j]->GetY(), false);
            }
}

void wxImagePanel::RenderTimer(wxTimerEvent& event) {
    movingblock->Move();

    wxClientDC client(this);
    wxBufferedDC dc(&client, wxNullBitmap, wxBUFFER_CLIENT_AREA);
    render(dc);

    if (!movingblock->IsMoving) renderTimer.Stop();
}