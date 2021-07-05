#pragma once
#include "Scene.h"
class CharactorScene : public Scene
{
public:
	CharactorScene();
	CharactorScene(stack<Scene*>* scenes);
	virtual ~CharactorScene();

private:
	virtual void Init();


public:
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

