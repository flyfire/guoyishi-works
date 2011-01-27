// ** 2011-01-28 Win32 2.3.4 02CreateProcess
// ** Yishi Guo
#include <iostream>
#include <windows.h>

int main( int argc, char** argv ) {
	char szCommandLine[] = "cmd";
	STARTUPINFO si = {sizeof(si) };
	PROCESS_INFORMATION pi;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;

	BOOL bRet = ::CreateProcess(
		NULL,
		szCommandLine,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi);
	if ( bRet ) {
		::CloseHandle( pi.hThread );
		::CloseHandle( pi.hProcess );
		printf( " �½��̵Ľ���ID�ţ�%d\n", pi.dwProcessId );
		printf( " �½��̵����߳�ID�ţ�%d\n", pi.dwThreadId );
	}

	getchar();

	return 0;
}