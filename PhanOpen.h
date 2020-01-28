#pragma once
class PhanOpen : public GameObject
{
public:
	PhanOpen();
	~PhanOpen();

	LPDIRECT3DTEXTURE9 tex_1;
	LPDIRECT3DTEXTURE9 tex_2;

	int delay = 0;
	float t = 0;

	void Awake();
	void Update();
	void Render();
};

