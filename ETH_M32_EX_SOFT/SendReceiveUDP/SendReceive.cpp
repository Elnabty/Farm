#include "StdAfx.h"
#include "SendReceive.h"
#include "UDPSocket.h"
#include "SendReceiveDocument.h"
#include "resource.h"
#include "SendReceiveView.h"
#include "OpenDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//	*	*	*	*	*	*	*	*	*	*

CSendReceiveApp SendReceiveApp;

BEGIN_MESSAGE_MAP(CSendReceiveApp, CWinApp)
//{{AFX_MSG_MAP(CSendReceiveApp)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//	*	*	*	*	*	*	*	*	*	*

BOOL CSendReceiveApp::InitInstance() {
#ifdef _AFXDLL
	Enable3dControls(); // Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic(); // Call this when linking to MFC statically
#endif
if (!AfxSocketInit()) {
	AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
	return FALSE;
	}
SetRegistryKey(_T("Sam Hobbs"));	// Change to whatever is relevant
LoadStdProfileSettings(8);
CFrameWnd *pFrameWnd;
pFrameWnd = new CFrameWnd;
m_pSendReceiveDocument = new CSendReceiveDocument;
m_pSendReceiveDocument->m_bAutoDelete = FALSE;
CCreateContext Context;
Context.m_pNewViewClass = RUNTIME_CLASS(CSendReceiveView);
Context.m_pCurrentFrame = pFrameWnd;
Context.m_pCurrentDoc = m_pSendReceiveDocument;
if (!pFrameWnd->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		NULL, &Context)) {
	AfxMessageBox("Frame Load Error");
	return FALSE;
	}
m_pMainWnd = pFrameWnd;
pFrameWnd->InitialUpdateFrame(NULL, TRUE);	// Will do ShowWindow
TRACE("InitInstance: %s %s\n", m_pSendReceiveDocument->GetRuntimeClass()->m_lpszClassName,
	  m_pSendReceiveDocument->m_UDPSocket.m_pDocument->GetRuntimeClass()->m_lpszClassName);
return CWinApp::InitInstance();
}

//	*	*	*	*	*	*	*	*	*	*

void GetErrorMessage(const DWORD e, CString &Message) {
	LPTSTR lpMsgBuf=NULL;
	DWORD Size, fme;
Size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, e, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
fme = GetLastError();
if (lpMsgBuf) {
	Message = lpMsgBuf;
	LocalFree(lpMsgBuf);
	if (Size)
		return;
	}
if (fme)
	Message.Format("FormatMessage error code %u", fme);
else
	Message.Format("unknown error code %u", e);
}

//	*	*	*	*	*	*	*	*	*	*

int CSendReceiveApp::ExitInstance() {
m_pSendReceiveDocument->OnCloseDocument();
delete m_pSendReceiveDocument;
return CWinApp::ExitInstance();
}

//	*	*	*	*	*	*	*	*	*	*

void CSendReceiveApp::OnFileOpen() {
	CString PathName, SocketAddress, s;
	COpenDialog OpenDialog;
	in_addr DWordAddress;
	int ColonIndex;
	UINT Port(0);
PathName = m_pSendReceiveDocument->GetPathName();
ColonIndex = PathName.Find(':');
if (ColonIndex == -1)
	SocketAddress = PathName;
else {
	SocketAddress = PathName.Left(ColonIndex);
	s = PathName.Mid(ColonIndex+1);
	s.TrimLeft();
	Port = strtoul(s, NULL, 10);
	}
SocketAddress.TrimRight();
OpenDialog.m_IPAddress = htonl(inet_addr(SocketAddress));
OpenDialog.m_Port = Port;
if (OpenDialog.DoModal() != IDOK)
	return;
DWordAddress.S_un.S_addr = ntohl(OpenDialog.m_IPAddress);
PathName.Format("%s:%u", inet_ntoa(DWordAddress), OpenDialog.m_Port);
m_pSendReceiveDocument->OnOpenDocument(PathName);
}
