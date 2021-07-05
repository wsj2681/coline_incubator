#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	GameScene(stack<Scene*>* scenes);
	~GameScene();

private:

	vector<Object*> jellys;

	vector<Vector2f> jellyPositions;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
};
