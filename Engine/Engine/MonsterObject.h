#pragma once
#include "Object.h"


enum MONSTERSTATE
{
	IDLE,
	CHASING
};

class MonsterObject : public Object
{
public:
	MonsterObject();
	MonsterObject(const string& textureFilePath);
	MonsterObject(const string& textureFilePath, const Vector2f& position);
	MonsterObject(const MonsterObject&) = delete;
	MonsterObject& operator=(const MonsterObject&) = delete;
	~MonsterObject();

private:

	int HP = 0;
	Object* hpBar = nullptr;
	int state = IDLE;
	int oldState = IDLE;

	Vector2f targetPosition{};

private:

	virtual void Init();

public:

	virtual void Destroy();

	int GetHp();
	void SetHp(const int& Hp);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	void ChasingUpdate(Object* object);

	virtual void Render(RenderTarget* target);
};

