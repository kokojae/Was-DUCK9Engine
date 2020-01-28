#include "stdafx.h"
#include "SmallBlock.h"

SmallBlock::SmallBlock()
{
}

SmallBlock::~SmallBlock()
{
}

void SmallBlock::Awake()
{
	SetTexture(L"resorce/background/stage/stage1/smallblock.png", D3DXVECTOR2(100, 30));
	SetCollider(D3DXVECTOR2(270, 60), D3DXVECTOR2(100, 0));
	collider.layer = Layer::BLOCK;
	texture.scale = { 2,2 };
}
