#pragma once
#include "CommonHeader.h"
#include "devGameObject.h"

namespace dev
{
	class Application
	{
	public:
		Application();
		~Application();

		void Init(HWND hwnd, const UINT& width, const UINT& height);
		

		void Update();
		void LateUpdate();


	private:
		void BeginRender();
		void StopRender();
		void Render();

	private:
		HWND _hwnd;
		HDC _hdc;
		HDC _backHdc;
		HBITMAP _backBuffer;
		UINT _width;
		UINT _height;
		std::atomic<bool> _bRendering;

	private:
		std::thread* _renderThread;
		std::thread* _inputThread;

		GameObject _gameObj;
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
	};
}

