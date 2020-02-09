#include "Device.h"

BOOL Device::Initialize(const HWND& hInst)
{
	//// InitD3d が初期化されているかどうか ////

	if (NULL == (pDirect3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


	//// InitDinput 初期化されているかどうか ////
	if (NULL == (pDirect3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hInst,
		D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &pDevice)))
	{
		return E_FAIL;
	}

	return S_OK;
}
