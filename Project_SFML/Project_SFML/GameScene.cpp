#include "framework.h"
#include "GameScene.h"
#include "JellyObject.h"
#include "BackGroundObject.h"
#include "Charactor.h"
#include "ResultScene.h"

#define PI 3.13459f

GameScene::GameScene()
{
	Init();
}

GameScene::GameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	backGround = new BackGroundObject("Texture/BackGround/game.png");
	backGround->setScale(3.f, 3.f);

	animationObjects.push_back(new Charactor);

	//data()[0] HP ¹è°æ
	staticObjects.push_back(new StuffObject("Texture/gaugebg_heart02.png", 
		Vector2f(1384.f / 2.f, 75.f)));
	
	//data()[1] HP ¹è°æ µÞ²¿¸®
	staticObjects.push_back(new StuffObject("Texture/gaugebg_heart_tail.png", 
		{ staticObjects.data()[0]->getGlobalBounds().left + staticObjects.data()[0]->getGlobalBounds().width, staticObjects.data()[0]->getPosition().y }));
	
	//data()[2] ³²Àº HP
	staticObjects.push_back(new StuffObject("Texture/gauge_heart_orange.png", 
		{ staticObjects.data()[0]->getPosition().x, staticObjects.data()[0]->getPosition().y }));
	
	//data()[3] HP¹°¾à
	staticObjects.push_back(new StuffObject("Texture/icon_heartLife.png", 
		{ staticObjects.data()[2]->getGlobalBounds().left, staticObjects.data()[2]->getPosition().y }));
	
	//data()[4] ³²Àº HP ²¿¸®
	staticObjects.push_back(new StuffObject("Texture/effect_gaugeHeart_Shine01.png", 
		{ staticObjects.data()[2]->getGlobalBounds().width, staticObjects.data()[2]->getPosition().y }));
	staticObjects.data()[4]->setPosition(
		staticObjects.data()[2]->getGlobalBounds().left + staticObjects.data()[2]->getGlobalBounds().width,
		staticObjects.data()[2]->getPosition().y);

	for (int i = 0; i < 20; ++i)
	{
		jellys.push_back(new JellyObject(Orange));
	}
	for (int i = 0; i < 20; ++i)
	{
		jellys.push_back(new JellyObject(Pupple));
	}
	for (int i = 0; i < 20; ++i)
	{
		jellys.push_back(new JellyObject(Green));
	}

	int i = 0;
	for (auto& j : jellys)
	{
		j->setPosition(Vector2f(100 + i * 100.f, 475.f));
		i++;
	}

	mTexts["Score"] = new TextObject("Score : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", Vector2f(1200.f, 150.f));
	
	mButtons["JUMP"] = new Button("Texture/Buttons/btn_pair1168169_L.png", "Texture/Buttons/btn_pair1168169_L_dim.png", Vector2f(150.f, 600.f));
	mButtons["JUMP"]->setScale(0.8f, 0.8f);
	mButtons["SLIDE"] = new Button("Texture/Buttons/btn_pair1168169_R.png", "Texture/Buttons/btn_pair1168169_R_dim.png", Vector2f(1234.f, 600.f));
	mButtons["SLIDE"]->setScale(0.8f, 0.8f);
}

Vector2f GameScene::JellyPattern(int pattern)
{
	static int degree = 0;

	Vector2f position;
	position.x = 100.f * jellys.size();

	switch (pattern)
	{
	case SIN:
	{
		position.y = 720.f - abs(sin(PI * (++degree * 10) / 180) * 700);
		break;
	}
	case ABS:
	{
		break;
	}
	case 2:
	{
		break;
	}
	default:
		break;
	}
	
	if (position.y > 475.f)
	{
		position.y = 475.f;
	}
	else if (position.y < 0.f)
	{
		position.y = 0;
	}
	return position;
}

void GameScene::Destroy()
{
}

void GameScene::Input(Event* e)
{
	if (mButtons["JUMP"]->IsPressed())
	{
		dynamic_cast<Charactor*>(animationObjects.data()[0])->Jump();
	}
}

void GameScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;

	if ((elapsedTime += deltaTime) >= 1.f)
	{
		staticObjects.data()[2]->setTextureRect(IntRect(0, 0, staticObjects.data()[2]->getTextureRect().width - 10, staticObjects.data()[2]->getTextureRect().height));
		staticObjects.data()[4]->setPosition(staticObjects.data()[2]->getGlobalBounds().left + staticObjects.data()[2]->getGlobalBounds().width, staticObjects.data()[2]->getPosition().y);
		elapsedTime = 0.f;
	}

	

	if (mButtons["SLIDE"]->IsPressed())
	{
		dynamic_cast<Charactor*>(animationObjects.data()[0])->SetState(SLIDE);
	}

	for (auto& jelly : jellys)
	{
		if (jelly->IsActive())
		{
			jelly->Update(deltaTime);

			if (jelly->getPosition().x <= 0.f)
			{
				jelly->setPosition(JellyPattern(jellyPattern));
			}


			if (animationObjects.data()[0]->getGlobalBounds().intersects(jelly->getGlobalBounds()))
			{
				jelly->SetActive(false);
				player->hp -= 10;
			}
		}
	}

	if (player->hp <= 0)
	{

	}


	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
	}

	for (auto& j : jellys)
	{
		if (j->IsActive())
		{
			window->draw(*j);
			if (j->GetHitBoxActive())
			{
				window->draw(j->GetHitBox(), 5, LinesStrip);
			}
		}
	}

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
			if (obj->GetHitBoxActive())
			{
				window->draw(obj->GetHitBox(), 5, LinesStrip);
			}
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
			if (obj->GetHitBoxActive())
			{
				window->draw(obj->GetHitBox(), 5, LinesStrip);
			}
		}
	}

	for (auto& btn : mButtons)
	{
		window->draw(*btn.second);
	}

	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}


}
