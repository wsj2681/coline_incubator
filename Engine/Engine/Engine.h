#pragma once
#include "SoundSystem.h"

class Scene;

class Engine final
{
public:
	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	~Engine();

private:

	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr;
	stack<Scene*> scenes;

	Event* event = nullptr;
	Vector2f mousePosition{ 0.f, 0.f };

	Clock* clock = nullptr;
	float deltaTime = 0.f;
	float elapsedTime = 0.f;

private:

	void Init();

	void Destroy();

	void Input();

	void Update();

public:

	bool Render();

};

