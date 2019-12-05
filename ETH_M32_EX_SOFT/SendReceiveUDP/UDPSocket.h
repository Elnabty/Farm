#if !defined(AFX_UDPSOCKET_H__7276059B_93AB_47FD_983E_1E43CCEE7FFB__INCLUDED_)
#define AFX_UDPSOCKET_H__7276059B_93AB_47FD_983E_1E43CCEE7FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

class CSendReceiveDocument;

class CUDPSocket : public CAsyncSocket {

public:
	CSendReceiveDocument *m_pDocument;		// public for debugging
	CUDPSocket() : m_pDocument(NULL) {};
	virtual ~CUDPSocket() {};
	void SetDocument(CSendReceiveDocument *pDocument) {m_pDocument=pDocument;};
	void Close() {CAsyncSocket::Close();};
	BOOL IsOpen() const {return (m_hSocket != INVALID_SOCKET);};

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CUDPSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

protected:
};

/////////////////////////////////////////////////////////////////////////////

class CSocketAddressIn : sockaddr_in  {		// public
public:
	CSocketAddressIn()
		{ZeroMemory(this, sizeof sockaddr_in);sin_family = AF_INET;};
	CSocketAddressIn(u_long Address, u_short Port = 0);
	void SetAddress(u_long Address) {sin_addr.s_addr = htonl(Address);};
	void GetAddress(CString &s) {s=inet_ntoa(sin_addr);};
	void SetPort(u_short Port) {sin_port = htons(Port);};
	operator sockaddr *() const {return (struct sockaddr *)this;}
};

//	-	-	-	-	-	-	-	-	-

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSOCKET_H__7276059B_93AB_47FD_983E_1E43CCEE7FFB__INCLUDED_)
