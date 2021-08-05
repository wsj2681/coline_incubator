#pragma once

#include "BombObject.h"

class BombManager final
{
public:
	BombManager(const size_t& bombCount = 10);
	BombManager(const BombManager&) = delete;
	BombManager& operator=(const BombManager&) = delete;
	~BombManager() = default;

private:

	vector<BombObject*> bombs;

public:

	void Destroy();

	void SetBomb(const Vector2f& position);

	vector<BombObject*>* GetBullets();

	void Update(const float& deltaTime);

	void Update(const Vector2f& mousePosition);

	void Render(RenderTarget* target);

};

