#include "Phonebook.hpp"
#include <iostream>


int		main(void)
{
	Phonebook		phonebook;
	std::string		command;
	std::string		index_str;
	int				index_num;

	while (true)
	{
		std::cout << "What do you want to do? (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
		{
			phonebook.display_table();
			std::cout << "Type the index of the person you want to see: ";
			std::getline(std::cin, index_str);
			if (std::cin.eof())
				break;
			if (index_str.length() > 1 || !std::isdigit(index_str[0]))
			{
				std::cout << "That's not a valid index number." << std::endl;
				continue ;
			}
			index_num = index_str[0] - '0';
			if (index_num >= phonebook.get_num_contacts())
			{
				std::cout << "That's not the index of an existing entry." << std::endl;
				continue ;
			}
			phonebook.search(index_num);
		}
	}
	return 0;
}
