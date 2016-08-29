#include "Camera.h"
#include <iostream>

static void print_Vec2(const DL::Vec2 & a)
{
	std::cout << a.x << ' ' << a.y << ' ' << a.getLength() << std::endl;
}

DL::Camera::Camera(const Vec2 & pos, sf::RenderWindow & wind) :
	_pos(pos), _window(&wind) {
	auto size = _window->getSize();
	_half_height = size.y / 2;
	_half_width = size.x / 2;
	_pos -= DL::Vec2(_half_width, _half_height);
}
DL::Camera::~Camera() {
}

void DL::Camera::clear() const {
	_window->clear(sf::Color::Blue);
}
void DL::Camera::render(const sf::Drawable & a) const {
	_window->draw(a);
}
void DL::Camera::render(const DL::Ship & a) const {
	sf::ConvexShape shape(a._points);
	shape.setPosition(a._pos.minus(_pos));
	_window->draw(shape);
}
void DL::Camera::render(const DL::Bullet & a) const {
	sf::CircleShape circle(5);
	circle.setPosition(a._pos.minus(_pos));
	circle.setFillColor(sf::Color::Black);
	_window->draw(circle);
}
void DL::Camera::renderList(const std::list<DL::Ship> & list) const {
	for (auto i = list.cbegin(); i != list.cend(); ++i)
		this->render(*i);
}
void DL::Camera::renderList(const std::list<DL::Bullet> & list) const {
	for (auto i = list.cbegin(); i != list.cend(); ++i)
		this->render(*i);
}
void DL::Camera::show() const {
	_window->display();
}
void DL::Camera::follow(const DL::Ship & a) {
	_pos.x += (a._pos.x - _pos.x - _half_width) * Camera::follow_speed;
	_pos.y += (a._pos.y - _pos.y - _half_height) * Camera::follow_speed;
}