#pragma once
#include "AnimationObject.h"

enum CHARATOR_STATE
{
	// IDLE
	RUN,
	DASH,
	JUMP,
	SLIDE,
	SKILL,
};

class Charactor : public AnimationObject
{
public:
	Charactor();
	virtual ~Charactor();

private:

	Vector2f position{ 200.f, 0.f };
	Vector2f velocity{ 0.f, 0.f };
	Vector2f acceleration{ 0.f, 0.f };
	float speed = 50.f;
	float gravity = 2.f;

	vector<Texture*> runAnimation;
	vector<Texture*> dashAnimation;
	vector<Texture*> jumpAnimation;
	vector<Texture*> slideAnimation;
	vector<Texture*> skillAnimation;
	int state = RUN;

	map<int, vector<Texture*>> stateAnimation;



private:

	virtual void Init();

public:

	virtual void Destroy();
	void Jump();
	void MoveUpdate(const float& deltaTime);
	void SetState(const int& state);
	virtual void Update(const float& deltaTime);
};

