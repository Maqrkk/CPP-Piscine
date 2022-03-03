#include "ZombieEvent.hpp"
#include <iostream>

void	makeStackZombie(void)
{
	Zombie			zombie1("Stacker", "Chris");
	Zombie			zombie2;

	zombie1.announce();
	zombie2.announce();
}

int		main(void)
{
	ZombieEvent		event;
	Zombie			stackZombie("Walker", "Bart");
	Zombie			*heapZombie1;
	Zombie			*heapZombie2;

	stackZombie.announce();

	std::cout << std::endl;

	event.setZombieType("Biter");
	heapZombie1 = event.randomChump();
	heapZombie2 = event.randomChump();
	delete heapZombie1;
	delete heapZombie2;

	std::cout << std::endl;

	event.setZombieType("Crawler");
	heapZombie1 = event.newZombie("Gregory");
	heapZombie2 = event.newZombie("Evelyn");
	heapZombie1->announce();
	heapZombie2->announce();
	delete heapZombie1;
	delete heapZombie2;

	std::cout << std::endl;

	makeStackZombie();

	std::cout << std::endl;

	event.setZombieType("Hunter");
	heapZombie1 = event.newZombie("Tammy");
	event.setZombieType("Spitter");
	heapZombie2 = event.randomChump();
	heapZombie1->announce();
	delete heapZombie1;
	delete heapZombie2;

	std::cout << std::endl;

	stackZombie.announce();
	// To check for leaks, uncomment the next line
	//while (1);
}
