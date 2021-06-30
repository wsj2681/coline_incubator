#include "framework.h"
#include "BlueEffect.h"

BlueEffect::BlueEffect()
{
	Init();
}

BlueEffect::~BlueEffect()
{
}

void BlueEffect::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 0; i < 25; ++i)
	{
		if (i < 10)
		{
			sprintf(filePath, "Texture/Effect/tile00%d.png", i);
		}
		else
		{
			sprintf(filePath, "Texture/Effect/tile0%d.png", i);
		}
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
}

void BlueEffect::Destroy()
{
	Effect::Destroy();
}

void BlueEffect::Update(const float& deltaTime)
{
	Effect::Update(deltaTime);
}
