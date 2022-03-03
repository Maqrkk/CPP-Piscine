#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	std::cout << "Cure copy constructor" << std::endl;
	*this = src;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor" << std::endl;
	return ;
}

Cure			&Cure::operator=(Cure const &src)
{
	AMateria::operator=(src);
	return (*this);
}

AMateria		*Cure::clone(void) const
{
	AMateria		*tmp;

	tmp = new Cure(*this);
	return (tmp);
}

void			Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
