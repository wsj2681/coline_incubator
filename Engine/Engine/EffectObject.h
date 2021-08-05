#pragma once
#include "AnimationObject.h"

class EffectObject : public AnimationObject
{
public:
	EffectObject();
	EffectObject(const EffectObject&) = delete;
	EffectObject& operator=(const EffectObject&) = delete;
	virtual ~EffectObject() = default;

private:

	vector<Texture*> effectAnimation;

public:
	virtual void Destroy();

	void Start();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

