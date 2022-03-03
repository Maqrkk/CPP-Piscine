#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool			FragTrap::_seeded = false;

FragTrap::FragTrap(std::string const &name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
	_maxEnergyPoints(100), _level(1), _name(name), _meleeDamage(30), _rangedDamage(20),
	_armorDamageReduction(5)
{
	std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
	FragTrap::_seed();
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << ": No fair! I wasn't ready." << std::endl;
	return ;
}

FragTrap		&FragTrap::operator=(FragTrap const &src)
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

void			FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_rangedDamage;
	std::cout << " points of damage!" << std::endl;
}

void			FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeDamage;
	std::cout << " points of damage!" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name;
		std::cout << " was attacked, but was already at 0 hit points!" << std::endl;
		return ;
	}
	if (amount < this->_armorDamageReduction)
	{
		std::cout << "FR4G-TP " << this->_name;
		std::cout << " is hit, but their armor absorbs the damage." << std::endl;
		return ;
	}
	amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "FR4G-TP " << this->_name << " is hit for ";
		std::cout << amount << " points of damage, which is more than it's hit points.";
		std::cout << " It's totally broken." << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "FR4G-TP " << this->_name << " is hit for ";
		std::cout << amount << " points of damage. It now has ";
		std::cout << this->_hitPoints << " hit points left." << std::endl;
	}
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "FR4G-TP " << this->_name << " was repaired,";
		std::cout << " but was already full on hit points!" << std::endl;
		return ;
	}
	if (amount + this->_hitPoints >= this->_maxHitPoints)
	{
		this->_hitPoints = this->_maxHitPoints;
		std::cout << "FR4G-TP " << this->_name << " is fully repaired!" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << "FR4G-TP " << this->_name << " is repaired for ";
		std::cout << amount << ". It now has " << this->_hitPoints;
		std::cout << " hit points!" << std::endl;
	}
}

void			FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::string		attacks[] = {"Clap-In-The-Box", "Gun Wizard", "Torgue Fiesta",
						"Pirate Ship Mode", "One Shot Wonder"};
	std::string		quotes[] = {"Gotta blow up a bad guy, GOTTA BLOW UP A BAD GUY!",
						"You can call me Gundalf!",
						"It's time for my free grenade giveaway!",
						"I feel a joke about poop decks coming on!",
						"Like those guys who made only one song ever."};
	int				numAttacks;
	int				randomId;

	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name << " is broken. It can't use an attack!";
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP " << this->_name << " tried to attack ";
		std::cout << target << ", but it didn't have enough energy points." << std::endl;
		return ;
	}
	numAttacks = sizeof(attacks) / sizeof(attacks[0]);
	randomId = rand() % numAttacks;
	this->_energyPoints -= 25;
	std::cout << "FR4G-TP " << this->_name << " uses \"" << attacks[randomId];
	std::cout << "\" on " << target << "." << std::endl;
	std::cout << this->_name << ": " << quotes[randomId] << std::endl;
}

void			FragTrap::_seed(void)
{
	if (FragTrap::_seeded == false)
	{
		FragTrap::_seeded = true;
		srand(time(0));
	}
}

FragTrap::FragTrap(void)
{
	return ;
}
