#include "stdafx.h"
#include "YouDie.h"


YouDie::YouDie()
{
}


YouDie::~YouDie()
{
}

void YouDie::Awake()
{
	if (GameManager::hp > 0)
		SetTexture(L"resorce/background/scene/ending/deadscene.png", D3DXVECTOR2(1920, 1080));
	else
		SetTexture(L"resorce/background/scene/ending/deadscene.png", D3DXVECTOR2(1920, 1080));
	texture.center = D3DXVECTOR2(0, 0);
	texture.camera_on = false;
	z = -200;
}

void YouDie::Update()
{
	if (alpha < 254)
		alpha += 2;

	if (alpha > 30)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			GameManager::ReStart();
		}
	}
	
	texture.color = D3DCOLOR_ARGB((int)alpha, 255, 255, 255);
}
