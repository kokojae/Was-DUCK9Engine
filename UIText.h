#pragma once
class UIText : public GameObject
{
public:
	UIText();
	~UIText();

	wstring text = L"";
	D3DXVECTOR2 scale = D3DXVECTOR2(1, 1);

	void SetText(wstring text, D3DXVECTOR2 scale)
	{
		this->text = text;
		this->scale = scale;
	};
	void Render();
};

