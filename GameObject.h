#pragma once

#include "ObjectManager.h"
#include "BoxCollider.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	TextureInfo texture;
	D3DXVECTOR2 position = D3DXVECTOR2(0, 0);
	BoxCollider collider;
	string tag = "";
	int z = 0;
	bool destroy = false;
	bool destroy_me = true;


	virtual void Awake();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void DestroyMe();

	void DrawSelf();

	template <class T>
	T* Instantiate(D3DXVECTOR2 position = D3DXVECTOR2(0, 0))
	{
		return ObjectManager::Instantiate<T>(position);
	}

	GameObject * PlaceMeeting(D3DXVECTOR2 vector, int layer = Layer::DEFAULT);

	void SetTexture(wstring path, D3DXVECTOR2 texture_size);
	void SetCollider(D3DXVECTOR2 size, D3DXVECTOR2 center = D3DXVECTOR2(0, 0));

};

