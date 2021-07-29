#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"
#include "PracticeScene.h"

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
	this->window->setFramerateLimit(75);
	//this->window->setVerticalSyncEnabled(true);
	this->event = new Event;
	this->clock = new Clock;
	engineClock = new Clock;
	soundSystem = new SoundSystem("Sound/MouseClick.wav", false);

	scenes.push(new PracticeScene(&scenes, window, soundSystem));
	//scenes.push(new TitleScene(&scenes, window, soundSystem));
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
	if (engineClock->getElapsedTime().asSeconds() >= 1.f)
	{
		FPS = frame;
		frame = 0;
		engineClock->restart();
		this->elapsedTime += deltaTime;

		ostringstream Oss;
		Oss << "Window FPS(" << FPS << ")";

		window->setTitle(Oss.str());

	}
	++frame;

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
