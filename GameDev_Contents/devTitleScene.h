#pragma once
#include "../GameDev_Source/devScene.h"

namespace dev
{
	class TitleScene : public Scene
	{
		enum class eMenu
		{
			Start,
			Exit,
		};

	public:
		TitleScene();
		~TitleScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		GameObject* selectObj = new GameObject();
		eMenu menu;
	};

}