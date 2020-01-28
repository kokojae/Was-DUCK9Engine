#include "stdafx.h"
#include "ASD.h"


ASD::ASD()
{
}


ASD::~ASD()
{
}

void ASD::Awake()
{
	SetTexture(L"Source/block.png", D3DXVECTOR2(100, 100));
}

void ASD::Update()
{
	t += 0.15f;

	texture.rotation = sin(t/4) * 80;
	texture.scale = D3DXVECTOR2(0.5 + sin(t)*0.1, 0.5 + sin(t + 10) * 0.1);

	position.y += sin(t / 4);

	D3DXCOLOR * a = new D3DXCOLOR(D3DCOLOR_ARGB(180, 0,60,255));
	D3DXCOLOR * b = new D3DXCOLOR(D3DCOLOR_ARGB(180, 60, 255, 0));

	D3DXColorLerp(&texture.color,a, b, 0.5 + sin(t/3) * 0.5);
}

void ASD::Render()
{
	DrawSelf();
	GrapicManager::TextRender(L"hjine01.blog.me", position + D3DXVECTOR2(30,0), D3DXVECTOR2(0.3, 0.3));
}
