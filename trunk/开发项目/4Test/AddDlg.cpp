// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "4Test.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddDlg dialog


AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddDlg)
	m_path = _T("");
	m_strA = _T("");
	m_strQ = _T("");
	//}}AFX_DATA_INIT
}


void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddDlg)
	DDX_Text(pDX, IDC_EDIT_PATH, m_path);
	DDX_Text(pDX, IDC_EDIT_A, m_strA);
	DDX_Text(pDX, IDC_EDIT_Q, m_strQ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddDlg, CDialog)
	//{{AFX_MSG_MAP(AddDlg)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, OnButtonSelect)
	ON_BN_CLICKED(IDSAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddDlg message handlers

void AddDlg::OnButtonSelect() 
{
	CString filter;
	filter = "考试程序文件(*.kaoshi)|*.kaoshi||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY, filter );
	if ( dlg.DoModal() != IDOK ) {
		return;
	}
	m_path = dlg.GetPathName();
	CFileStatus status;
	if ( !CFile::GetStatus( m_path, status ) ) {
		MessageBox( "该文件不存在！" );
		return;
	}
	if ( !theFile.Open( m_path, CFile::modeReadWrite ) ) {
		MessageBox( "该文件无法打开或写入！" );
		return;
	}
	// MessageBox( "Test: " + m_path );

	UpdateData( FALSE );	
}

void AddDlg::OnSave() 
{
	UpdateData( TRUE );
	CString strs[2] = { m_strQ, m_strA };
	CString strFinds[2] = { "(%Q%)", "(%A%)" };
	for ( int i = 0; i < 2; ++i ) {
		for ( int j = 0; j < 2; ++j ) {
			if ( strs[i].IsEmpty() == TRUE ) {          // 空内容，错误处理
				MessageBox( "输入为空，请输入内容！" );
				return;
			}
			if ( strs[i].Find(strFinds[j], 0) >= 0 ) {  // 包含特征字符，错误处理
				MessageBox( "错误输入，请修改内容！" );
				return;
			}
		}
	}

	if ( SaveQA( m_strQ, m_strA ) ) {   // 保存输入结果
		// MessageBox( "Save" );
	} else {
		return;
	}

	m_strQ.Empty();  // 清空问题输入框，方便下次输入
	m_strA.Empty();  // 清空回答输入框，方便下次输入

	UpdateData( FALSE );  // 刷新界面。	
}



BOOL AddDlg::SaveQA(CString strQ, CString strA)
{
	if ( theFile.GetFileName().IsEmpty() ) {
		MessageBox( "保存路径有问题，请重新确认！" );
		return FALSE;
	}
	CString str;
	str = "\r\n(%Q%)\r\n" + strQ + "\r\n(%A%)\r\n" + strA;
	theFile.SeekToEnd();
	theFile.Write( str, str.GetLength() );
	return TRUE;
}
