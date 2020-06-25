#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <d3d9.h>

#include "../RectSize/RectSize.h"

namespace Library
{
	class WindowParameter
	{
	public:

		static inline void GetInstanceHandle(HINSTANCE* pHInstance)
		{
			*pHInstance = hInst;
		}

		static inline void SetInstanceHandle(const HINSTANCE& hInstance)
		{
			hInst = hInstance;
		}

		static inline void GetWindowHandle(HWND* hwnd)
		{
			*hwnd = hWnd;
		}

		static inline void SetWindowHandle(const HWND& hwnd)
		{
			hWnd = hwnd;
		}

		static inline void GetWindowSize(RectSize* rect_size)
		{
			*rect_size = WindowSize;
		}

		static inline void SetWindowSize(const RectSize& rect_size)
		{
			WindowSize = rect_size;
		}

	private:
		static HINSTANCE hInst;

		static HWND hWnd;

		static RectSize WindowSize;
	};

	class Window
	{
	public:
		Window(const LPCSTR window_name)
		{
			Initialize(window_name);
		}

		BOOL Cenerate();



	private:

		WNDCLASSEX  wndclass;

		VOID Initialize(const LPCSTR window_name);

		static LRESULT CALLBACK WndProc(HWND hWNd, UINT iMsg, WPARAM wParam, LPARAM lParam);

	};

}

#endif
