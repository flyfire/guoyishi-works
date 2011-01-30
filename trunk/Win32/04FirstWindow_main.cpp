// ** 2011-01-30 Win32 4.2.3 04FirstWindow
// ** Yishi Guo
#include <windows.h>

LRESULT CALLBACK MainWndProc( HWND, UINT, WPARAM, LPARAM );

int APIENTRY WinMain( HINSTANCE	hInstance,
					 HINSTANCE	hPrevInstance,
					 LPSTR		lpCmdLine,
					 int		nCmdShow ) {

	char szClassName[] = "MainWClass";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof( wndclass );
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = MainWndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = ::LoadIcon( NULL, IDI_APPLICATION );
	wndclass.hCursor = ::LoadCursor( NULL, IDC_ARROW );
	wndclass.hbrBackground = (HBRUSH)::GetStockObject( WHITE_BRUSH );
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;
	wndclass.hIconSm = NULL;

	::RegisterClassEx( &wndclass );

	HWND hwnd = ::CreateWindowEx(
		0,
		szClassName,
		"My first Window!",
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
		::MessageBox( NULL, "Create Window Error!", "error", MB_OK | MB_ICONEXCLAMATION );
		return -1;
	}
	
	::ShowWindow( hwnd, nCmdShow );
	::UpdateWindow( hwnd );

	MSG msg;
	while ( ::GetMessage( &msg, NULL, 0, 0 ) ) {
		::TranslateMessage( &msg );
		::DispatchMessage( &msg );
	}

	return msg.wParam;	//
}

LRESULT CALLBACK MainWndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam ) {
	char szText[] = "Simple Window Application!";
	switch ( message ) {
	case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;

			hdc = ::BeginPaint( hwnd, &ps );

			::TextOut( hdc, 10, 10, szText, strlen( szText ) );
			::EndPaint( hwnd, &ps );
			
			return 0;
		}
	case WM_DESTROY:
		::PostQuitMessage( 0 );
		
		return 0;
	}

	return ::DefWindowProc( hwnd, message, wParam, lParam );
}