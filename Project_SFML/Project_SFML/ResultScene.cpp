#include "framework.h"
#include "ResultScene.h"

ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
}

void ResultScene::Destroy()
{
}

void ResultScene::Input(Event* e)
{
}

void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void ResultScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
