#include "framework.h"
#include "MapToolScene.h"

MapToolScene::MapToolScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void MapToolScene::Init()
{
}

void MapToolScene::Destroy()
{
	Scene::Destroy();
}

void MapToolScene::Input(Event* event)
{
}

void MapToolScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void MapToolScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void MapToolScene::Render()
{
	Scene::Render();
}
