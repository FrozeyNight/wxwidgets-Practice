#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this); // Without the panel, the controls would stretch to fit the entire window

    // The origin is the top left corner, so the 50 in wxPoint mean that it's 50px below the top and 150px from the left
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100,35));
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Enjoying life?", wxPoint(150, 100));
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "static text - NOT editable", wxPoint(150, 150)); // not specifying size makes it the default size
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "control text - editable", wxPoint(150, 200), wxSize(200, -1)); // -1 means default height
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(150, 250), wxSize(200, -1));
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 50), wxSize(200, -1));
    gauge->SetValue(50);

    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(500, 100), wxSize(200, -1), choices); // You can choose to use a normal string array, but you have to use a different constructor (you need to pass the length of the array and then the array)
    choice->Select(0);

    // Non-standard control, need to add a special header file for it (it's included in the cloned repo by default)
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(500, 150), wxSize(150, -1));

    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(500, 200), wxSize(150, -1), choices);
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radiobox", wxPoint(500, 300), wxSize(250, -1), choices);

    // ALWAYS use the new keyword (allocate dynamically)
    // Don't worry about deallocating, it's done automatically.
}