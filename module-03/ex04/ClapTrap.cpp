#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool			ClapTrap::_seeded = false;

ClapTrap::ClapTrap(void)
{
	std::cout << "Creating a ClapTrap base class!" << std::endl;
	ClapTrap::_seed();
	return ;
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "Creating a ClapTrap base class!" << std::endl;
	ClapTrap::_seed();
	this->_name = "CL4P-TP " + name;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destroying a ClapTrap base class!" << std::endl;
	return ;
}

ClapTrap			&ClapTrap::operator=(ClapTrap const &src)
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

void				ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage;
	std::cout << " points of damage!" << std::endl;
}

void				ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << this->_name << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeDamage;
	std::cout << " points of damage!" << std::endl;
}

void				ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " was attacked, but was already at 0 hit points!" << std::endl;
		return ;
	}
	if (amount < this->_armorDamageReduction)
	{
		std::cout << this->_name << " is hit, but their armor absorbs the damage." << std::endl;
		return ;
	}
	amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " is hit for " << amount;
		std::cout << " points of damage, which is more than it's hit points.";
		std::cout << " It's totally broken." << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " is hit for " << amount << " points of damage. It now has ";
		std::cout << this->_hitPoints << " hit points left." << std::endl;
	}
}

void				ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << this->_name << " was repaired,";
		std::cout << " but was already full on hit points!" << std::endl;
		return ;
	}
	if (amount + this->_hitPoints >= this->_maxHitPoints)
	{
		this->_hitPoints = this->_maxHitPoints;
		std::cout << this->_name << " is fully repaired!" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " is repaired for ";
		std::cout << amount << ". It now has " << this->_hitPoints;
		std::cout << " hit points!" << std::endl;
	}
}

std::string	const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

void			ClapTrap::_seed(void)
{
	if (ClapTrap::_seeded == false)
	{
		ClapTrap::_seeded = true;
		srand(time(0));
	}
}
