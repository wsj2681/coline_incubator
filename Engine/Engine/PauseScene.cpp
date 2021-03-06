#include "framework.h"
#include "PauseScene.h"
#include "LobbyScene.h"
#include "GameScene.h"

PauseScene::PauseScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PauseScene::Init()
{
	texts["TEXT"] = new TextObject("PAUSE SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void PauseScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		scenes->push(new GameScene(scenes, window, soundSystem));
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		scenes->push(new LobbyScene(scenes, window, soundSystem));
		break;
	}
	default:
		break;
	}
}
