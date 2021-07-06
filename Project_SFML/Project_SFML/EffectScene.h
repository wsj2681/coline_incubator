#pragma once
#include "Scene.h"
class EffectScene : public Scene
{
public:
	EffectScene();
	EffectScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~EffectScene();

private:
	virtual void Init();


public:
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

