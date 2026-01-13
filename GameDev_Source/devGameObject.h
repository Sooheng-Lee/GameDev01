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

		void SetScale(const Vector2& scale)
		{
			_scale = scale;
		}

		Vector2 GetScale()
		{
			return _scale;
		}

		template <typename T>
		T* AddComponent(T* component)
		{
			component->SetOwner(this);
			_components.push_back(component);
			return component;
		}

		void SetLayer(eLayer layer)
		{
			_layer = layer;
		}

		eLayer GetLayer()
		{
			return _layer;
		}
		
	protected:
		Vector2 _position;
		Vector2 _scale;
		std::vector<Component*> _components;
		eLayer _layer;
	};
}

