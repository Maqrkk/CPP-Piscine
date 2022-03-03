#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(std::string const &name) : ClapTrap("INAC " + name)
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeDamage = 60;
	this->_rangedDamage = 5;
	this->_armorDamageReduction = 0;
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
	ninja.takeDamage(0);
}

NinjaTrap::NinjaTrap(void)
{
	return ;
}
