#pragma once
#include "AnimationObject.h"
#include "Weapon.h"

enum CHARACTER_STATE
{
	MOVE_IDLE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT
};

enum CHARACTER_CLASS
{
	WARRIOR_MALE,
	WARRIOR_FEMALE
};

class Character : public AnimationObject
{
public:
	Character(int characterClass = WARRIOR_MALE);
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;
	virtual ~Character() = default;

protected:

	vector<Texture*> downAnimation;
	vector<Texture*> upAnimation;
	vector<Texture*> leftAnimation;
	vector<Texture*> rightAnimation;

	map<int, vector<Texture*>*> stateAnimation;

	float speed = 10.f;

	int characterClass = WARRIOR_MALE;
	int characterState = MOVE_IDLE;
	int oldState = MOVE_DOWN;

	Weapon* weapon = nullptr;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Attack();
	virtual void Render(RenderTarget* target);
};

