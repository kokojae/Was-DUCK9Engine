#include "stdafx.h"
#include "PhanOpen.h"


PhanOpen::PhanOpen()
{
}


PhanOpen::~PhanOpen()
{
}

void PhanOpen::Awake()
{
	SetTexture(L"resorce/UI/loading_L.png",D3DXVECTOR2(1930,1080));
	tex_1 = TextureManager::LoadTexture(L"resorce/UI/loading_L.png");
	tex_2 = TextureManager::LoadTexture(L"resorce/UI/loading_R.png");
	texture.camera_on = false;
	texture.center = D3DXVECTOR2(0, 0);
	z = -500;
	
}

void PhanOpen::Update()
{
	if (delay > 0)
		delay--;
	else
		t +=(1100 - t) / 10;

	if (t > 1000)
		destroy = true;
}

void PhanOpen::Render()
{
	position.x = -t;
	texture.texture = tex_1;
	DrawSelf();

	position.x = t;
	texture.texture = tex_2;
	DrawSelf();
}
