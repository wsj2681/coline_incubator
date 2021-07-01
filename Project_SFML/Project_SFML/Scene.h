#pragma once

class Object;

class Scene
{
public:
	Scene();
	virtual ~Scene();

protected:


	vector<Object*> vObjects;

private:

	virtual void Init();

public:

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};