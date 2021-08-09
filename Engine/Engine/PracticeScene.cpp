#include "framework.h"
#include "PracticeScene.h"
#include "JumpObject.h"
#include "PracticeMap.h"
#include "Object.h"
#include "MonsterObject.h"
#include "BulletManager.h"

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

	// 48 x 8 HP bar
	// 32 x 32
	player = new JumpObject("Textures/Character/Warrior_Male/Down00.png", {500, 500});

	for (int i = 0; i < 1; ++i)
	{
		monsters.push_back(new MonsterObject("Textures/Character/Warrior_Male/Down00.png", Vector2f(rand() % 1080, rand() % 720)));
	}

	gameView = new View(player->getPosition(), { 800, 600 });
	//window->setView(*gameView);
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
				player->SetBomb();
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
		//cout << player->getPosition().x << "/ " << player->getPosition().y << endl;
	}
	player->GetBulletMgr()->GetBullets();

	for (auto& bullet : *player->GetBulletMgr()->GetBullets())
	{
		for (auto& monster : monsters)
		{
			if (monster->IsActive() && bullet->IsActive())
			{
				if (bullet->getGlobalBounds().intersects(monster->getGlobalBounds()))
				{
					bullet->SetActive(false);
					bullet->setPosition({});
					monster->SetHp(monster->GetHp() - bullet->GetBulletType());
				}
			}
		}
	}

	for (auto& monster : monsters)
	{
		monster->Update(mousePosition);
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
	for (auto& monster : monsters)
	{
		monster->Update(deltaTime);
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

	for (auto& monster : monsters)
	{
		monster->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}

}
