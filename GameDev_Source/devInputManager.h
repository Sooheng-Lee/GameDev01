#pragma once
#include "CommonHeader.h"
namespace dev
{




	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		static void Init();
		static void Update();
		static void CheckKeyState();

		static bool GetKey(const eKeyCode& code)
		{
			return _keys[(UINT)code].state == eKeyState::Pressed;
		}
		
		static bool GetKeyDown(const eKeyCode& code)
		{
			return _keys[(UINT)code].state == eKeyState::Down;
		}

		static bool GetKeyUp(const eKeyCode& code)
		{
			return _keys[(UINT)code].state == eKeyState::Released;
		}

	private:
		static std::vector<Key> _keys;
		static std::thread* _inputThread;
	};
}

