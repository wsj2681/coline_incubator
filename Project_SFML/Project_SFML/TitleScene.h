#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	TitleScene(stack<Scene*>* scenes);
	~TitleScene();

private:
	
	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
};

