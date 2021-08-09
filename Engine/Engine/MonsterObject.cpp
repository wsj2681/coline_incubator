#include "framework.h"
#include "MonsterObject.h"

MonsterObject::MonsterObject()
{
}

MonsterObject::MonsterObject(const string& textureFilePath)
	:Object(textureFilePath)
{
	Init();
}

MonsterObject::MonsterObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	Init();
}

MonsterObject::~MonsterObject()
{
}

void MonsterObject::Init()
{
	hpBar = new Object("Textures/HUD/hpBar.png");
	HP = 48;
	dir = Vector2f(Math::RandomIntager(-1, 1), Math::RandomIntager(-1, 1));
}

void MonsterObject::Destroy()
{
	Object::Destroy();
}

int MonsterObject::GetHp()
{
	return HP;
}

void MonsterObject::SetHp(const int& Hp)
{
	this->HP = Hp;

	// Àý´ñ°ª
	if (abs(HP) >= 48)
	{
		HP = 48;
	}
}

void MonsterObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);

	if (!(getPosition().x <= 1080 && getPosition().x >= 0 &&
		getPosition().y <= 720 && getPosition().y >= 0))
	{
		setPosition(Math::RandomIntager(0, 1080), Math::RandomIntager(0, 720));
	}

	if (hpBar && HP)
	{
		hpBar->Update(deltaTime);
		hpBar->setTextureRect({ 0, 0, HP, hpBar->getTextureRect().height });
		hpBar->setPosition(this->getPosition().x, this->getPosition().y - 24);
	}
	else
	{
		this->isActive = false;
	}

	move(dir * deltaTime * speed);

}

void MonsterObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void MonsterObject::Render(RenderTarget* target)
{
	Object::Render(target);

	if (hpBar && isActive)
	{
		hpBar->Render(target);
	}

}
