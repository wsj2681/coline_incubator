#include "framework.h"
#include "LobbyScene.h"
#include "BackGroundObject.h"
#include "GameScene.h"

LobbyScene::LobbyScene()
{
	Init();
}

LobbyScene::LobbyScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	static uniform_int_distribution<> uid(0, 3);
	static default_random_engine dre;
	switch (uid(dre))
	{
	case 0:
	{
		backGround = new BackGroundObject("Texture/background/lobby1.png");
		break;
	}
	case 1:
	{
		backGround = new BackGroundObject("Texture/background/lobby2.png");
		break;
	}
	case 2:
	{
		backGround = new BackGroundObject("Texture/background/lobby3.png");
		break;
	}
	default:
		break;
	}
}

void LobbyScene::Destroy()
{
}

void LobbyScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Space:
	{
		scenes->push(new GameScene(scenes, window));
		break;
	}
	}
}

void LobbyScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LobbyScene::Render()
{
	Scene::Render();
}
