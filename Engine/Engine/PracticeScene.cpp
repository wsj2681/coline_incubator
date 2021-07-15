#include "framework.h"
#include "PracticeScene.h"
#include "GameScene.h"
#include "Button.h"
#include "JumpObject.h"

PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PracticeScene::Init()
{

	bts["Button1"] = new Button("Textures/Button/btn_jump_no.png", "Textures/Button/btn_jump_dim.png", { 200.f, 200.f });
	bts["Button2"] = new Button("Textures/Button/btn_jump_no.png", "Textures/Button/btn_jump_dim.png", { 500.f, 200.f });
	bts["Button3"] = new Button("Textures/Button/btn_jump_no.png", "Textures/Button/btn_jump_dim.png", { 500.f, 500.f });
	bts["Button4"] = new Button("Textures/Button/btn_jump_no.png", "Textures/Button/btn_jump_dim.png", { 200.f, 500.f });

	doll = new JumpObject("Textures/Character/Warrior_Male/Down00.png",{ 500.f, 500.f });
	portal = new Object("Textures/HUD/portal.png");

	doll->setScale(4.f, 4.f);
	portal->setPosition(50.f, 500.f);
}

void PracticeScene::Destroy()
{
	for (auto& army : bts)
	{
		army.second->Destroy();
	}
}

void PracticeScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		switch (event->key.code)
		{
			case Keyboard::Space:
			{
				// Down Casting
				dynamic_cast<JumpObject*>(doll)->Jump();
				break;
			}
		default:
			break;
		}
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		break;
	}
	default:
		break;
	}
}

void PracticeScene::Update(const Vector2f& mousePosition)
{
	for (auto& army : bts)
	{
		army.second->Update(mousePosition);
	}

	if (bts["Button1"]->IsPressed())
	{
		scenes->push(new GameScene(scenes, window, soundSystem));
	}

}

void PracticeScene::Update(const float& deltaTime)
{
	if (doll)
	{
		doll->Update(deltaTime);
	}

	if (portal)
	{
		portal->Update(deltaTime);
	}

	if (portal && doll)
	{
		if (portal->getGlobalBounds().contains(doll->getPosition()))
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				//soundSystem->EffectPlay("");
				scenes->push(new GameScene(scenes, window, soundSystem));
			}
		}
	}

}

void PracticeScene::Render()
{
	for (auto& army : bts)
	{
		army.second->Render(window);
	}
	if (portal)
	{
		portal->Render(window);
	}

	if (doll)
	{
		doll->Render(window);
	}

}
