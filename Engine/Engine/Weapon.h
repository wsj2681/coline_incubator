#pragma once
#include "Object.h"
class Weapon : public Object
{
public:
	Weapon() = default;
	Weapon(int weaponLevel);
	Weapon(const Weapon&) = delete;
	Weapon& operator=(const Weapon&) = delete;
	virtual ~Weapon() = default;
private:

	map<int, Texture*> levelforWeapon;

	int level = 1;

public:

	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Attack();
	virtual void Render(RenderTarget* target);

};

