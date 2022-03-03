#include <iostream>
#include <unistd.h>

void		memoryLeak()
{
	std::string*		panther = new std::string("String panther");

	std::cout << *panther << std::endl;
	delete panther;
}

int			main(void)
{
	while(1)
	{
		memoryLeak();
		sleep(1);
	}
}
