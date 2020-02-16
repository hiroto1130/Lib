#include <windows.h>
#include <d3d9.h>

#include "../Winodw/Window.h"
#include "../Key.h"
#include "../Mouse.h"

using namespace Library;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, int iCmdShow)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	Window* window = new Window("Test");

	Key key;
	Mouse mouse;



	window->Cenerate(640, 420);

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

