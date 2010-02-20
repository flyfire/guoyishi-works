// 4TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "4Test.h"
#include "4TestDlg.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy4TestDlg dialog

CMy4TestDlg::CMy4TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy4TestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy4TestDlg)
	m_strA = _T("");
	m_strQ = _T("");
	m_strSearch = _T("");
	m_nSlider = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy4TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy4TestDlg)
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_HOTKEY1, m_Hotkey);
	DDX_Control(pDX, IDC_LIST_RESULTS, m_listBox);
	DDX_Text(pDX, IDC_EDIT_A, m_strA);
	DDX_Text(pDX, IDC_EDIT_Q, m_strQ);
	DDX_Text(pDX, IDC_EDIT_SEARCH, m_strSearch);
	DDX_Slider(pDX, IDC_SLIDER1, m_nSlider);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy4TestDlg, CDialog)
	//{{AFX_MSG_MAP(CMy4TestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_LBN_SELCHANGE(IDC_LIST_RESULTS, OnSelchangeListResults)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_DRAWCLIPBOARD, OnClipChange)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_HIDE, OnButtonShowHide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy4TestDlg message handlers

BOOL CMy4TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set Clipboard viewer
	SetClipboardViewer();

	// 设置滑动条
	m_slider.SetRange( 30, 255 );
	m_slider.SetPos( 100 );
	UpdateData( TRUE );

	// 背景颜色
	m_brushWhite.CreateSolidBrush( RGB(255,255,255) );

	// 热键部分
	IsShow = TRUE;

	// 让窗口不在任务栏显示
	::SetWindowLong( GetSafeHwnd(), GWL_EXSTYLE, WS_EX_TOOLWINDOW );   

	// Ctrl + 1 切换
	WORD virtualcode,modifiers;
	m_Hotkey.SetRules(HKCOMB_CA,HOTKEYF_CONTROL);
	m_Hotkey.SetHotKey(VK_NUMPAD1,HOTKEYF_CONTROL);

	m_Hotkey.GetHotKey(virtualcode,modifiers);
	if (!RegisterHotKey(this->m_hWnd,100,modifiers,virtualcode)) // 隐藏窗口
	{
		MessageBox("Ctrl+1热键冲突！");
	}

	/*
	// Alt + Z 切换
	m_Hotkey.SetRules(HKCOMB_C,HOTKEYF_CONTROL);
	m_Hotkey.SetHotKey(0x31,HOTKEYF_CONTROL);

	m_Hotkey.GetHotKey(virtualcode,modifiers);
	if (!RegisterHotKey(this->m_hWnd, 1122, modifiers,virtualcode) ) {  // 隐藏窗口
		MessageBox( "Ctrl+111热键冲突！");
	}
	*/

	// Ctrl + 0 关闭程序
	m_Hotkey.SetRules(HKCOMB_CA,HOTKEYF_CONTROL);
	m_Hotkey.SetHotKey(VK_NUMPAD0,HOTKEYF_CONTROL);

	m_Hotkey.GetHotKey(virtualcode,modifiers);
	if (!RegisterHotKey(this->m_hWnd, 101, modifiers,virtualcode) ) {  // 关闭程序
		MessageBox( "关闭程序热键冲突！");
	}



	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy4TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy4TestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy4TestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy4TestDlg::OnButtonAdd() 
{
	AddDlg dlg;
	dlg.DoModal();
}

void CMy4TestDlg::OnButtonLoad() 
{
	CString filter;
	CFile theFile;
	filter = "考试程序文件(*.kaoshi)|*.kaoshi||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY, filter );
	if ( dlg.DoModal() != IDOK ) {
		return;
	}
	CString path = dlg.GetPathName();
	CFileStatus status;
	if ( !CFile::GetStatus( path, status ) ) {
		MessageBox( "该文件不存在！" );
		return;
	}
	if ( !theFile.Open( path, CFile::modeRead ) ) {
		MessageBox( "该文件无法打开！" );
		return;
	}
	// MessageBox( "Test: " + m_path );
	theFile.Close();

	// 清空已有文件
	m_Qs.RemoveAll();
	m_As.RemoveAll();
	Load(path);
	SetSearchTitle( m_Qs.GetSize() );

	UpdateData( FALSE );	
}

void CMy4TestDlg::Load(CString path)
{
	CFile theFile;
	theFile.Open( path, CFile::modeRead );
	char szBuffer[80];
	UINT nActual = 0;
	CString str;
	while ( nActual = theFile.Read( szBuffer, sizeof( szBuffer ) ) ) {
		CString strBuffer( szBuffer, nActual );
		str += strBuffer;

	}
	long pos_Q1 = 0;
	long pos_Q2 = 0;
	long pos_A = 0;
	CString strQ_S = "(%Q%)", strA_S = "(%A%)";
	CString strQ = "", strA = "";
	
	while ( pos_Q1 != -1 && pos_Q1 < str.GetLength() ) {
		strQ = "";
		strA = "";
		pos_Q1 = str.Find( strQ_S, pos_Q1 );
		if ( pos_Q1 >= 0 ) {
			pos_Q2 = str.Find( strQ_S, pos_Q1+1 );
			if ( pos_Q2 >= 0 ) {
				pos_A = str.Find( strA_S, pos_Q1 );
				if ( pos_A < pos_Q2 ) {
					strQ = str.Mid( pos_Q1+5, pos_A-pos_Q1-5 );
					// MessageBox( strQ );

					strA = str.Mid( pos_A+5, pos_Q2-pos_A-5 );
					// MessageBox( strA );
					// Insert!
					insert( strQ, strA );

				} else {
				}
			}
		}
		pos_Q1 = pos_Q2;
	}
}

void CMy4TestDlg::insert(CString Q, CString A)
{
	m_Qs.Add( Q );
	m_As.Add( A );
}

void CMy4TestDlg::OnButtonSearch() 
{
	UpdateData( TRUE );
	int pos = 0;
	int pos2 = 0;
	m_listBox.ResetContent(); // reset
	nIndexs.RemoveAll();

	// For debug
	// 
	// CString str = m_strSearch;
	// MessageBox( str );
	for ( int i = 0; i < m_Qs.GetSize(); ++i ) {
		for ( int j = 0; j < 2; ++j ) {
			if ( j == 0 ) {
				pos2 = (m_Qs[i]).Find( m_strSearch );
			} else {
				pos2 = (m_As[i]).Find( m_strSearch );
			}
			// For debug
			//
			// str.Format( "i: %d j:%d pos: %d", i, j, pos );
			// essageBox( str );
			if ( pos2 >= 0 ) {
				nIndexs.Add( i );
				insert_pos( i );
				pos = ++pos2;
				break;
			}
		}
	}

	SetResultListTitle( nIndexs.GetSize() );
	
	// Set Focus to list box
	// GetDlgItem(IDC_LIST_RESULTS)->SetFocus();
	// GetDlgItem( IDD_MY4TEST_DIALOG )->SetFocus();
	// ::SendMessage(m_hWnd,WM_NCACTIVATE,true,NULL);

	m_listBox.SetFocus();
	m_listBox.SetCurSel( 0 );
	if ( nIndexs.GetSize() > 0 ) {
		OnSelchangeListResults();
	} else {
		m_strQ = m_strA = "";
	}

	UpdateData( FALSE );	
}

void CMy4TestDlg::insert_pos(int pos)
{
	CString Q,A;
	Q = m_Qs.GetAt(pos);
	A = m_As.GetAt(pos);
	m_listBox.AddString( Q + "/" + A );
}

void CMy4TestDlg::OnSelchangeListResults() 
{
	int nIndex = m_listBox.GetCurSel();
	int pos = nIndexs[nIndex];
	m_strQ = m_Qs[pos];
	m_strA = m_As[pos];
	UpdateData( FALSE );	
}

// 热键
void CMy4TestDlg::OnHotKey(WPARAM wParam,LPARAM lParam)
{
	switch( wParam ) {
	case 100:
		ShowAndHideWindow();
		break;
	case 101:
		SendMessage(WM_CLOSE);
		break;
	}
	/*
	if (wParam==100)
	{
		if ( IsShow ) {
			ShowWindow(SW_HIDE);
			IsShow = FALSE;
		} else {
			ShowWindow( SW_SHOW );
			IsShow = TRUE;
		}
	} else if ( wParam == 101 ) {
		SendMessage(WM_CLOSE);
	}
	*/
}

void CMy4TestDlg::OnDestroy() 
{
	CDialog::OnDestroy();
}

void CMy4TestDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));	
	CDialog::OnLButtonDown(nFlags, point);	
}

HBRUSH CMy4TestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// 滑动条透明度设置
	UpdateData( TRUE );
	SetTransparent( this->m_hWnd, m_nSlider );

	// 设置控件颜色
	switch( nCtlColor ) {
		case CTLCOLOR_DLG:
		case CTLCOLOR_BTN:
		case CTLCOLOR_LISTBOX:
		case CTLCOLOR_EDIT:
		case CTLCOLOR_MSGBOX:
		case CTLCOLOR_SCROLLBAR:
			return    m_brushWhite;
			break;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMy4TestDlg::SetTransparent(HWND hwnd, UINT alpha)
{
	typedef   BOOL   (FAR   PASCAL*LAYERFUNC)(HWND,COLORREF,BYTE,DWORD);  
	LAYERFUNC   SetLayer;  
	HMODULE   hmod=LoadLibrary("user32.dll");  
	SetWindowLong(hwnd,GWL_EXSTYLE,GetWindowLong(hwnd,GWL_EXSTYLE)|0x80000L);  
	SetLayer=(LAYERFUNC)GetProcAddress(hmod,"SetLayeredWindowAttributes");  
	SetLayer(hwnd,0,alpha,0x2);  
       
	FreeLibrary(hmod);  
}

void CMy4TestDlg::OnOK()
{
	// 按回车键自动调用“搜索”功能
	OnButtonSearch();
}

void CMy4TestDlg::SetSearchTitle(int count)
{
	// 设置搜索框的标题，是加载的条目
	CString str;
	str.Format( "搜索：%d条结果", count );
	SetDlgItemText( IDC_STATIC_SEARCH_TITLE, str );
}

void CMy4TestDlg::SetResultListTitle(int count)
{
	// 设置搜索结果列表框标题，是搜索的条目
	if ( m_Qs.GetSize() > 0 ) {
		CString str;
		if ( count > 0 ) {
			str.Format( "【%s】共用%d条搜索结果", m_strSearch, count );
		} else {
			str.Format( "【%s】无搜索结果", m_strSearch );
		}
		SetDlgItemText( IDC_STATIC_RESULT_TITLE, str );
	}
}

void CMy4TestDlg::OnClipChange()
{
	if ( IsShow ) {  // If the window is show
		if ( OpenClipboard() ) {
			HANDLE hData = GetClipboardData( CF_TEXT );
			char *buffer = (char*)GlobalLock( hData );
			m_strSearch = buffer;
			GlobalUnlock( hData );
			CloseClipboard();
			UpdateData( FALSE );

			// Search "Clip Content"
			OnButtonSearch();
		}
	}
}

void CMy4TestDlg::ShowAndHideWindow()
{
	if ( IsShow ) {
		ShowWindow(SW_HIDE);
		IsShow = FALSE;
	} else {
		ShowWindow( SW_SHOW );
		IsShow = TRUE;
	}
}

void CMy4TestDlg::OnButtonShowHide() 
{
	ShowAndHideWindow();
}
