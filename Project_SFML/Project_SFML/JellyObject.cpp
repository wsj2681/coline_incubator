#include "framework.h"
#include "JellyObject.h"

JellyObject::JellyObject()
{
	Init();
}

JellyObject::JellyObject(int type)
	:type(type)
{
	Init();
}

JellyObject::~JellyObject()
{
}

void JellyObject::Init()
{
	texture = new Texture;
	switch (type)
	{
	case Orange:
	{
		texture->loadFromFile("Texture/Jellys/basic_jelly.png");
		break;
	}
	case Pupple:
	{
		texture->loadFromFile("Texture/Jellys/basic_jelly2.png");
		break;
	}
	case Green:
	{
		texture->loadFromFile("Texture/Jellys/basic_jelly3.png");
		break;
	}
	default:
		break;
	}

	setTexture(*texture);
}

void JellyObject::Destroy()
{
}

void JellyObject::Update(const float& deltaTime)
{
	setPosition(getPosition().x - 1.f * speed * deltaTime, getPosition().y);
}

void JellyObject::Update(const Vector2f& mousePosition)
{
	if (getGlobalBounds().contains(mousePosition))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->SetActive(false);
		}
	}
}
