#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src._hp, src._type)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return ;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh..." << std::endl;
	return ;
}

SuperMutant		&SuperMutant::operator=(SuperMutant const &src)
{
	Enemy::operator=(src);
	return (*this);
}

void			SuperMutant::takeDamage(int amount)
{
	Enemy::takeDamage(amount - 3);
}
