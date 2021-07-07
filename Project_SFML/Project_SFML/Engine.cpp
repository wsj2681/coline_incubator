#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	// ���� window ������ �����ͷ� �����Ѵ�.
	// window Size 1384 x 720
	this->window = new RenderWindow(VideoMode(1384, 720), "Oven Break");
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Texture/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// ����ȭ��
	this->scenes.push(new TitleScene(&scenes, window));

}

void Engine::Destroy()
{
	// �����찡 nullptr�� �ƴ϶��
	if (window)
	{
		delete window;
	}

}

void Engine::Input()
{
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::MouseButtonPressed:
		case Event::KeyPressed:
		{
			if (!scenes.empty())
			{
				scenes.top()->Input(&evt);
			}
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();


	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			// ���� �������� scene�� �����Ѵ�

			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else
	{
		window->close();
	}
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		
		if (!scenes.empty())
		{
			scenes.top()->Render();
		}
		
		window->display();
	}
}
