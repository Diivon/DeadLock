#include "SFML/Graphics.hpp"
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Time.hpp"
#include "DL/Vec2.h"
#include "DL/Ship.h"
#include "DL/Bullet.h"
#include "DL/Camera.h"
#include "DL/Random.h"
#include <iostream>
#include <list>

void initAllStatics();

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
	initAllStatics();

	sf::ContextSettings camera_settings;
	camera_settings.antialiasingLevel = 0;
	sf::RenderWindow main_window(sf::VideoMode(800,600), "DeadLock", sf::Style::Close, camera_settings);

	auto camera = DL::Camera(DL::Vec2(100, 100), main_window);

	DL::Ship::ship_list.emplace_back(DL::Vec2(0, 0), DL::Vec2(0, 1));
	DL::Ship::ship_list.emplace_back(DL::Vec2(120, 120), DL::Vec2(0, 1));

	DL::Ship & player = DL::Ship::ship_list.front();

	sf::Clock clock;
	while (main_window.isOpen())
	{
		clock.restart();

		processEvents(main_window);
		player.update(c_MillisecondsForOneFrame);
		DL::Bullet::updateList(DL::Bullet::bullet_list, c_MillisecondsForOneFrame);
		camera.follow(player);

		camera.clear();
		camera.renderList(DL::Ship::ship_list);
		camera.renderList(DL::Bullet::bullet_list);
		camera.show();

		//std::cout << DL::getRandom<float>(0.0, 10.0) << std::endl;

		auto time = clock.getElapsedTime().asMilliseconds();
		if (time < c_MillisecondsForOneFrame) sf::sleep(sf::milliseconds(static_cast<sf::Int32>(c_MillisecondsForOneFrame - time)));
	}
	return 0;
}