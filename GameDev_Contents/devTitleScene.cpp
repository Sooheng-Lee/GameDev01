#include "devTitleScene.h"
#include "devSpriteRenderer.h"
#include "devInputManager.h"

namespace dev
{
	TitleScene::TitleScene() : menu(eMenu::Start)
	{

	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Init()
	{
		selectObj = new GameObject();
		selectObj->AddComponent<SpriteRenderer>()->SetImagePath(L"archer.png");
		selectObj->SetPosition(Vector2(600, 200));
		selectObj->SetLayer(eLayer::GameObject);
		_objects.push_back(selectObj);
		Scene::Init();
	}

	void TitleScene::Update()
	{
		Scene::Update();
		INT menuIdx = (INT)menu;
		if (InputManager::GetKeyDown(eKeyCode::Up))
		{
			menuIdx -= 1;
			if (menuIdx < (INT)eMenu::Start)
			{
				menuIdx = (INT)eMenu::Exit;
			}
			
		}

		if (InputManager::GetKeyDown(eKeyCode::Down))
		{
			menuIdx += 1;
			if (menuIdx > (INT)eMenu::Exit)
			{
				menuIdx = (INT)eMenu::Start;
			}
		}
		menu = (eMenu)menuIdx;

		if (InputManager::GetKeyDown(eKeyCode::A))
		{
			switch (menu)
			{
			case eMenu::Start:
			{
				break;
			}
			case eMenu::Exit:
			{
				PostQuitMessage(0);
				break;
			}
			default:
				break;
			}

		}
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		Vector2 position = selectObj->GetPosition();
		if (menu == eMenu::Start)
		{
			position.y = 200;
		}
		else
		{
			position.y = 400;
		}
		selectObj->SetPosition(position);
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		HFONT font = CreateFont(50,
			0,
			0,
			0,
			FW_BOLD,
			false,
			false,
			false,
			DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"¸¼Àº °íµñ");
		HFONT oldFont = (HFONT)SelectObject(hdc, font);
		TextOut(hdc, 725, 225, L"Start", wcslen(L"Start"));
		TextOut(hdc, 725, 425, L"Exit", wcslen(L"Exit"));
		(HFONT)SelectObject(hdc, oldFont);
		DeleteObject(font);
		TextOut(hdc, 725, 10, L"Title Scene", wcslen(L"Title Scene"));
	}
}