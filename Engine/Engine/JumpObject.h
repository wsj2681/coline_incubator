#pragma once
#include "Object.h"

enum STATE
{
	MOVE_IDLE, // ���� ����
	PATROL, // ���� ����
	CHASE // ���� ����
};

class BulletManager;
class BombManager;

class JumpObject : public Object
{
public:
	JumpObject();
	JumpObject(const string& textureFilePath);
	JumpObject(const string& textureFilePath, const Vector2f& position);
	virtual ~JumpObject() = default;

private:

	Vector2f position{ 0.f, 0.f };
	Vector2f velocity{ 0.f, 0.f };
	Vector2f acceleration{ 0.f, 0.f };
	Vector2f direction{ 0.f, 0.f };

	Vector2f patrolPosition{ 0.f, 0.f };

	int state = MOVE_IDLE;

	float speed = 50.f;
	float gravity = 2.f;

	BulletManager* bulletMgr = nullptr;
	float shootCoolTime = 0.1f;

	Vector2f bulletTargetPosition{ 0.f, 0.f };

	BombManager* bombMgr = nullptr;
	float bombSetCoolTime = 0.5f;


public:

	virtual void Destroy();

	BulletManager* GetBulletMgr();
	BombManager* GetBombMgr();

	const Vector2f& GetDirection();
	void SetDirection(const Vector2f& direction);

	void JumpUpdate(const float& deltTime);
	void Jump();
	
	void Shoot();

	void SetBomb();

	void TargetMove(const Vector2f& targetPosition);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

