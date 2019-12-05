#if !defined(AFX_SENDRECEIVEDOCUMENT_H__41B17E1C_70EE_4AD8_9973_DFFFE8B09163__INCLUDED_)
#define AFX_SENDRECEIVEDOCUMENT_H__41B17E1C_70EE_4AD8_9973_DFFFE8B09163__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

class CSendReceiveDocument : public CDocument {
protected:
	DECLARE_DYNCREATE(CSendReceiveDocument)

	CUDPSocket m_UDPSocket;
	int m_DataSize;
	UINT m_rSocketPort;
	CString m_rSocketAddress;
	static const CString m_NoPath;
	CString m_Message, m_ReceivedData;
	CTime m_TimeReceived;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendReceiveDocument)
	public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual BOOL OnNewDocument();
	virtual void DeleteContents();
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

public:
	CSendReceiveDocument();
	virtual ~CSendReceiveDocument() {};
	void SendTo(LPCTSTR, DWORD, LPCTSTR);
	void OnReceive(void * const, int, const CString, UINT);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSendReceiveDocument)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDRECEIVEDOCUMENT_H__41B17E1C_70EE_4AD8_9973_DFFFE8B09163__INCLUDED_)
