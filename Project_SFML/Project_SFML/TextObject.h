#pragma once
class TextObject final : public Text
{
public:
	TextObject();
	TextObject(const string& text, const string& fontFilePath, const Vector2f& position);

private:

	Font* font = nullptr;

private:

	void Init(const string& text, const string& fontFilePath, const Vector2f& position);
};

