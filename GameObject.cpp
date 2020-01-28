#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Awake()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	DrawSelf();
}

void GameObject::DestroyMe()
{
}

void GameObject::DrawSelf()
{
	GrapicManager::TextureRender(texture, position);
}

GameObject * GameObject::PlaceMeeting(D3DXVECTOR2 vector, int layer)
{
	collider.enable = false;

	GameObject * inst = ObjectManager::CollidCheck(position - collider.center + vector, collider.size, layer);

	collider.enable = true;

	return inst;
}

void GameObject::SetTexture(wstring path, D3DXVECTOR2 texture_size)
{
	texture.texture = TextureManager::LoadTexture(path);
	texture.size = texture_size;
	texture.center = texture_size / 2;
}

void GameObject::SetCollider(D3DXVECTOR2 size, D3DXVECTOR2 center)
{
	collider.size = size;
	collider.center = center;

	ObjectManager::collid_list.push_back(this);
}