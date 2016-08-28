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
void DL::Ship::update()
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
}
void DL::Ship::shootLeft()
{
	Bullet::bullet_list.emplace_back(this, _pos, Vec2(-_look.y, _look.x));
}
void DL::Ship::shootRight()
{
	Bullet::bullet_list.emplace_back(this, _pos, Vec2(_look.y, -_look.x));
}
void DL::Ship::shoot(DL::Direction)
{
	//static_assert(false, "todo!");
}
