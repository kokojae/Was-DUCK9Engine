#include "stdafx.h"
#include "SceneManager.h"
#include "Player.h"
#include "Block.h"
#include "SmallBlock.h"
#include "Enemy1.h"
#include "BackGround.h"
#include "GameUI.h"
#include "ASD.h"
#include "Text.h"
#include "UIText.h"
#include "Tank.h"
#include "UIImage.h"
#include "MainMenu.h"
#include "Intro.h"
#include "Ending.h"
#include "Option.h"
#include <time.h>

SceneManager::Scene SceneManager::current_scene;

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(Scene scene, bool camera_clear)
{
	srand(time(NULL));
	current_scene = scene;
	SmallBlock* inst_s;
	Block* inst;
	if (camera_clear)
	{
		Camera::position = D3DXVECTOR2(0, 0);
		Camera::rotation = 0;
		Camera::zoom = 1;
	}

	GameManager::Reset();
	ObjectManager::Clear();
	switch (scene)
	{
	case Main:
		ObjectManager::Instantiate<PhanOpen>();
		SoundManager::PlayBGM(L"resorce/sound/scene/mainmenu.mp3");
		ObjectManager::Instantiate<MainMenu>(D3DXVECTOR2(0, 0));
		break;
	case Stage1:
		SoundManager::PlayBGM(L"resorce/sound/scene/stage1.mp3");
		ObjectManager::Instantiate<PhanOpen>();
		ObjectManager::Instantiate<BackGround>();
		ObjectManager::Instantiate<GameUI>();
		ObjectManager::Instantiate<Player>(D3DXVECTOR2(0,-100));

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * i, 300 + (55 * j)));
			}
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * i + 4, 300 + (55 * j)));
			}
		}

		for (int j = 0; j < 5; j++)
		{
			ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 4 + 600, 300 + (55 * j)));
		}

		for (int j = 0; j < 5; j++)
		{
			ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 4 + 600 + 480 + 100, 300 + (55 * j)));
		}

		for (int j = 0; j < 5; j++)
		{
			ObjectManager::Instantiate<Block>(D3DXVECTOR2((960 * 4) + 600 + (480 * 2) + 800, 300 + (55 * j)));
		}

		

		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(100, 200));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(200, 200));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(600, 0));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(1000, 100));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(1100, 100));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(1200, 100));

		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 3 - 70, 300));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 3, 300));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 3 + 70, 300));

		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 4 - 350, 400));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 4-250, 400));
		ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 4 -150, 400));

		//ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 1000, 400))->texture.scale = { 0.5f, 2 };
		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 1100, 400));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 1300, 450));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 1600, 450));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		for (int j = 0; j < 5; j++)
		{
			//ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 6 + 2300, 300 + (55 * j)));
			inst = ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 6 + 2200, 300 + (55 * j)));
			inst->texture.color = D3DCOLOR_ARGB(150, 150, 150, 150);
			inst->collider.size = { 0,0 };
		}

		for (int j = 0; j < 5; j++)
		{
			//ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 6 + 2300, 300 + (55 * j)));
			inst = ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * 7 + 2200, 300 + (55 * j)));
			inst->texture.color = D3DCOLOR_ARGB(150, 150, 150, 150);
			inst->collider.size = { 0,0 };
		}

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 1800, 400));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 2000, 300));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 2300, 300));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 2500, 400));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 2700, 450));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 3000, 450));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		inst_s = ObjectManager::Instantiate<SmallBlock>(D3DXVECTOR2(960 * 6 + 3200, 400));
		inst_s->texture.scale = { 0.5f, 2 };
		inst_s->texture.color = D3DCOLOR_ARGB(120, 150, 150, 150);
		inst_s->collider.size.x = inst_s->collider.size.x * inst_s->texture.scale.x;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				ObjectManager::Instantiate<Block>(D3DXVECTOR2(960 * (7 + i) + 2500, 300 + (55 * j)));
			}
		}
		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(600, 200));
		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(1100, -100));

		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(2000, 0));

		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(960 * 3 + 200, 0));

		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(960 * 3 + 1500, 0));

		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(960 * 3 + 3000, 0));

		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(960 * 7 + 2500, -200));
		
		ObjectManager::Instantiate<Enemy1>(D3DXVECTOR2(960 * 7 + 2800, -200));

		break;
	default:
		break;
	}
}
