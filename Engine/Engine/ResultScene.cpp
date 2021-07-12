#include "framework.h"
#include "ResultScene.h"
#include "GameScene.h"
#include "LobbyScene.h"

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
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
		// Ű���� �Է�
	case Event::KeyPressed:
	{
		scenes->push(new GameScene(scenes, window, soundSystem));
		break;
	}

	// ���콺 �Է�
	case Event::MouseButtonPressed:
	{
		scenes->push(new LobbyScene(scenes, window, soundSystem));
		break;
	}
	default:
		break;
	}
}
