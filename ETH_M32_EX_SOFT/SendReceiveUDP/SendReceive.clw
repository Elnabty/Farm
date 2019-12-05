; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSendReceiveView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sendreceive.h"
LastPage=0

ClassCount=5
Class1=CSendReceiveApp

ResourceCount=3
Resource1=IDR_MAINFRAME
Class2=CSendReceiveView
Class3=CSendReceiveDocument
Class4=CUDPSocket
Resource2=IDD_FORMVIEW
Class5=COpenDialog
Resource3=IDD_OPEN_DIALOG

[CLS:CSendReceiveApp]
Type=0
BaseClass=CWinApp
HeaderFile=SendReceive.h
ImplementationFile=SendReceive.cpp
LastObject=CSendReceiveApp
Filter=N
VirtualFilter=AC

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=IDM_LOOPBACK
Command3=IDM_BROADCAST
Command4=IDM_SEND
Command5=ID_FILE_CLOSE
Command6=ID_APP_EXIT
CommandCount=6

[DLG:IDD_FORMVIEW]
Type=1
Class=CSendReceiveView
ControlCount=13
Control1=IDC_MESSAGE,static,1342313099
Control2=IDC_IPADDRESS1,SysIPAddress32,1342373888
Control3=IDC_PORT,edit,1350639744
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DATA,edit,1350631556
Control7=IDC_STATIC,static,1342308352
Control8=IDC_DATA_RECEIVED,edit,1350633604
Control9=IDC_DATA_RECEIVED_HEADER,static,1342308352
Control10=IDC_STATIC,static,1342308491
Control11=IDC_TIME,edit,1350633600
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FROM,edit,1350633600

[CLS:CSendReceiveView]
Type=0
HeaderFile=SendReceiveView.h
ImplementationFile=SendReceiveView.cpp
BaseClass=CFormView
Filter=D
LastObject=CSendReceiveView
VirtualFilter=VWC

[CLS:CSendReceiveDocument]
Type=0
HeaderFile=SendReceiveDocument.h
ImplementationFile=SendReceiveDocument.cpp
BaseClass=CDocument
Filter=N
VirtualFilter=DC
LastObject=CSendReceiveDocument

[CLS:CUDPSocket]
Type=0
HeaderFile=UDPSocket.h
ImplementationFile=UDPSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CUDPSocket

[DLG:IDD_OPEN_DIALOG]
Type=1
Class=COpenDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CLEAR_BUTTON,button,1342242816
Control4=IDC_STATIC,static,1342308353
Control5=IDC_IPADDRESS,SysIPAddress32,1342373888
Control6=IDC_STATIC,static,1342308353
Control7=IDC_PORT,edit,1350639744
Control8=IDC_STATIC,static,1342312577

[CLS:COpenDialog]
Type=0
HeaderFile=OpenDialog.h
ImplementationFile=OpenDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COpenDialog

