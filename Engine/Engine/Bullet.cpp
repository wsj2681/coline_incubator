#include "framework.h"
#include "Bullet.h"

Bullet::Bullet(const string& textureFilePath)
	:Object(textureFilePath)
{
}

void Bullet::Destroy()
{
	Object::Destroy();
}

void Bullet::SetDirection(const Vector2f& dir)
{
	this->dir = dir;
}

void Bullet::SetSpeed(const float& speed)
{
	this->speed = speed;
}


void Bullet::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	lifeTime -= deltaTime;

	if (lifeTime <= 0.f)
	{
		SetActive(false);
		lifeTime = 2.f;
	}

	if (isActive)
	{
		move(dir * speed * deltaTime);
	}
}

void Bullet::Update(const Vector2f& mousePosition)
{
}

void Bullet::Render(RenderTarget* target)
{
	Object::Render(target);
}
