#pragma once
class GameUI : public GameObject
{
public:
	GameUI();
	~GameUI();

	float t = 0;
	LPDIRECT3DTEXTURE9 tex_back;
	LPDIRECT3DTEXTURE9 tex_life;

	void Awake();
	void Update();
	void Render();
};

