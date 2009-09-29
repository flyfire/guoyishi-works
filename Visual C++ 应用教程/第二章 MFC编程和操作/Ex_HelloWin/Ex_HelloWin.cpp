//////////////////////////////////
// Date:               2009-09-21
// Author:             Yishi Guo
// Chapter:            2
// Page:               34
// Exercise:           Ex_HelloWin
//////////////////////////////////
#include <windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = "HelloWin";
	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "Window Register False!", "HelloWin", 0);
		return 0;
	}
	hwnd = CreateWindow("HelloWin",
		                "My Window",
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						NULL,
						NULL,
						hInstance,
						NULL);
	ShowWindow( hwnd, nCmdShow );
	UpdateWindow( hwnd );
	while (GetMessage (&msg, NULL, 0, 0)) {
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message) {
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(NULL, "Hello, My Virtual C++ World!", "Hello", 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}