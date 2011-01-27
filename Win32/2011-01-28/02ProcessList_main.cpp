// ** 2011-01-28 Win32 2.4.1 02ProcessList
// ** Yishi Guo
#include <windows.h>
#include <tlhelp32.h>	// Defination of CreateToolhelp32Snapshot Function
#include <stdio.h>

int main( int argc, char** argv ) {
	PROCESSENTRY32 pe32;			// declare pe32
	pe32.dwSize = sizeof( pe32 );	// set the size of pe32
	// Snapshot:
	HANDLE hProcessSnap = 
		::CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
							// valid values:
								// TH32CS_INHERIT		0x80000000
								// TH32CS_SNAPALL 
								// TH32CS_SNAPHEAPLIST	0x00000001
								// TH32CS_SNAPMODULE	0x00000008
								// TH32CS_SNAPMOUDLE32	0x00000010
								// TH32CS_SNAPPROCESS	0x00000002
								// TH32CS_SNAPTHREAD	0x00000004

	if ( hProcessSnap == INVALID_HANDLE_VALUE ) {	// error occur
		printf( " CreateToolhelp32Snapshot 调用失败！\n" );
		return -1;
	}

	BOOL bMore = ::Process32First( hProcessSnap, &pe32 );	// Get the first one
	while( bMore ) {
		printf( " 进程名称：%s\n", pe32.szExeFile );		// Print process name
		printf( " 进程ID号：%u\n\n", pe32.th32ProcessID );	// Print process ID Number
		bMore = ::Process32Next( hProcessSnap, &pe32 );		// Get the next one
	}

	// Close the handle
	::CloseHandle( hProcessSnap );

	getchar();
	return 0;
}