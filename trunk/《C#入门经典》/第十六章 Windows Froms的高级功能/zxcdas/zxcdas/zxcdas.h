// zxcdas.h : main header file for the zxcdas application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CzxcdasApp:
// See zxcdas.cpp for the implementation of this class
//

class CzxcdasApp : public CWinApp
{
public:
	CzxcdasApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CzxcdasApp theApp;