#include "FragTrap.hpp"
#include <iostream>

const unsigned int	FragTrap::maxHP = 100;
const unsigned int	FragTrap::maxEP = 100;
const unsigned int	FragTrap::meleeDamage = 30;
const unsigned int	FragTrap::rangedDamage = 20;
const unsigned int	FragTrap::armorReduction = 5;

FragTrap::FragTrap(void)
{
	std::cout << "Creating a FragTrap to be extended." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name)
{
	this->_hitPoints = FragTrap::maxHP;
	this->_maxHitPoints = FragTrap::maxHP;
	this->_energyPoints = FragTrap::maxEP;
	this->_maxEnergyPoints = FragTrap::maxEP;
	this->_level = 1;
	this->_name = "FR4G-TP " + name;
	this->_meleeDamage = FragTrap::meleeDamage;
	this->_rangedDamage = FragTrap::rangedDamage;
	this->_armorDamageReduction = FragTrap::armorReduction;
	std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
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
		std::cout << this->_name << " is broken. It can't use an attack!";
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints < 25)
	{
		std::cout << this->_name << " tried to attack ";
		std::cout << target << ", but it didn't have enough energy points." << std::endl;
		return ;
	}
	numAttacks = sizeof(attacks) / sizeof(attacks[0]);
	randomId = rand() % numAttacks;
	this->_energyPoints -= 25;
	std::cout << this->_name << " uses \"" << attacks[randomId] << "\" on " << target;
	std::cout << "." << std::endl << this->_name << ": " << quotes[randomId] << std::endl;
}

unsigned int	FragTrap::getHitPoints(void) const
{
	return (100);
}
