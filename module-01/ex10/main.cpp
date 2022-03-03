#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>

void	readFile(const char *name)
{
	std::ifstream	file(name);
	std::string		line;
	struct stat		fileinfo;

	stat(name, &fileinfo);
	if (S_ISDIR(fileinfo.st_mode))
	{
		std::cout << "cato9tails: " << name << ": ";
		std::cout << "Is a directory" << std::endl;
	}
	else if (!file)
	{
		std::cout << "cato9tails: " << name << ": ";
		std::cout << std::strerror(errno) << std::endl;
	}
	else
	{
		while(std::getline(file, line))
		{
			std::cout << line << std::endl;
		}
	}
}

void	readStdIn(void)
{
	std::string		line;

	while(std::getline(std::cin, line))
	{
		std::cout << line << std::endl;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i ++)
		{
			if (std::string(argv[i]) == "-")
				readStdIn();
			else
				readFile(argv[i]);
		}
	}
	else
	{
		readStdIn();
	}
}
