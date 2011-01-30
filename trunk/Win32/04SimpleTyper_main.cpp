// ** 2011-01-30 Win32 4.3 04SimpleTyper
// ** Yishi Guo
#include <windows.h>
#include <string>
#include "resource.h"

LRESULT CALLBACK MainWndProc( HWND, UINT, WPARAM, LPARAM );

int APIENTRY WinMain( HINSTANCE	hInstance,
					  HINSTANCE	hPrevInstance,
					  LPSTR		lpCmdLine,
					  int nCmdShow ) {

	char szClassName[] = "MainWClass";

	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof( wndclass );
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = MainWndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = ::LoadIcon( hInstance, (LPSTR)IDI_TYPER );
	wndclass.hCursor = ::LoadCursor( NULL, IDC_ARROW );
	wndclass.hbrBackground = (HBRUSH)::GetStockObject( WHITE_BRUSH );
	// wndclass.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
	wndclass.lpszMenuName = (LPSTR)IDR_TYPER;
	wndclass.lpszClassName = szClassName;
	wndclass.hIconSm = NULL;

	::RegisterClassEx( &wndclass );

	HWND hwnd = ::CreateWindowEx(
		0,
		szClassName,
		"My First Window!",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL );
	if ( hwnd == NULL ) {
		::MessageBox( NULL, "Creating window error!", "Error", MB_OK | MB_ICONEXCLAMATION );
		return -1;
	}

	::ShowWindow( hwnd, nCmdShow );
	::UpdateWindow( hwnd );

	MSG msg;
	while ( ::GetMessage( &msg, NULL, 0, 0 ) ) {
		::TranslateMessage( &msg );
		::DispatchMessage( &msg );
	}

	return msg.wParam;
}

LRESULT CALLBACK MainWndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam ) {
	char szText[] = "Simplest Window Application!";
	static std::string str;

	switch( message ) {
	case WM_CREATE:
		{
			::SetWindowText( hwnd, szText );
			return 0;
		}
	case WM_COMMAND:
		{
			switch( LOWORD( wParam ) ) {
			case ID_FILE_EXIT:	// File > Exit
				::SendMessage( hwnd, WM_CLOSE, 0, 0 );
				break;
			}
			return 0;
		}
	case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = ::BeginPaint( hwnd, &ps );
			// Set the background and Text color
			::SetTextColor( hdc, RGB( 255, 0, 0 ) );
			::SetBkColor( hdc, ::GetSysColor( COLOR_3DFACE ) );

			::TextOut( hdc, 10, 10, str.c_str(), str.length() );
			::EndPaint( hwnd, &ps );

			return 0;
		}
	case WM_CHAR:
		{
			str += char( wParam );
			::InvalidateRect( hwnd, NULL, 0 );

			return 0;
		}
	case WM_LBUTTONDOWN:
		{
			char szPoint[56];
			wsprintf( szPoint, "X = %d, Y = %d", LOWORD(lParam), HIWORD(lParam) );
			str = szPoint;
			if ( wParam & MK_SHIFT ) {
				str += " < Shift Key is down.";
			}
			::InvalidateRect( hwnd, NULL, TRUE );
			return 0;
		}
	case WM_CLOSE:
		{
			int nSel = ::MessageBox( NULL, "Is close the window?", "Closing", MB_YESNO );
			switch ( nSel ) {
			case IDYES:
				::DestroyWindow( hwnd );
				return 0;
			case IDNO:
				return 0;
			}
		}
	case WM_DESTROY:
		::PostQuitMessage( 0 );
		return 0;
	}

	return ::DefWindowProc( hwnd, message, wParam, lParam );
}