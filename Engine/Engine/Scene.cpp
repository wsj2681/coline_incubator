#include "framework.h"
#include "Scene.h"

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:scenes(scenes), window(window), soundSystem(soundSystem)
{
	Init();
}

void Scene::Init()
{

}

void Scene::EndScene()
{
	this->Quit = true;
}

bool Scene::GetQuit()
{
	return Quit;
}

void Scene::Destroy()
{
	if (backGround)
	{
		backGround->Destroy();
	}

	for (auto& obj : objects)
	{
		obj->Destroy();
	}
}

void Scene::Input(Event* event)
{
	switch (event->type)
	{
	// Ű���� �Է�
	case Event::KeyPressed:
	{
		break;
	}

	// ���콺 �Է�
	case Event::MouseButtonPressed:
	{
		break;
	}
	default:
		break;
	}
}

void Scene::Update(const Vector2f& mousePosition)
{
	for (auto& obj : objects)
	{
		obj->Update(mousePosition);
	}

	for (auto& btn : buttons)
	{
		btn.second->Update(mousePosition);
	}
}

void Scene::Update(const float& deltaTime)
{
	for (auto& obj : objects)
	{
		obj->Update(deltaTime);
	}

	for (auto& txt : texts)
	{
		txt.second->Update();
	}
}

void Scene::Render()
{
	if (backGround)
	{
		backGround->Render(window);
	}

	for (auto& obj : objects)
	{
		obj->Render(window);
	}

	for (auto& btn : buttons)
	{
		btn.second->Render(window);
	}

	for (auto& txt : texts)
	{
		txt.second->Render(window);
	}
}
