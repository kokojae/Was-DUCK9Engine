#include "stdafx.h"
#include "ObjectManager.h"

list<GameObject*> ObjectManager::object_list = list<GameObject*>();
list<GameObject*> ObjectManager::collid_list = list<GameObject*>();

bool SortObject(const GameObject*  a, const GameObject*  b)
{
	return a->z > b->z;
};

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}




void ObjectManager::sort()
{
	object_list.sort(SortObject);
}

void ObjectManager::Update()
{
	if (Camera::shake.x > 1)
		Camera::shake.x--;
	if (Camera::shake.y > 1)
		Camera::shake.y--;

	if (GetAsyncKeyState('T'))
	{
		if (SceneManager::current_scene == SceneManager::Stage1 || SceneManager::current_scene == SceneManager::Stage2)
		{
			GameManager::Reset();
			GameManager::HardReset();
			if (SceneManager::current_scene == SceneManager::Stage1)
				GameManager::score1 = 0;
			if (SceneManager::current_scene == SceneManager::Stage2)
				GameManager::score2 = 0;
			SceneManager::LoadScene(SceneManager::current_scene);
		}
	}

	if (GetAsyncKeyState('R'))
	{
		if (SceneManager::current_scene == SceneManager::Stage1 || SceneManager::current_scene == SceneManager::Stage2)
		{
			GameManager::ReStart();
		}
	}

	list<GameObject*>::iterator it = object_list.begin();

	while (it != object_list.end())
	{
		GameObject * inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			collid_list.remove(inst);
			object_list.erase(it++);
			delete(inst);
			continue;
		}

		inst->Update();
		it++;
	}

	
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : object_list)
	{
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : object_list)
	{
		inst->Render();
	}
}

void ObjectManager::Clear()
{
	for (GameObject* inst : object_list)
	{
		inst->destroy = true;
	}
}

GameObject * ObjectManager::CollidCheck(D3DXVECTOR2 position, D3DXVECTOR2 size, int layer)
{
	for (GameObject* inst : collid_list)
	{
		if ((layer & inst->collider.layer) == 0)
			continue;
		if (inst->collider.enable == false)
			continue;
		if (inst->destroy)
			continue;


		if (position.x < inst->position.x + inst->collider.size.x - inst->collider.center.x)
			if (position.x + size.x > inst->position.x - inst->collider.center.x)
				if (position.y < inst->position.y + inst->collider.size.y - inst->collider.center.y)
					if (position.y + size.y > inst->position.y - inst->collider.center.y)
					{
						return inst;
					}
	}
	return nullptr;
}
