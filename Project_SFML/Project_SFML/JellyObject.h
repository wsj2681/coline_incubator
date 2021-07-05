#pragma once
#include "Object.h"

enum Jelly_Type
{
	Orange,
	Pupple,
	Green
};

class JellyObject : public Object
{
public:

	JellyObject();
	JellyObject(int type = 0);
	virtual ~JellyObject();

private:

	Texture* texture = nullptr;
	
	int type = -1;

private:

	virtual void Init();

public:

	virtual void Destroy();
	virtual void Update(const float& deltaTime);

};

