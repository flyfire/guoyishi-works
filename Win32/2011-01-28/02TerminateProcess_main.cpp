// ** 2011-01-28 Win32 2.4.2 02TerminateProcess
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>

BOOL TerminateProcessFromId( DWORD ); 

int main( int argc, char** argv ) {
	while ( 1 ) {
		DWORD dwId;
		BOOL bFlag = FALSE;
		printf( "Input the Process ID: " );
		int nCnt = scanf( "%u", &dwId );					// Get the Process ID.
		if ( nCnt < 1 ) {	// invalid input
			printf( "Input error!\n" );
			break;	// break out
		}
		bFlag = TerminateProcessFromId( dwId );	// Terminate the process

		// For debug scanf input
		// printf( "nCnt: %d\n", nCnt );

		// Print result
		if ( bFlag ) {
			printf( "Terminate Process: %u\n", dwId );
		} else {
			printf( "Can not terminate process: %u\n", dwId );
		}
	}

	return 0;
}

// Terminate Process From ID
BOOL TerminateProcessFromId( DWORD dwId ) {
	BOOL bRet = FALSE;

	// Open the process, get the Handle
	HANDLE hProcess = ::OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwId );
	if ( hProcess != NULL ) {
		// Terminate the process
		bRet = ::TerminateProcess( hProcess, 0 );
	}

	::CloseHandle( hProcess );

	return bRet;
}
