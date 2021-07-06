#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	LobbyScene();
	LobbyScene(stack<Scene*>* scenes, RenderWindow* window);
	~LobbyScene();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render();
};

