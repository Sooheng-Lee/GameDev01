#include "devTimeManager.h"

namespace dev
{
	LARGE_INTEGER TimeManager::_cpuFrequency = {0};
	LARGE_INTEGER TimeManager::_currentCounter = {0};
	LARGE_INTEGER TimeManager::_prevCounter = {0};
	float TimeManager::_deltaTime = 0.0f;
	float TimeManager::_totalTime = 0.0f;

	TimeManager::TimeManager()
	{
	}
	TimeManager::~TimeManager()
	{
	}
	void TimeManager::Init()
	{
		QueryPerformanceFrequency(&_cpuFrequency);
		QueryPerformanceCounter(&_prevCounter);
		_currentCounter.QuadPart = 0;
	}

	void TimeManager::Update()
	{
		QueryPerformanceCounter(&_currentCounter);
		LONGLONG diff = _currentCounter.QuadPart - _prevCounter.QuadPart;
		_deltaTime = static_cast<float>(diff) / static_cast<float>(_cpuFrequency.QuadPart);
		_totalTime += _deltaTime;
		_prevCounter.QuadPart = _currentCounter.QuadPart;
	}

	void TimeManager::Render(HDC hdc)
	{
		wchar_t timeStr[50] = L"";
		int textLen = swprintf_s(timeStr, 50, L"Time elapsed : %3f sec", _totalTime);
		
		TextOut(hdc, 10, 10, timeStr, textLen);
	}
}