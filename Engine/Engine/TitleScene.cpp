#include "framework.h"
#include "TitleScene.h"
#include "LobbyScene.h"

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void TitleScene::Init()
{
	texts["TEXT"] = new TextObject("TITLE SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void TitleScene::Input(Event* event)
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
		scenes->push(new LobbyScene(scenes, window));
		break;
	}
	default:
		break;
	}
}

