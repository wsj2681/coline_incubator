#include "framework.h"
#include "TextObject.h"

TextObject::TextObject()
{
}

TextObject::TextObject(const string& text, const string& fontFilePath, const Vector2f& position)
{
	Init(text, fontFilePath, position);
}

void TextObject::Init(const string& text, const string& fontFilePath, const Vector2f& position)
{
	font = new Font;
	font->loadFromFile(fontFilePath);
	this->setFont(*font);
	this->setString(text);
	this->setFillColor(Color::White);
	this->setOrigin(getLocalBounds().width / 2.f, getLocalBounds().height / 2.f);
	this->setPosition(position);
}
