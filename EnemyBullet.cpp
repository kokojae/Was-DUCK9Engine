#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Awake()
{
	SetTexture(L"resorce/enemy/enemy1/bullet.png", D3DXVECTOR2(20, 14));
	SetCollider(D3DXVECTOR2(20, 14));
	collider.layer = Layer::MONSTERBULLET;
	z = -5;
}

void EnemyBullet::Update()
{
	GameObject* inst = PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BLOCK | Layer::PLAYER | Layer::BULLET | Layer::BLOCKUP);
	if (inst != nullptr)
	{
		if (inst->collider.layer == Layer::PLAYER)
		{
			GameManager::hp--;
			if (GameManager::hp <= 0)
				GameManager::GameOver();

			destroy = true;
		}
		if (inst->collider.layer == Layer::BLOCK || inst->collider.layer == Layer::BLOCKUP)
		{
			destroy = true;
		}

		if (inst->collider.layer == Layer::BULLET)
		{
			inst->destroy = true;
		}
	}

	hspeed += dire * 0.2;
	position.x += dire * 7;
}
