#include "framework.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "ResultScene.h"
#include "Character.h"
#include "TileMap.h"

GameScene::GameScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void GameScene::Init()
{
	character = new Character(WARRIOR_FEMALE);
	character->setScale(0.5f, 0.5f);
	
	levels.resize(200 * 200);
	for (auto& i : levels)
	{
		i = 113;
	}
	world = new TileMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 50, 50 });

	world->LoadMap("MapData/111.bin");

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
		case Keyboard::F1:
		{
			soundSystem->VolumeDown();
			break;
		}
		case Keyboard::F2:
		{
			soundSystem->VolumeUp();
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
		soundSystem->EffectPlay("CoinGet");
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

	if (!world->GetMapBounds().intersects(character->getGlobalBounds()))
	{
		character->setPosition(character->getPosition());
	}

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
