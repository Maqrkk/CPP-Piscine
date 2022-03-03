#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern			&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

Form			*Intern::makeForm(std::string const &name, std::string const &target)
{
	typedef Form*(Intern::*InternFunction)(std::string const &target);
	InternFunction	functions[] = {
		&Intern::_createPresidentialPardonForm,
		&Intern::_createRobotomyRequestForm,
		&Intern::_createShrubberyCreationForm};
	std::string		functionNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (functionNames[i] == name)
			return (this->*functions[i])(target);
	}
	throw FormTypeNotFoundException();
}

const char		*Intern::FormTypeNotFoundException::what() const throw()
{
	return ("Intern: Form type not found");
}

Form			*Intern::_createPresidentialPardonForm(std::string const &target)
{
	Form		*form;

	form = new PresidentialPardonForm(target);
	return (form);
}

Form			*Intern::_createRobotomyRequestForm(std::string const &target)
{
	Form		*form;

	form = new RobotomyRequestForm(target);
	return (form);
}

Form			*Intern::_createShrubberyCreationForm(std::string const &target)
{
	Form		*form;

	form = new ShrubberyCreationForm(target);
	return (form);
}
