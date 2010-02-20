#if !defined(AFX_ADDDLG_H__5F01AA39_4048_44DF_9550_111CB24451A1__INCLUDED_)
#define AFX_ADDDLG_H__5F01AA39_4048_44DF_9550_111CB24451A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddDlg dialog

class AddDlg : public CDialog
{
// Construction
public:
	BOOL SaveQA( CString strQ, CString strA);
	CFile theFile;
	AddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_path;
	CString	m_strA;
	CString	m_strQ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddDlg)
	afx_msg void OnButtonSelect();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__5F01AA39_4048_44DF_9550_111CB24451A1__INCLUDED_)
