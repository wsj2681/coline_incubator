#include "framework.h"
#include "EffectObject.h"

EffectObject::EffectObject()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 1; i < 32; ++i)
	{
		if (i < 10)
		{
			sprintf(filePath, "Textures/bombEffect/tile00%d.png", i);
		}
		else
		{
			sprintf(filePath, "Textures/bombEffect/tile0%d.png", i);
		}
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->effectAnimation.push_back(tx);
	}
	setTexture(*effectAnimation.data()[0]);

	setOrigin(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f);
	frameTime = 0.1;
	isActive = false;
}

void EffectObject::Destroy()
{
	AnimationObject::Destroy();
}

void EffectObject::Start()
{
	isActive = true;
	keyFrame = 0;
}

void EffectObject::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;

	if (isActive)
	{
		if (elapsedTime >= frameTime)
		{
			setTexture(*effectAnimation.data()[keyFrame % effectAnimation.size()]);

			++keyFrame;
			elapsedTime = 0.f;

			if (keyFrame % effectAnimation.size() == effectAnimation.size() - 1)
			{
				isActive = false;
			}
		}
	}
}

void EffectObject::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);
}

void EffectObject::Render(RenderTarget* Render)
{
	AnimationObject::Render(Render);
}
