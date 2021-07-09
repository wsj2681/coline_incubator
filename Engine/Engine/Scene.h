#pragma once

#include "Object.h"
#include "ButtonObject.h"
#include "TextObject.h"

class Scene
{
public:

	Scene() = delete;
	Scene(stack<Scene*>* scenes, RenderWindow* window);
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene() = default;

protected:

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	Object* backGround = nullptr;
	vector<Object*> objects;
	map<string, ButtonObject*> buttons;
	map<string, TextObject*> texts;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();

};

