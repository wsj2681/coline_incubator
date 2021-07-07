#pragma once
#include "Scene.h"

enum PATTERN
{
	SIN,
	ABS
};

class GameScene : public Scene
{
public:
	GameScene();
	GameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~GameScene();

private:

	vector<Object*> jellys;

	size_t score = 0;

	int jellyPattern = SIN;

private:

	virtual void Init();

public:

	Vector2f JellyPattern(int pattern);

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render();
};

