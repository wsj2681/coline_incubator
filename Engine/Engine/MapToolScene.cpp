#include "framework.h"
#include "MapToolScene.h"
#include <fstream>

MapToolScene::MapToolScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void MapToolScene::Init()
{
	cout << "Input MapSize [x y]: ";
	Vector2u mapSize;
	cin >> mapSize.x >> mapSize.y;

	levels.resize(mapSize.x * mapSize.y);
	for (auto& i : levels)
	{
		i = 113;
	}
	map = new TileMap("Textures/Map/tileSet.png", { 32, 32 }, levels, mapSize);

	gameView = new View(viewRect);
	gameView->setCenter(map->getPosition());

	texts["INFO"] = 
		new TextObject("'Q' : SetTile, 'W' : SetBaseTile, '[' : Zoom In, ']' : Zoom Out", 
		"Font/CookieRunFont_TTF/CookieRun_Bold.ttf",
		{ +300.f, -50.f });

	texts["INFO"]->setCharacterSize(50);
	mouseCursor = new Object("Textures/Map/tileSet.png");
	mouseCursor->setOrigin(0, 0);
	mouseCursor->setTextureRect(map->GetTile(tileType));
	mouseCursor->SetDebugBoxActive(true);
}

void MapToolScene::Destroy()
{
	Scene::Destroy();
}

void MapToolScene::Input(Event* event)
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
			string mapName{};
			cout << "Input MapName : ";
			cin >> mapName;
			map->SaveMap("MapData/" + mapName + ".bin");
			break;
		}
		case Keyboard::F2:
		{
			string mapName{};
			cout << "Input MapName : ";
			cin >> mapName;
			map->LoadMap("MapData/" + mapName + ".bin");
			break;
		}
		case Keyboard::LBracket:
		{
			gameView->zoom(1.1f);
			break;
		}
		case Keyboard::RBracket:
		{
			gameView->zoom(0.9f);
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
		if (Mouse::isButtonPressed(Mouse::Right))
		{
			gameView->setCenter(mousePosition);
		}

		break;
	}
	case Event::MouseWheelMoved:
	{
		tileType += event->mouseWheel.delta;

		if (tileType <= 56)
		{
			tileType = 56;
		}
		else if(tileType >= 56*23-1)
		{
			tileType = 56 * 23 - 1;
		}
		cout << tileType << endl;
		mouseCursor->setTextureRect(map->GetTile(tileType));
		break;
	}
	default:
		break;
	}
}

void MapToolScene::Update(const Vector2f& mousePosition)
{
	this->mousePosition = mousePosition;
	Scene::Update(mousePosition);
	mouseCursor->setPosition(mousePosition.x + 32.f, mousePosition.y - 32.f);

}

void MapToolScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
	window->setView(*gameView);
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		map->Update(mousePosition, tileType);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		map->Update(mousePosition, tileType, true);
	}
	mouseCursor->Update(deltaTime);
}

void MapToolScene::Render()
{
	Scene::Render();
	window->draw(*map);
	mouseCursor->Render(window);
}
