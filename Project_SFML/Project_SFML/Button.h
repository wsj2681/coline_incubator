#pragma once
#include "Object.h"
class Button : public Object
{
public:
	Button();
	~Button();

private:

	


private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

