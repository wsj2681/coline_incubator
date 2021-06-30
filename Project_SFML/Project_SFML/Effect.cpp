
#include "framework.h"
#include "Effect.h"

Effect::Effect()
{
	Init();
}

Effect::~Effect()
{
}

void Effect::Init()
{

}

void Effect::Destroy()
{
	AnimationObject::Destroy();
}

void Effect::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
