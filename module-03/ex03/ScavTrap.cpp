#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string const &name) : ClapTrap("SC4V-TP " + name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeDamage = 20;
	this->_rangedDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << this->_name << ": Let's get this party started!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << this->_name << ": Let's get this party started!" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << ": Oh well." << std::endl;
	return ;
}

ScavTrap		&ScavTrap::operator=(ScavTrap const &src)
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

void			ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string		challenges[] = {"You versus me! Me versus you! Either way!",
						"I will prove to you my robotic superiority!",
						"Dance battle! Or, you know... regular battle.",
						"Man versus machine! Very tiny streamlined machiine!",
						"Care to have a friendly duel?"};
	int				numChallenges;
	int				randomId;

	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " tried to give " << target;
		std::cout << " a challenge, but it is broken." << std::endl;
		return ;
	}
	if (this->_energyPoints < 25)
	{
		std::cout << this->_name << " tried to give " << target;
		std::cout << " a challenge, but it does not have enough energy points." << std::endl;
		return ;
	}
	numChallenges = sizeof(challenges)/sizeof(challenges[0]);
	randomId = rand() % numChallenges;
	this->_energyPoints -= 25;
	std::cout << this->_name << " challenges " << target;
	std::cout << "." << std::endl << this->_name << ": " << challenges[randomId] << std::endl;
}

ScavTrap::ScavTrap(void)
{
	return ;
}
