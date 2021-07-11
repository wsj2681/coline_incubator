#pragma once
#include "Object.h"
class AnimationObject : public Object
{
public:

	AnimationObject() = default;
	AnimationObject(const AnimationObject&) = delete;
	AnimationObject& operator=(const AnimationObject&) = delete;
	virtual ~AnimationObject() = default;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

