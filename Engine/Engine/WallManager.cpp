#include "framework.h"
#include "WallManager.h"
#include "JumpObject.h"
#include "Bullet.h"

WallManager::WallManager(const size_t& WallCount)
{
	for (auto i = 0; i < WallCount; ++i)
	{
		walls.push_back(new WallObject("Textures/Object/wall3.png"));
	}
}

void WallManager::Destroy()
{
	for (auto& i : walls)
	{
		i->Destroy();
	}
}

void WallManager::SetWall(WallObject* object)
{
	if (object)
	{
		walls.push_back(object);
	}
}

vector<WallObject*>* WallManager::GetWalls()
{
	return &walls;
}

void WallManager::Update(const float& deltaTime)
{
	for (auto& i : walls)
	{
		i->Update(deltaTime);
	}
}

void WallManager::Update(const Vector2f& mousePosition)
{
	for (auto& i : walls)
	{
		i->Update(mousePosition);
	}
}

void WallManager::CollisionUpdate(Object* object)
{
	for (auto& wall : walls)
	{
		if (object && object->IsActive())
		{
			// Object == Bullet
			if (dynamic_cast<Bullet*>(object))
			{	
				if (dynamic_cast<Bullet*>(object)->getGlobalBounds().intersects(wall->getGlobalBounds()))
				{
					object->SetActive(false);
					object->setPosition({});
				}
			}
			else if (dynamic_cast<JumpObject*>(object))
			{
				Vector2f dir = dynamic_cast<JumpObject*>(object)->GetDirection();
				if (dir.x != 0.f || dir.y != 0.f)
				{
					if (wall->getGlobalBounds().intersects(object->getGlobalBounds()))
					{
						dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
					}
				}
			}

		}
	}
}

void WallManager::Render(RenderTarget* target)
{
	for (auto& i : walls)
	{
		i->Render(target);
	}
}
