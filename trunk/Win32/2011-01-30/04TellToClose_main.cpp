// ** 2011-01-30 Win32 4.2.2 04TellToClose
// ** Yishi Guo
#include <windows.h>

int main( int argc, char** argv ) {
	HWND hWnd = ::FindWindow( "Notepad", NULL );
	if ( hWnd != NULL ) {
		::SendMessage( hWnd, WM_CLOSE, 0, 0 );
	}

	return 0;
}