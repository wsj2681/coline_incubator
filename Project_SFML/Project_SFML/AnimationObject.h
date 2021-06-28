#pragma once
#include "Object.h"
class AnimationObject : public Object
{
public:

	AnimationObject();
	virtual ~AnimationObject();


private:

	vector<Texture*> vAnimation;
	size_t keyFrame = 0;

	float elapsedTime = 0.f;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

