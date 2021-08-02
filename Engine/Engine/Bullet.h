#pragma once
#include "Object.h"

enum Bullet_Type
{
    NONE,
    ONE,
    TWO,
    THREE
};

class Bullet : public Object
{
public:
    Bullet() = delete;
    Bullet(const string& textureFilePath);
    Bullet(const Bullet&) = delete;
    Bullet& operator=(const Bullet&) = delete;
    virtual ~Bullet() = default;

private:

    Vector2f dir{ 0.f, 0.f };
    float speed = 0.f;

    float lifeTime = 2.f;

    int bulletType = THREE;

public:

    virtual void Destroy();

    void SetDirection(const Vector2f& dir);
    void SetSpeed(const float& speed);

    const int GetBulletType();

    virtual void Update(const float& deltaTime);
    virtual void Update(const Vector2f& mousePosition);

    virtual void Render(RenderTarget* target);

};

