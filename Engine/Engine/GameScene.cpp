#include "framework.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "ResultScene.h"

GameScene::GameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void GameScene::Init()
{
	texts["TEXT"] = new TextObject("GAME SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void GameScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		scenes->push(new PauseScene(scenes, window));
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		scenes->push(new ResultScene(scenes, window));
		break;
	}
	default:
		break;
	}
}
