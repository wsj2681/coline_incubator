#pragma once
#include "AnimationObject.h"

enum CHARATOR_STATE
{
	// IDLE
	RUN,
	DASH,
	SLIDE,
	SKILL
};

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

	vector<Texture*> runAnimation;
	vector<Texture*> dashAnimation;
	vector<Texture*> slideAnimation;
	vector<Texture*> skillAnimation;

	int state = RUN;

	map<int, vector<Texture*>> stateAnimation;

private:

	virtual void Init();

public:

	virtual void Destroy();
	void Jump();
	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};

