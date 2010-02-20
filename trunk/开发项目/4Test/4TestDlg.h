// 4TestDlg.h : header file
//

#if !defined(AFX_4TESTDLG_H__70AE7A82_5066_4B51_8897_551B802FF144__INCLUDED_)
#define AFX_4TESTDLG_H__70AE7A82_5066_4B51_8897_551B802FF144__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy4TestDlg dialog

class CMy4TestDlg : public CDialog
{
// Construction
public:
	void ShowAndHideWindow();
	void OnClipChange();
	void SetResultListTitle( int count );
	void SetSearchTitle( int count );
	void OnOK();
	void SetTransparent(HWND hwnd, UINT alpha);
	CBrush m_brushWhite;
	BOOL IsShow;
	void insert_pos(int pos);
	CUIntArray nIndexs;
	CStringArray m_As;
	CStringArray m_Qs;
	void insert( CString Q, CString A);
	void Load(CString path);
	CMy4TestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy4TestDlg)
	enum { IDD = IDD_MY4TEST_DIALOG };
	CSliderCtrl	m_slider;
	CHotKeyCtrl	m_Hotkey;
	CListBox	m_listBox;
	CString	m_strA;
	CString	m_strQ;
	CString	m_strSearch;
	int		m_nSlider;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy4TestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy4TestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonLoad();
	afx_msg void OnButtonSearch();
	afx_msg void OnSelchangeListResults();
	afx_msg void OnHotKey(WPARAM wp,LPARAM lp);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonShowHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_4TESTDLG_H__70AE7A82_5066_4B51_8897_551B802FF144__INCLUDED_)
