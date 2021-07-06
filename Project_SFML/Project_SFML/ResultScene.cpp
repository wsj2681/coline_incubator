#include "framework.h"
#include "ResultScene.h"
#include "LobbyScene.h"


ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
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

void ResultScene::Render()
{
	Scene::Render();
}
