#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void			Contact::ask_info(void)
{
	this->_ask_field("First name? ", &(this->_first_name));
	this->_ask_field("Last name? ", &(this->_last_name));
	this->_ask_field("Nickname? ", &(this->_nickname));
	this->_ask_field("Login? ", &(this->_login));
	this->_ask_field("Postal address? ", &(this->_postal_address));
	this->_ask_field("Email address? ", &(this->_email_address));
	this->_ask_field("Phone number? ", &(this->_phone_number));
	this->_ask_field("Birth date? ", &(this->_birth_date));
	this->_ask_field("Favorite meal? ", &(this->_favorite_meal));
	this->_ask_field("Underwear color? ", &(this->_underwear_color));
	this->_ask_field("Darkest secret? ", &(this->_darkest_secret));
}

std::string		Contact::get_first_name(void) const
{
	return this->_first_name;
}

std::string		Contact::get_last_name(void) const
{
	return this->_last_name;
}

std::string		Contact::get_nickname(void) const
{
	return this->_nickname;
}

void			Contact::display_info(void) const
{
	this->_format_output("First name:", this->_first_name);
	this->_format_output("Last name:", this->_last_name);
	this->_format_output("Nickname:", this->_nickname);
	this->_format_output("Login:", this->_login);
	this->_format_output("Postal address:", this->_postal_address);
	this->_format_output("Email address:", this->_email_address);
	this->_format_output("Phone number:", this->_phone_number);
	this->_format_output("Birth date:", this->_birth_date);
	this->_format_output("Favorite meal:", this->_favorite_meal);
	this->_format_output("Underwear color:", this->_underwear_color);
	this->_format_output("Darkest secret:", this->_darkest_secret);
}

void			Contact::_format_output(std::string field_name, std::string info) const
{
	std::cout << std::left << std::setw(20) << field_name << info << std::endl;
}

void			Contact::_ask_field(std::string question, std::string *field)
{
	std::cout << question;
	std::getline(std::cin, *field);
	if (std::cin.eof())
		exit(0);
}
