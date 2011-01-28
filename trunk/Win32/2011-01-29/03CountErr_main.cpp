// ** 2011-01-29 Win32 3.2.1 03CountErr
// ** Yishi Guo
// ** The "Release" edition can not be used. ** //
#include <stdio.h>
#include <windows.h>
#include <process.h>

int g_nCount1 = 0;
int g_nCount2 = 0;
BOOL g_bContinue = TRUE;

UINT __stdcall ThreadFunc( LPVOID );

int main( int argc, char** argv ) {
	UINT uId;
	HANDLE h[2];
	// Use "_beginthreadex" for create thread
	h[0] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );
	h[1] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );

	Sleep( 1000 );			// Wait for 1 second
	g_bContinue = FALSE;	// Stop the threads

	::WaitForMultipleObjects( 2, h, TRUE, INFINITE );
	::CloseHandle( h[0] );
	::CloseHandle( h[1] );

	// The "counts" are not equal
	printf( "g_nCount1 = %d\n", g_nCount1 );
	printf( "g_nCount2 = %d\n", g_nCount2 );

	// For debug:
	getchar();

	return 0;
}

UINT __stdcall ThreadFunc( LPVOID ) {
	while( g_bContinue ) {
		g_nCount1++;
		g_nCount2++;
	}

	return 0;
}