#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <fstream>
#include <random>
using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr
constexpr float PI = 3.14159265f;

namespace Math
{
	inline const float Length(const float& posX, const float& posY)
	{
		return sqrt((posX * posX) + (posY * posY));
	}

	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		float dirX = vec1.x - vec2.x;
		float dirY = vec1.y - vec2.y;

		float length = Length(dirX, dirY);

		return { dirX / length, dirY / length };
	}

	inline const float RotateAxis(const Vector2f& vec1, const Vector2f& vec2, const float& angle)
	{
		Vector2f normal = Normalize(vec1, vec2);
		return ((atan2(normal.y, normal.x) * 180.f / PI)) + angle;
	}

	inline const float RandomFloat(const float& maximum)
	{
		static std::uniform_real_distribution<float> urd(0.f, maximum);
		static std::default_random_engine dre;

		return urd(dre);
	}

	inline const int RandomIntiger(const int& maximum)
	{
		static std::uniform_int_distribution<int> urd(0, maximum);
		static std::default_random_engine dre;

		return urd(dre);
	}
}