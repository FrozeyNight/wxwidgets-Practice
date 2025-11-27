#include "MainFrame.h"
#include <wx/wx.h>
//#include <wx/spinctrl.h>

enum IDs {
    // Custom ID - Rules
    // 1. Must be positive
    // 2. Cannot be 0 or 1
    // 3. Cannot be from wxID_LOWEST (4999) to wxID_HIGHEST (5999)
    BUTTON_ID = 2,
    SLIDER_ID = 3,
    TEXT_ID = 4
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
    EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    
    wxPanel* panel = new wxPanel(this);
    
    wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
    wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));
    
    CreateStatusBar();
    
    
    
    /* CONTROLS + STYLES
    wxPanel* panel = new wxPanel(this); // Without the panel, the controls would stretch to fit the entire window

    // The origin is the top left corner, so the 50 in wxPoint mean that it's 50px below the top and 150px from the left
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100,35), wxBU_LEFT); // last argument is a style
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Enjoying life?", wxPoint(150, 100), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER); // use the | (binary or) to use 2 styles
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "static text - NOT editable", wxPoint(10, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL); // not specifying size makes it the default size
    staticText->SetBackgroundColour(*wxBLUE);
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "control text - editable", wxPoint(150, 200), wxSize(200, -1), wxTE_PASSWORD); // -1 means default height
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(150, 250), wxSize(200, -1), wxSL_VALUE_LABEL); // styles specific to a given control have that control's first few letters in caps at the begining of it's name(BU for button, CHK for checkbox ect.)
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(600, 10), wxSize(-1, 75), wxGA_VERTICAL);
    gauge->SetValue(50);

    wxArrayString choices;
    choices.Add("Item C");
    choices.Add("Item B");
    choices.Add("Item A");

    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(500, 100), wxSize(200, -1), choices, wxCB_SORT); // You can choose to use a normal string array, but you have to use a different constructor (you need to pass the length of the array and then the array)
    choice->Select(0);

    // Non-standard control, need to add a special header file for it (it's included in the cloned repo by default)
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(500, 150), wxSize(150, -1), wxSP_WRAP);

    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(500, 200), wxSize(150, -1), choices, wxLB_MULTIPLE);
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radiobox", wxPoint(500, 300), wxSize(250, -1), choices);

    // ALWAYS use the new keyword (allocate dynamically)
    // Don't worry about deallocating, it's done automatically.
    */
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt){
    wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Text: %s", evt.GetString());
    wxLogStatus(str);
}