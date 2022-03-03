#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void)
{
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}

void		ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	Zombie		*zombie;

	zombie = new Zombie(this->_type, name);
	return zombie;
}

Zombie		*ZombieEvent::randomChump(void)
{
	Zombie		*zombie;

	zombie = new Zombie(this->_type);
	zombie->announce();
	return zombie;
}
