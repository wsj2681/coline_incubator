#include "framework.h"
#include "Charactor.h"
#define FLOOR_Y 500.f

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
	for (int i = 1; i < 8; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_000%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->doubleJumpAnimation.push_back(tx);
	}

	for (int i = 8; i < 10; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_000%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->jumpAnimation.push_back(tx);
	}

	for (int i = 10; i < 14; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_00%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->slideAnimation.push_back(tx);
	}

	for (int i = 32; i < 36; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_00%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runAnimation.push_back(tx);
	}

	for (int i = 36; i < 40; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_00%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->dashAnimation.push_back(tx);
	}

	for (int i = 136; i < 155; ++i)
	{
		sprintf(filePath, "Texture/cookie0020x2/cookie0020x2_0%d.png", i);

		tx = new Texture;
		tx->loadFromFile(filePath);
		this->skillAnimation.push_back(tx);
	}

	stateAnimation[RUN] = runAnimation;
	stateAnimation[DASH] = dashAnimation;
	stateAnimation[SLIDE] = slideAnimation;
	stateAnimation[SKILL] = skillAnimation;
	stateAnimation[JUMP] = jumpAnimation;
	stateAnimation[DOUBLEJUMP] = doubleJumpAnimation;

	setPosition(Vector2f(100.f, 100.f));
	setTexture(*runAnimation.data()[0]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
}

void Charactor::Destroy()
{
	AnimationObject::Destroy();
}

void Charactor::MoveUpdate(const float& deltaTime)
{
	if (position.y < FLOOR_Y)
	{
		// -10 -> -8 -> -6 ...
		// 위로 점프하기 위한 행동
		velocity.y += gravity * speed * deltaTime;
	}
	else if (position.y > FLOOR_Y)
	{
		// 바닥으로 꺼지는 것을 막기위한 행동
		position.y = FLOOR_Y;
	}

	velocity += acceleration * speed * deltaTime;

	position += velocity;

	setPosition(position);
}

void Charactor::Jump()
{
	if (--jumpCount > 0)
	{
		velocity.y = -20.f;
	}
}

void Charactor::SetState(const int& state)
{
	this->state = state;
}

int Charactor::GetState()
{
	return this->state;
}

void Charactor::Update(const float& deltaTime)
{
	MoveUpdate(deltaTime);
	static int count = 0;
	if (position.y < FLOOR_Y - 30.f)
	{
		state = JUMP;
	}
	else
	{
		jumpCount = 2;
	}
	cout << "JumpCount = " << jumpCount << endl;

	if (state == JUMP && jumpCount != 2)
	{
		state = DOUBLEJUMP;
	}

	elapsedTime += deltaTime;

	if (state != DOUBLEJUMP)
	{
		frameTime = 0.05f;
	}
	else
	{
		frameTime = 0.02f;
	}

	if (elapsedTime > frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == state)
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first != RUN)
				{
					if (keyFrame % animation.second.size() >= animation.second.size() - 1)
					{
						state = RUN;
					}
				}
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}
