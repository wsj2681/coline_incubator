#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"
#include "LobbyScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	backGround = new BackGroundObject("Texture/BackGround/title.png");

	mTexts["TITLE"] = new TextObject("Press Any Keys", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", Vector2f(1384 / 2.f, 650.f));
}

void TitleScene::Destroy()
{
}

void TitleScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape:
	{
		scenes->top()->EndScene();
		break;
	}

	default:
	{
		scenes->push(new LobbyScene(scenes, window));
		break;
	}
	}
	
}

void TitleScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;
	static float txtScale = 1.3f;
	static int frame = 0;
	static int div = 1;
	
	if ((elapsedTime += deltaTime) >= 0.01f)
	{

		if ((++frame % 30) == 0)
		{
			div *= -1;
		}

		txtScale += (0.01f * div);

		mTexts["TITLE"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}
	Scene::Update(deltaTime);
}

void TitleScene::Render()
{
	Scene::Render();
}
