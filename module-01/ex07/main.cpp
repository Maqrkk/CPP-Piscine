#include <iostream>
#include <fstream>

void	replaceLoop(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
	std::string		line;
	std::size_t		pos;
	std::size_t		prev_pos;

	while (std::getline(ifs, line))
	{
		prev_pos = 0;
		while((pos = line.find(s1, prev_pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			prev_pos = pos + s2.length();
		}
		ofs << line;
		ofs << std::endl;
	}
}

int		main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		input_file;
	std::string		output_file;
	std::string		s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}
	input_file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cout << "The string arguments may not be empty." << std::endl;
		return 1;
	}
	ifs.open(input_file.c_str());
	if (!ifs)
	{
		std::cout << "Opening the file " << input_file << " failed." << std::endl;
		return 1;
	}
	output_file = input_file + ".replace";
	ofs.open(output_file.c_str());
	if (!ofs)
	{
		std::cout << "Creating the file " << output_file << " failed." << std::endl;
		return 1;
	}
	replaceLoop(ifs, ofs, s1, s2);
	return 0;
}
