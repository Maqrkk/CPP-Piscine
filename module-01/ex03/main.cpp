#include "ZombieHorde.hpp"
#include <iostream>

int		main(void)
{
	ZombieHorde		stackHorde(5);
	ZombieHorde		*heapHorde;

	stackHorde.announce();

	std::cout << std::endl;

	heapHorde = new ZombieHorde(3);
	heapHorde->announce();
	delete heapHorde;

	std::cout << std::endl;

	stackHorde.announce();

	// for memory leak check, uncomment next line
	// while(1);
}
