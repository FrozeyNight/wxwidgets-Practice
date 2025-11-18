#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this);

    // The origin is the top left corner, so the 50 in wxPoint mean that it's 50px below the top and 150px from the left
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100,35));
}