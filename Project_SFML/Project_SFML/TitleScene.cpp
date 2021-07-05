#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"
#include "LobbyScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	vObjects.push_back(new BackGroundObject("Texture/BackGround/title.png"));
	Font* font = new Font;
	font->loadFromFile("Font/CookieRunFont_TTF/CookieRun_Bold.ttf");
	Text* text = new Text("Press Any Keys", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getLocalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
	text->setPosition(Vector2f(1136 / 2.f, 580.f));
	mTexts["TITLE"] = text;
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
		scenes->push(new LobbyScene(scenes));
		break;
	}
	}
}

void TitleScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;
	
	static float txtScale = 1.f;
	
	static int frame = 0;

	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.02f)
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

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
