#pragma once
#include "Scene.h"
class ResultScene : public Scene
{
public:
	ResultScene();
	ResultScene(stack<Scene*>* scenes);
	~ResultScene();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
};

