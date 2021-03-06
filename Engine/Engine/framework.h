#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <iostream>
#include <sstream>
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
	// 이 안에 있는 함수의 Math::Function();

	inline const float Length(const float& postionX, const float& positionY)
	{
		return sqrt((postionX * postionX) + (positionY * positionY));
	}

	inline const float Length(const Vector2f& vec1, const Vector2f& vec2)
	{
		Vector2f direction;
		direction.x = vec1.x - vec2.x;
		direction.y = vec1.y - vec2.y;

		return sqrt((direction.x * direction.x) + (direction.y * direction.y));
	}

	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		Vector2f direction;
		direction.x = vec1.x - vec2.x;
		direction.y = vec1.y - vec2.y;

		float length = Length(direction.x, direction.y);
			
		return { direction.x / length, direction.y / length };
	}

	inline int RandomIntager(const int& minimum, const int& maximum)
	{
		static uniform_int_distribution<int> urd(minimum, maximum);
		static default_random_engine dre;

		return urd(dre);
	}

	inline const float RotateAxis(const Vector2f& vec1, const Vector2f& vec2, const float& angle)
	{
		Vector2f normal = Math::Normalize(vec1, vec2);

		return (atan2(normal.y, normal.x) * 180 / PI) + angle;
	}

	inline const float RotateAxis(const Vector2f& vec, const float& angle)
	{
		return (atan2(vec.y, vec.x) * 180 / PI) + angle;
	}
}