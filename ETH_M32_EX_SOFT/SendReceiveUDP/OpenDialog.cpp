#include "stdafx.h"
#include "SendReceive.h"
#include "resource.h"
#include "OpenDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

COpenDialog::COpenDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COpenDialog::IDD, pParent) {
	//{{AFX_DATA_INIT(COpenDialog)
	m_Port = 0;
	//}}AFX_DATA_INIT
}

void COpenDialog::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenDialog)
	DDX_Control(pDX, IDC_IPADDRESS, m_ctlIPAddress);
	DDX_Control(pDX, IDC_PORT, m_ctlPort);
	DDX_Text(pDX, IDC_PORT, m_Port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COpenDialog, CDialog)
	//{{AFX_MSG_MAP(COpenDialog)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, OnClearButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

void COpenDialog::OnOK() {
CDialog::OnOK();
m_ctlIPAddress.GetAddress(m_IPAddress);
}

void COpenDialog::OnClearButton() {
m_ctlPort.SetWindowText("0");
m_ctlIPAddress.ClearAddress();
}

BOOL COpenDialog::OnInitDialog() {
CDialog::OnInitDialog();
m_ctlIPAddress.SetAddress(m_IPAddress);
return TRUE;  // return TRUE unless you set the focus to a control
}
