// ** 2011-01-29 Win32 3.2.3 03EventDemo
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>
#include <process.h>

HANDLE g_hEvent;
UINT __stdcall ChildFunc( LPVOID );

int main( int argc, char** argv ) {
	HANDLE hChildThread;
	UINT uId;

	// Create Event
	g_hEvent = ::CreateEvent(
		NULL,			// LPSECURITY_ATTRIBUTES	lpEventAttributes
		FALSE,			// BOOL						bManualReset
		FALSE,			// BOOL						bIniticalState
		NULL			// LPCTSTR					lpName
	);

	hChildThread = (HANDLE)::_beginthreadex( NULL, 0, ChildFunc, NULL, 0, &uId );

	printf( " Please input a char to tell the Child Thread to work:\n" );
	getchar();

	// Set the event to signaled
	::SetEvent( g_hEvent );

	::WaitForSingleObject( hChildThread, INFINITE );

	printf( " All the works has been finished.\n" );

	::CloseHandle( g_hEvent );
	::CloseHandle( hChildThread );

	return 0;
}

UINT __stdcall ChildFunc( LPVOID ) {
	// Wait for the event set to signaled
	::WaitForSingleObject( g_hEvent, INFINITE );

	printf( " Chlid thread is working ...\n" );

	::Sleep( 5 * 1000 );	// Sleep 5 second for "workinging"
	
	return 0;
}