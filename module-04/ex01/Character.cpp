#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(0)
{
	return ;
}

Character::Character(Character const &src)
{
	*this = src;
	return ;
}

Character::~Character(void)
{
	return ;
}

Character			&Character::operator=(Character const &src)
{
	this->_name = src._name;
	this->_ap = src._ap;
	this->_weapon = src._weapon;
	return (*this);
}

void				Character::recoverAP(void)
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void				Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void				Character::attack(Enemy* enemy)
{
	if (this->_weapon == 0)
		return ;
	if (this->_weapon->getAPCost() > this->_ap)
	{
		std::cout << this->getName() << " tried to attack " << enemy->getType();
		std::cout << " with a " << this->_weapon->getName();
		std::cout << ", but does not have enough AP." << std::endl;
		return ;
	}
	std::cout << this->getName() << " attacks " << enemy->getType() << " with a ";
	std::cout << this->_weapon->getName() << "." << std::endl;
	this->_weapon->attack();
	this->_ap -= this->_weapon->getAPCost();
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() == 0)
		delete enemy;
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

int					Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon				*Character::getWeapon(void) const
{
	return (this->_weapon);
}

std::ostream		&operator<<(std::ostream &o, Character const &src)
{
	if (src.getWeapon() != 0)
	{
		o << src.getName() << " has " << src.getAP() << " AP and wields a ";
		o << src.getWeapon()->getName() << "." << std::endl;
	}
	else
		o << src.getName() << " has " << src.getAP() << " AP and is unarmed." << std::endl;
	return (o);
}
