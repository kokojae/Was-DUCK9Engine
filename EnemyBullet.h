#pragma once
class EnemyBullet : public GameObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	int dire = 0;
	float hspeed = 0;

	void Awake();
	void Update();

};

