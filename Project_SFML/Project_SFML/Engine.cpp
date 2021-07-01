#include "framework.h"
#include "Engine.h"
#include "EffectScene.h"
#include "CharactorScene.h"


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
	
	this->window = new RenderWindow(VideoMode(500, 500), "Window");
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Texture/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// �ƹ��͵� ���� ���
	this->scenes.push(new Scene);

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
		case Event::KeyPressed:
		{
			switch (evt.key.code)
			{
			case Keyboard::A:
			{
				this->scenes.push(new CharactorScene);
				cout << "Now Scene : CharactorScene\n";
				break;
			}
			case Keyboard::S:
			{
				this->scenes.push(new EffectScene);
				cout << "Now Scene : EffectScene\n";
				break;
			}
			case Keyboard::Q:
			{
				scenes.top()->EndScene();
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}

	// KeyBoardInput
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}

	// Mouse Input
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		window->setTitle("Left Click");
	}
	else if (Mouse::isButtonPressed(Mouse::Right))
	{
		window->setTitle("Right Click");
	}
	else
	{
		window->setTitle("Window");
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();
	Input();
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
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		
		if (!scenes.empty())
		{
			scenes.top()->Render(window);
		}
		
		window->display();
	}
}
