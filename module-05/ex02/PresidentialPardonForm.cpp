#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("Presidential Pardon Form", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	Form("Presidential Pardon Form", 25 ,5), _target(src.getTarget())
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	Form::operator=(src);
	return (*this);
}

std::string const		&PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void					PresidentialPardonForm::_performAction() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() :
	Form("Presidential Pardon Form", 25, 5)
{
	return ;
}
