#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	LobbyScene() = delete;
	LobbyScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~LobbyScene() = default;

private:

	virtual void Init();

public:

	virtual void Input(Event * event);

};

