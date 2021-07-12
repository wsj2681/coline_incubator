#pragma once
#include "Scene.h"
#include "TileMap.h"

class MapToolScene : public Scene
{
public:

	MapToolScene() = delete;
	MapToolScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	MapToolScene(const MapToolScene&) = delete;
	MapToolScene& operator=(const MapToolScene&) = delete;
	virtual ~MapToolScene() = default;

private:

	vector<int> levels;

	int tileType = 56;

	Object* mouseCursor = nullptr;

	Vector2f mousePosition{ 0.f, 0.f };

	TileMap* map = nullptr;

	View* gameView = nullptr;
	FloatRect viewRect{0, 0,  1080, 720 };
	float viewZoomFactor = 1.f;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();

};

