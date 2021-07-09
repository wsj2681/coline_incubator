#pragma once
#include "Scene.h"
class PauseScene : public Scene
{
public:
	PauseScene() = delete;
	PauseScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~PauseScene() = default;

private:

	virtual void Init();

public:

	virtual void Input(Event* event);

};

