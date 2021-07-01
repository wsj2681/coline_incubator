#include "framework.h"
#include "EffectScene.h"
#include "BlasterEffect.h"
#include "BlueEffect.h"
#include "ExplosionEffect.h"

EffectScene::EffectScene()
{
	Init();
}

EffectScene::EffectScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

EffectScene::~EffectScene()
{
}

void EffectScene::Init()
{
	vObjects.push_back(new BlasterEffect);
	vObjects.push_back(new BlueEffect);
	vObjects.push_back(new ExplosionEffect);
}

void EffectScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void EffectScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
