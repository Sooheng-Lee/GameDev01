#pragma once
#include "devObject.h"
#include "devComponent.h"
namespace dev
{
	class GameObject : public Object
	{
	public:
		GameObject();
		~GameObject();

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	
	public:
		void SetPosition(const Vector2& position)
		{
			_position = position;
		}

		Vector2 GetPosition()
		{
			return _position;
		}

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->SetOwner(this);
			_components.push_back(component);
			return component;
		}
		
	private:
		Vector2 _position;
		std::vector<Component*> _components;
	};
}

