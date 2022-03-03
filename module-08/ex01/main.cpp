#include "span.hpp"
#include <iostream>
#include <climits>

void	subject_tests()
{
	// The test main from the subject:
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_copy_and_assign()
{
	// These are some tests to show off copy constructors and assignation
	// operators, to show they are deepcopies.
	std::cout << "=== Start of the deepcopy tests ===" << std::endl;
	Span sp1 = Span(2);
	Span sp2 = Span(3);

	sp1.addNumber(2);
	sp1.addNumber(3);
	sp2.addNumber(16);
	sp2.addNumber(17);
	sp2.addNumber(5);
	sp1.debug();
	sp2.debug();

	Span sp3 = Span(sp1);
	sp1.debug();
	sp3.debug();

	sp1 = sp2;
	// 3 is a copy of 1, but after assigning 2 to 1, 3 should still be the
	// original 1, since it was a deepcopy.
	sp1.debug();
	sp2.debug();
	sp3.debug();
	std::cout << "=== End of the deepcopy tests ===" << std::endl;
}

void	random_number_test(unsigned int size)
{
	std::cout << "=== Start of the randomised test with " << size;
	std::cout << " numbers ===" << std::endl;
	// This will generate a Span with random numbers
	Span sp = Span(size);
	for (unsigned int i = 0; i < size; i++)
		sp.addNumber(rand() - RAND_MAX / 2);
	std::cout << "Shortest span with " << size << " numbers: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span with " << size << " numbers:" << sp.longestSpan() << std::endl;
	std::cout << "=== End of the randomised test ===" << std::endl;
}

void	range_tests()
{
	std::cout << "=== Start of the range test ===" << std::endl;
	// Create and populate a vector.
	std::vector<int>	orig;

	for (int i = 0; i < 10; i++)
		orig.push_back(i * 3);

	// Create a span, and populate with some numbers.
	Span				s1(20);
	s1.addNumber(16);
	s1.addNumber(41);
	s1.debug();

	// Now add a range of numbers from the vector into the Span.
	s1.addRange(orig.begin(), orig.end());
	s1.debug();

	// Just for fun, add another number to the Span manually.
	s1.addNumber(199);
	s1.debug();

	// Finally, if we add too many numbers at once, we get another exception.
	try
	{
		s1.addRange(orig.begin(), orig.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "=== End of the range test ===" << std::endl;
}

void	custom_tests()
{
	std::cout << "=== Start of the custom test ===" << std::endl;
	// Testing with a span that's not full, where all items are equally spaced.
	Span sp = Span(10);
	sp.addNumber(0);
	sp.addNumber(5);
	sp.addNumber(10);
	sp.addNumber(15);
	sp.addNumber(20);

	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest  : " << sp.longestSpan() << std::endl << std::endl;

	// Adding INT_MIN and INT_MAX, so longest_span should be UINT_MAX
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);

	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest  : " << sp.longestSpan() << std::endl;

	// Printing UINT_MAX, which should max with the longest span.
	std::cout << "UINT_MAX : " << UINT_MAX << std::endl << std::endl;

	// Now a test with 9 the same numbers and 1 different.
	// Meaning the shortest span should be 0, and the longest the 11 (16 - 5).
	Span	s2 = Span(10);
	for (int i = 0; i < 9; i++)
		s2.addNumber(5);
	s2.addNumber(16);
	std::cout << "Shortest: " << s2.shortestSpan() << std::endl;
	std::cout << "Longest: " << s2.longestSpan() << std::endl;
	std::cout << "=== End of the custom test ===" << std::endl;
}

int		main(void)
{
	subject_tests();

	// Tests for copy constructors and assignation operators.
	test_copy_and_assign();

	// Test with a big vector with randomised items.
	srand(time(NULL));
	random_number_test(100000);

	// Test with a range constructor.
	range_tests();

	// Some small custom tests.
	custom_tests();
}
