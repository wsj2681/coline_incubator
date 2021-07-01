#include "framework.h"
#include "CharactorScene.h"
#include "Charactor.h"

CharactorScene::CharactorScene()
{
	Init();
}

CharactorScene::CharactorScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

CharactorScene::~CharactorScene()
{
}

void CharactorScene::Init()
{
	vObjects.push_back(new Charactor);
}

void CharactorScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void CharactorScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
