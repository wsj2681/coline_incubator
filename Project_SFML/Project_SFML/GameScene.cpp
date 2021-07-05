#include "framework.h"
#include "GameScene.h"
#include "JellyObject.h"
#include "BackGroundObject.h"
#include "Charactor.h"

GameScene::GameScene()
{
	Init();
}

GameScene::GameScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	Object* backGround = new BackGroundObject("Texture/BackGround/game.png");
	backGround->setScale(2.5f, 2.f);
	vObjects.push_back(backGround);

	vObjects.push_back(new Charactor);

	for (int i = 0; i < 10; ++i)
	{
		jellys.push_back(new JellyObject(Orange));
	}
	for (int i = 0; i < 10; ++i)
	{
		jellys.push_back(new JellyObject(Pupple));
	}
	for (int i = 0; i < 10; ++i)
	{
		jellys.push_back(new JellyObject(Green));
	}

	uniform_real_distribution<float> urd(0.f, 640.f);
	default_random_engine dre;

	shuffle(jellys.begin(), jellys.end(), dre);


	for (auto& j : jellys)
	{
		j->setPosition(urd(dre), urd(dre));
	}
}

void GameScene::Destroy()
{
}

void GameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene::Render(RenderWindow* window)
{
	Scene::Render(window);

	for (auto& j : jellys)
	{
		window->draw(*j);
	}
}