#include "stdafx.h"
#include "MonsterParent.h"
//#include "DieEffect.h"


MonsterParent::MonsterParent()
{
}


MonsterParent::~MonsterParent()
{
}

void MonsterParent::Damage(float damage)
{
	red = 255;
	scale = 1.4;
	hp -= damage;
	if (hp <= 0)
	{
		if (Camera::shake.x < 45)
			Camera::shake.x = 45;
		if (Camera::shake.y < 45)
			Camera::shake.y = 45;
		for (GameObject * inst : ObjectManager::collid_list)
		{
			if (inst->tag == "Homing")
			{
				Instantiate<Effect>(inst->position);
				inst->destroy = true;
			}
		}
		Instantiate<Effect>(position + D3DXVECTOR2(80, 0));
		Instantiate<Effect>(position + D3DXVECTOR2(-80, 0));
		Instantiate<Effect>(position + D3DXVECTOR2(0, 80));
		Instantiate<Effect>(position + D3DXVECTOR2(0, -80));
		Instantiate<Effect>(position + D3DXVECTOR2(0, 0));
		//Instantiate<DieEffect>(position)->Set(texture.texture,texture.size);
		SoundManager::PlaySFX(L"resorce/sound/enemy/enemy1/die.wav");
		if (SceneManager::current_scene == SceneManager::Stage1)
			GameManager::score1 += score;
		else
			GameManager::score2 += score;
		destroy = true;
	}
}
