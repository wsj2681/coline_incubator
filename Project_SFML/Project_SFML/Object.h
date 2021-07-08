#pragma once
class Object : public Sprite
{
public:
	Object() = default;
	virtual ~Object() = default;

private:

	bool isActive = true;
	bool hitBoxActive = true;

	Vertex hitBox[5];

private:

	virtual void Init() = 0;

public:

	bool IsActive();
	void SetActive(bool isActive);

	bool GetHitBoxActive();
	void SetHitBoxActive(bool active);
	
	const Vertex* GetHitBox();
	void UpdateHitBox();

	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Update(const Vector2f& mousePosition);
	
};

