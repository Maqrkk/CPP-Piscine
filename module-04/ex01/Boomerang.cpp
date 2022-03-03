#include "Boomerang.hpp"
#include <iostream>

Boomerang::Boomerang(void) : AWeapon("Boomerang", 2, 15)
{
	return ;
}

Boomerang::Boomerang(Boomerang const &src) : AWeapon(src._name, src._apcost, src._damage)
{
	*this = src;
	return ;
}

Boomerang::~Boomerang(void)
{
	return ;
}

Boomerang			&Boomerang::operator=(Boomerang const &src)
{
	AWeapon::operator=(src);
	return (*this);
}

void				Boomerang::attack(void) const
{
	std::cout << "* WOOSH WOosh woosh wooSH WOOSH. *" << std::endl;
}
