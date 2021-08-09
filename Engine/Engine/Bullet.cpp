#include "framework.h"
#include "Bullet.h"

Bullet::Bullet(const string& textureFilePath)
	:Object(textureFilePath)
{
	setScale(0.2f, 0.2f);
}

void Bullet::Destroy()
{
	Object::Destroy();
}

void Bullet::SetDirection(const Vector2f& dir)
{
	this->dir = dir;
	this->setRotation(Math::RotateAxis(dir, 90.f));
}

void Bullet::SetSpeed(const float& speed)
{
	this->speed = speed;
}

const int Bullet::GetBulletType()
{
	return this->bulletType;
}


void Bullet::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	lifeTime -= deltaTime;

	if (lifeTime <= 0.f)
	{
		SetActive(false);
	}

	if (!IsActive())
	{
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
