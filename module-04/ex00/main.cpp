#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Grunt.hpp"
#include <iostream>

int		main(void)
{
	Sorcerer	robert("Robert", "the Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Grunt		jesse("Jesse");

	std::cout << robert << jim << joe << jesse;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(jesse);

	std::cout << std::endl;

	// This test is for the copy constructor.
	Peon		*joe2 = new Peon(joe);
	delete joe2;

	std:: cout << std::endl;

	// This test is to showcase that all of this also works with pointers
	// and dynamically allocated memory.
	Victim		*bob = new Peon("Bob");
	std::cout << *bob;
	robert.polymorph(*bob);
	delete bob;

	std::cout << std::endl;

	// This test is to see if the assignment operator worked. The name should
	// change from Hank to Joe.
	// Keep in mind that during Destruction this will also mention Joe instead
	// of Hank now!
	Peon		hank("Hank");
	hank = joe;
	std::cout << hank;

	std::cout << std::endl;

	// Unccomment the next line to check for leaks.
	// while (1);
	return 0;
}
