#pragma once
#include "Object.h"
class AnimationObject : public Object
{
public:

	AnimationObject() = default;
	AnimationObject(const AnimationObject&) = delete;
	AnimationObject& operator=(const AnimationObject&) = delete;
	virtual ~AnimationObject() = default;

protected:

	vector<Texture*> vAnimation;
	float frameTime = 0.2f;
	unsigned int keyFrame = 0;

private:

	virtual void Init();

public:

	virtual void Destroy();

	void SetAnimation(vector<Texture*>* animation, float frameTime = 0.2f);

	const unsigned int& GetKeyFrame();
	void SetKeyFrame(unsigned int& frame);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

