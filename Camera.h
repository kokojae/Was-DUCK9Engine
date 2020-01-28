#pragma once
class Camera
{
public:
	Camera();
	~Camera();

	static D3DXVECTOR2 position;
	static float scale;
	static float rotation;
	static float zoom;
	static D3DXVECTOR2 shake;

	static D3DXMATRIX GetMatrix();
};