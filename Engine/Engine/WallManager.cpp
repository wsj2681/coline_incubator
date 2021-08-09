#include "framework.h"
#include "WallManager.h"
#include "JumpObject.h"

WallManager::WallManager(const size_t& WallCount)
{

}

void WallManager::Destroy()
{
	for (auto& i : walls)
	{
		i->Destroy();
	}
}

void WallManager::SetWall(const Vector2f& position)
{
	for (auto& i : walls)
	{
		if (!i->IsActive())
		{
			i->setPosition(position);
		}
	}
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

void WallManager::Update(const float& deltaTime, Object* object)
{
	for (auto& i : walls)
	{
		if (object && i)
		{
			if (object->getGlobalBounds().intersects(i->getGlobalBounds()))
			{
				if (dynamic_cast<JumpObject*>(object))
				{
				
				}
				else
				{

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
