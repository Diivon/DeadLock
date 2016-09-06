#pragma once
#include "DL/Vec2.h"
#include <list>

namespace DL
{
	class Ship;
	class Bullet
	{
		friend class Camera;
		friend class Ship;
		Ship * _owner;
		Vec2 _pos;
		Vec2 _look;
		float _lifetime;
		std::list<Bullet>::iterator _it;

		Bullet() = delete;
		Bullet(const Bullet &) = delete;
		Bullet(Bullet &&) = delete;
		void operator = (const Bullet &) = delete;
		void operator = (Bullet &&) = delete;
		void destroySelf();
	public:
		static float move_speed;//pix / ms
		static float lifetime;//ms
		static std::list<Bullet> bullet_list;
		static void updateList(std::list<Bullet> &, const float &);

		Bullet(Ship * owner, const Vec2 & position, const Vec2 & direction);
		void update(const float & delta_time);
		~Bullet();
	};
}