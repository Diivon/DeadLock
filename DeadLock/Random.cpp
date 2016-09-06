#include "DL/Random.h"

template<class T>
T DL::getRandom(T l, T h) { static_assert(false, "use DL::getRandom with float/int only!") }

template<>
int DL::getRandom(int l, int h) {
	static std::random_device rd;
	static std::mt19937 mt(time(0));
	static std::uniform_int_distribution<int> urd(l, h);
	return urd(mt);
}
template<>
float DL::getRandom(float l, float h) {
	static std::random_device rd;
	static std::mt19937 mt(time(0));
	static std::uniform_real_distribution<float> urd(l, h);
	return urd(mt);
}