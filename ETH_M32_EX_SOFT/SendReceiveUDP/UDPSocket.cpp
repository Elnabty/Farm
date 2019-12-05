#include "stdafx.h"
#include "SendReceive.h"
#include "UDPSocket.h"
#include "SendReceiveDocument.h"
#pragma comment(lib, "ws2_32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CUDPSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CUDPSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////

void CUDPSocket::OnReceive(int nErrorCode) {
	CString IPAddress;
	char Buffer[512];		// Increase size as needed
	CString Message;
	DWORD Error;
	UINT Port;
	int Size;
CAsyncSocket::OnReceive(nErrorCode);
if (nErrorCode) {
	Message.Format("OnReceive nErrorCode: %i", nErrorCode);
	AfxMessageBox(Message);
	return;
	}
Size = ReceiveFrom(Buffer, sizeof Buffer, IPAddress, Port);
if (!Size || Size == SOCKET_ERROR) {
	Error = GetLastError();
	Message.Format("ReceiveFrom error code: %u", Error);
	AfxMessageBox(Message);
	return;
	}
if (m_pDocument)
	m_pDocument->OnReceive(Buffer, Size, IPAddress, Port);
else
	AfxMessageBox("No document pointer");
}

//////////////////////////////////////////////////////////////////////
// CSocketAddressIn Class
//////////////////////////////////////////////////////////////////////

CSocketAddressIn::CSocketAddressIn(u_long Address, u_short Port) {
sin_family = AF_INET;
sin_addr.s_addr = htonl(Address);
sin_port = htons(Port);
ZeroMemory(sin_zero, sizeof sin_zero);
}
