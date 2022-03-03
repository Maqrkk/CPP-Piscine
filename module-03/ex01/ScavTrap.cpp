#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool			ScavTrap::_seeded = false;

ScavTrap::ScavTrap(std::string const &name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
	_maxEnergyPoints(50), _level(1), _name(name), _meleeDamage(20), _rangedDamage(15),
	_armorDamageReduction(3)
{
	std::cout << this->_name << ": Let's get this party started!" << std::endl;
	ScavTrap::_seed();
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

void			ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage;
	std::cout << " points of damage!" << std::endl;
}

void			ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeDamage;
	std::cout << " points of damage!" << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "SC4V-TP " << this->_name;
		std::cout << " was attacked, but was already at 0 hit points!" << std::endl;
		return ;
	}
	if (amount < this->_armorDamageReduction)
	{
		std::cout << "SC4V-TP " << this->_name;
		std::cout << " is hit, but their armor absorbs the damage." << std::endl;
		return ;
	}
	amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "SC4V-TP " << this->_name << " is hit for ";
		std::cout << amount << " points of damage, which is more than it's hit points.";
		std::cout << " It's totally broken." << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "SC4V-TP " << this->_name << " is hit for ";
		std::cout << amount << " points of damage. It now has ";
		std::cout << this->_hitPoints << " hit points left." << std::endl;
	}
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "SC4V-TP " << this->_name << " was repaired,";
		std::cout << " but was already full on hit points!" << std::endl;
		return ;
	}
	if (amount + this->_hitPoints >= this->_maxHitPoints)
	{
		this->_hitPoints = this->_maxHitPoints;
		std::cout << "SC4V-TP " << this->_name << " is fully repaired!" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << "SC4V-TP " << this->_name << " is repaired for ";
		std::cout << amount << ". It now has " << this->_hitPoints;
		std::cout << " hit points!" << std::endl;
	}
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
		std::cout << "SC4V-TP " << this->_name << " tried to give " << target;
		std::cout << " a challenge, but it is broken." << std::endl;
		return ;
	}
	if (this->_energyPoints < 25)
	{
		std::cout << "SC4V-TP " << this->_name << " tried to give " << target;
		std::cout << " a challenge, but it does not have enough energy points." << std::endl;
		return ;
	}
	numChallenges = sizeof(challenges)/sizeof(challenges[0]);
	randomId = rand() % numChallenges;
	this->_energyPoints -= 25;
	std::cout << "SC4V-TP " << this->_name << " challenges " << target;
	std::cout << "." << std::endl << this->_name << ": " << challenges[randomId] << std::endl;
}

void			ScavTrap::_seed(void)
{
	if (ScavTrap::_seeded == false)
	{
		ScavTrap::_seeded = true;
		srand(time(0));
	}
}

ScavTrap::ScavTrap(void)
{
	return ;
}
