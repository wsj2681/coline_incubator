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
	targetPosition = Vector2f(Math::RandomIntager(0, 1080), Math::RandomIntager(0, 720));
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
}

void MonsterObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void MonsterObject::ChasingUpdate(Object* object)
{
	float distance = Math::Length(object->getPosition(), this->getPosition());
	float targetDistance = Math::Length(targetPosition, this->getPosition());
	Vector2f direction;

	if (distance <= 100)
	{
		oldState = state;
		state = CHASING;
	}
	else
	{
		oldState = state;
		state = IDLE;
	}

	if (oldState != state || targetDistance <= 5)
	{
		targetPosition = Vector2f(Math::RandomIntager(0, 1080), Math::RandomIntager(0, 720));
	}


	switch (state)
	{
	case IDLE:
	{
		direction = Math::Normalize(targetPosition, this->getPosition());
		this->move(direction);
		break;
	}
	case CHASING:
	{
		direction = Math::Normalize(object->getPosition(), this->getPosition());
		this->move(direction);

		if (this->getGlobalBounds().intersects(object->getGlobalBounds()))
		{
			cout << "player HP ±ðÀÌ´ÂÁß\n";
		}

		break;
	}
	default:
		break;
	}

}

void MonsterObject::Render(RenderTarget* target)
{
	Object::Render(target);

	if (hpBar && isActive)
	{
		hpBar->Render(target);
	}

}
