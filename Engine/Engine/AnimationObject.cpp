#include "framework.h"
#include "AnimationObject.h"

void AnimationObject::Init()
{
}

void AnimationObject::Destroy()
{
	Object::Destroy();
}

void AnimationObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
}

void AnimationObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void AnimationObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
