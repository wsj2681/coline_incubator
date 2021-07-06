#pragma once
class Object : public Sprite
{
public:
	Object() = default;
	virtual ~Object() = default;

private:

	bool isActive = true;

private:

	virtual void Init() = 0;

public:

	bool IsActive();
	void SetActive(bool isActive);

	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Update(const Vector2f& mousePosition);
};

