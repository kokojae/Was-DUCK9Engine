#pragma once
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static map<wstring, LPDIRECT3DTEXTURE9> texture_map;

	static LPDIRECT3DTEXTURE9 LoadTexture(wstring path);
};

