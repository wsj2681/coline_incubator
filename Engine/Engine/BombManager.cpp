#include "framework.h"
#include "BombManager.h"

BombManager::BombManager(const size_t& bombCount)
{
	for (auto i = 0; i < bombCount; ++i)
	{
		this->bombs.push_back(new BombObject("Textures/Object/bomb.png"));
	}

	for (auto& bomb : bombs)
	{
		bomb->SetActive(false);
	}
}

void BombManager::Destroy()
{
	for (auto& bomb : bombs)
	{
		bomb->Destroy();
	}
}

void BombManager::SetBomb(const Vector2f& position)
{
	for (auto& bomb : bombs)
	{
		if (!bomb->IsActive())
		{
			bomb->SetBomb(position);
			break;
		}
		else
		{
			continue;
		}
	}
}

vector<BombObject*>* BombManager::GetBullets()
{
	return &bombs;
}

void BombManager::Update(const float& deltaTime)
{
	for (auto& bomb : bombs)
	{
		bomb->Update(deltaTime);
	}
}

void BombManager::Update(const Vector2f& mousePosition)
{
	for (auto& bomb : bombs)
	{
		bomb->Update(mousePosition);
	}
}

void BombManager::Render(RenderTarget* target)
{
	for (auto& bomb : bombs)
	{
		bomb->Render(target);
	}
}
