#pragma once
#include "AnimationObject.h"
class ItemObject :
    public AnimationObject
{
public:

	ItemObject();
	virtual ~ItemObject();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

