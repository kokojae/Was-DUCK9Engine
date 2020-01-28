#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Awake()
{
	SetTexture(L"resorce/player/bullet.png", D3DXVECTOR2(6, 2));
	texture.scale = { 2,2 };
	z = -10;
	time = 20;
}

void Bullet::Update()
{
	time--;
	if (time <= 0)
		destroy = true;

	texture.scale.x = dire;

	MonsterParent* inst = (MonsterParent*)PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BOX | Layer::MONSTER);
	if (inst != nullptr)
	{
		Instantiate<Effect>(position);
		inst->Damage(35);

		destroy = true;
	}
	position.x -= dire * 20;
}
