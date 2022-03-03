#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name), _equipped(0)
{
	std::cout << "Character normal constructor" << std::endl;
	return ;
}

Character::Character(Character const &src) : _name(src._name), _equipped(0)
{
	std::cout << "Character copy constructor" << std::endl;
	*this = src;
	return ;
}

Character::~Character(void)
{
	std::cout << "Character destructor" << std::endl;
	_deleteMateria();
	return ;
}

Character			&Character::operator=(Character const &src)
{
	std::cout << "Character assignment" << std::endl;
	_deleteMateria();
	for (int i = 0; i < src._equipped; i++)
		_materia[i] = src._materia[i]->clone();
	_equipped = src._equipped;
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	if (this->_equipped == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->_equipped; i++)
	{
		if (this->_materia[i] == m)
			return ;
	}
	this->_materia[this->_equipped] = m;
	this->_equipped++;
	std::cout << "Succesfully equipped " << m->getType() << " in slot " << this->_equipped - 1 << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx >= this->_equipped)
		return ;
	this->_equipped--;
	for (int i = idx; i < 3; i++)
		this->_materia[i] = this->_materia[i + 1];
	this->_materia[3] = NULL;
	std::cout << "Succesfully unequipped slot " << idx << std::endl;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= this->_equipped)
		return ;
	this->_materia[idx]->use(target);
}

void				Character::_deleteMateria(void)
{
	for (int i = 0; i < _equipped; i++)
		delete _materia[i];
	_equipped = 0;
}

Character::Character(void)
{
	return ;
}
