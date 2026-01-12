#pragma once
#include "CommonHeader.h"
namespace dev
{
	class TimeManager
	{
	public:
		TimeManager();
		~TimeManager();
		static void Init();
		static void Update();
		static void Render(HDC hdc);

	public:
		static float DeltaTime() { return _deltaTime; }

	private:
		static LARGE_INTEGER _cpuFrequency;
		static LARGE_INTEGER _currentCounter;
		static LARGE_INTEGER _prevCounter;
		static float _deltaTime;
		static float _totalTime;
	};
}

