#include "Bullet.h"
#include <iostream>

void DL::Bullet::updateList(std::list<DL::Bullet> & a, const float & dt) {
	for (auto i = a.begin(); i != a.end(); ++i)
		i->update(dt);
}

DL::Bullet::Bullet(DL::Ship * owner, const Vec2 & position, const Vec2 & direction) :
	_owner(owner), _pos(position), _look(direction), _lifetime(0)
{}
void DL::Bullet::update(const float & dt)
{
	_pos.x += _look.x * move_speed;
	_pos.y += _look.y * move_speed;
	_lifetime += dt;
	if (_lifetime >= Bullet::lifetime)
		this->destroySelf();
}
void DL::Bullet::searchCollides(const std::list<DL::Ship> & list) {
	//static_assert(false, "todo!");
}
void DL::Bullet::destroySelf() {
	DL::Bullet::bullet_list.erase(_it);
}
DL::Bullet::~Bullet(){
}