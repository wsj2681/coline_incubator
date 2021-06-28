#pragma once

// ���漱��
class AnimationObject;

// ���� ��ü�� �̸��� Ŭ����
class Engine final // final : ���̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{
public: /* ������, �Ҹ��� */

	Engine();
	~Engine();

private:/* �ɹ� ���� */

	RenderWindow* window = nullptr;
	Event evt;

	Clock timer;
	float deltaTime = 0.f;

	vector<AnimationObject*> obj;

private:/* �޼ҵ� */

	// ������ �ʱ�ȭ �ϴ� �Լ�
	void Init();

	// ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.
	void Update();

	// ��������� �Է°��� ó���Ѵ�.
	void Input();

public:

	// ������ ������������ ȣ��Ǵ� �Լ�
	void Destroy();

	// �����쿡 ������� ����Ѵ�.
	void Render();

};

