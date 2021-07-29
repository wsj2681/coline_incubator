#include "framework.h"
#include "PracticeScene.h"
#include "JumpObject.h"
#include "PracticeMap.h"
#include "Object.h"

PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PracticeScene::Init()
{
	vector<int> levels;

	for (int i = 0; i < 50 * 50; ++i)
	{
		levels.push_back(56);
	}

	map = new PracticeMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 50, 50 });

	mouseCursor = new Object("Textures/Map/tileSet.png");
	mouseCursor->setOrigin({});
	mouseCursor->setTextureRect(map->GetTile(tileNumber));

	player = new JumpObject("Textures/Character/Warrior_Male/Down00.png", {500, 500});
}

void PracticeScene::Destroy()
{

}

void PracticeScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		switch (event->key.code)
		{
			case Keyboard::Space:
			{
				
			} 
			case Keyboard::F1:
			{
				map->SaveMap("Test.bin"); 
				break;
			}
			case Keyboard::F2:
			{
				map->LoadMap("Test.bin");
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
		break;
	}
	case Event::MouseWheelMoved:
	{
		tileNumber += event->mouseWheel.delta;

		if (tileNumber <= 56)
		{
			tileNumber = 56;
		}
		else if (tileNumber >= 56 * 23 - 1)
		{
			tileNumber = 56 * 23 - 1;
		}

		mouseCursor->setTextureRect(map->GetTile(tileNumber));

		break;
	}
	default:
		break;
	}
}

void PracticeScene::Update(const Vector2f& mousePosition)
{
	mouseCursor->setPosition(mousePosition.x + 32, mousePosition.y - 32);
	if (map)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			player->Shoot();
			//map->Update(mousePosition, tileNumber);
		}
	}

	if (player)
	{
		player->Update(mousePosition);
	}
}

void PracticeScene::Update(const float& deltaTime)
{
	if (mouseCursor)
	{
		mouseCursor->Update(deltaTime);
	}

	if (player)
	{
		player->Update(deltaTime);
	}
}

void PracticeScene::Render()
{
	if (map)
	{
		window->draw(*map);
	}
	
	if (player)
	{
		player->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}
}
