#include "iter.hpp"
#include <iostream>

// This is my custom function used to test the iter function
template <typename T>
void	print_thing(T thing)
{
	std::cout << "thing = " << thing << std::endl;
}

int		main(void)
{
	// I will test the iter function by calling the print_thing function on them.
	int			int_array[] = {5, 3, 2, 1};
	std::string str_array[] = {"Hello", "world", "another string", "the last item"};
	float		flo_array[] = {3.2f, 5.4f, -3.2f};

	// First an array of ints.
	iter(int_array, 4, print_thing);
	std::cout << std::endl;

	// Now the same array, but only the first 2 elements.
	iter(int_array, 2, print_thing);
	std::cout << std::endl;

	// Next, an array of strings.
	iter(str_array, 4, print_thing);
	std::cout << std::endl;

	// Finally, floats.
	iter(flo_array, 3, print_thing);
	std::cout << std::endl;

	// Printing a negative amount of things?
	std::cout << "Printing negative amount of things?" << std::endl;
	iter(flo_array, -1, print_thing);
	std::cout << "Nothing should have been printed" << std::endl;
	return 0;
}
