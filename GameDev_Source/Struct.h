#pragma once
#include "Enum.h"
namespace dev
{
	struct Key
	{
		eKeyState state;
		eKeyCode code;
		bool bPressed;
	};

	struct Vector2
	{
		float x;
		float y;
	};
}