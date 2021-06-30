#pragma once
#include "AnimationObject.h"
class Effect : public AnimationObject
{
public:
	Effect();
	virtual ~Effect();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

