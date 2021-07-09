#include "framework.h"
#include "ResultScene.h"
#include "GameScene.h"
#include "LobbyScene.h"

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void ResultScene::Init()
{
	texts["TEXT"] = new TextObject("RESULT SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void ResultScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		scenes->push(new GameScene(scenes, window));
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		scenes->push(new LobbyScene(scenes, window));
		break;
	}
	default:
		break;
	}
}
