#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

const unsigned int	NinjaTrap::maxHP = 60;
const unsigned int	NinjaTrap::maxEP = 120;
const unsigned int	NinjaTrap::meleeDamage = 60;
const unsigned int	NinjaTrap::rangedDamage = 5;
const unsigned int	NinjaTrap::armorReduction = 0;

NinjaTrap::NinjaTrap(void)
{
	std::cout << "Creating a NinjaTrap to be extended." << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string const &name)
{
	this->_hitPoints = NinjaTrap::maxHP;
	this->_maxHitPoints = NinjaTrap::maxHP;
	this->_energyPoints = NinjaTrap::maxEP;
	this->_maxEnergyPoints = NinjaTrap::maxEP;
	this->_level = 1;
	this->_name = "INAC " + name;
	this->_meleeDamage = NinjaTrap::meleeDamage;
	this->_rangedDamage = NinjaTrap::rangedDamage;
	this->_armorDamageReduction = NinjaTrap::armorReduction;
	std::cout << this->_name << ": Hi, I'm a NinjaTrap." << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	std::cout << this->_name << ": Hi, I'm a NinjaTrap." << std::endl;
	*this = src;
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << this->_name << ": I'm afraid. My mind is going. I can feel it. My mind is going! There's no question about it. I can feel it. I'm a... fraid." << std::endl;
	return ;
}

NinjaTrap		&NinjaTrap::operator=(NinjaTrap const &src)
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

void			NinjaTrap::ninjaShoebox(ClapTrap &clap)
{
	std::cout << this->_name << " puts " << clap.getName() << " in it's shoe box." << std::endl;
	clap.takeDamage(this->_meleeDamage);
}

void			NinjaTrap::ninjaShoebox(FragTrap &frag)
{
	std::cout << this->_name << " throws shoes from it's shoebox on " << frag.getName() << "." << std::endl;
	frag.takeDamage(this->_rangedDamage);
}

void			NinjaTrap::ninjaShoebox(ScavTrap &scav)
{
	std::cout << this->_name << " makes " << scav.getName() << " smell a shoe." << std::endl;
	scav.takeDamage(this->_meleeDamage);
}

void			NinjaTrap::ninjaShoebox(NinjaTrap &ninja)
{
	std::cout << this->_name << " shows " << ninja.getName() << " it's collection of shoes." << std::endl;
}
