#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = src;
	return ;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh..." << std::endl;
	return ;
}

TacticalMarine	&TacticalMarine::operator=(TacticalMarine const &src)
{
	(void) src;
	return (*this);
}

ISpaceMarine	*TacticalMarine::clone(void) const
{
	ISpaceMarine	*tmp;

	tmp = new TacticalMarine(*this);
	return (tmp);
}

void			TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
