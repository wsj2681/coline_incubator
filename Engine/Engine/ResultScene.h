#pragma once
#include "Scene.h"
class ResultScene : public Scene
{
public:
	ResultScene() = delete;
	ResultScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~ResultScene() = default;

private:

	virtual void Init();

public:

	virtual void Input(Event* event);

};

