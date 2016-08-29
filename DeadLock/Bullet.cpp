#include "Bullet.h"

void DL::Bullet::updateList(std::list<DL::Bullet> & a) {
	for (auto i = a.begin(); i != a.end(); ++i)
		i->update();
}

DL::Bullet::Bullet(DL::Ship * owner, const Vec2 & position, const Vec2 & direction) :
	_owner(owner), _pos(position), _look(direction)
{}
void DL::Bullet::update()
{
	_pos.x += _look.x * move_speed;
	_pos.y += _look.y * move_speed;
}
void DL::Bullet::searchCollides(const std::list<DL::Ship> & list) {
	//static_assert(false, "todo!");

}