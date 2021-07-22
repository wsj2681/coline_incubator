#include "framework.h"
#include "PracticeScene.h"
#include "GameScene.h"
#include "TileMap.h"
#include "JumpObject.h"


PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PracticeScene::Init()
{
	doll = new JumpObject("Textures/Character/Warrior_Male/Down00.png",{ 500.f, 500.f });
	portal = new Object("Textures/HUD/portal.png");

	doll->setScale(5.f, 5.f);
	portal->setPosition(50.f, 500.f);
}

void PracticeScene::Destroy()
{

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
	if (doll)
	{
		dynamic_cast<JumpObject*>(doll)->TargetMove(mousePosition);
	}
}

void PracticeScene::Update(const float& deltaTime)
{
	// TODO : 현재 씬의 몬스터 마릿수 세기
	// TODO : 몬스터 마릿수가 0마리면, 다음 씬으로 이동


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
				scenes->push(new GameScene(scenes, window, soundSystem));
			}
		}
	}
}

void PracticeScene::Render()
{
	if (portal)
	{
		portal->Render(window);
	}

	if (doll)
	{
		doll->Render(window);
	}

}
