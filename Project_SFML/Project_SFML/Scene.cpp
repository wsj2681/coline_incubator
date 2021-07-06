#include "framework.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window)
	:scenes(scenes), window(window)
{
	Init();
}

Scene::~Scene()
{
}

void Scene::Init()
{

}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Input(Event* e)
{
}

void Scene::Update(const float& deltaTime)
{
	mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
		}
	}

	for (auto& btn : mButtons)
	{
		btn.second->Update(mousePosition);
	}
}

void Scene::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
	}

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
		}
	}

	for (auto& btn : mButtons)
	{
		window->draw(*btn.second);
	}

	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}
