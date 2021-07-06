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

	stateAnimation.insert({ RUN, runAnimation });
	stateAnimation[DASH] = dashAnimation;
	stateAnimation[SLIDE] = slideAnimation;
	stateAnimation[SKILL] = skillAnimation;

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
		// -10 -> -8 -> -6 ...
		// 위로 점프하기 위한 행동
		velocity.y += gravity;
	}
	else if (position.y > 200.f)
	{
		// 바닥으로 꺼지는 것을 막기위한 행동
		position.y = 200.f;
	}

	velocity += acceleration;

	position += velocity;

	setPosition(position);
}

void Charactor::Jump()
{
	velocity.y = -10.f;
}

void Charactor::Update(const float& deltaTime)
{
	MoveUpdate();

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = DASH;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		state = SLIDE;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		keyFrame = 0;
		state = SKILL;
	}


	elapsedTime += deltaTime;

	if (elapsedTime > 0.05f)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == state)
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first == SKILL)
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
