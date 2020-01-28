#pragma once
#include "Layer.h"
class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	bool enable = true;
	D3DXVECTOR2 size;
	D3DXVECTOR2 center;
	int layer = Layer::DEFAULT;
};

