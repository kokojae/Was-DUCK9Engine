#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Awake()
{
	SetTexture(L"resorce/background/stage/stage1/stage1.png", D3DXVECTOR2(1920, 1080));
	texture.camera_on = false;
	z = 10;
	texture.center = D3DXVECTOR2(0, 0);


	tex_1 = TextureManager::LoadTexture(L"resorce/background/stage/stage1/stage1.png");
}

void BackGround::Update()
{
}

void BackGround::Render()
{
	texture.texture = tex_1;
	GrapicManager::TextureRender(texture, D3DXVECTOR2(0, 0));
}
