#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <iostream>

int		main(void)
{
	Bureaucrat		john("John", 40);
	Bureaucrat		fred("Fred", 50);
	Intern			intern;
	Form			*form;

	// First, we test the Robotomy Request Form.
	form = intern.makeForm("robotomy request", "Bender");

	// These tests are to show that the created form has the right properties.
	fred.signForm(*form);
	// Fred cannot execute this form because a grade of 45 is needed for that.
	fred.executeForm(*form);
	// Now to show that john can execute the form because he has the required grade.
	for (int i = 0; i < 3; i++)
		john.executeForm(*form);
	delete form;

	std::cout << std::endl;

	// Next up, we test the Shrubbery Creation:
	form = intern.makeForm("shrubbery creation", "home");
	fred.signForm(*form);
	fred.executeForm(*form);
	delete form;

	std::cout << std::endl;

	// Finally, the Presidential Pardon form.
	// We need a new bureaucrat for this.
	Bureaucrat		susan("Susan", 1);
	form = intern.makeForm("presidential pardon", "Hank");
	susan.signForm(*form);
	susan.executeForm(*form);
	delete form;

	std::cout << std::endl;

	// Trying to create a type of form that does not exist throws an error:
	try
	{
		form = intern.makeForm("non existing form type", "intern");
	}
	catch (Intern::FormTypeNotFoundException &e)
	{
		std::cout << "Exception thrown while creating a form: ";
		std::cout << e.what() << std::endl;
	}
}
