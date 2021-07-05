#pragma once
#include "AnimationObject.h"

class Charactor : public AnimationObject
{
public:
	Charactor();
	virtual ~Charactor();

private:

	Vector2f position{ 0.f, 0.f };
	Vector2f velocity{ 0.f, 0.f };
	Vector2f acceleration{ 0.f, 0.f };

	float gravity = 2.f;

private:

	virtual void Init();

public:

	virtual void Destroy();

	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};

