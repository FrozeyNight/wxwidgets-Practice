#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this);

    // The origin is the top left corner, so the 50 in wxPoint mean that it's 50px below the top and 150px from the left
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100,35));
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Enjoying life?", wxPoint(150, 100));
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "static text - NOT editable", wxPoint(150, 150)); // not specifying size makes it the default size
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "control text - editable", wxPoint(150, 200), wxSize(200, -1)); // -1 means default height
}