#include "framework.h"
#include "TitleScene.h"
#include "LobbyScene.h"
#include "MapToolScene.h"

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void TitleScene::Init()
{
	texts["TEXT"] = new TextObject("TITLE SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
	buttons["MapTool"] = new ButtonObject("Textures/Button/maptool.png", "Textures/Button/maptoolactive.png", { 1080 / 2.f, 720.f - 100.f });
}

void TitleScene::Destroy()
{
	Scene::Destroy();
}

void TitleScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		switch (event->key.code)
		{
		case Keyboard::Escape:
		{
			EndScene();
			break;
		}
		default:
			break;
		}
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{

		//scenes->push(new LobbyScene(scenes, window));
		break;
	}
	default:
		break;
	}
}

void TitleScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);

	if (buttons["MapTool"]->IsPressed())
	{
		scenes->push(new MapToolScene(scenes, window));
	}
}

void TitleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TitleScene::Render()
{
	Scene::Render();
}

