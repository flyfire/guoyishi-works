// ** 2011-01-29 Win32 3.1.1 03ThreadDemo
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadProc( LPVOID lpParam ) {
	int i = 0;
	while ( i < 20 ) {
		printf( " I am from a thread, count = %d\n", i++ );
	}

	return 0;
}

int main( int argc, char** argv ) {
	HANDLE hThread;
	DWORD dwThreadId;

	// Create a new thread
	hThread = ::CreateThread(
		NULL,			// LPSECURITY_ATTRIBUTES	lpThreadAttributes
		NULL,			// DWORD					dwStackSize
		ThreadProc,		// LPTHREAD_START_ROUTINE	lpStartAddress
		NULL,			// LPVOID					lpParameter
		0,				// DWORD					dwCreationFlags
		&dwThreadId		// LPDWORD					lpThreadId
	);

	printf( " Now another thread has been created. ID = %d\n", dwThreadId );

	// Wait the thread end
	::WaitForSingleObject( hThread, INFINITE);
	::CloseHandle( hThread );

	// For Debug
	printf( " End here!\n" );
	getchar();

	return 0;
}
