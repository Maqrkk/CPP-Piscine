#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int		main(void)
{
	FragTrap	frag("Peter");
	ScavTrap	scav("Susan");

	frag.takeDamage(20);
	frag.takeDamage(100);
	frag.vaulthunter_dot_exe("John");
	frag.takeDamage(54450);
	frag.beRepaired(20);
	frag.vaulthunter_dot_exe("Mary");
	frag.beRepaired(80);
	frag.vaulthunter_dot_exe("John");
	frag.beRepaired(100);

	frag.vaulthunter_dot_exe("Mary");
	frag.vaulthunter_dot_exe("John");

	scav.takeDamage(30);
	scav.beRepaired(100);
	scav.challengeNewcomer("Mary");
	scav.challengeNewcomer("John");
	scav.challengeNewcomer("Mary");

	std::cout << std::endl;

	frag.meleeAttack("Hank");
	scav.meleeAttack("Hank");
	frag.rangedAttack("Hank");
	scav.rangedAttack("Hank");

	std::cout << std::endl;

	scav.takeDamage(70);
	scav.takeDamage(9);
	scav.challengeNewcomer("John");
	return (0);
}
