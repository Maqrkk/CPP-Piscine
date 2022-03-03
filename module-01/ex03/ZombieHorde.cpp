#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n)
{
	if (n > 0)
		this->_zombies = new Zombie[n];
	this->_amount = n;
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	if (this->_amount > 0)
		delete[] this->_zombies;
	return ;
}

void		ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_amount; i++)
	{
		this->_zombies[i].announce();
	}
}
