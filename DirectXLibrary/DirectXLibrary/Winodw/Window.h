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

	private:
		static HINSTANCE hInst;

		static HWND hWnd;

	};

	class Window
	{
	public:
		Window(const LPCSTR window_name)
		{
			Initialize(window_name);
		}

		/**
		 Windoiw生�?関数
		 */
		BOOL Cenerate(const INT WindowWidth, const INT WindowHeight);



	private:

		//! WNDCLASSEX のインスタンス
		WNDCLASSEX  wndclass;

		RectSize WindowSize;

		VOID Initialize(const LPCSTR window_name);

		static LRESULT CALLBACK WndProc(HWND hWNd, UINT iMsg, WPARAM wParam, LPARAM lParam);

	};

}

#endif
