#include "main.h"
#include "FifteenApp.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    FifteenApp* app = new FifteenApp(wxT("Fifteen Puzzle"));
    app->Show(true);

    return true;
}