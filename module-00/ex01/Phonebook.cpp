#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void)
{
	_num_contacts = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::add_contact(void)
{
	if (this->_num_contacts < 8)
	{
		this->_contacts[this->_num_contacts].ask_info();
		this->_num_contacts++;
		std::cout << "Contact successfully added!" << std::endl;
	}
	else
		std::cout << "Phonebook is full!" << std::endl;
}

void	Phonebook::display_table(void) const
{
	for (int i = 0; i < 8; i++)
		this->_format_line(i);
}

void	Phonebook::search(int n) const
{
	this->_contacts[n].display_info();
}

int		Phonebook::get_num_contacts() const
{
	return this->_num_contacts;
}

void	Phonebook::_format_line(int i) const
{
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;

	first_name = this->_contacts[i].get_first_name();
	last_name = this->_contacts[i].get_last_name();
	nickname = this->_contacts[i].get_nickname();
	std::cout << std::right << std::setw(10) << i << "|";
	this->_format_value(first_name);
	std::cout << "|";
	this->_format_value(last_name);
	std::cout << "|";
	this->_format_value(nickname);
	std::cout << std::endl;
}

void	Phonebook::_format_value(std::string val) const
{
	if (val.length() > 10)
	{
		val.resize(9);
		std::cout << std::setw(9) << std::right << val << ".";
	}
	else
		std::cout << std::setw(10) << std::right << val;
}
