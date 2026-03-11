#include "MainFrame.h"
#include<wx/wx.h>

enum IDs
{
	BUTTON_ID = 2
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::onButtonClicked)
	EVT_BUTTON(BUTTON_ID, MainFrame::onTextChanged)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "ADD WORD", wxPoint(150, 50), wxSize(100,35));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "SEARCH WORD", wxPoint(250, 50), wxSize(100,35));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "DELETE WORD", wxPoint(350, 50), wxSize(100,35));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "UPDATE WORD", wxPoint(450, 50), wxSize(100,35));
	wxButton* button5 = new wxButton(panel, wxID_ANY, "SUGGEST WORD", wxPoint(550, 50), wxSize(100,35));
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TYPE YOUR WORD HERE", wxPoint(275, 145), wxSize(200, -1));


	this->Bind(wxEVT_BUTTON, &MainFrame::onButtonClicked, this);
	panel->Bind(wxEVT_TEXT, &MainFrame::onTextChanged, this);

	button->Unbind(wxEVT_BUTTON, &MainFrame::onButtonClicked, this);
}

void MainFrame::onButtonClicked(wxCommandEvent& evt)
{
	wxLogMessage("BUTTON CLICKED");

}

void MainFrame::onTextChanged(wxCommandEvent& evt)
{
	wxLogStatus("TEXT CHANGED");

}