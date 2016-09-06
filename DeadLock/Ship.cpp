#include "DL/Ship.h"
#include "DL/Random.h"
#include <iostream>

DL::Ship::Ship(const Vec2 & pos, const Vec2 & look) :
	_look(look), _pos(pos), _points(6), _ang(0)
{
	_points.setPoint(0, Vec2(0, 10));
	_points.setPoint(1, Vec2(5, -10));
	_points.setPoint(2, Vec2(4, -20));
	_points.setPoint(3, Vec2(-4, -20));
	_points.setPoint(4, Vec2(-5, -10));
	_points.setPoint(5, Vec2(0, 10));
	_points.setOutlineColor(sf::Color::Black);
	_points.setOutlineThickness(1);
	_points.setFillColor(sf::Color(139, 69, 19));

	DL::Vec2 nullVec(0, 0);
	
	_left_side.HP = 100;
	_left_side.shoot_cooldown = Ship::shoot_cooldown;
	_left_side._cannon_pos[0] = DL::Vec2(2, 2);
	_left_side._cannon_pos[1] = DL::Vec2(3, -2);
	_left_side._cannon_pos[2] = DL::Vec2(4, -6);;
	_left_side._cannon_pos[3] = DL::Vec2(5, -10);
	_left_side._cannon_pos[4] = DL::Vec2(4.5, -15);

	_right_side.HP = 100;
	_right_side.shoot_cooldown = Ship::shoot_cooldown;
	_right_side._cannon_pos[0] = DL::Vec2(-2, 2);
	_right_side._cannon_pos[1] = DL::Vec2(-3, -2);
	_right_side._cannon_pos[2] = DL::Vec2(-4, -6);
	_right_side._cannon_pos[3] = DL::Vec2(-5, -10);
	_right_side._cannon_pos[4] = DL::Vec2(-4.5, -15);
}
DL::Ship::~Ship() {}
void DL::Ship::moveOn(const Vec2 & a) {
	_pos += a;
}
void DL::Ship::moveTo(const Vec2 & a) {
	_pos = a;
}
void DL::Ship::rotate(float angle) {
	float _angle = angle / 180 * Pi;
	float coss = cos(_angle);
	float sinn = sin(_angle);
	_points.rotate(angle);
	_look.rotateCS(coss, sinn);
	for (auto & i : _left_side._cannon_pos)
		i.rotateCS(coss, sinn);
	for (auto & i : _right_side._cannon_pos)
		i.rotateCS(coss, sinn);
}
void DL::Ship::update(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->moveOn(_look.operator*(move_speed * dt));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			this->rotate(-rotate_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			this->rotate(rotate_speed);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (_left_side.shoot_cooldown >= Ship::shoot_cooldown)
			this->shootLeft();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		if (_right_side.shoot_cooldown >= Ship::shoot_cooldown)
			this->shootRight();
	}

	_left_side.shoot_cooldown += dt;
	_right_side.shoot_cooldown += dt;
}
void DL::Ship::shootLeft()
{
	DL::Vec2 dir(_look.y, -_look.x);
	for (auto i = _left_side._cannon_pos.cbegin(); i != _left_side._cannon_pos.cend(); ++i) {
		auto deg = DL::getRandom<float>(-shoot_dispersion, shoot_dispersion);
		auto bullDir = dir.getRotatedDeg(deg);

		auto it = Bullet::bullet_list.emplace(Bullet::bullet_list.cend(), this, i->plus(_pos), bullDir);
		it->_it = it;
	}
	_left_side.shoot_cooldown = 0;
}
void DL::Ship::shootRight()
{
	DL::Vec2 dir(-_look.y, _look.x);
	for (auto i = _right_side._cannon_pos.cbegin(); i != _right_side._cannon_pos.cend(); ++i) {
		auto deg = DL::getRandom<float>(-shoot_dispersion, shoot_dispersion);
		auto bullDir = dir.getRotatedDeg(deg);

		auto it = Bullet::bullet_list.emplace(Bullet::bullet_list.cend(), this, i->plus(_pos), bullDir);
		it->_it = it;
	}
	_right_side.shoot_cooldown = 0;
}