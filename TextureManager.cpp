#include "stdafx.h"
#include "TextureManager.h"


map<wstring, LPDIRECT3DTEXTURE9> TextureManager::texture_map = map<wstring, LPDIRECT3DTEXTURE9>();


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(wstring path)
{
	LPDIRECT3DTEXTURE9 texture;

	if (texture_map.count(path))
	{
		texture = texture_map.find(path)->second;
		printf("%s ��Ȱ��\n", path.c_str());
	}
	else
	{
		D3DXCreateTextureFromFileEx(GrapicManager::device,
			path.c_str(),//���⼭ ������ ���ٸ� �������� �����ڵ� - ��Ƽ����Ʈ�� �ٲٱ�
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			0,
			NULL,
			NULL,
			&texture);

		texture_map[path] = texture;
		printf("%s �ҷ����� ����\n", path.c_str());
	}

	return texture;
}
