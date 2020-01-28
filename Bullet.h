#pragma once
class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	int dire = 0;
	int time = 100;

	void Awake();
	void Update();
};

