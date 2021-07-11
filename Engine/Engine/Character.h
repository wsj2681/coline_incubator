#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
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

	float frameTime = 0.2f;
	unsigned int keyFrame = 0;
	float speed = 10.f;

	int characterClass = WARRIOR_MALE;
	int characterState = IDLE;
	int oldState = MOVE_DOWN;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

