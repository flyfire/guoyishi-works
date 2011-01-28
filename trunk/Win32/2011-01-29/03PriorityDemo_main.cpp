// ** 2011-01-29 Win32 3.1.4 03PriorityDemo
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>

DWORD __stdcall ThreadIdle( LPVOID lpParam ) {
	int i = 0;
	while ( i++ < 10 ) {
		printf( "Idle Thread is running\n" );
	}

	return 0;
}

DWORD __stdcall ThreadNormal( LPVOID lpParam ) {
	int i = 10;
	while ( i-- > 0 ) {
		printf( "Normal Thread is running\n" );
	}

	return 0;
}

int main( int argc, char** argv ) {
	DWORD dwThreadId;
	HANDLE h[2];

	// Create the idle thread
	h[0] = ::CreateThread( NULL, 0, ThreadIdle, NULL,
										CREATE_SUSPENDED, &dwThreadId );
	::SetThreadPriority( h[0], THREAD_PRIORITY_IDLE );
	::ResumeThread( h[0] );

	// Create the normal thread
	h[1] = ::CreateThread( NULL, 0, ThreadNormal, NULL,
										0, &dwThreadId );

	// Wait for all threads
	DWORD dw = ::WaitForMultipleObjects( 2, h, TRUE, INFINITE );

	// For Debug:
	switch ( dw ) {
	case WAIT_FAILED:
		printf( "WAIT_FAILED\n" );
		break;
	case WAIT_TIMEOUT:
		printf( "WAIT_TIMEOUT\n" );
		break;
	case WAIT_OBJECT_0 + 0:
		printf( "h[0]\n" );
		break;
	case WAIT_OBJECT_0 + 1:
		printf( "h[1]\n" );
		break;
	default:
		printf( "Default\n" );
		break;
	}

	// Close all handles
	::CloseHandle( h[0] );
	::CloseHandle( h[1] );

	return 0;
}