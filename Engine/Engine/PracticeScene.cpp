#include "framework.h"
#include "PracticeScene.h"
#include "PracticeMap.h"
#include "JumpObject.h"
#include "MonsterObject.h"
#include "WallObject.h"
#include "BulletManager.h"
#include "BombManager.h"
#include "WallManager.h"
#include "CrossBomb.h"

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
		levels.push_back(56); // grass
	}

	map = new PracticeMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 50, 50 });

	mouseCursor = new Object("Textures/Map/tileSet.png");
	mouseCursor->setOrigin({});
	mouseCursor->setTextureRect(map->GetTile(tileNumber));

	// 48 x 8 HP bar
	// 32 x 32
	player = new JumpObject("Textures/Character/Warrior_Male/Down00.png", {100.f, 100.f});

	for (int i = 0; i < 10; ++i)
	{
		monsters.push_back(new MonsterObject("Textures/Character/Warrior_Male/Down00.png", Vector2f(rand() % 1080, rand() % 720)));
	}

	wallMgr = new WallManager();
	
	WallObject* object = new WallObject("Textures/Object/wall1.png", { 300.f, 300.f });
	wallMgr->SetWall(object);

	object = new WallObject("Textures/Object/wall3.png", { 500.f, 500.f });
	wallMgr->SetWall(object);

	gameView = new View(player->getPosition(), { 800, 600 });
	//window->setView(*gameView);

	bomb = new CrossBomb();
	bomb->setPosition(400.f, 200.f);
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
		//tileNumber += event->mouseWheel.delta;

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
		map->Update(player);

		if (Mouse::isButtonPressed(Mouse::Right))
		{
			map->Update(mousePosition, tileNumber);
		}
	}

	if (player)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			player->Shoot();
		}
		player->Update(mousePosition);
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

			if (wallMgr)
			{
				wallMgr->CollisionUpdate(bullet);
			}

		}
	}

	for (auto& monster : monsters)
	{
		monster->Update(mousePosition);
	}

	if (wallMgr)
	{
		wallMgr->Update(mousePosition);
		wallMgr->CollisionUpdate(player);
	}

}

void PracticeScene::Update(const float& deltaTime)
{
	if (mouseCursor)
	{
		mouseCursor->Update(deltaTime);
	}

	if (bomb)
	{
		bomb->Update(deltaTime);
	}

	if (player)
	{
		player->Update(deltaTime);
	}

	for (auto& monster : monsters)
	{
		monster->Update(deltaTime);
		if (player)
		{
			player->GetBombMgr()->DamageBoom(monster);
		}
	}

	if (wallMgr)
	{
		wallMgr->Update(deltaTime);
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

	if (wallMgr)
	{
		wallMgr->Render(window);
	}

	if (bomb)
	{
		bomb->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}

}
