#include "framework.h"
#include "CharactorScene.h"
#include "Charactor.h"

CharactorScene::CharactorScene()
{
	Init();
}

CharactorScene::CharactorScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

CharactorScene::~CharactorScene()
{
}

void CharactorScene::Init()
{
	animationObjects.push_back(new Charactor);
}

void CharactorScene::Input(Event* e)
{
}

void CharactorScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void CharactorScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
