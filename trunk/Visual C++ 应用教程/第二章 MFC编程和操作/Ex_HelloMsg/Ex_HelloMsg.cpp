////////////////////////////////////////
// Date:            2009-09-21
// Author:          Yishi Guo
// Chapter:         2
// Page:            33
// Exercise:        Ex_HelloMsg
////////////////////////////////////////
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	MessageBox(NULL, "Hello, My Virtual C++ World!", "Hello!", 0);

	return 0;
}