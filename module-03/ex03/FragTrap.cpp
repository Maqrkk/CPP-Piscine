#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string const &name) : ClapTrap("FR4G-TP " + name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeDamage = 30;
	this->_rangedDamage = 20;
	this->_armorDamageReduction = 5;
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

FragTrap::FragTrap(void)
{
	return ;
}
