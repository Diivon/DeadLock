#pragma once
#include <random>
#include <ctime>

namespace DL
{
	template<class T>
	T getRandom(T l, T h);

	template<>
	float getRandom(float l, float h);

	template<>
	int getRandom(int l, int h);
}