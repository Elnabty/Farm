#include "stdafx.h"
#include "SendReceive.h"
#include "UDPSocket.h"
#include "SendReceiveDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const CString CSendReceiveDocument::m_NoPath = "None";

/////////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CSendReceiveDocument, CDocument)

BEGIN_MESSAGE_MAP(CSendReceiveDocument, CDocument)
	//{{AFX_MSG_MAP(CSendReceiveDocument)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void CSendReceiveDocument::AssertValid() const {CDocument::AssertValid();}
void CSendReceiveDocument::Dump(CDumpContext& dc) const {CDocument::Dump(dc);}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////

CSendReceiveDocument::CSendReceiveDocument() : m_DataSize(0), m_rSocketPort(0) {
	CString Path;
m_UDPSocket.SetDocument(this);
CSocketAddressIn SocketAddressIn(INADDR_ANY);
SocketAddressIn.GetAddress(Path);
Path += " : 0";
SetPathName(Path);
}

BOOL CSendReceiveDocument::OnOpenDocument(LPCTSTR lpszPathName) {
	CString ErrorMessage, Message, PathName(lpszPathName), SocketAddress, s;
	int ColonIndex;
	UINT Port(0);
	long Events;
OnCloseDocument();
if (PathName == m_NoPath)
	return TRUE;
ColonIndex = PathName.Find(':');
if (ColonIndex == -1)
	SocketAddress = PathName;
else {
	SocketAddress = PathName.Left(ColonIndex);
	s = PathName.Mid(ColonIndex+1);
	s.TrimLeft();
	Port = strtoul(s, NULL, 10);
	}
Events = FD_READ | FD_WRITE | FD_CONNECT | FD_CLOSE;
if (!m_UDPSocket.Create(Port, SOCK_DGRAM, Events, SocketAddress)) {
	GetErrorMessage(GetLastError(), ErrorMessage);
	Message.Format("The socket for %s was not created:\r\n%s",
		PathName, ErrorMessage);
	AfxMessageBox(Message);
	SetPathName(m_NoPath);
	m_Message = "Open failed";
	UpdateAllViews(NULL, 8, NULL);
	return FALSE;
	}
SetPathName(PathName);
m_Message = "Opened: ";
m_Message += PathName;
UpdateAllViews(NULL, 1, NULL);
SetModifiedFlag(TRUE);
return TRUE;
}

void CSendReceiveDocument::OnCloseDocument() {
m_UDPSocket.Close();
// CDocument::OnCloseDocument();	// Don't call; will close view and frame
DeleteContents();
SetModifiedFlag(FALSE);
}

BOOL CSendReceiveDocument::OnNewDocument() {
AfxMessageBox("Sorry, \"New Document\" is not available");
return CDocument::OnNewDocument();
}

void CSendReceiveDocument::DeleteContents()  {
m_DataSize = 0;
m_Message.Empty();
m_ReceivedData.Empty();
UpdateAllViews(NULL, 9, NULL);
SetTitle(m_NoPath);
CDocument::DeleteContents();
}

void CSendReceiveDocument::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) {
m_strPathName = lpszPathName;
ASSERT(!m_strPathName.IsEmpty());       // must be set to something
m_bEmbedded = FALSE;
SetTitle(lpszPathName);
}

void CSendReceiveDocument::OnReceive(void *const Buffer, int Size,
				const CString rSocketAddress, UINT rSocketPort) {
m_rSocketPort = rSocketPort;
m_rSocketAddress = rSocketAddress;
m_DataSize = Size;
m_TimeReceived = CTime::GetCurrentTime();
memcpy(m_ReceivedData.GetBuffer(Size), Buffer, Size);
m_ReceivedData.ReleaseBuffer(Size);
UpdateAllViews(NULL, 2, NULL);
}

void CSendReceiveDocument::SendTo(LPCTSTR Data, DWORD dwAddress, LPCTSTR Port) {
	CSocketAddressIn SocketAddress;
	CString ErrorMessage, Message;
	int rv;
if (!m_UDPSocket.IsOpen()) {
	AfxMessageBox("Socket is not open");
	m_Message = "Socket is not open";
	UpdateAllViews(NULL, 8, NULL);
	return;
	}
SocketAddress.SetAddress(dwAddress);
SocketAddress.SetPort((u_short)strtoul(Port, NULL, 10));
rv = m_UDPSocket.SendTo(Data, strlen(Data), SocketAddress, sizeof SocketAddress, 0);
if (rv == SOCKET_ERROR) {
	GetErrorMessage(GetLastError(), ErrorMessage);
	Message.Format("The data was not sent:\r\n%s", ErrorMessage);
	AfxMessageBox(Message);
	m_Message = "Send failed";
	}
else
	m_Message = "Data sent";
UpdateAllViews(NULL, 8, NULL);
}

BOOL CSendReceiveDocument::SaveModified() {return TRUE;}
