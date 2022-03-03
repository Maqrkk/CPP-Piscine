#include "Array.hpp"
#include <iostream>

template <typename T>
void	print_array(Array<T> *array)
{
	for (int i = 0; i < (*array).size(); i++)
		std::cout << i << ": " << (*array)[i] << std::endl;
}

int		main(void)
{
	Array<int>			empty_array;
	Array<int>			first(5);
	Array<int>			second(3);

	// This array should be empty, since it was constructed without parameters.
	std::cout << "Printing an array constructed without parameters" << std::endl;
	print_array(&empty_array);
	std::cout << "Done printing" << std::endl << std::endl;

	// Initializing int_array to 1, 2, 3, 4, 5, using the size() member function.
	for (int i = 0; i < first.size(); i++)
		first[i] = i + 1;

	// Initializing second array to 3, 5, 2.
	second[0] = 3;
	second[1] = 5;
	second[2] = 2;

	// Printing both arrays to see their contents.
	std::cout << "Printing first array" << std::endl;
	print_array(&first);
	std::cout << std::endl << "Print second array" << std::endl;
	print_array(&second);
	std::cout << std::endl;

	// Assigning second to int_array (1,2,3,4,5) and changing the
	// third element to be 16.
	second = first;
	second[2] = 16;

	// Printing both arrays again to show the original hasn't changed,
	// and the second is now a copy of the original with a slight change.
	std::cout << "Printing first array" << std::endl;
	print_array(&first);
	std::cout << std::endl << "Print second array" << std::endl;
	print_array(&second);
	std::cout << std::endl;

	// Making a copy of the second array, and changing an element in the copy.
	Array<int>		third(second);
	third[0] = 42;

	// Printing both these arrays again.
	std::cout << "Printing second array" << std::endl;
	print_array(&second);
	std::cout << std::endl << "Printing third array" << std::endl;
	print_array(&third);
	std::cout << std::endl;

	// It also works with another type, for example strings.
	Array<std::string>	str_array(2);
	str_array[0] = "Hello";
	str_array[1] = "world.";
	print_array(&str_array);
	std::cout << std::endl;

	// You can also print a random element from arrays.
	std::cout << second[2] << std::endl;
	std::cout << str_array[0] << std::endl;
	std::cout << std::endl;

	// An excepion is thrown when trying to access an out of bounds element.
	try
	{
		str_array[5];
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught with an index that's too high" << std::endl;
	}
	try
	{
		first[-3];
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught with an index that's too low" << std::endl;
	}
}
