#include "whatever.hpp"
#include <iostream>

int		main(void)
{
	// this is the main from the subject.
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	// these are some more tests
	std::cout << std::endl;
	a = 10;
	b = -10;
	std::cout << "A = " << a << ", B = " << b << std::endl;
	std::cout << "min = " << min(a, b) << ", max = " << max(a, b) << std::endl;
	swap(a, b);
	std::cout << "A = " << a << ", B = " << b << std::endl;
	std::cout << "min = " << min(a, b) << ", max = " << max(a, b) << std::endl;
	swap(a, b);
	std::cout << "A = " << a << ", B = " << b << std::endl;
	std::cout << "min = " << min(a, b) << ", max = " << max(a, b) << std::endl;
	swap(a, b);
	std::cout << "A = " << a << ", B = " << b << std::endl;
	std::cout << "min = " << min(a, b) << ", max = " << max(a, b) << std::endl;

	// it also works with floats
	std::cout << std::endl;
	float	f1 = 9.3f;
	float	f2 = 9.4f;
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min = " << min(f1, f2) << ", max = " << max(f1, f2) << std::endl;
	swap(f1, f2);
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min = " << min(f1, f2) << ", max = " << max(f1, f2) << std::endl;

	return 0;
}
