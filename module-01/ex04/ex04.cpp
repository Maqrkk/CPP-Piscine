#include <iostream>

int		main(void)
{
	std::string		message;
	std::string		*ptr;
	std::string		&ref = message;

	message = "HI THIS IS BRAIN";
	ptr = &message;

	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}
