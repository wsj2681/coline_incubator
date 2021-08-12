#pragma once
#include "Scene.h"

class PracticeMap;
class Object;
class JumpObject;
class MonsterObject;
class WallManager;

class PracticeScene : public Scene
{
public:

	PracticeScene() = delete;
	PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	PracticeScene(const PracticeScene&) = delete;
	PracticeScene& operator=(const PracticeScene&) = delete;
	virtual ~PracticeScene() = default;

private:

	PracticeMap* map = nullptr;
	int tileNumber = 111; // water

	Object* mouseCursor = nullptr;

	JumpObject* player = nullptr;
	vector<MonsterObject*> monsters;

	View* gameView = nullptr;

	WallManager* wallMgr = nullptr;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};

