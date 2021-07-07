#pragma once
#include "Object.h"
class StuffObject :public Object
{
public:
	StuffObject();
	StuffObject(const string& filePath, const Vector2f& position);
	virtual ~StuffObject();

private:

	Texture* texture = nullptr;
	float speed = 1000.f;
	int type = -1;

private:
	virtual void Init();
	virtual void Init(const string& filePath, const Vector2f& position);

public:

	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
};

