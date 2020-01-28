#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player* Player::me = nullptr;

Player::Player()
{
}


Player::~Player()
{
}

void Player::Awake()
{
	GameManager::player_alive = true;
	me = this;
	SetTexture(L"resorce/player/idle.png",D3DXVECTOR2(100,100));
	SetCollider(D3DXVECTOR2(46, 89 * 2), D3DXVECTOR2(0, 80));
	z = -10;
	collider.layer = Layer::PLAYER;
	texture.scale = { 2,2 };

	tex_idle = TextureManager::LoadTexture(L"resorce/player/idle.png");
	tex_run = TextureManager::LoadTexture(L"resorce/player/move.png");
	tex_jump = TextureManager::LoadTexture(L"resorce/player/Jump.png");
	tex_gun = TextureManager::LoadTexture(L"resorce/player/attack.png");
	Camera::zoom = 0;
	position = GameManager::check;
	if (position.x == 0)
		position.x = 400;
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();

	if (GameManager::score1 >= 150 * 8)
	{
		GameManager::GameWin();
		SoundManager::PlayBGM(L"resorce/sound/scene/gamewin.mp3");
	}

	texture.index += 0.1;
	if (texture.texture == tex_idle)
		if (texture.index >= 1)
			texture.index = 0;
	if (texture.texture == tex_run)
		if (texture.index >= 10)
			texture.index = 0;
	if (texture.texture == tex_jump)
		if (texture.index >= 5)
			texture.index = 0;
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{

	shot_delay -= 1;

	if (GetAsyncKeyState('X'))
	{
		if (shot_delay <= 0)
		{
			if (Camera::shake.y < 10)
				Camera::shake.y = 10;
			shot_delay = 26;

			Camera::zoom = 0.97;

			Instantiate<Bullet>(position + D3DXVECTOR2(0, -35))->dire = texture.scale.x;
			SoundManager::PlaySFX(L"resorce/sound/player/shoot.wav");
		}

		texture.index += 0.15;
		if (texture.index >= 5)
			texture.index = 0;
		texture.texture = tex_gun;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		texture.scale.x = 2;
		collider.center.x = -16;
		if (hspeed > -5)
			hspeed -= 0.5f;
		if (PlaceMeeting(D3DXVECTOR2(0, 10), Layer::BLOCK | Layer::BLOCKUP))
			texture.texture = tex_run;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		texture.scale.x = -2;
		collider.center.x = 16;
		if (hspeed < 5)
			hspeed += 0.5f;
		if (PlaceMeeting(D3DXVECTOR2(0, 10), Layer::BLOCK | Layer::BLOCKUP))
			texture.texture = tex_run;
	}
	else
	{
		texture.texture = tex_idle;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting(D3DXVECTOR2(0, 10), Layer::BLOCK | Layer::BLOCKUP))
		{
			vspeed = -15;
		}
		texture.texture = tex_jump;
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		hspeed -= hspeed / 8;
	}

	if (PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BLOCK))
	{
		position.x -= PlaceMeeting(D3DXVECTOR2(0, 0), Layer::BLOCK)->position.x - position.x;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		//ObjectManager::Clear();
		SceneManager::LoadScene(SceneManager::Stage1);
	}

	if (GetAsyncKeyState(VK_F1))
	{
		position = { 960 * 7 + 2500+3000,-200 };
	}
}

void Player::Hspeed()
{
	GameObject* inst = PlaceMeeting(D3DXVECTOR2(hspeed, 0), Layer::BLOCK | Layer::BLOCKUP | Layer::BOX);
	if (inst != nullptr)
	{
		if (inst->collider.layer == Layer::BLOCKUP)
		{
			if ((hspeed > 0 ? 1 : -1) == inst->texture.scale.x)
			{
				position.x += hspeed;
				position.y -= abs(hspeed);
			}
			else
			{
				position.x += hspeed;
				//hspeed = 0;
			}
		}
		else
		{
			hspeed = 0;
		}
	}
	else
	{
		position.x += hspeed;
	}
}

void Player::Gravity()
{
	vspeed += 0.5;

	if (position.y > 500)
	{
		GameManager::hp = 0;
		GameManager::GameOver();
	}

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

void Player::CameraMove()
{
	camera_position.x += (position.x - camera_position.x) / 5;
	camera_position.y += (position.y - camera_position.y - 180) / 20;
	if (camera_position.x < SCREEN_HEIGHT / 2)
		camera_position.x = SCREEN_HEIGHT / 2;

	Camera::position = camera_position + D3DXVECTOR2((rand() % (int)Camera::shake.x - (int)Camera::shake.x / 2), (rand() % (int)Camera::shake.y - (int)Camera::shake.y / 2));

	Camera::zoom += (1 - Camera::zoom) / 10;
}

