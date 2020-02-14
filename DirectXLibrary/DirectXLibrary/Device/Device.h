#ifndef DEVICE_H
#define DEVICE_H

#include <windows.h>
#include <d3d9.h>

#include "../Winodw/Window.h"

namespace Library
{

	class Device
	{
	public:

		Device()
		{
			Initialize();
		}



	private:

		LPDIRECT3D9 pDirect3d;
		LPDIRECT3DDEVICE9 pDevice;
		D3DPRESENT_PARAMETERS d3dpp;

		HRESULT Initialize();


	};

}

#endif
