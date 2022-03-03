#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
	return ;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src._name, src._apcost, src._damage)
{
	*this = src;
	return ;
}

PowerFist::~PowerFist(void)
{
	return ;
}

PowerFist			&PowerFist::operator=(PowerFist const &src)
{
	AWeapon::operator=(src);
	return (*this);
}

void				PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
