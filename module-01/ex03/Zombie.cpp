#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool		Zombie::_seeded = false;

Zombie::Zombie(std::string type, std::string name) : _type(type)
{
	if (!_seeded)
	{
		srand(time(0));
		Zombie::_seeded = true;
	}
	if (name == "")
		this->_setRandomName();
	else
		this->_name = name;
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void		Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void		Zombie::_setRandomName(void)
{
	std::string names[] = {"Jeff", "Edgar", "Felix", "Rickie", "Tom", "Karl", "Donna",
							"Stan", "Meredith", "Kelly", "Jasmine", "Alan", "Ted",
							"Tyler", "Hank", "Susan", "Mary", "Elisabeth", "Kim",
							"Nicole", "Naomi", "Sally", "Jimmy"};
	int			arr_size;
	int			random_index;

	arr_size = sizeof(names)/sizeof(std::string);
	random_index = rand() % arr_size;
	this->_name = names[random_index];
}
