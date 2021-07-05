#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	LobbyScene();
	LobbyScene(stack<Scene*>* scenes);
	~LobbyScene();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
};

