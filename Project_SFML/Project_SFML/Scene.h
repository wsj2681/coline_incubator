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

	// 배경화면
	Object* backGround = nullptr;

	// 애니메이션이 되는 오브젝트 컨테이너
	vector<Object*> animationObjects;

	// 애니메이션이 없는 오브젝트 컨테이너
	vector<Object*> staticObjects;

	// 텍스트 컨테이너
	map<string, TextObject*> mTexts;

	// 버튼 컨테이너
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// 마우스의 위치 (게임 창 내에서의)
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