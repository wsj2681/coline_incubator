#pragma once
#include "AnimationObject.h"

class Charactor : public AnimationObject
{
public:
	Charactor();
	virtual ~Charactor();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

