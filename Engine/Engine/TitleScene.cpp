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

	vector<int> levels;

	for (int i = 0; i < 56 * 23 - 1; ++i)
	{
		levels.push_back(i);
	}

	map = new TileMap("Textures/Map/tileSet.png", Vector2u(32, 32), levels, Vector2u(56, 23));
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

void TitleScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void TitleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TitleScene::Render()
{
	Scene::Render();

	window->draw(*map);
}

