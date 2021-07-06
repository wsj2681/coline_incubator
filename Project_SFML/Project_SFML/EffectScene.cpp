#include "framework.h"
#include "EffectScene.h"
#include "BlasterEffect.h"
#include "BlueEffect.h"
#include "ExplosionEffect.h"

EffectScene::EffectScene()
{
	Init();
}

EffectScene::EffectScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

EffectScene::~EffectScene()
{
}

void EffectScene::Init()
{
	animationObjects.push_back(new BlasterEffect);
	animationObjects.push_back(new BlueEffect);
	animationObjects.push_back(new ExplosionEffect);
}

void EffectScene::Input(Event* e)
{
}

void EffectScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void EffectScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
