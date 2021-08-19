#include "framework.h"
#include "CrossBomb.h"

CrossBomb::CrossBomb()
{
	Init();
}

void CrossBomb::Init()
{
	Texture* texture = nullptr;
	
	string filePath = "Textures/Object/Bomb/";
	string filetype = ".png";

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "bubble0" + to_string(i) + filetype);
		this->bombAnimation.push_back(texture);
	}

	for (int i = 0; i < 3; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "bomb0" + to_string(i) + filetype);
		this->boomAnimation.push_back(texture);
	}

	vector<Texture*> rightEndAnimation;
	vector<Texture*> leftEndAnimation;
	vector<Texture*> topEndAnimation;
	vector<Texture*> bottomEndAnimation;
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{
			texture = new Texture;
			texture->loadFromFile(filePath + "rightend/tile00" + to_string(i) + filetype);
			if (j == 0)
			{
				rightEndAnimation.push_back(texture);
			}
			else if (j == 1)
			{
				leftEndAnimation.push_back(texture);
			}
			else if (j == 2)
			{
				topEndAnimation.push_back(texture);
			}
			else if (j == 3)
			{
				bottomEndAnimation.push_back(texture);
			}
			
		}
		
	}

	vector<Texture*> rightMidAnimation;
	vector<Texture*> leftMidAnimation;
	vector<Texture*> topMidAnimation;
	vector<Texture*> bottomMidAnimation;

	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			texture = new Texture;
			texture->loadFromFile(filePath + "rightmid/tile00" + to_string(i) + filetype);
			if (j == 0)
			{
				rightMidAnimation.push_back(texture);
			}
			else if (j == 1)
			{
				leftMidAnimation.push_back(texture);
			}
			else if (j == 2)
			{
				topMidAnimation.push_back(texture);
			}
			else if (j == 3)
			{
				bottomMidAnimation.push_back(texture);
			}
		}
	}

	pairObject* right = new pairObject;
	right->first = new AnimationObject();
	right->first->SetAnimation(&rightMidAnimation, 0.4f);
	right->second = new AnimationObject();
	right->second->SetAnimation(&rightEndAnimation, 0.4f);

	pairObject* left = new pairObject;
	left->first = new AnimationObject();
	left->first->setRotation(180.f);
	left->first->SetAnimation(&leftMidAnimation, 0.4f);
	left->second = new AnimationObject();
	left->second->setRotation(180.f);
	left->second->SetAnimation(&leftEndAnimation, 0.4f);

	pairObject* top = new pairObject;
	top->first = new AnimationObject();
	top->first->SetAnimation(&topMidAnimation, 0.4f);
	top->first->setRotation(270.f);
	top->second = new AnimationObject();
	top->second->SetAnimation(&topEndAnimation, 0.4f);
	top->second->setRotation(270.f);

	pairObject* bottom = new pairObject;
	bottom->first = new AnimationObject();
	bottom->first->SetAnimation(&bottomMidAnimation, 0.4f);
	bottom->first->setRotation(90.f);

	bottom->second = new AnimationObject();
	bottom->second->SetAnimation(&bottomEndAnimation, 0.4f);
	bottom->second->setRotation(90.f);

	bombLeafObjects["right"] = right;
	bombLeafObjects["left"] = left;
	bombLeafObjects["top"] = top;
	bombLeafObjects["bottom"] = bottom;

	for (auto& p : bombLeafObjects)
	{
		p.second->first->setOrigin(20.f, 20.f);
		p.second->second->setOrigin(20.f, 20.f);
	}
	isActive = false;
	isLive = false;

}

void CrossBomb::Destroy()
{
	AnimationObject::Destroy();
}

void CrossBomb::SetBomb(const Vector2f& position)
{
	this->setPosition(position);
	isLive = true;
	isActive = true;
	lifeTime = 3.f;
	keyFrame = 0;
}

void CrossBomb::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float frame = 0.f;
	frame += 0.1f;

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;
	lifeTime -= deltaTime;

	if (lifeTime <= 0.f && isLive)
	{
		lifeTime = 3.f;
		isLive = false;
		keyFrame = 0;
		bombLeafAnimation = true; // 3초마다 true 로 바뀌어서 물줄기가 렌더링된다.
	}

	if (elapsedTime >= frameTime)
	{
		if (isLive)
		{
			setTexture(*bombAnimation.data()[keyFrame % bombAnimation.size()]);
			setTextureRect({ 0, 0, 46, 46 });
		}
		else
		{
			setTexture(*boomAnimation.data()[keyFrame % boomAnimation.size()]);
			setTextureRect({ 0, 0, 40, 40 });
		}
		keyFrame++;
		elapsedTime = 0.f;
	}

	auto ggb = this->getGlobalBounds();


	if ((int)frame % 8 >= 7)
	{
		bombLeafAnimation = false; // 물줄기 애니메이션 한 루프를 돌면 물줄기 렌더링을 끈다.
		if (isLive == false)
		{
			isActive = false;
		}
	}

	if (bombLeafAnimation == true)
	{
		for (auto& p : bombLeafObjects)
		{
			p.second->first->Update(deltaTime);
			p.second->second->Update(deltaTime);

			auto midgb = p.second->first->getGlobalBounds();

			unsigned int frameInt = frame;
			p.second->first->SetKeyFrame(frameInt);
			p.second->second->SetKeyFrame(frameInt);

			if (p.first == "right")
			{
				p.second->first->setPosition({ ggb.left + ggb.width + ggb.width / 2.f, ggb.top + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width + midgb.width / 2.f, midgb.top + midgb.height / 2.f });
			}
			else if (p.first == "left")
			{
				p.second->first->setPosition({ ggb.left - ggb.width / 2.f, ggb.top + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left - midgb.width / 2.f,  midgb.top + midgb.height / 2.f });
			}
			else if (p.first == "top")
			{
				p.second->first->setPosition({ ggb.left + ggb.width / 2.f, ggb.top - ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width / 2.f, midgb.top - midgb.height / 2.f });
			}
			else if (p.first == "bottom")
			{
				p.second->first->setPosition({ ggb.left + ggb.width / 2.f, ggb.top + ggb.height + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width / 2.f, midgb.top + midgb.height + ggb.height / 2.f });
			}
		}
	}
}

void CrossBomb::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);
}

void CrossBomb::Render(RenderTarget* target)
{
	AnimationObject::Render(target);

	if (bombLeafAnimation == true)
	{
		for (auto& p : bombLeafObjects)
		{
			p.second->first->Render(target);
			p.second->second->Render(target);
		}
	}
}
