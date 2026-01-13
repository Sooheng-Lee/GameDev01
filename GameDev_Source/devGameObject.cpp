#include "devGameObject.h"
#include "devInputManager.h"
#include "devTimeManager.h"
#include "devSpriteRenderer.h"
namespace dev
{
	GameObject::GameObject() : _position{ 0.0f, 0.0f }, _components{}, _layer(eLayer::None)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Init()
	{
		for (Component* comp : _components)
		{
			comp->Init();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : _components)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : _components)
		{
			comp->LateUpdate();
		}

		/*
		if (InputManager::GetKey(eKeyCode::A))
		{
			_position.x -= 200.0f * TimeManager::DeltaTime();
		}

		if (InputManager::GetKey(eKeyCode::D))
		{
			_position.x += 200.0f * TimeManager::DeltaTime();
		}

		if (InputManager::GetKey(eKeyCode::W))
		{
			_position.y -= 200.0f * TimeManager::DeltaTime();
		}

		if (InputManager::GetKey(eKeyCode::S))
		{
			_position.y += 200.0f * TimeManager::DeltaTime();
		}
		*/
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : _components)
		{
			comp->Render(hdc);
		}
	}
}