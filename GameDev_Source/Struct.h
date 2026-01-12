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
}