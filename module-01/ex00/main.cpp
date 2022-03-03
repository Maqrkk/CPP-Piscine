#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap(void)
{
	Pony	*pony;

	pony = new Pony("Jack");
	pony->pet();
	pony->print_status();
	pony->pet();
	pony->feed();
	pony->feed();
	pony->feed();
	pony->ride();
	pony->print_status();

	delete pony;
}

void	ponyOnTheStack(void)
{
	Pony	pony;

	pony.print_status();
	pony.ride();
	pony.pet();
	pony.feed();
	pony.pet();
	pony.set_name("Bob");
	pony.feed();
	pony.pet();
	pony.print_status();
}

int		main(void)
{
	std::cout << "==================" << std::endl;
	ponyOnTheHeap();
	std::cout << "==================" << std::endl;
	ponyOnTheStack();
	std::cout << "==================" << std::endl;
}
