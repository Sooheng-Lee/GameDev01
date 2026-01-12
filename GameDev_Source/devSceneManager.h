#pragma once
#include "CommonHeader.h"
#include "devScene.h"

namespace dev
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<std::wstring, Scene*> _scenes;
		static Scene* _activeScene;
	};
}

