#include "stdafx.h"
#include "Camera.h"


D3DXVECTOR2 Camera::position = D3DXVECTOR2(0,0);
float Camera::scale = 1;
float Camera::rotation = 0;
float Camera::zoom = 1;
D3DXVECTOR2 Camera::shake = D3DXVECTOR2(1, 1);

Camera::Camera()
{
}


Camera::~Camera()
{
}

D3DXMATRIX Camera::GetMatrix()
{
	D3DXMATRIX mat, mat_rotation, mat_scale, mat_position, screen;

	D3DXMatrixTranslation(&mat_position, -(int)position.x, -(int)position.y, 0);
	D3DXMatrixRotationZ(&mat_rotation, D3DXToRadian(rotation));
	D3DXMatrixScaling(&mat_scale, 1/scale, 1/scale, 0);
	D3DXMatrixTranslation(&screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

	mat = mat_position * mat_scale * mat_rotation * screen;

	return mat;
};
