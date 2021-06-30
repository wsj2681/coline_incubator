#pragma once
#include "Effect.h"
class BlueEffect : public Effect
{
public:
	BlueEffect();
	virtual ~BlueEffect();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

