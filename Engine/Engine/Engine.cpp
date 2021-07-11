#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"
#include "MapToolScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	Destroy();
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(32 * 56, 32 * 23), "Window");
	this->window->setFramerateLimit(60);
	this->event = new Event;
	this->clock = new Clock;

	//scenes.push(new TitleScene(&scenes, window));
	scenes.push(new MapToolScene(&scenes, window));
}

void Engine::Destroy()
{
	DELETE(clock);
	DELETE(event);
	DELETE(window);

	for (size_t i = 0; i < scenes.size(); ++i)
	{
		scenes.top()->Destroy();
		scenes.top() = nullptr;
		delete scenes.top();
		scenes.pop();
	}
}

void Engine::Input()
{
	while (window->pollEvent(*event))
	{
		switch (event->type)
		{
		case Event::Closed:
		{
			this->window->close();
			break;
		}
		case Event::KeyPressed:
		case Event::MouseButtonPressed:
		case Event::MouseWheelMoved:
		{
			// Scene InputUpdate();
			if (!scenes.empty())
			{
				scenes.top()->Input(event);
			}
			break;
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	clock->restart();
	this->deltaTime = clock->getElapsedTime().asSeconds();
	this->elapsedTime += deltaTime;
	this->mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);
		scenes.top()->Update(mousePosition);
	}
	else
	{
		window->close();
	}
}

bool Engine::Render()
{
	if (window->isOpen())
	{
		window->clear();
		
		Input();
		Update();

		if (!scenes.empty())
		{
			scenes.top()->Render();
		}

		window->display();
		return true;
	}
	else
	{
		return false;
	}
}
