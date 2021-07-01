#pragma once
#include "Scene.h"
class EffectScene : public Scene
{
public:
	EffectScene();
	EffectScene(stack<Scene*>* scenes);
	virtual ~EffectScene();

private:
	virtual void Init();


public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

