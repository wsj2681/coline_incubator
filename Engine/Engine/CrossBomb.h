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
	vector<Texture*> boomAnimation;
	bool isLive = true;

	float lifeTime = 3.f;

	map<string, pairObject*> bombLeafObjects;
	bool bombLeafAnimation = false;

private:

	virtual void Init();

public:

	virtual void Destroy();

	void SetBomb(const Vector2f& position);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

