#pragma once

#include "TextureInfo.h"


class GrapicManager
{
private:
	

public:
	GrapicManager();
	~GrapicManager();

	static HWND window;
	static LPDIRECT3D9 direct;
	static LPDIRECT3DDEVICE9 device;
	static LPD3DXSPRITE sprite;
	static ID3DXFont* font;

	static int Init();
	static int Render();
	static void TextureRender(TextureInfo info, D3DXVECTOR2 position);
	static void TextRender(wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale = D3DXVECTOR2(1,1));
	static void TextUIRender(wstring text, D3DXVECTOR2 position, D3DXVECTOR2 scale = D3DXVECTOR2(1, 1));

};

