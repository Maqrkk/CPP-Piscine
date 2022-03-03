#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src._hp, src._type)
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion		&RadScorpion::operator=(RadScorpion const &src)
{
	Enemy::operator=(src);
	return (*this);
}
