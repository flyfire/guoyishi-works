; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMy4TestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "4Test.h"

ClassCount=4
Class1=CMy4TestApp
Class2=CMy4TestDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MY4TEST_DIALOG
Class4=AddDlg
Resource4=IDD_DIALOG1

[CLS:CMy4TestApp]
Type=0
HeaderFile=4Test.h
ImplementationFile=4Test.cpp
Filter=N

[CLS:CMy4TestDlg]
Type=0
HeaderFile=4TestDlg.h
ImplementationFile=4TestDlg.cpp
Filter=D
LastObject=CMy4TestDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=4TestDlg.h
ImplementationFile=4TestDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY4TEST_DIALOG]
Type=1
Class=CMy4TestDlg
ControlCount=14
Control1=IDC_STATIC_SEARCH_TITLE,button,1342177287
Control2=IDC_EDIT_SEARCH,edit,1350631552
Control3=IDC_BUTTON_SEARCH,button,1342242816
Control4=IDC_STATIC_RESULT_TITLE,button,1342177287
Control5=IDC_LIST_RESULTS,listbox,1352663297
Control6=IDC_STATIC,button,1342177287
Control7=IDC_EDIT_Q,edit,1352665156
Control8=IDC_EDIT_A,edit,1352730692
Control9=IDC_BUTTON_ADD,button,1476460544
Control10=IDC_BUTTON_LOAD,button,1342242816
Control11=IDC_HOTKEY1,msctls_hotkey32,1082130432
Control12=IDC_SLIDER1,msctls_trackbar32,1342177301
Control13=IDC_STATIC,button,1342177287
Control14=IDC_BUTTON_SHOW_HIDE,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=AddDlg
ControlCount=10
Control1=IDSAVE,button,1342177281
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_PATH,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON_SELECT,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_Q,edit,1352728644
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_A,edit,1352728644

[CLS:AddDlg]
Type=0
HeaderFile=AddDlg.h
ImplementationFile=AddDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AddDlg
VirtualFilter=dWC

