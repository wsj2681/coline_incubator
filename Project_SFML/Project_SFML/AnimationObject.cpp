#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

AnimationObject::~AnimationObject()
{
}

void AnimationObject::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 32; i < 36; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_00%d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

}

void AnimationObject::Destroy()
{
}

void AnimationObject::Update(const float& deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime > 0.2f)
	{
		setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
		++keyFrame;
		elapsedTime = 0.f;
	}
}
