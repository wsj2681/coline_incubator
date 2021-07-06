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

void Object::Update(const Vector2f& mousePosition)
{
}
