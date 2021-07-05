#include "framework.h"
#include "LobbyScene.h"
#include "BackGroundObject.h"

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
	vObjects.push_back(new BackGroundObject(""));
}

void LobbyScene::Destroy()
{
}

void LobbyScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LobbyScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
