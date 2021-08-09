#pragma once
#include "Object.h"

class EffectObject;

class BombObject : public Object
{
public:

    BombObject() = delete;
    BombObject(const string& textureFilePath);
    BombObject(const BombObject&) = delete;
    BombObject& operator=(const BombObject&) = delete;
    virtual ~BombObject() = default;

private:

    float lifeTime = 3.f;

    EffectObject* bombEffect = nullptr;

    FloatRect boomArea{ 0.f, 0.f, 0.f, 0.f };

public:

    virtual void Destroy();

    void SetBomb(const Vector2f& mousePosition);
    const FloatRect& GetBoomArea();

    bool IsDamaging();

    virtual void Update(const float& deltaTime);
    virtual void Update(const Vector2f& mousePosition);

    virtual void Render(RenderTarget* target);

};

