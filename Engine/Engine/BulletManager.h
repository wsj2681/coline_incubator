#pragma once

#include "Bullet.h"

class BulletManager final
{
public:
	BulletManager(const size_t& bulletCount = 10);
	BulletManager(const BulletManager&) = delete;
	BulletManager& operator=(const BulletManager&) = delete;
	~BulletManager() = default;

private:

	vector<Bullet*> bullets;

public:

	void Destroy();

	void Shoot(const Vector2f& dir, const Vector2f& position, const float& speed);

	void Update(const float& deltaTime);

	void Update(const Vector2f& mousePosition);

	void Render(RenderTarget* target);

};

