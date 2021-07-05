#include "framework.h"
#include "Charactor.h"

Charactor::Charactor()
{
	Init();
}

Charactor::~Charactor()
{
}

void Charactor::Init()
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

	setPosition(Vector2f(100.f, 100.f));
}

void Charactor::Destroy()
{
	AnimationObject::Destroy();
}

void Charactor::MoveUpdate()
{
	if (position.y < 200.f)
	{
		velocity.y += gravity;
	}
	else if (position.y > 200.f)
	{
		position.y = 200.f;
	}

	velocity += acceleration;

	position += velocity;
}

void Charactor::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		velocity.y = -10;
	}
	MoveUpdate();
	setPosition(position);
	AnimationObject::Update(deltaTime);
}
