#pragma once
class YouDie : public GameObject
{
public:
	YouDie();
	~YouDie();

	float alpha = 0;

	void Awake();
	void Update();
};

