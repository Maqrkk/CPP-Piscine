#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int		main(void)
{
	Bureaucrat		john("John", 140);
	Bureaucrat		fred("Fred", 130);
	ShrubberyCreationForm	form1("home");
	ShrubberyCreationForm	form2("idk");
	ShrubberyCreationForm	form3(form1);

	// We first try to execute an unsigned form.
	fred.executeForm(form1);

	// Now we sign it, and execute it with a bureaucrat that has the right grade.
	fred.signForm(form1);
	fred.executeForm(form1);

	// Now we sign another form, and try to execute with a bureaucrat
	// that does not have a high enough grade.
	john.signForm(form2);
	john.executeForm(form2);

	std::cout << std::endl;
	// Now let's test the RobotomyRequestForm
	Bureaucrat		susan("Susan", 1);
	RobotomyRequestForm		form4("Hank");
	susan.signForm(form4);
	for (int i = 0; i < 10; i++)
	{
		susan.executeForm(form4);
	}

	std::cout << std::endl;
	// And finally the PresidentialPardonForm
	PresidentialPardonForm	form5("Hank");
	john.signForm(form5);
	fred.signForm(form5);
	susan.signForm(form5);
	susan.executeForm(form5);
}
