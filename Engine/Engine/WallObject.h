#pragma once
#include "Object.h"
class WallObject : public Object
{
public:
	WallObject() = delete;
	WallObject(const string& textureFilePath);
	WallObject(const string& textureFilePath, const Vector2f& position);
	WallObject(const WallObject&) = delete;
	WallObject& operator=(const WallObject&) = delete;
	~WallObject() = default;

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

