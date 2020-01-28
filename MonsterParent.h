#pragma once
#include "SoundManager.h"
class MonsterParent : public GameObject
{
public:
	MonsterParent();
	~MonsterParent();

	float hp = 100;
	float red = 0;
	float scale = 2;
	int score = 100;

	void Damage(float damage);
};

