#include "Form.hpp"
#include <iostream>

Form::Form(std::string const &name, int signGrade, int executeGrade) :
	_name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	return ;
}

Form::Form(Form const &src) :
	_name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
	return ;
}

Form::~Form()
{
	return ;
}

Form				&Form::operator=(Form const &src)
{
	_signed = src._signed;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (_name);
}

bool				Form::getSignedStatus() const
{
	return (_signed);
}

int					Form::getSignGrade() const
{
	return (_signGrade);
}

int					Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void				Form::beSigned(Bureaucrat bureaucrat)
{
	if (_signed)
		return ;
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low");
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high");
}

Form::Form() : _signGrade(0), _executeGrade(0)
{
	return ;
}

std::ostream		&operator<<(std::ostream &o, Form const &src)
{
	o << "Form name: " << src.getName() << ", grade required to sign: ";
	o << src.getSignGrade() << ", grade required to execute: " << src.getExecuteGrade();
	if (src.getSignedStatus())
		o << ". The form is signed." << std::endl;
	else
		o << ". The form is not signed." << std::endl;
	return (o);
}
