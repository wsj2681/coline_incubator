#include "framework.h"
#include "BombManager.h"
#include "MonsterObject.h"

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

vector<BombObject*>* BombManager::GetBombs()
{
	return &bombs;
}

void BombManager::DamageBoom(Object* object)
{
	for (auto& bomb : bombs)
	{
		if (object && bomb->GetBoomArea().intersects(object->getGlobalBounds()) && bomb->IsDamaging())
		{
			if (dynamic_cast<MonsterObject*>(object))
			{
				// �ð����� ����־ - 1 X -> 56
				dynamic_cast<MonsterObject*>(object)->SetHp(dynamic_cast<MonsterObject*>(object)->GetHp() - 1);
			}
			else
			{
				cout << "�ٸ� ������Ʈ�� �������� �Ծ����ϴ�.\n";
			}
		}
	}
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
