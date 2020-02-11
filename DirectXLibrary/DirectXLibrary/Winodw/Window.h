#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <d3d9.h>

#include "../RectSize/RectSize.h"

class Window
{
public:
	Window(const HINSTANCE hInst, const LPCSTR window_name)
	{
		InitializeWindowClass(hInst, window_name);
	}

	/**
	 Windoiw生成関数
	 
	 */
	BOOL Generate(HWND& hWnd, const INT WindowWidth, const INT WindowHeight);

	static inline void SetWindowSize(const RectSize& rect_size)
	{
		WindowSize = rect_size;
	}

	static inline RectSize GetWindowSize()
	{
		return WindowSize;
	}

private:

	//! WNDCLASSEX のインスタンス
	WNDCLASSEX  wndclass;

	static RectSize WindowSize;

	VOID InitializeWindowClass(const HINSTANCE hInst, const LPCSTR window_name);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

};

#endif
