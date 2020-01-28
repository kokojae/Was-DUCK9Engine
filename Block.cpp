#include "stdafx.h"
#include "Block.h"


Block::Block()
{
}


Block::~Block()
{
}

void Block::Awake()
{
	SetTexture(L"resorce/background/stage/stage1/block.png", D3DXVECTOR2(960, 55));
	SetCollider(D3DXVECTOR2(960, 55), D3DXVECTOR2(960 / 2, -55/2));
	collider.layer = Layer::BLOCK;
}
