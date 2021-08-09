#include "framework.h"
#include "WallObject.h"

WallObject::WallObject(const string& textureFilePath)
	:Object(textureFilePath)
{
}

WallObject::WallObject(const string& textureFilePath, const Vector2f& position)
	:Object(textureFilePath, position)
{
}

void WallObject::Destroy()
{
	Object::Destroy();
}

void WallObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
}

void WallObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void WallObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
