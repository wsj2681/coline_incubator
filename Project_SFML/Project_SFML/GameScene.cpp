#include "framework.h"
#include "GameScene.h"
#include "JellyObject.h"
#include "BackGroundObject.h"
#include "Charactor.h"
#include "ResultScene.h"

GameScene::GameScene()
{
	Init();
}

GameScene::GameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	backGround = new BackGroundObject("Texture/BackGround/game.png");
	backGround->setScale(2.5f, 2.f);

	animationObjects.push_back(new Charactor);

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
	mTexts["Score"] = new TextObject("Score : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", Vector2f(1000.f, 100.f));

	mButtons["JUMP"] = new Button("Texture/Buttons/btn_pair1168169_L.png", "Texture/Buttons/btn_pair1168169_L_dim.png", Vector2f(100.f, 600.f));

}

void GameScene::Destroy()
{
}

void GameScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Q:
	{
		scenes->push(new ResultScene(scenes, window));
		break;
	}
	}


}

void GameScene::Update(const float& deltaTime)
{
	mTexts["Score"]->setString(to_string(++score).c_str());

	for (auto& jelly : jellys)
	{
		jelly->Update(mousePosition);
	}


	if (mButtons["JUMP"]->IsPressed())
	{
		dynamic_cast<Charactor*>(animationObjects.data()[0])->Jump();
	}

	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	Scene::Render();

	for (auto& j : jellys)
	{
		if (j->IsActive())
		{
			window->draw(*j);
		}
	}
}
