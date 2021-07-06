#pragma once

#include "BackGroundObject.h"
#include "Button.h"
#include "TextObject.h"

class Object;

class Scene
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~Scene();

protected:

	// ���ȭ��
	Object* backGround = nullptr;

	// �ִϸ��̼��� �Ǵ� ������Ʈ �����̳�
	vector<Object*> animationObjects;

	// �ִϸ��̼��� ���� ������Ʈ �����̳�
	vector<Object*> staticObjects;

	// �ؽ�Ʈ �����̳�
	map<string, TextObject*> mTexts;

	// ��ư �����̳�
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// ���콺�� ��ġ (���� â ��������)
	Vector2f mousePosition{ 0.f, 0.f };

	bool quit = false;

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render();

};