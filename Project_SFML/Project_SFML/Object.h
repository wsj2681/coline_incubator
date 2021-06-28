#pragma once
class Object : public Sprite
{
public:
	Object() = default;
	virtual ~Object() = default;


private:

	virtual void Init() = 0;

public:

	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;

};

