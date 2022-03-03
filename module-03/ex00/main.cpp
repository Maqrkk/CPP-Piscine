#include "FragTrap.hpp"
#include <iostream>

int		main(void)
{
	FragTrap	frag("Peter");

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

	std::cout << std::endl;

	frag.meleeAttack("Hank");
	frag.rangedAttack("Hank");
	return (0);
}
