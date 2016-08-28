#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "Vec2.h"
#include "Ship.h"

namespace DL
{
	class Camera
	{
		Vec2 _pos;//world coords
		sf::RenderWindow * _window;
		unsigned int _half_height;
		unsigned int _half_width;
	public:
		//static float move_speed;

		Camera(const Vec2 & pos, sf::RenderWindow & wind);
		~Camera();
		void clear() const;
		void render(const Ship &) const;
		void render(const Bullet &) const;
		void render(const sf::Drawable &) const;
		void renderList(const std::list<DL::Ship> & list) const;
		void renderList(const std::list<DL::Bullet> & list) const;
		void follow(const Ship &);
		void show() const;
	};
}