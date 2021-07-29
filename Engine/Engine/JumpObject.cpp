#include "framework.h"
#include "JumpObject.h"
#include "BulletManager.h"

JumpObject::JumpObject()
{
}

JumpObject::JumpObject(const string& textureFilePath)
	:Object(textureFilePath)
{
	bulletMgr = new BulletManager(100);
}

JumpObject::JumpObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	this->position = position;
	bulletMgr = new BulletManager(100);
}

void JumpObject::Destroy()
{
}

void JumpObject::JumpUpdate(const float& deltaTime)
{
	if (position.y < 500.f) // ���� ��ǥ ����
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if(position.y > 500.f) // �ٴ����� ������ ���� �����ϱ� ����
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
		bulletMgr->Shoot({ Math::Normalize(bulletTargetPosition, position) }, position, 600.f);
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
	case PATROL:	// patrolPosition���� �̵��Ѵ�.
	{
		// TODO : �ð��� �������� ������ �������� �ϱ�
		// A : elapsedTime�� ���� Speed�� �����ϱ�
		position += Math::Normalize(patrolPosition, position);
		break;
	}
	case CHASE:		// targetPosition���� �̵��Ѵ�.
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

}

void JumpObject::Update(const Vector2f& mousePosition)
{
	bulletTargetPosition = mousePosition;
	if (bulletMgr)
	{
		bulletMgr->Update(mousePosition);
	}
}

void JumpObject::Render(RenderTarget* target)
{
	Object::Render(target);
	if (bulletMgr)
	{
		bulletMgr->Render(target);
	}

}
