#include "devApplication.h"
#include "devTimeManager.h"
#include "devInputManager.h"
#include "devSceneManager.h"
#include "../GameDev_Contents/devTitleScene.h"
namespace dev
{
	Application::Application() : _hwnd(nullptr), _hdc(nullptr), _backHdc(nullptr), _backBuffer(nullptr), _width(0), _height(0), _bRendering{ false }, _renderThread(nullptr)
	{

	}

	Application::~Application()
	{
		StopRender();
		GdiplusShutdown(gdiplusToken);
	}

	void Application::Init(HWND hwnd, const UINT& width, const UINT& height)
	{
		RECT winRect = {0, 0, width, height};
		AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, false);
		_hwnd = hwnd;
		_width = winRect.right - winRect.left;
		_height = winRect.bottom - winRect.top;
		SetWindowPos(hwnd, nullptr, _width / 3, _height / 3, _width, _height, 0);
		ShowWindow(_hwnd, 0);
		_hdc = GetDC(_hwnd);
		TitleScene* titleScene = new TitleScene();
		SceneManager::AddScene(L"TitleScene", titleScene);
		SceneManager::LoadScene(L"TitleScene");

		TimeManager::Init();
		_backBuffer = CreateCompatibleBitmap(_hdc, _width, _height);
		_backHdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(oldBitmap);

		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

		BeginRender();
		InputManager::Init();
		SceneManager::Init();
	}

	void Application::BeginRender()
	{
		_bRendering = true;
		_renderThread = new std::thread(&dev::Application::Render, this);
	}

	void Application::StopRender()
	{
		_bRendering = false;
		if (_renderThread->joinable())
		{
			_renderThread->join();
			_renderThread = nullptr;
		}
	}

	void Application::Update()
	{
		TimeManager::Update();
		InputManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		while (_bRendering.load())
		{
			Rectangle(_backHdc, 0, 0, _width, _height);
			TimeManager::Render(_backHdc);
			SceneManager::Render(_backHdc);
			_gameObj.Render(_backHdc);
			BitBlt(_hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY);
		}
	}
}