#pragma once
#include "Scene.h"

class Character;
class TileMap;

class GameScene : public Scene
{
public:
	GameScene() = delete;
	GameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~GameScene() = default;

private:

	Character* character = nullptr;


	// Map Variables

	TileMap* world = nullptr;
	vector<int> levels;

	View* gameView = nullptr;
	FloatRect viewRect{ 0, 0,  1080, 720 };
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