#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	GameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~GameScene();

private:

	vector<Object*> jellys;

	vector<Vector2f> jellyPositions;

	size_t score = 0;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render();
};

