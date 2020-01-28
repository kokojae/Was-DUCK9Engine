#include "stdafx.h"
#include "Enemy1.h"
#include "EnemyBullet.h"

Enemy1::Enemy1()
{
}

Enemy1::~Enemy1()
{
}

void Enemy1::Awake()
{
	SetTexture(L"resorce/enemy/enemy1/idle.png", D3DXVECTOR2(100, 120));
	SetCollider(D3DXVECTOR2(100 * scale, 120 * scale), D3DXVECTOR2(0, 120));
	texture.scale = { 2,2 };

	tex_idle = TextureManager::LoadTexture(L"resorce/enemy/enemy1/idle.png");
	tex_move = TextureManager::LoadTexture(L"resorce/enemy/enemy1/move.png");
	tex_atk = TextureManager::LoadTexture(L"resorce/enemy/enemy1/attack.png");
	collider.layer = Layer::MONSTER;
	score = 150;
	z = -5;
}

void Enemy1::Update()
{
	Gravity();

	if (GameManager::player_alive == false)
		return;

	scale += (2 - scale) / 10;
	red -= red / 6;
	texture.scale = D3DXVECTOR2(scale, scale);
	texture.color = D3DCOLOR_XRGB(255, 255 - (int)red, 255 - (int)red);
	if (PlaceMeeting(D3DXVECTOR2(0, 0), Layer::MONSTER))
	{
		position.x -= PlaceMeeting(D3DXVECTOR2(0, 0), Layer::MONSTER)->position.x - position.x;
	}
	if (PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BLOCK))
	{
		position.x -= (PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BLOCK)->position.x - position.x) / 5;

	}

	texture.index += 0.1;
	if (texture.texture == tex_idle)
	{
		if (texture.index >= 7)
			texture.index = 0;
	}
	if (texture.texture == tex_move)
	{
		if (texture.index >= 2)
			texture.index = 0;
	}
	if (texture.texture == tex_atk)
	{
		if (texture.index >= 3)
			texture.index = 0;
	}

	t += 0.06;

	//position.x += sin(t) * 2;

	if (abs(position.x - Player::me->position.x) < 750)
	{
		awake = true;
		if (!((texture.texture == tex_atk) && (texture.index > 0)))
			texture.texture = tex_move;
	}
	else
	{
		awake = false;
		if (!((texture.texture == tex_atk) && (texture.index > 0)))
			texture.texture = tex_idle;
	}

	if (awake == true)
	{
		position.x += (Player::me->position.x - position.x) / 100;

		if (position.x > Player::me->position.x)
			texture.scale.x = scale;
		else
			texture.scale.x = -scale;

		shot_delay--;
		if (shot_delay <= 0)
		{
			SoundManager::PlaySFX(L"resorce/sound/enemy/enemy1/shoot.wav");
			EnemyBullet* inst = Instantiate<EnemyBullet>(position);
			inst->dire = position.x > Player::me->position.x ? -1 : 1;
			inst->texture.scale = texture.scale;

			shot_delay = 90;
		}
	}
}

void Enemy1::Gravity()
{
	vspeed += 0.5;

	if (position.y > 500)
		destroy = true;

	if (PlaceMeeting(D3DXVECTOR2(0, vspeed), Layer::BLOCK | Layer::BLOCKUP | Layer::BOX) != nullptr)
	{
		if (vspeed < 0)
		{
			position.y += vspeed;
		}

		vspeed = 0;
	}
	else
	{
		position.y += vspeed;
	}
}
