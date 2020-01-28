#include "stdafx.h"
#include "Effect.h"


Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::Awake()
{
	SetTexture(L"resorce/player/effect.png", D3DXVECTOR2(200, 200));
	texture.scale *= 1.6;
	texture.rotation = rand() % 360;
	z = -30;
}

void Effect::Update()
{
	texture.index += 0.3;
	if (texture.index > 4)
		destroy = true;
}
