#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"

namespace DL
{
	const float Pi = 3.1415927f;
	enum class Direction
	{
		Ahead,
		Back,
		Right,
		Left
	};


	struct Vec2
	{
		float x, y;

		Vec2(float x, float y) : x(x), y(y) {}
		Vec2() : x(0), y(0) {}
		~Vec2() {}
		Vec2(const Vec2 & a) : x(a.x), y(a.y) {}
		Vec2(Vec2 && a) : x(a.x), y(a.y) {}
		const Vec2 & operator = (const Vec2 & a) { x = a.x; y = a.y; return *this; }
		const Vec2 & operator = (Vec2 && a) { x = a.x; y = a.y; return *this; }
		operator sf::Vector2f() const { return sf::Vector2f(x, y); }
		operator bool()			const { return (x != 0 && y != 0); }

		const Vec2 & operator + () { return *this; }
		const Vec2 & operator - () { x = -x; y = -y; return *this; }

		const Vec2	operator + (const Vec2 & a) { return Vec2(x + a.x, y + a.y); }
		const Vec2	operator - (const Vec2 & a) { return Vec2(x - a.x, y - a.y); }
		const float	operator * (const Vec2 & a) { return (x * a.x) + (y + a.y); }
		const Vec2	operator * (float a) { return Vec2(x * a, y * a); }
		const Vec2  operator / (float a) { return Vec2(x / a, y / a); }

		const Vec2 & operator += (const Vec2 & a) { x += a.x; y += a.y; return *this; }
		const Vec2 & operator -= (const Vec2 & a) { x -= a.x; y -= a.y; return *this; }
		const Vec2 & operator *= (float a) { x *= a; y *= a; return *this; }
		const Vec2 & operator /= (float a) { x /= a; y /= a; return *this; }

		const Vec2 & rotate(float angle) {
			angle = angle / 180 * Pi;
			float coss = std::cos(angle);
			float sinn = std::sin(angle);
			float newX = x * coss - y * sinn;		//x*coss - y*sinn
			y = x * sinn + y * coss;		//x*sinn + y*coss
			x = newX;
			return *this;
		}
		const Vec2 & rotate(float coss, float sinn) {
			float newX = x * coss - y * sinn;		//x*coss - y*sinn
			y = x * sinn + y * coss;		//x*sinn + y*coss
			x = newX;
			return *this;
		}

		const Vec2 getRotated(float angle) const {
			angle = angle / 180 * Pi;
			float coss = std::cos(angle);
			float sinn = std::sin(angle);
			return Vec2(x * coss - y * sinn, x * sinn + y * coss);
		}
		const Vec2 getRotated(float coss, float sinn) const {
			return Vec2(x * coss - y * sinn, x * sinn + y * coss);
		}

		const float getLength() const {
			return std::sqrt(x * x + y * y);
		}
		const Vec2 & normalize() {
			if (x == 0 && y == 0) return *this;
			float len = this->getLength();
			x /= len;
			y /= len;
			return *this;
		}
		const Vec2 getNormalized() const {
			if (x == 0 && y == 0) return Vec2(0, 0);
			float len = this->getLength();
			float nx = x / len;
			float ny = y / len;
			return Vec2(nx, ny);
		}
		const Vec2 & setLength(float l) {
			if (x == 0 && y == 0) return *this;
			float len = this->getLength();
			x /= len; y /= len;
			x *= l;	  y *= l;
			return *this;
		}

		const Vec2 & add(const Vec2 & a)
		{
			x += a.x;
			y += a.y;
			return *this;
		}
		const Vec2 plus(const Vec2 & a) const
		{
			return Vec2(x + a.x, y + a.y);
		}

		const Vec2 & sub(const Vec2 & a) {
			x -= a.x;
			y -= a.y;
		}
		const Vec2 minus(const Vec2 & a) const {
			return Vec2(x - a.x, y - a.y);
		}

		const Vec2 & multiply(float a) {
			x *= a;
			y *= a;
		}
	};
}