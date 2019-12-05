#if !defined(AFX_SENDRECEIVEVIEW_H__C341FA83_2EB1_42E7_9CAB_541EDA20F684__INCLUDED_)
#define AFX_SENDRECEIVEVIEW_H__C341FA83_2EB1_42E7_9CAB_541EDA20F684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendReceiveView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendReceiveView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSendReceiveView : public CFormView
{
protected:
	CSendReceiveView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSendReceiveView)

public:
	//{{AFX_DATA(CSendReceiveView)
	enum { IDD = IDD_FORMVIEW };
	CStatic	m_ctlDataReceivedHeader;
	CEdit	m_ctlTime;
	CEdit	m_ctlFrom;
	CEdit	m_ctlDataReceived;
	CIPAddressCtrl	m_ctlIPAddress;
	CEdit	m_ctlPort;
	CEdit	m_ctlData;
	CStatic	m_ctlMessage;
	UINT	m_Port;
	//}}AFX_DATA

	CSendReceiveDocument* GetDocument();

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendReceiveView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSendReceiveView() {};
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSendReceiveView)
	afx_msg void OnBroadcast();
	afx_msg void OnLoopback();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void OnReceive();
	void OnOpen();
};

#ifndef _DEBUG  // debug version in UDPListenView.cpp
inline CSendReceiveDocument* CSendReceiveView::GetDocument()
   { return (CSendReceiveDocument*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDRECEIVEVIEW_H__C341FA83_2EB1_42E7_9CAB_541EDA20F684__INCLUDED_)
