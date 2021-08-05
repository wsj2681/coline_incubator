#include "framework.h"
#include "BombObject.h"
#include "EffectObject.h"

BombObject::BombObject(const string& textureFilePath)
	:Object(textureFilePath)
{

	setScale(0.1f, 0.1f);
	bombEffect = new EffectObject();
	bombEffect->setScale(0.3f, 0.3f);
}

void BombObject::Destroy()
{
	Object::Destroy();
}

void BombObject::SetBomb(const Vector2f& mousePosition)
{
	setPosition(mousePosition);
	this->isActive = true;
	lifeTime = 3.f;
}

void BombObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	
	bombEffect->setPosition(this->getPosition());
	bombEffect->Update(deltaTime);

	if (this->isActive)
	{
		lifeTime -= deltaTime;
		bombEffect->SetActive(false);
	}

	if (lifeTime <= 0.f)
	{
		this->isActive = false;
		bombEffect->Start();
		lifeTime = 3.f;
	}

}

void BombObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void BombObject::Render(RenderTarget* target)
{
	Object::Render(target);

	bombEffect->Render(target);
}
