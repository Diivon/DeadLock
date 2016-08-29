#include "SFML/Graphics.hpp"
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Time.hpp"
#include "Vec2.h"
#include "Ship.h"
#include "Bullet.h"
#include "Camera.h"
#include <iostream>
#include <list>

void initAllStatics(float a);

std::ostream & operator << (std::ostream & stream, const DL::Vec2 & a) {
	stream << a.x << ' ' << a.y << std::endl;
	return stream;
}

inline void processEvents(sf::RenderWindow & w)
{
	sf::Event event;
	while (w.pollEvent(event)) {
		if (event.type == sf::Event::Closed) { w.close(); continue; }
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Escape)
				w.close();
	}
}

const int c_framesPerSecond = 60;
const float c_MillisecondsForOneFrame = 1'000 / c_framesPerSecond;

int main()
{
	initAllStatics(c_MillisecondsForOneFrame);

	sf::ContextSettings camera_settings;
	camera_settings.antialiasingLevel = 0;
	sf::RenderWindow main_window(sf::VideoMode(800,600), "DeadLock", sf::Style::Close, camera_settings);

	auto camera = DL::Camera(DL::Vec2(100, 100), main_window);

	DL::Ship::ship_list.emplace_back(DL::Vec2(50, 50), DL::Vec2(0, 1));
	DL::Ship::ship_list.emplace_back(DL::Vec2(200, 200), DL::Vec2(0, 1));

	DL::Ship & player = DL::Ship::ship_list.front();

	sf::Clock clock;
	while (main_window.isOpen())
	{
		clock.restart();

		processEvents(main_window);

		player.update();
		DL::Bullet::updateList(DL::Bullet::bullet_list);
		camera.follow(player);

		camera.clear();
		camera.renderList(DL::Ship::ship_list);
		camera.renderList(DL::Bullet::bullet_list);
		camera.show();

		float time = clock.getElapsedTime().asMilliseconds();
		if (time < c_MillisecondsForOneFrame) sf::sleep(sf::milliseconds(c_MillisecondsForOneFrame - time));
	}
	return 0;
}