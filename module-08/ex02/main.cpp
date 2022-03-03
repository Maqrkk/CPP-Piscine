#include "mutantstack.hpp"
#include <iostream>

void	subject_tests()
{
	// The test main from the subject:
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	copying_tests()
{
	// These tests are to showcase copy constructor and assignment.
	std::cout << "=== Start of the deepcopy tests ===" << std::endl;

	MutantStack<int>	s1;
	MutantStack<int>	s2;

	for(int i = 0; i < 10; i++)
		s1.push(i);
	for(int i = 0; i < 5; i++)
		s2.push(i);

	// Showing that the correct amount of items is pushed.
	std::cout << "s1 size: " << s1.size() << std::endl;
	std::cout << "s2 size: " << s2.size() << std::endl;

	// After assignation, s1 should now contain 5, not the original 10 items.
	s1 = s2;
	std::cout << "Assigned s1 to s2" << std::endl;
	std::cout << "s1 size: " << s1.size() << std::endl;
	std::cout << "s2 size: " << s2.size() << std::endl;

	// s3 is a copy of 1, which is the original s2.
	MutantStack<int>	s3(s1);

	// We push an item to 1, and show that both 2 and 3 are still their originals
	// So they are not linked, which they shouldn't be.
	s1.push(12);
	std::cout << "Made a copy of s1 called s3, and pushed an item to s1" << std::endl;
	std::cout << "s1 size: " << s1.size() << std::endl;
	std::cout << "s2 size: " << s2.size() << std::endl;
	std::cout << "s3 size: " << s3.size() << std::endl;
	std::cout << "=== End of the deepcopy tests ===" << std::endl;
}

void	normal_and_reverse_tests()
{
	// These tests are to showcase forward and reverse iterators.
	std::cout << "=== Start of the normal and reverse tests ===" << std::endl;

	MutantStack<int>	s1;

	// Make a simple staack containing numbers 0 to 9.
	for (int i = 0; i < 10; i++)
		s1.push(i);
	// First we create normal iterators and loop through it, printing every number.
	MutantStack<int>::iterator it = s1.begin();
	MutantStack<int>::iterator ite = s1.end();
	while (it != ite)
	{
		std::cout << "Normal loop: " << *it << std::endl;
		it++;
	}

	// Now we create reverse iterators and loop through, printing every number.
	MutantStack<int>::reverse_iterator	rit = s1.rbegin();
	MutantStack<int>::reverse_iterator	rite = s1.rend();
	while (rit != rite)
	{
		std::cout << "Reverse loop: " << *rit << std::endl;
		rit++;
	}
	std::cout << "=== End of the normal and reverse tests ===" << std::endl;
}

int		main()
{
	subject_tests();
	copying_tests();
	normal_and_reverse_tests();
}
