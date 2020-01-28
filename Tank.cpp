#include "stdafx.h"
#include "Tank.h"


Tank::Tank()
{
}


Tank::~Tank()
{
}

void Tank::Awake()
{
	SetTexture(L"Source/tank.png", D3DXVECTOR2(300, 250));
	SetCollider(D3DXVECTOR2(200, 80));
}

void Tank::Update()
{
	texture.index += 0.2;
	if (texture.index > 3)
		texture.index = 0;

	position.x += 3;
}

void Tank::Render()
{
	DrawSelf();
	GrapicManager::TextRender(L"애니메이션 예시", position + D3DXVECTOR2(-60, -130), D3DXVECTOR2(0.6, 0.6));
}
