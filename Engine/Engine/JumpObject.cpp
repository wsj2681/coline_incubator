#include "framework.h"
#include "JumpObject.h"
#include "BulletManager.h"
#include "BombManager.h"

JumpObject::JumpObject()
{
}

JumpObject::JumpObject(const string& textureFilePath)
	:Object(textureFilePath)
{
	bulletMgr = new BulletManager(100);
	bombMgr = new BombManager(10);
}

JumpObject::JumpObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	this->position = position;
	bulletMgr = new BulletManager(100);
	bombMgr = new BombManager(7);
}

void JumpObject::Destroy()
{
}

BulletManager* JumpObject::GetBulletMgr()
{
	return bulletMgr;
}

void JumpObject::JumpUpdate(const float& deltaTime)
{
	if (position.y < 500.f) // 점프 좌표 갱신
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if(position.y > 500.f) // 바닥으로 꺼지는 것을 방지하기 위함
	{
		position.y = 500.f;
	}

	velocity += acceleration * speed * deltaTime;
	position += velocity;

}

void JumpObject::Jump()
{
	velocity.y = -20.f;
}

void JumpObject::Shoot()
{
	if (bulletMgr)
	{
		if (shootCoolTime <= 0.f)
		{
			bulletMgr->Shoot({ Math::Normalize(bulletTargetPosition, position) }, position, 600.f);
			shootCoolTime = 0.1f;
		}
	}
}

void JumpObject::SetBomb()
{
	if (bombMgr)
	{
		if (bombSetCoolTime <= 0.f)
		{
			bombMgr->SetBomb(this->getPosition());
			bombSetCoolTime = 0.5f;
		}
	}
}

void JumpObject::TargetMove(const Vector2f& targetPosition)
{
	float length = Math::Length(targetPosition.x - getPosition().x, targetPosition.y - getPosition().y);

	if (length < 300.f)
	{
		state = CHASE;
	}
	else
	{
		state = PATROL;
	}

	switch (state)
	{
	case IDLE:
	{
		break;
	}
	case PATROL:	// patrolPosition으로 이동한다.
	{
		// TODO : 시간이 지날수록 움직임 빨라지게 하기
		// A : elapsedTime에 따라 Speed값 조정하기
		position += Math::Normalize(patrolPosition, position);
		break;
	}
	case CHASE:		// targetPosition으로 이동한다.
	{
		position += Math::Normalize(targetPosition, position);
		break;
	}
	default:
		break;
	}

	setPosition(position);
}

void JumpObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	//JumpUpdate(deltaTime);
	
	//(1080, 720)
	if (this->getGlobalBounds().top + this->getGlobalBounds().height > 720.f)
	{
		position.y = 720.f - this->getGlobalBounds().height / 2.f;
	}
	else if (this->getGlobalBounds().top < 0.f)
	{
		position.y = 0.f + this->getGlobalBounds().height / 2.f;
	}

	if (this->getGlobalBounds().left + this->getGlobalBounds().width > 1080.f)
	{
		position.x = 1080 - this->getGlobalBounds().width / 2.f;
	}
	else if (this->getGlobalBounds().left < 0.f)
	{
		position.x = 0.f + this->getGlobalBounds().width / 2.f;
	}

	shootCoolTime -= deltaTime;
	bombSetCoolTime -= deltaTime;

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			position.x -= 5.f;
		}
		else
		{
			position.x -= 3.f;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			position.x += 5.f;
		}
		else
		{
			position.x += 3.f;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			position.y -= 5.f;
		}
		else
		{
			position.y -= 3.f;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			position.y += 5.f;
		}
		else
		{
			position.y += 3.f;
		}
	}
	setPosition(position);

	if (bulletMgr)
	{
		bulletMgr->Update(deltaTime);
	}

	if (bombMgr)
	{
		bombMgr->Update(deltaTime);
	}

}

void JumpObject::Update(const Vector2f& mousePosition)
{
	bulletTargetPosition = mousePosition;
	if (bulletMgr)
	{
		bulletMgr->Update(mousePosition);
	}

	if (bombMgr)
	{
		bombMgr->Update(mousePosition);
	}
}

void JumpObject::Render(RenderTarget* target)
{
	Object::Render(target);
	if (bulletMgr)
	{
		bulletMgr->Render(target);
	}
	if (bombMgr)
	{
		bombMgr->Render(target);
	}
}
