#include "framework.h"
#include "Object.h"

Object::Object()
{
	vertices = new Vertex[5];
}

Object::Object(const string& textureFilePath)
{
	this->texture = new Texture;
	
	if (this->texture->loadFromFile(textureFilePath))
	{
		setTexture(*this->texture);

		// GlobalBoundBox
		auto gbb = this->getGlobalBounds();

		setOrigin(gbb.width / 2.f, gbb.height / 2.f);

		vertices = new Vertex[5];
		vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
		vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
		vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
		vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
		vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	}
}


Object::Object(const string& textureFilePath, const Vector2f& position)
	:Object(textureFilePath)
{
	setPosition(position);
}

void Object::Destroy()
{
	DELETE(texture);
	DELETE(vertices);
}

void Object::SetDebugBoxActive(bool isActive)
{
	this->debugBox = isActive;
}

void Object::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool Object::IsActive()
{
	return isActive;
}

void Object::SetBoxColor(const Color& color)
{
	this->boxColor = color;
}

void Object::SetBoxColor(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a)
{
	SetBoxColor(Color(r, g, b, a));
}

bool Object::IsRightCollide(Object* target)
{
	auto gbb = this->getGlobalBounds();
	auto targetGbb = target->getGlobalBounds();
	if (gbb.left + gbb.width > targetGbb.left &&
		gbb.top < targetGbb.top + targetGbb.height)
	{
		return true;
	}
	else if (gbb.left + gbb.width > targetGbb.left &&
		gbb.top + gbb.height > targetGbb.top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::IsLeftCollide(Object* target)
{
	auto gbb = this->getGlobalBounds();
	auto targetGbb = target->getGlobalBounds();
	if (gbb.left  < targetGbb.left + targetGbb.width &&
		gbb.top < targetGbb.top + targetGbb.height)
	{
		return true;
	}
	else if (gbb.left  < targetGbb.left + targetGbb.width &&
		gbb.top + gbb.height > targetGbb.top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::IsTopCollide(Object* target)
{
	auto gbb = this->getGlobalBounds();
	auto targetGbb = target->getGlobalBounds();
	if (gbb.top < targetGbb.top + targetGbb.height &&
		gbb.left < targetGbb.left + targetGbb.width)
	{
		return true;
	}
	else if (gbb.top < targetGbb.top + targetGbb.height &&
		gbb.left + gbb.width > targetGbb.left)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::IsBottomCollide(Object* target)
{
	auto gbb = this->getGlobalBounds();
	auto targetGbb = target->getGlobalBounds();
	if (gbb.top + gbb.height > targetGbb.top &&
		gbb.left < targetGbb.left + targetGbb.width)
	{
		return true;
	}
	else if (gbb.top + gbb.height > targetGbb.top &&
		gbb.left + gbb.width > targetGbb.left)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Object::IsCollideAABB(Object* target, const float& push)
{
	Vector2f otherPosition = target->getPosition();
	Vector2f thisPosition = this->getPosition();
	Vector2f otherHalfSize = target->GetHalfSize();
	Vector2f thisHalfSize = this->GetHalfSize();

	Vector2f delta = { otherPosition.x - thisPosition.x, otherPosition.y - thisPosition.y };

	Vector2f intersect = { abs(otherPosition.x - thisPosition.x),abs(otherPosition.y - thisPosition.y) };

	if (intersect.x < 0.f && intersect.y < 0.f)
	{

		if (intersect.x > intersect.y)
		{
			if (delta.x > 0.f)
			{
				move(intersect.x*(1.f - push), 0.f);
				target->move(-intersect.x * (push), 0.f);
			}
			else
			{
				move(-intersect.x*(1.f - push), 0.f);
				target->move(intersect.x * (push), 0.f);
			}
		}
		else
		{
			if (delta.y > 0.f)
			{
				move(0.f, intersect.y*(1.f - push));
				target->move(0.f,-intersect.y * (push));
			}
			else
			{
				move(0.f, -intersect.y*(1.f - push));
				target->move(0.f,intersect.y * (push));
			}
		}
		return true;
	}

	return false;
}

const Vector2f Object::GetHalfSize()
{
	Vector2f halfSize = { getLocalBounds().width / 2.f, getLocalBounds().height / 2.f };
	return halfSize;
}

void Object::Update(const float& deltaTime)
{
	auto gbb = this->getGlobalBounds();
	vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
	vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
	vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
	vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
}

void Object::Update(const Vector2f& mousePosition)
{
	auto gbb = this->getGlobalBounds();
	vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
	vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
	vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
	vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
}

void Object::Render(RenderTarget* target)
{
	if (target && isActive)
	{
		target->draw(*this);

		if (vertices && debugBox)
		{
			target->draw(this->vertices, 5, LinesStrip);
		}
	}
}
