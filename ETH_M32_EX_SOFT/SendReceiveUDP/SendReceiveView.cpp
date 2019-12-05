#include "StdAfx.h"
#include "SendReceive.h"
#include "UDPSocket.h"
#include "SendReceiveDocument.h"
#include "resource.h"
#include "SendReceiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CSendReceiveView, CFormView)

CSendReceiveView::CSendReceiveView()
	: CFormView(CSendReceiveView::IDD) {
	//{{AFX_DATA_INIT(CSendReceiveView)
	m_Port = 0;
	//}}AFX_DATA_INIT
}

void CSendReceiveView::DoDataExchange(CDataExchange* pDX) {
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendReceiveView)
	DDX_Control(pDX, IDC_DATA_RECEIVED_HEADER, m_ctlDataReceivedHeader);
	DDX_Control(pDX, IDC_TIME, m_ctlTime);
	DDX_Control(pDX, IDC_FROM, m_ctlFrom);
	DDX_Control(pDX, IDC_DATA_RECEIVED, m_ctlDataReceived);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctlIPAddress);
	DDX_Control(pDX, IDC_PORT, m_ctlPort);
	DDX_Control(pDX, IDC_DATA, m_ctlData);
	DDX_Control(pDX, IDC_MESSAGE, m_ctlMessage);
	DDX_Text(pDX, IDC_PORT, m_Port);
	DDV_MinMaxUInt(pDX, m_Port, 0, 65535);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendReceiveView, CFormView)
	//{{AFX_MSG_MAP(CSendReceiveView)
	ON_COMMAND(IDM_BROADCAST, OnBroadcast)
	ON_COMMAND(IDM_LOOPBACK, OnLoopback)
	ON_COMMAND(IDM_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG
void CSendReceiveView::AssertValid() const {CFormView::AssertValid();}
void CSendReceiveView::Dump(CDumpContext& dc) const {CFormView::Dump(dc);}
CSendReceiveDocument* CSendReceiveView::GetDocument() {
ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSendReceiveDocument)));
return (CSendReceiveDocument*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CSendReceiveView::OnInitialUpdate() {
CFormView::OnInitialUpdate();
GetParentFrame()->RecalcLayout();
ResizeParentToFit(FALSE);
}

void CSendReceiveView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) {
switch (lHint) {
	case 1:			// open
		OnOpen();
		break;
	case 2:			// receive
		OnReceive();
		break;
	case 8:			// message
		m_ctlMessage.SetWindowText(GetDocument()->m_Message);
		break;
	case 9:			// clear
		m_ctlMessage.SetWindowText("");
		m_ctlDataReceived.SetWindowText("");
		m_ctlData.SetWindowText("");
		m_ctlTime.SetWindowText("");
		m_ctlFrom.SetWindowText("");
		break;
	}
}

void CSendReceiveView::OnBroadcast() {
m_ctlIPAddress.SetAddress(INADDR_BROADCAST);
}

void CSendReceiveView::OnLoopback() {
m_ctlIPAddress.SetAddress(INADDR_LOOPBACK);
}

void CSendReceiveView::OnSend() {
	CString Data, Port;
	DWORD dwAddress;
m_ctlData.GetWindowText(Data);
m_ctlPort.GetWindowText(Port);
m_ctlIPAddress.GetAddress(dwAddress);
GetDocument()->SendTo(Data, dwAddress, Port);
}

void CSendReceiveView::OnOpen() {
	CSendReceiveDocument *pDocument;
	CString Path, Port;
	int ColonIndex;
pDocument = GetDocument();
m_ctlMessage.SetWindowText(pDocument->m_Message);
Path = pDocument->GetPathName();
ColonIndex = Path.Find(':');
if (ColonIndex == -1)
	m_ctlPort.SetWindowText("0");	// no port
else {
	Port = Path.Mid(ColonIndex+1);	// port
	Port.TrimLeft();
	m_ctlPort.SetWindowText(Port);
	}
}

void CSendReceiveView::OnReceive() {
	CSendReceiveDocument *pDocument;
	CString s;
pDocument = GetDocument();
m_ctlMessage.SetWindowText("Data received");
m_ctlDataReceived.SetWindowText(pDocument->m_ReceivedData);
m_ctlTime.SetWindowText(pDocument->m_TimeReceived.Format("%X"));
s.Format("%s : %u", pDocument->m_rSocketAddress, pDocument->m_rSocketPort);
m_ctlFrom.SetWindowText(s);
s.Format("%i bytes received", pDocument->m_DataSize);
m_ctlDataReceivedHeader.SetWindowText(s);
}
