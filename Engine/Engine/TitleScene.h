#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene() = delete;
	TitleScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~TitleScene() = default;

private:

	virtual void Init();

public:

	virtual void Input(Event* event);

};

