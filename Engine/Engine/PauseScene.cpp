#include "framework.h"
#include "PauseScene.h"
#include "LobbyScene.h"
#include "GameScene.h"

PauseScene::PauseScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
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
		// Ű���� �Է�
	case Event::KeyPressed:
	{
		scenes->push(new GameScene(scenes, window));
		break;
	}

	// ���콺 �Է�
	case Event::MouseButtonPressed:
	{
		scenes->push(new LobbyScene(scenes, window));
		break;
	}
	default:
		break;
	}
}
