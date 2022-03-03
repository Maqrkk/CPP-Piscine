#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &src)
{
	_grade = src._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (_name);
}

int					Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::increaseGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::decreaseGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void				Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " cannot sign " << form.getName();
		std::cout << " because their grade is too low!" << std::endl;
	}
}

void				Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << "." << std::endl;
	}
	catch (Form::FormUnsignedException &e)
	{
		std::cout << _name << " cannot execute " << form.getName();
		std::cout << " because it isn't signed!" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " cannot execute " << form.getName();
		std::cout << " because their grade is too low!" << std::endl;
	}
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low");
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high");
}

Bureaucrat::Bureaucrat()
{
	return ;
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (o);
}
