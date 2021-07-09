#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene() = delete;
	GameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~GameScene() = default;

private:

	virtual void Init();

public:

	virtual void Input(Event * event);

};

