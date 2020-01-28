#include "stdafx.h"
#include "GameUI.h"


GameUI::GameUI()
{
}


GameUI::~GameUI()
{
}

void GameUI::Awake()
{
	//SetTexture("Source/wood.png", );
	texture.size = D3DXVECTOR2(500, 200);
	texture.camera_on = false;
	//tex_back = TextureManager::LoadTexture(L"Source/UI/wood.png");
	tex_life = TextureManager::LoadTexture(L"resorce/UI/hp.png");
	z = -100;
}

void GameUI::Update()
{
}

void GameUI::Render()
{
	t += 0.03;
	texture.texture = tex_life;
	texture.size = D3DXVECTOR2(150, 150);
	texture.scale = D3DXVECTOR2(0.8, 0.8);
	for (int i = 0; i < GameManager::hp; i++)
	{
		GrapicManager::TextureRender(texture, D3DXVECTOR2(30 + 150 * i, 10 + sin(t + i*1) * 10));
	}
	
}
