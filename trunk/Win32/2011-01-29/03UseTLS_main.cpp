// ** 2011-01-29 Win32 3.2.6 03UseTLS
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>
#include <process.h>

DWORD g_tlsUsedTime;
void InitStartTime();
DWORD GetUsedTime();
UINT __stdcall ThreadFunc( LPVOID );

int main( int argc, char** argv ) {
	UINT uId;
	int i;
	HANDLE h[10];

	// Allocate a TLS index
	g_tlsUsedTime = ::TlsAlloc();

	for ( i = 0; i < 10; i++ ) {
		h[i] = (HANDLE)::_beginthreadex( NULL, 0, ThreadFunc, NULL, 0, &uId );
	}
	
	for ( i = 0; i < 10; i++ ) {
		::WaitForSingleObject( h[i], INFINITE );
		::CloseHandle( h[i] );
	}

	// Free the TLS
	::TlsFree( g_tlsUsedTime );

	return 0;
}

void InitStartTime() {
	DWORD dwStart = ::GetTickCount();	// Get the time since the system was started
	::TlsSetValue( g_tlsUsedTime, (LPVOID)dwStart );	// Set the TLS values
}

// Get the time thread used
DWORD GetUsedTime() {
	DWORD dwElapsed = ::GetTickCount();
	dwElapsed = dwElapsed - (DWORD)::TlsGetValue( g_tlsUsedTime );
	return dwElapsed;
}

UINT __stdcall ThreadFunc( LPVOID ) {
	int i;
	InitStartTime();

	i = 1000 * 1000;

	// Do something
	while ( i-- ) {
		int gys = 19881211;
		int rbt = 19900715;
		int today = 20110129;
		today = gys + rbt;
	}

	printf( "This thread is comming to end. Thread ID: %-5d, Used Time: %d\n",
		::GetCurrentThreadId(), GetUsedTime() );

	// For debug
	// printf( "Tick Time: %d\n", ::GetTickCount() );
	// printf( "g_tlsUsedTime: %d\n\n", ::TlsGetValue( g_tlsUsedTime ) );

	return 0;
}