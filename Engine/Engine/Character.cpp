#include "framework.h"
#include "Character.h"

Character::Character(int characterClass)
{
	string filePath;
	string fileType = { ".png" };

	switch (characterClass)
	{
	case WARRIOR_MALE:
	{
		filePath = { "Textures/Character/Warrior_Male/" };
		break;
	}
	case WARRIOR_FEMALE:
	{
		filePath = { "Textures/Character/Warrior_Female/" };
		break;
	}
	}

	Texture* texture = nullptr;

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "Down0" + to_string(i) + fileType);
		this->downAnimation.push_back(texture);
	}

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "Up0" + to_string(i) + fileType);
		this->upAnimation.push_back(texture);
	}

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "Right0" + to_string(i) + fileType);
		this->rightAnimation.push_back(texture);
	}

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "Left0" + to_string(i) + fileType);
		this->leftAnimation.push_back(texture);
	}

	weapon = new Weapon(1);

	Init();
}

void Character::Init()
{

	stateAnimation[MOVE_DOWN] = &downAnimation;
	stateAnimation[MOVE_UP] = &upAnimation;
	stateAnimation[MOVE_RIGHT] = &rightAnimation;
	stateAnimation[MOVE_LEFT] = &leftAnimation;

	setTexture(*downAnimation.data()[1]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	setPosition(250.f, 250.f);
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		characterState = MOVE_UP;
		move({ 0.f, -1.f });
		weapon->setPosition(getGlobalBounds().left + getGlobalBounds().width / 2.f, getGlobalBounds().top + 5.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		characterState = MOVE_DOWN;
		move({ 0.f, 1.f });
		weapon->setPosition(getGlobalBounds().left + getGlobalBounds().width / 2.f, getGlobalBounds().top + getGlobalBounds().height - 5.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		characterState = MOVE_RIGHT;
		move({ 1.f, 0.f });
		weapon->setPosition(getGlobalBounds().left + getGlobalBounds().width - 5.f, getGlobalBounds().top + getGlobalBounds().height / 2.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		characterState = MOVE_LEFT;
		move({ -1.f, 0.f });
		weapon->setPosition(getGlobalBounds().left + 5.f, getGlobalBounds().top + getGlobalBounds().height / 2.f);
	}
	else
	{
		characterState = IDLE;
	}
	if (elapsedTime >= frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == characterState)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				oldState = animation.first;
			}
			else if (characterState == IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}


}

void Character::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);

	if (weapon)
	{
		weapon->Update(mousePosition);
	}
}

void Character::Attack()
{
}

void Character::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
	weapon->Render(target);
	target->draw(*this);
}
