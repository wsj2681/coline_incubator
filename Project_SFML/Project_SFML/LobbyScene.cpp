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
	mTexts["TEST"] = new TextObject("Press Space Key", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", Vector2f(1136 / 2.f, 580.f));
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
	static float elapsedTime = 0.f;
	
	static float txtScale = 1.f;

	static int frame = 0;

	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.01f)
	{

		if ((++frame % 30) == 0)
		{
			div *= -1;
		}

		txtScale += (0.01f * div);
		mTexts["TEST"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}

	Scene::Update(deltaTime);
}

void LobbyScene::Render()
{
	Scene::Render();
}
