#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App); // very important - This determines the main of this project

bool App::OnInit(){
    MainFrame* mainFrame = new MainFrame("C++ GUI");
    mainFrame->SetClientSize(800, 600); // This sets the window (not including the title bar and it's border) to 800x600. If you set this in the constructor instead, it would make the whole window 800x600.
    mainFrame->Center();
    mainFrame->Show(); // the window is hidden by default, you need to use this to show it 
    return true;
}