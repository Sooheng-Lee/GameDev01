#include "devInputManager.h"

namespace dev
{
	std::vector<Key> InputManager::_keys;
	std::thread* InputManager::_inputThread = nullptr;

	const static UINT ASCII[] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
	};
	
	InputManager::InputManager()
	{

	}

	InputManager::~InputManager()
	{

	}

	void InputManager::Init()
	{
		UINT keyNum = static_cast<UINT>(eKeyCode::END);
		_keys.resize(keyNum);
		for (int idx = 0; idx < keyNum; ++idx)
		{
			_keys[idx].code = (eKeyCode)idx;
			_keys[idx].bPressed = false;
			_keys[idx].state = eKeyState::None;
		}
	}

	void InputManager::Update()
	{
		CheckKeyState();
	}

	void InputManager::CheckKeyState()
	{
		if (_keys.empty())
			return;

		for (int idx = 0; idx < (UINT)eKeyCode::END; ++idx)
		{
			if (GetAsyncKeyState(ASCII[idx]) & 0x8000)
			{
				if (_keys[idx].bPressed)
				{
					_keys[idx].state = eKeyState::Pressed;
				}
				else
				{
					_keys[idx].state = eKeyState::Down;
				}
				_keys[idx].bPressed = true;
			}
			else
			{
				if (_keys[idx].bPressed)
				{
					_keys[idx].state = eKeyState::Released;
				}
				else
				{
					_keys[idx].state = eKeyState::None;
				}
				_keys[idx].bPressed = false;
			}
		}
	}
}