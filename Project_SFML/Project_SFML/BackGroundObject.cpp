#include "framework.h"
#include "BackGroundObject.h"

BackGroundObject::BackGroundObject()
{
}

BackGroundObject::BackGroundObject(const string& filePath)
{
	Init(filePath);
}

BackGroundObject::~BackGroundObject()
{
}

void BackGroundObject::Init()
{

}

void BackGroundObject::Init(const string& filePath)
{
	backGroundTexture = new Texture;
	backGroundTexture->setSmooth(true);
	backGroundTexture->loadFromFile(filePath);
	setTexture(*backGroundTexture);
}

void BackGroundObject::Destroy()
{
}

void BackGroundObject::Update(const float& deltaTime)
{
	
}
