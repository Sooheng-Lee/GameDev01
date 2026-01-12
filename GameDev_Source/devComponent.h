#pragma once
#include "CommonHeader.h"
namespace dev
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	};
}

