#include "devSceneManager.h"

namespace dev
{
	std::map<std::wstring, Scene*> SceneManager::_scenes = {};
	Scene* SceneManager::_activeScene = nullptr;

	SceneManager::SceneManager()
	{
	}
	SceneManager::~SceneManager()
	{
	}
	void SceneManager::Init()
	{
		if (_activeScene)
		{
			_activeScene->Init();
		}
	}

	void SceneManager::Update()
	{
		if (_activeScene)
		{
			_activeScene->Update();
		}
	}

	void SceneManager::LateUpdate()
	{
		if (_activeScene)
		{
			_activeScene->LateUpdate();
		}
	}

	void SceneManager::Render(HDC hdc)
	{
		if (_activeScene)
		{
			_activeScene->Render(hdc);
		}
	}
}