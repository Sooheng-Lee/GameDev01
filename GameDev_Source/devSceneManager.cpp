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

	void SceneManager::AddScene(const std::wstring name, Scene* scene)
	{
		_scenes.insert(std::make_pair(name, scene));
	}

	void SceneManager::LoadScene(const std::wstring name)
	{
		auto iter = _scenes.find(name);
		if (iter != _scenes.end())
		{
			_activeScene = iter->second;
		}
		else
		{
			_activeScene = _activeScene;
		}
	}
}