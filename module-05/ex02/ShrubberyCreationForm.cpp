#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : 
	Form("Shrubbery Creation Form", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	Form("Shrubbery Creation Form", 145, 137), _target(src.getTarget())
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	Form::operator=(src);
	return (*this);
}

std::string const		&ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void					ShrubberyCreationForm::_performAction() const
{
	std::ofstream	ofs;
	std::string		file_name;

	ofs.exceptions(std::ofstream::failbit);
	file_name = _target + "_shrubbery";
	try
	{
		ofs.open(file_name.c_str());
		ofs << "   X" << std::endl;
		ofs << "  XXX     X" << std::endl;
		ofs << " XXXXX   XXX" << std::endl;
		ofs << "XXXXXXX XXXXX" << std::endl;
		ofs << "   #      #" << std::endl;
		ofs << "   #      #" << std::endl;
	}
	catch (std::ios_base::failure &e)
	{
		std::cout << "Something went wrong with opening, creating or writing to the file: ";
		std::cout << file_name << "." << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("Shrubbery Creation Form", 145, 137)
{
	return ;
}
