#if !defined(AFX_OPENDIALOG_H__0BB5896E_172C_4096_8B8C_D78E2445BE26__INCLUDED_)
#define AFX_OPENDIALOG_H__0BB5896E_172C_4096_8B8C_D78E2445BE26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

class COpenDialog : public CDialog {
// Construction
public:
	COpenDialog(CWnd* pParent = NULL);   // standard constructor
	DWORD m_IPAddress;

// Dialog Data
	//{{AFX_DATA(COpenDialog)
	enum { IDD = IDD_OPEN_DIALOG };
	CIPAddressCtrl	m_ctlIPAddress;
	CEdit	m_ctlPort;
	UINT	m_Port;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenDialog)
	virtual void OnOK();
	afx_msg void OnClearButton();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENDIALOG_H__0BB5896E_172C_4096_8B8C_D78E2445BE26__INCLUDED_)
