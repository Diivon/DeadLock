#include "Ship.h"
#include "Bullet.h"
#include "Camera.h"


float DL::Ship::move_speed;
float DL::Ship::rotate_speed;
std::list<DL::Ship> DL::Ship::ship_list;

float DL::Bullet::move_speed;
std::list<DL::Bullet> DL::Bullet::bullet_list;

void initAllStatics(float milliseconds_per_frame)
{
	DL::Ship::move_speed = 100.0f / milliseconds_per_frame;
	DL::Ship::rotate_speed = 50.0f / milliseconds_per_frame;
	DL::Ship::ship_list = std::list<DL::Ship>();

	DL::Bullet::move_speed = 100.0f / milliseconds_per_frame;
	DL::Bullet::bullet_list = std::list<DL::Bullet>();

}