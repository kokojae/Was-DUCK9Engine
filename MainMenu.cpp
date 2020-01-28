#include "stdafx.h"
#include "MainMenu.h"
#include "Option.h"
#include "PhanClose.h"

int MainMenu::popup = 0;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Awake()
{
	SetTexture(L"resorce/background/scene/mainmenu/start_b.png", D3DXVECTOR2(50, 11));

	index = 0;
	main = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/mainmenu.png");
	start = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/start_b.png");
	option = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/option_b.png");

	Camera::rotation = 0;
	Camera::zoom = 0;
}

void MainMenu::Update()
{
	t += 0.06;

	if (popup != -1)
		if (popup > 0)
			popup--;

	if (t > 6)
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (select == 0)
			{
				if (popup == 0)
				{
					popup = 100;
					GameManager::HardReset();
					GameManager::Reset();
					GameManager::score1 = 0;
					GameManager::score2 = 0;
					Instantiate<PhanClose>()->scene = SceneManager::Stage1;
					//SceneManager::LoadScene();

				}
			}

			if (select == 1)
			{
				if (popup == 0)
					Instantiate<Option>();
			}
		}

	if (time > 0)
		time--;

	if (time <= 0)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			select--;
			if (select < 0)
				select = 1;
			Camera::zoom = 0.9;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			select++;
			if (select > 1)
				select = 0;
			Camera::zoom = 0.9;
		}

		time = 6;
	}
	Camera::zoom += (1 - Camera::zoom) / 20;
	Camera::rotation -= Camera::rotation / 20;
}

void MainMenu::Render()
{
	texture.color = D3DCOLOR_ARGB(255, 255, 255, 255);

	index += 0.1;
	if (index >= 13)
		index = 0;
	texture.index = index;
	texture.texture = main;
	texture.size = D3DXVECTOR2(192, 108);
	texture.scale= D3DXVECTOR2(10, 10);
	texture.center = texture.size / 2;
	GrapicManager::TextureRender(texture, D3DXVECTOR2(0, 0));
	
	texture.index = 0;
	texture.size = D3DXVECTOR2(50, 11);
	texture.center = texture.size / 2;
	if (select != 0)
		texture.color = D3DCOLOR_ARGB(180, 180, 180, 180);
	else
		texture.color = D3DCOLOR_ARGB(255, 255, 255, 255);
	texture.texture = start;
	GrapicManager::TextureRender(texture, D3DXVECTOR2(-650, -80));

	texture.size = D3DXVECTOR2(59, 11);
	texture.center = texture.size / 2;
	if (select != 1)
		texture.color = D3DCOLOR_ARGB(180, 180, 180, 180);
	else
		texture.color = D3DCOLOR_ARGB(255, 255, 255, 255);
	texture.texture = option;
	GrapicManager::TextureRender(texture, D3DXVECTOR2(-600, 150));
}
