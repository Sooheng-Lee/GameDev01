#include "devScene.h"

namespace dev
{
	Scene::Scene() : _objects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Init()
	{
		for (GameObject* obj : _objects)
		{
			obj->Init();
		}
	}

	void Scene::Update()
	{
		for (GameObject* obj : _objects)
		{
			obj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* obj : _objects)
		{
			obj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* obj : _objects)
		{
			obj->Render(hdc);
		}
	}
}