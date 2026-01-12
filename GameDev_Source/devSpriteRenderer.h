#pragma once
#include "devComponent.h"
#include "devGameObject.h"
namespace dev
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();
		void Render(HDC hdc) override;
	public:
		void SetImagePath(const wchar_t* imagePath);
		template <typename T>
		void SetOwner(T* owner)
		{
			_owner = dynamic_cast<GameObject*>(owner);
		}

		GameObject* GetOwner()
		{
			return _owner;
		}

	private:
		Image* _image;
		GameObject* _owner;
	};
}

