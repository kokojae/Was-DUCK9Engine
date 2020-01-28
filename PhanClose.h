#pragma once
class PhanClose : public GameObject
{
public:
	PhanClose();
	~PhanClose();

	static PhanClose* me;

	LPDIRECT3DTEXTURE9 tex_1;
	LPDIRECT3DTEXTURE9 tex_2;
	SceneManager::Scene scene;

	int delay = 0;
	float speed = 0;

	float t = 1000;

	void Awake();
	void Update();
	void Render();

};

