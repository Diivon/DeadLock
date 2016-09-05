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

void initAllStatics()
{
	DL::Ship::move_speed = 600.0f / 1'000;
	DL::Ship::rotate_speed = 3000.0f / 1'000;
	DL::Ship::shoot_cooldown = 2000;
	DL::Ship::ship_list = std::list<DL::Ship>();

	DL::Bullet::move_speed = 500.0f / 1'000;
	DL::Bullet::lifetime = 5000;
	DL::Bullet::bullet_list = std::list<DL::Bullet>();

	DL::Camera::follow_speed = 0.02f;
}