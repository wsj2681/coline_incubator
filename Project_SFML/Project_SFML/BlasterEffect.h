#pragma once
#include "Effect.h"
class BlasterEffect : public Effect
{
public:
	BlasterEffect();
	virtual ~BlasterEffect();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

