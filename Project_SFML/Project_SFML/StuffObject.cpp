#include "framework.h"
#include "StuffObject.h"

StuffObject::StuffObject()
{
	Init();
}

StuffObject::StuffObject(const string& filePath, const Vector2f& position)
{
	Init(filePath, position);
}

StuffObject::~StuffObject()
{
}

void StuffObject::Init()
{
}

void StuffObject::Init(const string& filePath, const Vector2f& position)
{
	setPosition(position);
	texture = new Texture;
	texture->loadFromFile(filePath);
	setTexture(*texture);
	setOrigin(texture->getSize().x / 2.f, texture->getSize().y / 2.f);
}

void StuffObject::Destroy()
{
}

void StuffObject::Update(const float& deltaTime)
{
}

void StuffObject::Update(const Vector2f& mousePosition)
{
}
