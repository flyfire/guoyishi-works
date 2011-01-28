// ** 2011-01-29 Win32 3.2.2 03InterlockDemo
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>
#include <process.h>

BOOL g_bContinue = TRUE;
int g_nCount1 = 0;
int g_nCount2 = 0;

UINT __stdcall ThreadFunc( LPVOID );

int main( int argc, char** argv ) {
	UINT uId;
	HANDLE h[2];

	h[0] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );
	h[1] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );

	// Wait For 1 second
	Sleep( 1000 );

	g_bContinue = FALSE;

	::WaitForMultipleObjects( 2, h, TRUE, INFINITE );

	::CloseHandle( h[0] );
	::CloseHandle( h[1] );

	printf( "g_nCount1 = %d\n", g_nCount1 );
	printf( "g_nCount2 = %d\n", g_nCount2 );

	return 0;
}

UINT __stdcall ThreadFunc( LPVOID ) {
	while ( g_bContinue ) {
		// Use "Interlock" for increment the counts
		::InterlockedIncrement( (long*) &g_nCount1 );
		::InterlockedIncrement( (long*) &g_nCount2 );
	}

	return 0;
}