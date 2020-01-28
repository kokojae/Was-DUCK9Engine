#pragma once
class Player : public GameObject
{
public:
	Player();
	~Player();

	static Player* me;

	float hspeed = 0;
	float vspeed = 0;

	int shot_delay = 0;

	LPDIRECT3DTEXTURE9 tex_idle;
	LPDIRECT3DTEXTURE9 tex_run;
	LPDIRECT3DTEXTURE9 tex_jump;
	LPDIRECT3DTEXTURE9 tex_gun;

	D3DXVECTOR2 camera_position;

	void Awake();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void Gravity();
	void CameraMove();
};

