#pragma once

#include "MonsterObject.h"

class BulletManager;

class MonsterManager
{
public:
	MonsterManager(const size_t& MonsterCount = 10);
	MonsterManager(const MonsterManager&) = delete;
	MonsterManager& operator=(const MonsterManager&) = delete;
	~MonsterManager() = default;

private:

	vector<MonsterObject*> monsters;

public:

	void Destroy();

	vector<MonsterObject*>* GetMonsters();

	void Update(const float& deltaTime);

	void Update(const Vector2f & mousePosition);

	void UpdateWithBullet(BulletManager* bulletMgr);
	void UpdateWithObject(Object* object);

	void Render(RenderTarget * target);

};

