#include "Window.h"

namespace Library
{


	HINSTANCE WindowParameter::hInst = nullptr;
	HWND WindowParameter::hWnd = nullptr;

	VOID Window::Initialize(const LPCSTR window_name)
	{
		HINSTANCE hInst = nullptr;
		WindowParameter::GetInstanceHandle(&hInst);

		wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = WndProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInst;
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = window_name;
		wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		RegisterClassEx(&wndclass);

		hInst = GetModuleHandle(nullptr);

	}

	BOOL Window::Cenerate(const INT WindowWidth, const INT WindowHeight)
	{
		HWND hWnd = nullptr;
		WindowParameter::GetWindowHandle(&hWnd);

		hWnd = CreateWindow(wndclass.lpszClassName, wndclass.lpszClassName, WS_OVERLAPPEDWINDOW, 0, 0, WindowWidth, WindowHeight, NULL, NULL, wndclass.hInstance, NULL);

		if (hWnd == NULL)
		{
			return FALSE;
		}

		WindowSize.Width = WindowWidth;
		WindowSize.Height = WindowHeight;

		ShowWindow(hWnd, SW_SHOW);

		UpdateWindow(hWnd);

		return TRUE;
	}

	LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (iMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			break;
		}

		return DefWindowProc(hWnd, iMsg, wParam, lParam);
	}
}
