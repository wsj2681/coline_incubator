#pragma once
#include "Scene.h"
class MapToolScene : public Scene
{
public:

	MapToolScene() = delete;
	MapToolScene(stack<Scene*>* scenes, RenderWindow* window);
	MapToolScene(const MapToolScene&) = delete;
	MapToolScene& operator=(const MapToolScene&) = delete;
	virtual ~MapToolScene() = default;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();

};

