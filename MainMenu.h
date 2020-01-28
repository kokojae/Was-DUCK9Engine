#pragma once
class MainMenu : public GameObject
{
public:
	MainMenu();
	~MainMenu();

	float t = 0;
	static int popup;

	float index;
	LPDIRECT3DTEXTURE9 main;
	LPDIRECT3DTEXTURE9 start;
	LPDIRECT3DTEXTURE9 option;

	int select = 0;
	int time = 0;

	D3DXVECTOR2 scale;
	float angle = 0;

	void Awake();
	void Update();
	void Render();
};

