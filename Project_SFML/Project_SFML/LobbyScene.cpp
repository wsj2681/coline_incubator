#include "framework.h"
#include "LobbyScene.h"
#include "BackGroundObject.h"
#include "GameScene.h"

LobbyScene::LobbyScene()
{
	Init();
}

LobbyScene::LobbyScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	//vObjects.push_back(new BackGroundObject(""));
	Font* font = new Font;
	font->loadFromFile("Font/CookieRunFont_TTF/CookieRun_Bold.ttf");
	Text* text = new Text("Press Space Key", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
	text->setPosition(Vector2f(1136 / 2.f, 580.f));
	mTexts["TEST"] = text;
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
		scenes->push(new GameScene(scenes));
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

void LobbyScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
