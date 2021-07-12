#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"

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
	this->window = new RenderWindow(VideoMode(1080, 720), "Window");
	this->window->setFramerateLimit(60);
	this->event = new Event;
	this->clock = new Clock;

	soundSystem = new SoundSystem("Sound/henesys.wav");
	soundSystem->AddEffectSound("Sound/MouseClick.wav", "Click");
	soundSystem->AddEffectSound("Sound/CoinGet.wav", "CoinGet");

	scenes.push(new TitleScene(&scenes, window, soundSystem));// 10ºÐ±îÁö

	soundSystem->Play();
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
	soundSystem->Destroy();
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
	this->deltaTime = clock->getElapsedTime().asSeconds();
	clock->restart();
	this->elapsedTime += deltaTime;
	this->mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	if (!scenes.empty())
	{
		if (scenes.top()->GetQuit())
		{
			scenes.top()->Destroy();
			scenes.top() = nullptr;
			delete scenes.top();
			scenes.pop();
		}
		else
		{
			scenes.top()->Update(deltaTime);
			scenes.top()->Update(mousePosition);
		}
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
