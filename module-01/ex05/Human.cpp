#include "Human.hpp"

Human::Human(void)
{
	return ;
}

Human::~Human(void)
{
	return ;
}

const Brain		&Human::getBrain(void) const
{
	return (this->_brain);
}

std::string		Human::identify(void) const
{
	return (this->_brain.identify());
}
