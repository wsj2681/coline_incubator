#include "framework.h"
#include "ItemObject.h"

ItemObject::ItemObject()
{
	Init();
}

ItemObject::~ItemObject()
{
}

void ItemObject::Init()
{
	Texture* tx = nullptr;

	char filePath[50];

	for (int i = 8; i < 10; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_000%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	this->setTexture(*vAnimation.front());
	this->setOrigin(getTexture()->getSize().x / 2.f, getTexture()->getSize().y / 2.f);
}

void ItemObject::Destroy()
{
}

void ItemObject::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
