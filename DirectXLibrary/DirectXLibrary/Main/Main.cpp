#include <windows.h>
#include <d3d9.h>

#include "../Winodw/Window.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, int iCmdShow)
{
	HWND hWnd = NULL;
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	Window* window = new Window(hInst, "Test");

	window->Create(hWnd, 640, 420);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	delete window;
	return (INT)msg.wParam;

}

