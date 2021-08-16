#include "framework.h"
#include "AnimationObject.h"

void AnimationObject::Init()
{
}

void AnimationObject::Destroy()
{
	Object::Destroy();
}

void AnimationObject::SetAnimation(vector<Texture*>* animation, float frameTime)
{
	this->frameTime = frameTime;
	this->vAnimation = *animation;
}

const unsigned int& AnimationObject::GetKeyFrame()
{
	return this->keyFrame;
}

void AnimationObject::SetKeyFrame(unsigned int& frame)
{
	this->keyFrame = frame;
}

void AnimationObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);

	if (!vAnimation.empty())
	{
		static float elapsedTime = 0.f;
		elapsedTime += deltaTime;

		//if (elapsedTime >= frameTime)
		{
			setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
			keyFrame++;
			elapsedTime = 0.f;
		}
	}
}

void AnimationObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void AnimationObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
