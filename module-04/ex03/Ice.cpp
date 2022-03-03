#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	std::cout << "Ice copy constructor" << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor" << std::endl;
	return ;
}

Ice				&Ice::operator=(Ice const &src)
{
	AMateria::operator=(src);
	return (*this);
}

AMateria		*Ice::clone(void) const
{
	AMateria		*tmp;

	tmp = new Ice(*this);
	return (tmp);
}

void			Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
