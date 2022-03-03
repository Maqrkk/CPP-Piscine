#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	this->_printName();
	std::cout << "is born!" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	this->_printName();
	std::cout << "is born!" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	this->_printName();
	std::cout << "is dead. Consequences will never be the same!" << std::endl;
	return ;
}

Sorcerer			&Sorcerer::operator=(Sorcerer const &src)
{
	this->_name = src._name;
	this->_title = src._title;
	return (*this);
}

std::string const	&Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string const	&Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void				Sorcerer::polymorph(Victim const &target) const
{
	target.getPolymorphed();
}

void				Sorcerer::_printName(void) const
{
	std::cout << this->_name << ", " << this->_title << ", ";
}

Sorcerer::Sorcerer(void)
{
	return ;
}

std::ostream		&operator<<(std::ostream &o, Sorcerer const &src)
{
	o << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies!" << std::endl;
	return (o);
}
