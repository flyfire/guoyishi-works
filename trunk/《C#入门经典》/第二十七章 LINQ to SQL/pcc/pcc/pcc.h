// pcc.h : main header file for the pcc application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CpccApp:
// See pcc.cpp for the implementation of this class
//

class CpccApp : public CWinApp
{
public:
	CpccApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CpccApp theApp;