#include "framework.h"
#include "MonsterManager.h"
#include "BulletManager.h"

MonsterManager::MonsterManager(const size_t& MonsterCount)
{
	for (size_t i = 0; i < MonsterCount; ++i)
	{
		monsters.push_back(new MonsterObject("Textures/Character/Warrior_Female/Down00.png", Vector2f(Math::RandomIntager(0, 1080), Math::RandomIntager(0, 720))));
	}
}

void MonsterManager::Destroy()
{
}

vector<MonsterObject*>* MonsterManager::GetMonsters()
{
	return &monsters;
}

void MonsterManager::Update(const float& deltaTime)
{
	for (auto& monster : monsters)
	{
		monster->Update(deltaTime);
	}
}

void MonsterManager::Update(const Vector2f& mousePosition)
{
	for (auto& monster : monsters)
	{
		monster->Update(mousePosition);
	}
}

void MonsterManager::UpdateWithBullet(BulletManager* bulletMgr)
{
	for (auto& bullet : *bulletMgr->GetBullets())
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
}

void MonsterManager::UpdateWithObject(Object* object)
{
	for (auto& monster : monsters)
	{
		monster->ChasingUpdate(object);
	}
}

void MonsterManager::Render(RenderTarget* target)
{
	for (auto& monster : monsters)
	{
		monster->Render(target);
	}
}
