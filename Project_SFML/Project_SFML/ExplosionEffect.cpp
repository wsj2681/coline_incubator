#include "framework.h"
#include "ExplosionEffect.h"

ExplosionEffect::ExplosionEffect()
{
	Init();
}

ExplosionEffect::~ExplosionEffect()
{
}

void ExplosionEffect::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 0; i < 32; ++i)
	{
		if (i < 10)
		{
			sprintf(filePath, "Texture/Explosion/tile00%d.png", i);
		}
		else
		{
			sprintf(filePath, "Texture/Explosion/tile0%d.png", i);
		}

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	this->setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
	setPosition(Vector2f(250.f, 250.f));
}

void ExplosionEffect::Destroy()
{
	AnimationObject::Destroy();
}

void ExplosionEffect::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
