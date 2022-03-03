#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name): _name(name), _num_pet(0), _num_feed(0), _num_ride(0)
{
	std::cout << this->_name << " the pony has appeared!" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << this->_name << " the pony has vanished into thin air!" << std::endl;
	return ;
}

void		Pony::set_name(std::string name)
{
	this->_name = name;
	std::cout << "The pony's new name is " << this->_name << "." << std::endl;
}

void		Pony::pet(void)
{
	std::cout << "You pet " << this->_name << " the pony." << std::endl;
	this->_num_pet++;
}

void		Pony::feed(void)
{
	std::cout << "You feed " << this->_name << " the pony." << std::endl;
	this->_num_feed++;
}

void		Pony::ride(void)
{
	std::cout << "You ride " << this->_name << " the pony." << std::endl;
	this->_num_ride++;
}

void		Pony::print_status(void) const
{
	std::cout << "The pony's name is " << this->_name << "." << std::endl;
	std::cout << "You've pet the pony " << this->_num_pet << " times." << std::endl;
	std::cout << "You've fed the pony " << this->_num_feed << " times." << std::endl;
	std::cout << "You've ridden the pony " << this->_num_ride << " times." << std::endl;
}
