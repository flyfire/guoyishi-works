// ** 2011-01-30 Win32 4.2.1 04Win32AppDemo
// ** Yishi Guo

#include "stdafx.h"

int APIENTRY WinMain( HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine,
					 int nCmdShow ) {
	::MessageBox( NULL, "Hello, Win32 Application", "04Win32AppDemo", MB_OK );

	int nSel = ::MessageBox( NULL, "Hello, Win32 Application 2", "04Win32AppDemo",
					MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3 );
	LPCSTR str;
	if ( nSel == IDYES ) {
		str = "Select YES";
	} else if ( nSel == IDNO ) {
		str = "Select NO";
	} else if ( nSel == IDCANCEL ) {
		str = "Select CANCEL";
	}

	::MessageBox( NULL, str, "Select", MB_OK );

	return 0;
}