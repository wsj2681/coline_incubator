#include "framework.h"
#include "Weapon.h"

Weapon::Weapon(int weaponLevel)
	:level(weaponLevel)
{

	string filePath = {"Textures/Sword/"};
	string fileType = { ".png" };

	for (int i = 0; i < 24; ++i)
	{
			levelforWeapon[i + 1] = new Texture;
		if (i < 10)
		{
			levelforWeapon[i + 1]->loadFromFile(filePath + "tile00" + to_string(i) + fileType);
		}
		else
		{
			levelforWeapon[i + 1]->loadFromFile(filePath + "tile0" + to_string(i) + fileType);
		}
	}

	this->setTexture(*levelforWeapon[weaponLevel]);
	this->setOrigin(getGlobalBounds().left, getGlobalBounds().height);
	this->setScale(0.5f, 0.5f);
}

void Weapon::Destroy()
{
	Object::Destroy();
}

void Weapon::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
}

void Weapon::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
	float rotation = Math::RotateAxis(getPosition(), mousePosition, 45.f + 180.f);
	setRotation(rotation);
}

void Weapon::Attack()
{
}

void Weapon::Render(RenderTarget* target)
{
	Object::Render(target);
}
