#include "framework.h"
#include "LobbyScene.h"
#include "GameScene.h"
#include "MapToolScene.h"

LobbyScene::LobbyScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void LobbyScene::Init()
{
	texts["TEXT"] = new TextObject("LOBBY SCENE !", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
	buttons["MapTool"] = new ButtonObject("Textures/Button/maptool.png", "Textures/Button/maptoolactive.png", { 1080 / 2.f, 720.f - 100.f });

	buttons["GameStart"] = new ButtonObject("Textures/Button/gamestart.png", "Textures/Button/gamestartactive.png", { 1080 / 2.f, 720.f - 300.f });

}

void LobbyScene::Destroy()
{
	Scene::Destroy();
}

void LobbyScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		//scenes->push(new GameScene(scenes, window));
		soundSystem->EffectPlay("Click");
		break;
	}
	default:
		break;
	}
}

void LobbyScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);

	if (buttons["MapTool"]->IsPressed())
	{
		scenes->push(new MapToolScene(scenes, window, soundSystem));
	}

	if (buttons["GameStart"]->IsPressed())
	{
		scenes->push(new GameScene(scenes, window, soundSystem));
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
