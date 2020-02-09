#ifndef DEVICE_H
#define DEVICE_H

#include <windows.h>
#include <d3d9.h>

class Device
{
public:
	Device()
	{

	}



private:

	LPDIRECT3D9 pDirect3d;
	LPDIRECT3DDEVICE9 pDevice;
	D3DPRESENT_PARAMETERS d3dpp;

	BOOL Initialize(const HWND& hInst);


};


#endif
