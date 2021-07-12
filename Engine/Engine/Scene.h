#pragma once

#include "Object.h"
#include "ButtonObject.h"
#include "TextObject.h"
#include "SoundSystem.h"

class Scene
{
public:

	Scene() = delete;
	Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene() = default;

protected:

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr;

	Object* backGround = nullptr;
	vector<Object*> objects;
	map<string, ButtonObject*> buttons;
	map<string, TextObject*> texts;

	bool Quit = false;

private:

	virtual void Init();

public:

	void EndScene();
	bool GetQuit();

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();

};

