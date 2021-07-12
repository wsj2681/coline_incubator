#include "framework.h"
#include "Object.h"

bool Object::IsActive()
{
	return isActive;
}

void Object::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool Object::GetHitBoxActive()
{
	return hitBoxActive;
}

void Object::SetHitBoxActive(bool active)
{
	hitBoxActive = active;
}

const Vertex* Object::GetHitBox()
{
	return hitBox;
}

void Object::UpdateHitBox()
{
	if (this->hitBoxActive)
	{
		hitBox[0] = Vertex(Vector2f(getGlobalBounds().left, getGlobalBounds().top), Color::Blue);
		hitBox[1] = Vertex(Vector2f(getGlobalBounds().left + getGlobalBounds().width, getGlobalBounds().top), Color::Blue);
		hitBox[2] = Vertex(Vector2f(getGlobalBounds().left + getGlobalBounds().width, getGlobalBounds().top + getGlobalBounds().height), Color::Blue);
		hitBox[3] = Vertex(Vector2f(getGlobalBounds().left, getGlobalBounds().top + getGlobalBounds().height), Color::Blue);
		hitBox[4] = hitBox[0];
	}
}

void Object::Update(const Vector2f& mousePosition)
{
}
