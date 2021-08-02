#include "framework.h"
#include "BulletManager.h"

BulletManager::BulletManager(const size_t& bulletCount)
{
	for (auto i = 0; i < bulletCount; ++i)
	{
		bullets.push_back(new Bullet("Textures/Object/Bullet.png"));
	}

	for (auto& bullet : bullets)
	{
		bullet->SetActive(false);
	}

}

void BulletManager::Destroy()
{
	for (auto& bullet : bullets)
	{
		bullet->Destroy();
	}
}

void BulletManager::Shoot(const Vector2f& dir, const Vector2f& position, const float& speed)
{
	for (auto& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->SetActive(true);
			bullet->SetDirection(dir);
			bullet->setPosition(position);
			bullet->SetSpeed(speed);
			break;
		}
		else
		{
			continue;
		}
	}
}

vector<Bullet*>* BulletManager::GetBullets()
{
	return &bullets;
}

void BulletManager::Update(const float& deltaTime)
{
	for (auto& bullet : bullets)
	{
		if (bullet->IsActive())
		{
			bullet->Update(deltaTime);
		}
	}
}

void BulletManager::Update(const Vector2f& mousePosition)
{
	for (auto& bullet : bullets)
	{
		bullet->Update(mousePosition);
	}
}

void BulletManager::Render(RenderTarget* target)
{
	for (auto& bullet : bullets)
	{
		bullet->Render(target);
	}
}
