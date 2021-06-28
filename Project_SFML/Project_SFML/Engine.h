#pragma once

// 전방선언
class AnimationObject;

// 게임 전체를 이르는 클래스
class Engine final // final : 더이상 이 클래스에게 상속받지 않는다.
{
public: /* 생성자, 소멸자 */

	Engine();
	~Engine();

private:/* 맴버 변수 */

	RenderWindow* window = nullptr;
	Event evt;

	Clock timer;
	float deltaTime = 0.f;

	vector<AnimationObject*> obj;

private:/* 메소드 */

	// 엔진을 초기화 하는 함수
	void Init();

	// 현재 살아있는 오브젝트를 업데이트한다.
	void Update();

	// 윈도우상의 입력값을 처리한다.
	void Input();

public:

	// 엔진이 없어지기전에 호출되는 함수
	void Destroy();

	// 윈도우에 결과물을 출력한다.
	void Render();

};

