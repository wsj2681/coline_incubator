#include "framework.h"
#include "BlasterEffect.h"

BlasterEffect::BlasterEffect()
{
	Init();
}

BlasterEffect::~BlasterEffect()
{
}

void BlasterEffect::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 0; i < 9; ++i)
	{
		if (i < 10)
		{
			sprintf(filePath, "Texture/BlasterEffect/tile00%d.png", i);
		}
		else
		{
			sprintf(filePath, "Texture/BlasterEffect/tile0%d.png", i);
		}
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	setPosition(Vector2f(270.f, 0.f));
}

void BlasterEffect::Destroy()
{
	Effect::Destroy();
}

void BlasterEffect::Update(const float& deltaTime)
{
	Effect::Update(deltaTime);
}
