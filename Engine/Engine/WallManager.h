#pragma once

#include"WallObject.h"

class WallManager final
{
public:
	WallManager(const size_t& WallCount = 10);
	WallManager(const WallManager&) = delete;
	WallManager& operator=(const WallManager&) = delete;
	~WallManager() = default;

private:

	vector<WallObject*> walls;

public:

	void Destroy();

	void SetWall(const Vector2f& position);

	void Update(const float& deltaTime);

	void Update(const Vector2f& mousePosition);

	void Update(const float& deltaTime, Object* object);

	void Render(RenderTarget* target);
};

