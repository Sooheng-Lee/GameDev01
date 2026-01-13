#pragma once

namespace dev
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Up, Down, Left, Right,
		END
	};

	enum class eKeyState
	{
		Pressed,
		Down,
		Released,
		None,
	};

	enum class eLayer
	{
		None,
		Background,
		GameObject,
		Effect,
	};
}