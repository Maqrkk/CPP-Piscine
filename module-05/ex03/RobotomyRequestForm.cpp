#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool					RobotomyRequestForm::_seeded = false;

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("Robotomy Request Form", 72, 45), _target(target)
{
	if (!_seeded)
	{
		srand(time(0));
		_seeded = true;
	}
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	Form("Robotomy Request Form", 72, 45), _target(src.getTarget())
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	Form::operator=(src);
	return (*this);
}

std::string const		&RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void					RobotomyRequestForm::_performAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2 == 1)
		std::cout << _target << " has been succesfully robotomized!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Robotomy Request Form", 72, 45)
{
	return ;
}
