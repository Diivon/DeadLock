#include "Ship.h"

DL::Ship::Ship(const Vec2 & pos, const Vec2 & look) :
	_look(look), _pos(pos), _points(6)
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
	
	_left_side.HP = 100;
	_left_side.shoot_cooldown = 0;

	_right_side.HP = 100;
	_right_side.shoot_cooldown = 0;
}
DL::Ship::~Ship() {}
void DL::Ship::moveOn(const Vec2 & a) {
	_pos += a;
}
void DL::Ship::moveTo(const Vec2 & a) {
	_pos = a;
}
void DL::Ship::rotate(float angle) {
	_points.rotate(angle);
	_look.rotate(angle);
}
void DL::Ship::update(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->moveOn(_look * move_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			this->rotate(-rotate_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			this->rotate(rotate_speed);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		this->shootLeft();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		this->shootRight();

	_left_side.shoot_cooldown += dt;
	_right_side.shoot_cooldown += dt;
}
void DL::Ship::shootLeft()
{
	if (_left_side.shoot_cooldown >= Ship::shoot_cooldown) {
		DL::Vec2 dir(_look.y, -_look.x);
		for (auto i = _left_side._cannons.cbegin(); i != _left_side._cannons.cend(); ++i)
			i->shoot(_pos, dir);
		_left_side.shoot_cooldown = 0;
	}
}
void DL::Ship::shootRight()
{
	if (_right_side.shoot_cooldown >= Ship::shoot_cooldown) {
		DL::Vec2 dir(-_look.y, _look.x);
		for (auto i = _right_side._cannons.cbegin(); i != _right_side._cannons.cend(); ++i)
			i->shoot(_pos, dir);
		_right_side.shoot_cooldown = 0;
	}
}
