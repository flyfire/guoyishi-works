// ** 2011-01-29 Win32 3_2_5 Mutex
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>
#include <process.h>

HANDLE g_hMutex = NULL;
char g_cArray[10];

UINT __stdcall ThreadProc1( LPVOID );
UINT __stdcall ThreadProc2( LPVOID );

int main( int argc, char** argv ) {
	UINT uId;
	HANDLE h[2];

	// Create the Mutex
	g_hMutex = ::CreateMutex( NULL, FALSE, NULL );

	h[0] = (HANDLE)::_beginthreadex( NULL, 0, ThreadProc1, NULL, 0, &uId );
	h[1] = (HANDLE)::_beginthreadex( NULL, 0, ThreadProc2, NULL, 0, &uId );

	::WaitForMultipleObjects( 2, h, TRUE, INFINITE );

	::CloseHandle( h[0] );
	::CloseHandle( h[1] );

	printf( "g_cArray: %s\n", g_cArray );

	return 0;
}

UINT __stdcall ThreadProc1( LPVOID pParam ) {
	// Wait for access the resource
	WaitForSingleObject( g_hMutex, INFINITE );
	for ( int i = 0; i < 10; i++ ) {
		g_cArray[i] = 'a';
		Sleep( 1 );
	}

	ReleaseMutex( g_hMutex );

	return 0;
}

UINT __stdcall ThreadProc2( LPVOID pParam ) {
	// Wait for access the resource
	WaitForSingleObject( g_hMutex, INFINITE );
	for ( int i = 9; i >= 0; i-- ) {
		g_cArray[i] = 'b';
		Sleep( 1 );
	}

	ReleaseMutex( g_hMutex );

	return 0;
}