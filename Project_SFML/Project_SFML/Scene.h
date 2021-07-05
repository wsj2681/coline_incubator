#pragma once

#include "BackGroundObject.h"

class Object;

class Scene
{
public:
	Scene();
	Scene(stack<Scene*>* scenes);
	virtual ~Scene();

protected:

	vector<Object*> vObjects;

	map<string, Text*> mTexts;

	stack<Scene*>* scenes;
	bool quit = false;

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};