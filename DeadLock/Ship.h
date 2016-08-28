#pragma once
#include "Vec2.h"
#include "SFML/Graphics.hpp"
#include <list>
#include "Bullet.h"

namespace DL
{
	class Ship
	{
		friend class Camera;
		Vec2 _look;
		Vec2 _pos;
		sf::ConvexShape _points;

		Ship() = delete;
		Ship(const Ship &) = delete;
		Ship(Ship &&) = delete;
		void operator = (Ship &&) = delete;
		void operator = (const Ship &) = delete;
	public:
		static float move_speed;
		static float rotate_speed;
		static std::list<Ship> ship_list;

		Ship(const Vec2 & pos, const Vec2 & look);
		~Ship();
		void moveOn(const Vec2 & a);
		void moveTo(const Vec2 & a);
		void rotate(float angle);
		void shoot(Direction);
		void shootLeft();
		void shootRight();

		void update();
	};
}