#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(std::string const &name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->_hitPoints = FragTrap::maxHP;
	this->_maxHitPoints = FragTrap::maxHP;
	this->_energyPoints = NinjaTrap::maxEP;
	this->_maxEnergyPoints = NinjaTrap::maxEP;
	this->_level = 1;
	this->_name = "SUP4R-TP " + name;
	this->_meleeDamage = NinjaTrap::meleeDamage;
	this->_rangedDamage = FragTrap::rangedDamage;
	this->_armorDamageReduction = FragTrap::armorReduction;
	std::cout << this->_name << ": Hey everybody! Check out my package!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
	std::cout << this->_name << ": Hey everybody! Check out my package!" << std::endl;
	*this = src;
	return ;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << this->_name << ": SuperTrap deactivate!" << std::endl;
	return ;
}

SuperTrap		&SuperTrap::operator=(SuperTrap const &src)
{
	this->_hitPoints = src._hitPoints;
	this->_maxHitPoints = src._maxHitPoints;
	this->_energyPoints = src._energyPoints;
	this->_maxEnergyPoints = src._maxEnergyPoints;
	this->_level = src._level;
	this->_name = src._name;
	this->_meleeDamage = src._meleeDamage;
	this->_rangedDamage = src._rangedDamage;
	this->_armorDamageReduction = src._armorDamageReduction;
	return (*this);
}

SuperTrap::SuperTrap(void)
{
	return ;
}
