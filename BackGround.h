#pragma once
class BackGround : public GameObject
{
public:
	BackGround();
	~BackGround();

	LPDIRECT3DTEXTURE9 tex_1;

	void Awake();
	void Update();
	void Render();
};

