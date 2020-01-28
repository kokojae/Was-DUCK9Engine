#include "stdafx.h"
#include "PhanClose.h"

PhanClose* PhanClose::me = nullptr;

PhanClose::PhanClose()
{
}


PhanClose::~PhanClose()
{
}

void PhanClose::Awake()
{
	if (me != nullptr)
	{
		destroy = true;
		return;
	}	
	else
	{
		me = this;
	}
		
	SetTexture(L"resorce/UI/loading_L.png", D3DXVECTOR2(2000, 1080));
	tex_1 = TextureManager::LoadTexture(L"resorce/UI/loading_L.png");
	tex_2 = TextureManager::LoadTexture(L"resorce/UI/loading_R.png");
	texture.camera_on = false;
	texture.center = D3DXVECTOR2(0,0);
	z = -500;

}

void PhanClose::Update()
{
	speed += 2;

	t -= speed;

	if (t < 0)
	{
		speed = -speed / 2;
		t = 0;
	}

	if (speed > -2 && speed < 0)
		t = -1;
		

	//t += (0 - t) / 10;
	



	if (t < 0)
	{
		delay ++;
		if (delay > 20)
		{
			me = nullptr;
			SceneManager::LoadScene(scene);
		}
			
	}

}

void PhanClose::Render()
{
	//position.y = 1080 / 2;

	position.x = -t;
	texture.texture = tex_1;
	DrawSelf();

	position.x = t;
	texture.texture = tex_2;
	DrawSelf();
}
