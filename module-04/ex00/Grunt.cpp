#include "Grunt.hpp"
#include <iostream>

Grunt::Grunt(std::string const &name) : Victim(name)
{
	std::cout << "Flip flop." << std::endl;
	return ;
}

Grunt::Grunt(Grunt const &src) : Victim(src._name)
{
	std::cout << "Flip flop." << std::endl;
	return ;
}

Grunt::~Grunt(void)
{
	std::cout << "Derp.." << std::endl;
	return ;
}

Grunt	&Grunt::operator=(Grunt const &src)
{
	Victim::operator=(src);
	return (*this);
}

void	Grunt::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a perifalk!" << std::endl;
}
