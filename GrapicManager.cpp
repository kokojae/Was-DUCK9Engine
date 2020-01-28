#include "stdafx.h"
#include "GrapicManager.h"

LPDIRECT3D9 GrapicManager::direct = nullptr;
LPDIRECT3DDEVICE9 GrapicManager::device = nullptr;
LPD3DXSPRITE GrapicManager::sprite = nullptr;
HWND GrapicManager::window = nullptr;
ID3DXFont* GrapicManager::font;

GrapicManager::GrapicManager()
{
}


GrapicManager::~GrapicManager()
{
}

int GrapicManager::Init()
{
	//-꿀팁-
	//Programs\Microsoft DirectX SDK (June 2010)\Samples\C++\Direct3D\Tutorials\Tut01_CreateDevice
	//에 들어가면 이거 복붙가능


	if (NULL == (direct = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Set up the structure used to create the D3DDevice. Most parameters are
	// zeroed out. We set Windowed to TRUE, since we want to do D3D in a
	// window, and then set the SwapEffect to "discard", which is the most
	// efficient method of presenting the back buffer to the display.  And 
	// we request a back buffer format that matches the current desktop display 
	// format.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !FULLSCREEN;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	// Create the Direct3D device. Here we are using the default adapter (most
	// systems only have one, unless they have multiple graphics hardware cards
	// installed) and requesting the HAL (which is saying we want the hardware
	// device rather than a software one). Software vertex processing is 
	// specified since we know it will work on all cards. On cards that support 
	// hardware vertex processing, though, we would see a big performance gain 
	// by specifying hardware vertex processing.
	if (FAILED(direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &device)))
	{
		return E_FAIL;
	}
	/*HRESULT hr = direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &device);
	E_FAIL*/

	
	//스프라이트 생성
	D3DXCreateSprite(device, &sprite);

	//폰트생성
	if (FAILED(D3DXCreateFont(device, 70, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"경기천년제목V Bold", &font)))
		exit(0);

	return 0;

}

int GrapicManager::Render()
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(device->BeginScene()))
	{
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		// Rendering of scene objects can happen here

		ObjectManager::Render();

		// End the scene
		sprite->End();
		device->EndScene();
	}

	// Present the backbuffer contents to the display
	device->Present(NULL, NULL, NULL, NULL);

	return 0;
}

void GrapicManager::TextureRender(TextureInfo info,D3DXVECTOR2 position)
{
	D3DXMATRIX mat,center,pos,scale,rotation;

	D3DXMatrixTranslation(&center, -info.center.x, -info.center.y, 0);
	D3DXMatrixTranslation(&pos,(int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale, info.scale.x, info.scale.y, 1);
	D3DXMatrixRotationZ(&rotation, D3DXToRadian(info.rotation));

	mat =  center * scale * rotation * pos;

	if (info.camera_on == true)
		mat *= Camera::GetMatrix();

	sprite->SetTransform(&mat);

	//도트겜일경우 사용
	device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	RECT rect = RECT{(LONG)(int)info.index * (LONG)info.size.x,0,(LONG)((int)info.index + 1) * (LONG)info.size.x,(LONG)info.size.y};

	sprite->Draw(info.texture, &rect, NULL, NULL, info.color);
}

void GrapicManager::TextRender(wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale)
{
	D3DXMATRIX mat, pos, scale_mat, rotation;

	D3DXMatrixTranslation(&pos, (int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale_mat, scale.x, scale.y, 1);

	mat = scale_mat * pos; 

	mat *= Camera::GetMatrix();

	sprite->SetTransform(&mat);

	font->DrawText(sprite, text.c_str(), -1, NULL, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}

void GrapicManager::TextUIRender(wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale)
{
	D3DXMATRIX mat, pos, scale_mat, rotation;

	D3DXMatrixTranslation(&pos, (int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale_mat, scale.x, scale.y, 1);

	mat = scale_mat * pos;

	sprite->SetTransform(&mat);

	font->DrawText(sprite, text.c_str(), -1,NULL , DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}
