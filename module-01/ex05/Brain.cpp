#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)
{
	return ;
}

Brain::~Brain(void)
{
	return ;
}

std::string			Brain::identify(void) const
{
	std::stringstream		idStream;

	idStream << this;
	return (idStream.str());
}
