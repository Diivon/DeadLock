#include "Ship.h"
#include "Bullet.h"
#include "Camera.h"


float DL::Ship::move_speed;
float DL::Ship::rotate_speed;
float DL::Ship::shoot_cooldown;
std::list<DL::Ship> DL::Ship::ship_list;

float DL::Bullet::move_speed;
float DL::Bullet::lifetime;
std::list<DL::Bullet> DL::Bullet::bullet_list;

float DL::Camera::follow_speed;

void initAllStatics(float milliseconds_per_frame)
{
	DL::Ship::move_speed = 120.0f / milliseconds_per_frame;
	DL::Ship::rotate_speed = 50.0f / milliseconds_per_frame;
	DL::Ship::shoot_cooldown = 2000;
	DL::Ship::ship_list = std::list<DL::Ship>();

	DL::Bullet::move_speed = 100.0f / milliseconds_per_frame;
	DL::Bullet::lifetime = 5000;
	DL::Bullet::bullet_list = std::list<DL::Bullet>();

	DL::Camera::follow_speed = 0.02f;
}