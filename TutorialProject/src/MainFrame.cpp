#include "MainFrame.h"
#include <wx/wx.h>
//#include <wx/spinctrl.h>

/*
enum IDs { //(old way of doing events (static), more in MainFrame.h)
    // Custom ID - Rules
    // 1. Must be positive
    // 2. Cannot be 0 or 1
    // 3. Cannot be from wxID_LOWEST (4999) to wxID_HIGHEST (5999)
    BUTTON_ID = 2,
    SLIDER_ID = 3,
    TEXT_ID = 4
};
*/

/* //(old way of doing events (static), more in MainFrame.h)
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
    EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()
*/

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    
    wxPanel* panel = new wxPanel(this);
    wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "To-Do List", wxPoint(325, 24), wxSize(200, 100));
    wxFont font = titleText->GetFont();
    font.SetPointSize(22);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    titleText->SetFont(font);
    wxTextCtrl* userInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(510, -1), wxTE_PROCESS_ENTER);
    wxButton* addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(615, 80), wxSize(-1, 28));
    wxArrayString items;

    wxCheckListBox* checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 115), wxSize(600, 420), items, wxLB_MULTIPLE);
    wxButton* clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(100, 540), wxSize(-1, 28));


    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
    userInput->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnEnterKeyEvent, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnCheckListBoxKeyEvent, this);

    // ---Keyboard Events---
    /*
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS); // wxWANTS_CHARS + wxEVT_CHAR_HOOK allows for global registering of keystrokes, which is clunky to do any other way, since other solutions will only accept keystrokes if the control in focus has the event, since it doesn't propagate
    wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
    wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));
    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this); // There is also wxEVT_CHAR that's good for combinations such as shift+letter, since _KEY_DOWN will show them as separate 
    
    CreateStatusBar();
    */

    // ---Mouse Events---
    /*
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));
    button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this); // since the wxMouseEvent doesn't propagate, if you want to know the position of the mouse even while hovering over controls, you need to add the wxMouseEvent to them.
    panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
    CreateStatusBar();*/

    // If a control flickers, store it in a local variable and enable double buffering. That should fix the issue
    //wxStatusBar* statusBar = new wxStatusBar();
    //statusBar->SetDoubleBuffered(true);

    // ---Event Propagation---
    /*
    wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));
    this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
    this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
    */


    // ---Dynamic Events---
    //wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
    //wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    //wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

    //button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // find out the event tag(first param) in the documentation
    //slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
    //text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

    //button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); // remove an event from an object

    //CreateStatusBar();

    /* //(old way of doing events (static), more in MainFrame.h)
    wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
    wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));
    */
    //CreateStatusBar();
    
    
    
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

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt){ // Event propagation - if a child of na object(for example a button of a Frame) is clicked, it looks for an event handler. If it doesn't have one, it checks for the event handler in it's parent. If there are multiple buttons, it will call the same event for all of them.
    wxLogMessage("Button Clicked");
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt){
    wxLogMessage("Button 1 clicked");
    evt.Skip(); // This tells propagation that it should continue(so if a parent has an event handler, it will not stop trying to call events added to the parent of the object that triggered this event, it will go up the chain and call the next event from it's parents)
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt){
    wxLogMessage("Button 2 clicked");
    evt.Skip();
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Text: %s", evt.GetString());
    wxLogStatus(str);
}

void MainFrame::OnClose(wxCloseEvent& evt){
    wxLogMessage("Frame Closed");
    evt.Skip();
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt){
    wxPoint mousePos = evt.GetPosition(); // This shows client position (so for example the position relative to the origin point of the button (the origin point of most objects in wxWidgets is by default the top left corner))
    //wxPoint mousePos = wxGetMousePosition(); // This shows screen position (so where the mouse is on the screen)
    //mousePos = this->ScreenToClient(mousePos); This converts the screen position to the clinet position 
    //mousePos = this->ClientToScreen(mousePos); This converts the clinet position to the screen position 
    wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
    wxLogStatus(message);
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt){
    // This is how you detect specific keys
    if(evt.GetUnicodeKey() == 'A'){
        wxLogStatus("A was pressed!");
        return;
    }
    else if(evt.GetKeyCode() == WXK_HOME){
        wxLogStatus("HOME was pressed!");
        return;
    }

    wxChar keyChar = evt.GetUnicodeKey(); // Shows basic keys like 'A' or '2', but not something like home or alt. If the user presess that, it returns WXK_NONE

    if(keyChar == WXK_NONE){ // Displays the code for certain keys for example alt, home, insert
        int keyCode = evt.GetKeyCode();
        wxLogStatus("Key Event %d", keyCode);
    }
    else{
        wxLogStatus("Key Event %c", keyChar);
    }
}

void MainFrame::OnAddButtonClicked(wxCommandEvent& evt){
    wxWindow* window = (wxWindow*)evt.GetEventObject();
    window = window->GetParent();
    for (wxWindowList::iterator i = window->GetChildren().begin(); i != window->GetChildren().end(); i++)
    {
        wxCheckListBox* checkBoxList = dynamic_cast<wxCheckListBox *>(*i);
        if(checkBoxList && checkBoxList->GetName() == "listBox"){
            for (wxWindowList::iterator j = window->GetChildren().begin(); j != window->GetChildren().end(); j++)
            {
                wxTextCtrl* inputText = dynamic_cast<wxTextCtrl *>(*j);
                if(inputText && inputText->GetName() == "text" && inputText->GetValue() != ""){
                    checkBoxList->Append(inputText->GetValue());
                    inputText->SetValue("");
                    return;
                }
            }
        }
    }
}

void MainFrame::OnEnterKeyEvent(wxCommandEvent& evt){
    wxWindow* window = (wxWindow*)evt.GetEventObject();
    window = window->GetParent();
    for (wxWindowList::iterator i = window->GetChildren().begin(); i != window->GetChildren().end(); i++)
    {
        wxCheckListBox* checkBoxList = dynamic_cast<wxCheckListBox *>(*i);
        if(checkBoxList && checkBoxList->GetName() == "listBox"){
            for (wxWindowList::iterator j = window->GetChildren().begin(); j != window->GetChildren().end(); j++)
            {
                wxTextCtrl* inputText = dynamic_cast<wxTextCtrl *>(*j);
                if(inputText && inputText->GetName() == "text" && inputText->GetValue() != ""){
                    checkBoxList->Append(inputText->GetValue());
                    inputText->SetValue("");
                    return;
                }
            }
        }
    }
}

void MainFrame::OnCheckListBoxKeyEvent(wxKeyEvent& evt){
    int pressedKey = evt.GetKeyCode();
    if(pressedKey == WXK_DELETE || pressedKey == WXK_UP || pressedKey == WXK_DOWN){
        wxWindow* window = (wxWindow*)evt.GetEventObject();
        window = window->GetParent();
        for (wxWindowList::iterator i = window->GetChildren().begin(); i != window->GetChildren().end(); i++)
        {
            wxCheckListBox* checkBoxList = dynamic_cast<wxCheckListBox *>(*i);
            if(checkBoxList && checkBoxList->GetName() == "listBox"){
                int itemsCount = checkBoxList->GetCount();
                for (int j = 0; j < itemsCount; j++)
                {
                    if(checkBoxList->IsSelected(j)){
                        if(pressedKey == WXK_DELETE){
                            checkBoxList->Delete(j);
                            checkBoxList->DeselectAll();
                            break;
                        }
                        /* try setting the clientobject data when adding things to it
                        else if(pressedKey == WXK_UP){
                            checkBoxList->SetClientObject(j)
                            //wxCheckBox* holder = (wxCheckBox*)checkBoxList->GetClientObject(j - 1);
                            //checkBoxList->Delete(j - 1);
                            //checkBoxList->Insert(holder->GetName(), j);
                        }
                        else{
                            wxCheckBox* holder = (wxCheckBox*)checkBoxList->GetClientObject(j + 1);
                            checkBoxList->Delete(j + 1);
                            checkBoxList->Insert(holder->GetName(), j);
                        }
                        */
                    }
                }
                
            }
                
        }
    }
}

void MainFrame::OnClearButtonClicked(wxCommandEvent& evt){
    wxWindow* window = (wxWindow*)evt.GetEventObject();
    window = window->GetParent();
    for (wxWindowList::iterator i = window->GetChildren().begin(); i != window->GetChildren().end(); i++)
    {
        wxCheckListBox* checkBoxList = dynamic_cast<wxCheckListBox *>(*i);
        if(checkBoxList && checkBoxList->GetName() == "listBox"){
            int itemsCount = checkBoxList->GetCount();
            wxMessageDialog* popUpMessage = new wxMessageDialog(window, "Are you sure you want to clear all tasks?", "Clear", wxYES_NO | wxCANCEL);
            int userChoice = popUpMessage->ShowModal();
            if(userChoice == wxID_YES){
                for (int j = itemsCount - 1; j >= 0; j--)
                {
                    checkBoxList->Delete(j);
                }
            }
            
        }
            
    }
}