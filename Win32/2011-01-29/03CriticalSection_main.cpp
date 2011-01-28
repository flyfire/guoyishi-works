// ** 2011-01-29 Win32 3.2.1 03CriticalSection
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>
#include <process.h>

BOOL g_bContinue = TRUE;
int g_nCount1 = 0;
int g_nCount2 = 0;

CRITICAL_SECTION g_cs;	// For Critical Section use
UINT __stdcall ThreadFunc( LPVOID );

int main( int argc, char** argv ) {
	UINT uId;
	HANDLE h[2];

	::InitializeCriticalSection( &g_cs );	// Initialize Critical Section
	h[0] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );
	h[1] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );

	Sleep( 1000 );							// Wait for 1 second
	g_bContinue = FALSE;

	::WaitForMultipleObjects( 2, h, TRUE, INFINITE );
	::CloseHandle( h[0] );
	::CloseHandle( h[1] );

	::DeleteCriticalSection( &g_cs );		// Delete the Critical Section

	printf( "g_nCount1 = %d\n", g_nCount1 );
	printf( "g_nCount2 = %d\n", g_nCount2 );

	return 0;
}

UINT __stdcall ThreadFunc( LPVOID ) {
	while ( g_bContinue ) {
		::EnterCriticalSection( &g_cs );	// Enter
		g_nCount1++;
		g_nCount2++;
		::LeaveCriticalSection( &g_cs );	// Leave
	}

	return 0;
}