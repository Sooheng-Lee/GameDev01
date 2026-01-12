#include "devInputManager.h"

namespace dev
{
	std::vector<Key> InputManager::_keys;
	std::atomic<bool> InputManager::_bInputReceiving = false;
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
		size_t keyNum = static_cast<size_t>(eKeyCode::END);
		_keys.resize(keyNum);
		for (int idx = 0; idx < keyNum; ++idx)
		{
			Key key = {};
			key.code = (eKeyCode)idx;
			key.bPressed = false;
			key.state = eKeyState::None;
			_keys.push_back(key);
		}
	}

	void InputManager::Update()
	{
		while (_bInputReceiving.load())
		{
			CheckKeyState();
		}
	}

	void InputManager::CheckKeyState()
	{
		for (int idx = 0; idx < (size_t)eKeyCode::END; ++idx)
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

	void InputManager::BeginInput()
	{
		_bInputReceiving.store(true);
		_inputThread = new std::thread(&InputManager::Update);
		_inputThread->detach();
	}

	void InputManager::EndInput()
	{
		_bInputReceiving.store(false);
		if (_inputThread->joinable())
		{
			_inputThread->join();
			_inputThread = nullptr;
		}
	}
}