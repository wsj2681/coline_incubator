#pragma once
#include "Effect.h"
class ExplosionEffect : public Effect
{
public:
	ExplosionEffect();
	virtual ~ExplosionEffect();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

