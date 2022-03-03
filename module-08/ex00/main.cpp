#include "easyfind.hpp"
#include <iostream>
#include <vector>

int		main(void)
{
	std::vector<int>			vec;
	std::vector<int>::iterator	it;

	// Creating a vector with values 7, 14, ..., 63, 70
	for (int i = 0; i < 10; i++)
		vec.push_back((i + 1) * 7);

	// Trying to find the element '70' in the vector.
	it = find(vec, 70);
	if (it == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "I found: " << *it << std::endl;

	// Increasing the iterator beyond the last element, so it should point
	// at the end.
	it++;
	if (it == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "I found: " << *it << std::endl;

	// Replacing the 4th element with 5 and searching for 0.
	vec[3] = 5;

	it = find(vec, 5);
	if (it == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "I found: " << *it << std::endl;

	// Now increasing and showing the next element.
	it++;
	if (it == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "I found: " << *it << std::endl;

	// Now finally, searching for a value that is not in the vector.
	it = find(vec, 20);
	if (it == vec.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "I found: " << *it << std::endl;
}
