#pragma once
#include <random>
#include <ctime>

namespace DL
{
	enum class Distribution
	{
		Normal,
		Float
	};

	template<class T, Distribution Y>
	struct getStdDistByDL {};

	template<>
	struct getStdDistByDL<float, Distribution::Float> {
		typedef std::uniform_real_distribution<float> type;
	};

	template<>
	struct getStdDistByDL<float, Distribution::Normal> {
		typedef std::normal_distribution<float> type;
	};

	template<>
	struct getStdDistByDL<int, Distribution::Float> {
		typedef std::uniform_int_distribution<int> type;
	};

	template<>
	struct getStdDistByDL<int, Distribution::Normal> {
		typedef std::normal_distribution<float> type;
	};


	template<class T = float,Distribution Y = Distribution::Float, class E = std::mt19937>//float float
	class Random {
	public:
		static inline T get(T l, T h) {
			static E engine(static_cast<unsigned int>(time(0)));
			static typename getStdDistByDL<T, Y>::type dist(l, h);
			return static_cast<T>(dist(engine));
		}
	};

}