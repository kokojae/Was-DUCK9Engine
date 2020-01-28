#pragma once
class Text : public GameObject
{
public:
	Text();
	~Text();

	wstring text = L"";
	D3DXVECTOR2 scale = D3DXVECTOR2(1,1);

	void SetText(wstring text, D3DXVECTOR2 scale)
	{
		this->text = text;
		this->scale = scale;
	};
	void Render();
};

