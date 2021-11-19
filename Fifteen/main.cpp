#include "main.h"
#include "PuzzleApp.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    PuzzleApp* app = new PuzzleApp(wxT("Fifteen Puzzle"));
    app->Show(true);

    return true;
}