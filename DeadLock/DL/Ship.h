#pragma once
#include "DL/Vec2.h"
#include "SFML/Graphics.hpp"
#include <list>
#include <array>
#include "DL/Bullet.h"

namespace DL
{
	class Ship
	{
		friend class Camera;
		Vec2 _look;//move direction
		Vec2 _pos;//position in world
		float _ang;//angle, on which ship is rotated
		sf::ConvexShape _points;//coords about _pos
		struct ShipSide {
			float shoot_cooldown;//in ms, when it > shoot_cooldown ready to fire
			float HP;//health points
			std::array<Vec2, 5> _cannon_pos;//Cannon positions about _pos
		} _left_side, _right_side;//:))

		Ship() = delete;
		Ship(const Ship &) = delete;
		Ship(Ship &&) = delete;
		void operator = (Ship &&) = delete;
		void operator = (const Ship &) = delete;
	public:
		static float move_speed;//in px / ms
		static float rotate_speed;//in degree / ms
		static float shoot_cooldown;//in ms
		static float shoot_dispersion;//is degree
		static std::list<Ship> ship_list;//list(owner) for renderer, every ship must be in it

		Ship(const Vec2 & pos, const Vec2 & look);
		~Ship();
		void moveOn(const Vec2 & a);
		void moveTo(const Vec2 & a);
		void rotate(float angle);
		void shootLeft();
		void shootRight();

		void update(const float & delta_time);
	};
}