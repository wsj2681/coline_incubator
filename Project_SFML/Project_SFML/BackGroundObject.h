#pragma once
#include "Object.h"
class BackGroundObject : public Object
{
public:
	BackGroundObject();
	BackGroundObject(const string& filePath);
	~BackGroundObject();

protected:

	Texture* backGroundTexture = nullptr;

private:
	
	virtual void Init();
	virtual void Init(const string& filePath);
public:

	virtual void Destroy();
	virtual void Update(const float& deltaTime);

};

