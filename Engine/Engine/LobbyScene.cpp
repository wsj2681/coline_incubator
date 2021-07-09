#include "framework.h"
#include "LobbyScene.h"
#include "GameScene.h"

LobbyScene::LobbyScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void LobbyScene::Init()
{
	texts["TEXT"] = new TextObject("LOBBY SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void LobbyScene::Input(Event* event)
{
	switch (event->type)
	{
		// Ű���� �Է�
	case Event::KeyPressed:
	{
		break;
	}

	// ���콺 �Է�
	case Event::MouseButtonPressed:
	{
		scenes->push(new GameScene(scenes, window));
		break;
	}
	default:
		break;
	}
}
