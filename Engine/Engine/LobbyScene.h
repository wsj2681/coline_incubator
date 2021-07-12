#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	LobbyScene() = delete;
	LobbyScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	virtual ~LobbyScene() = default;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};

