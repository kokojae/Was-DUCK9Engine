#pragma once


class GameObject;
using namespace std;
#include <list>
#include "Layer.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	static list<GameObject*> object_list;
	static list<GameObject*> collid_list;

	template <class T>
	static T* Instantiate(D3DXVECTOR2 position = D3DXVECTOR2(0, 0))
	{
		T* inst = new T;

		object_list.push_back(inst);
		inst->Awake();
		inst->position = position;

		sort();

		return inst;
	}

	static void sort();

	

	static void Update();
	static void LateUpdate();
	static void Render();
	static void Clear();

	static GameObject* CollidCheck(D3DXVECTOR2 position, D3DXVECTOR2 size, int layer = Layer::DEFAULT);
};