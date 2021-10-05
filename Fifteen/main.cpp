#include "main.h"
#include "fifteen.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Fifteen* fifteen = new Fifteen(wxT("Fifteen"));
    fifteen->Show(true);

    return true;
}