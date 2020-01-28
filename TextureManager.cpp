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
		printf("%s 재활용\n", path.c_str());
	}
	else
	{
		D3DXCreateTextureFromFileEx(GrapicManager::device,
			path.c_str(),//여기서 오류가 난다면 문자집합 유니코드 - 멀티바이트로 바꾸기
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
		printf("%s 불러오기 성공\n", path.c_str());
	}

	return texture;
}
