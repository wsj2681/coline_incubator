#include "framework.h"
#include "MapToolScene.h"
#include <fstream>

MapToolScene::MapToolScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void MapToolScene::Init()
{
	levels.resize(200 * 200);
	for (auto& i : levels)
	{
		i = 113;
	}
	map = new TileMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 200, 200 });
	view = new View(viewRect);
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
		case Keyboard::F1:
		{
			map->SaveMap("TileMap.bin");
			break;
		}
		case Keyboard::F2:
		{
			map->LoadMap("TileMap.bin");
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
			view->setCenter(mousePosition);
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
	window->setView(*view);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		map->Update(mousePosition, tileType);
	}
	mouseCursor->Update(deltaTime);
}

void MapToolScene::Render()
{
	Scene::Render();
	window->draw(*map);
	mouseCursor->Render(window);
}
