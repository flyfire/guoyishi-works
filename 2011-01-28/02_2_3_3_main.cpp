// ** 2011-01-28 Win32 2.3.3 CreateProcess
#include <windows.h>

int main( int argc, char** argv ) {
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	char* szCommandLine = "notepad";
	::CreateProcess( NULL, szCommandLine, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi );

	return 0;
}