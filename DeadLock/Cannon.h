#pragma once
#include "Vec2.h"
#include "Bullet.h"
#include <iostream>

namespace DL
{
	class Cannon
	{
		friend class Camera;
		friend class Ship;
		Cannon(Cannon &) = delete;
		Cannon(Cannon &&) = delete;
		void operator = (Cannon &) = delete;
		void operator = (Cannon &&) = delete;
		Ship * _owner;
	public:
		Cannon() {}
		void shoot(const Vec2 & pos, const Vec2 & dir) const {
			auto it = Bullet::bullet_list.emplace(Bullet::bullet_list.cend(), _owner, pos, dir);
			it->_it = it;
		}
	};
}