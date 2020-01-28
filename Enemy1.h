#pragma once
#include "MonsterParent.h"

class Enemy1 : public MonsterParent
{
public:
	Enemy1();
	~Enemy1();

	bool awake = false;

	float vspeed = 0;

	int shot_delay = 100;

	LPDIRECT3DTEXTURE9 tex_idle;
	LPDIRECT3DTEXTURE9 tex_move;
	LPDIRECT3DTEXTURE9 tex_atk;

	float t = 0;

	void Awake();
	void Update();

	void Gravity();

};

