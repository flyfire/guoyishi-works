// 4Test.h : main header file for the 4TEST application
//

#if !defined(AFX_4TEST_H__E31298F4_1A3C_49C5_A9C7_4F09DB322AC4__INCLUDED_)
#define AFX_4TEST_H__E31298F4_1A3C_49C5_A9C7_4F09DB322AC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy4TestApp:
// See 4Test.cpp for the implementation of this class
//

class CMy4TestApp : public CWinApp
{
public:
	CMy4TestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy4TestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy4TestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_4TEST_H__E31298F4_1A3C_49C5_A9C7_4F09DB322AC4__INCLUDED_)
