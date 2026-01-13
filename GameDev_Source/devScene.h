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

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	protected:
		std::vector<GameObject*> _objects;
	};
}

