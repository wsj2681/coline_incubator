#include "framework.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "ResultScene.h"
#include "Character.h"
#include "TileMap.h"

GameScene::GameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void GameScene::Init()
{
	//texts["TEXT"] = new TextObject("GAME SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
	character = new Character(WARRIOR_FEMALE);
	character->setScale(0.5f, 0.5f);
	
	levels.resize(200 * 200);
	for (auto& i : levels)
	{
		i = 113;
	}
	world = new TileMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 200, 200 });

	world->LoadMap("TileMap.bin");

	gameView = new View(viewRect);
	gameView->setCenter(character->getPosition());
	window->setView(*gameView);
	gameView->zoom(0.3f);
}

void GameScene::Destroy()
{
	Scene::Destroy();	
	character->Destroy();
}

void GameScene::Input(Event* event)
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
			window->setView(window->getDefaultView());
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
		//scenes->push(new ResultScene(scenes, window));
		break;
	}
	default:
		break;
	}
}

void GameScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
	character->Update(mousePosition);
}

void GameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
	character->Update(deltaTime);
	gameView->setCenter(character->getPosition());
	window->setView(*gameView);
}

void GameScene::Render()
{
	if (world)
	{
		window->draw(*world);
	}
	Scene::Render();
	if (character)
	{
		character->Render(window);
	}
}
