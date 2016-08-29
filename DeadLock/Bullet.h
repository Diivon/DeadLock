#pragma once
#include "Vec2.h"
#include <list>

namespace DL
{
	class Ship;
	class Bullet
	{
		friend class Camera;
		Ship * _owner;
		Vec2 _pos;
		Vec2 _look;
		float _lifetime;

		Bullet() = delete;
		Bullet(const Bullet &) = delete;
		Bullet(Bullet &&) = delete;
		void operator = (const Bullet &) = delete;
		void operator = (Bullet &&) = delete;
	public:
		static float move_speed;
		static std::list<Bullet> bullet_list;
		static void updateList(std::list<Bullet> &);

		Bullet(Ship * owner, const Vec2 & position, const Vec2 & direction);
		void update();
		void searchCollides(const std::list<Ship> &);
	};
}