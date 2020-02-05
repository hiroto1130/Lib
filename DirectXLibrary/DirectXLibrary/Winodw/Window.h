#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <d3d9.h>

class Window
{
public:
	Window(const HINSTANCE hInst, const LPCSTR window_name)
	{
		InitializeWindowClass(hInst, window_name);
	}

	BOOL Create(HWND& hWnd, const INT WindowWidth, const INT WindowHight);

private:

	WNDCLASSEX  wndclass;

	VOID InitializeWindowClass(const HINSTANCE hInst, const LPCSTR window_name);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

};

#endif
