#pragma once
#include "devObject.h"
#include "devGameObject.h"
namespace dev
{
	class Scene : public Object
	{
	public:
		Scene();
		~Scene();

		void Init();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	protected:
		std::vector<GameObject*> _objects;
	};
}

