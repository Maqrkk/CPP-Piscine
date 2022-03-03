#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src)
{
	std::cout << "* teleports from space *" << std::endl;
	*this = src;
	return ;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back..." << std::endl;
	return ;
}

AssaultTerminator	&AssaultTerminator::operator=(AssaultTerminator const &src)
{
	(void) src;
	return (*this);
}

ISpaceMarine		*AssaultTerminator::clone(void) const
{
	ISpaceMarine	*tmp;

	tmp = new AssaultTerminator(*this);
	return (tmp);
}

void				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
