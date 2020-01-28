#pragma once
class ASD : public GameObject
{
public:
	ASD();
	~ASD();

	float t = 0;

	void Awake();
	void Update();
	void Render();
};

