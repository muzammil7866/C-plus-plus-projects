#include <wx/frame.h>
class MainFrame : public wxFrame 
{
public:
	MainFrame(const wxString& title);	

	void onButtonClicked(wxCommandEvent& evt);
	void onTextChanged(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

	 
};

