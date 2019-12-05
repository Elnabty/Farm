#pragma once

void GetErrorMessage(const DWORD e, CString &Message);

class CSendReceiveDocument;

class CSendReceiveApp : public CWinApp {
	CSendReceiveDocument *m_pSendReceiveDocument;
public:
	CSendReceiveApp() {};

// Overrides
// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CSendReceiveApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

//{{AFX_MSG(CSendReceiveApp)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
