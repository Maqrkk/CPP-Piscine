#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type), _xp(0)
{
	std::cout << "AMateria constructor" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) : _type(src.getType())
{
	std::cout << "AMateria copy constructor" << std::endl;
	*this = src;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor" << std::endl;
	return ;
}

AMateria			&AMateria::operator=(AMateria const &src)
{
	this->_xp = src._xp;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter &target)
{
	this->_xp += 10;
	(void)target;
}
