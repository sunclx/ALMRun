#ifndef _MERRY_TEXT_CTRL_H_
#define _MERRY_TEXT_CTRL_H_

#include "MerryWx.h"

class MerryTextCtrl : public wxTextCtrl
{
public:
	long EnterArgs;
	void ExecuteCmd();
	MerryTextCtrl(wxWindow* parent);

private:
	void onContextMenu(wxContextMenuEvent& e);
	void OnKeyDownEvent(wxKeyEvent& e);
#ifdef __WXGTK__
	void OnIdleEvent(wxIdleEvent& e);
#else
	void OnTextEvent(wxCommandEvent& e);
#endif

private:
	void AutoCompletion(int keyCode);

private:
	int m_lastKeyDownCode;
#ifdef __WXGTK__
	wxString m_lastValue;
	bool m_needCompletion;
#endif

private:
	DECLARE_EVENT_TABLE()
};

#endif
