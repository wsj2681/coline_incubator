#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "BlasterEffect.h"
#include "BlueEffect.h"
#include "Charactor.h"
#include "ExplosionEffect.h"

Scene::Scene()
{
	Init();
}

Scene::~Scene()
{
}

void Scene::Init()
{
	vObjects.push_back(new BlasterEffect);
	vObjects.push_back(new BlueEffect);
	vObjects.push_back(new ExplosionEffect);
	vObjects.push_back(new Charactor);
}

void Scene::Update(const float& deltaTime)
{
	for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}
}
