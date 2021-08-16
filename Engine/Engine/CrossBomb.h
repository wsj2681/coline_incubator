#pragma once
#include "AnimationObject.h"

typedef pair<AnimationObject*, AnimationObject*> pairObject;

class CrossBomb : public AnimationObject
{
public:

	CrossBomb();
	CrossBomb(const CrossBomb&) = delete;
	CrossBomb& operator=(const CrossBomb&) = delete;
	virtual ~CrossBomb() = default;

private:

	vector<Texture*> bombAnimation;
	float lifeTime = 3.f;

	map<string, pairObject*> bombLeafObjects;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

