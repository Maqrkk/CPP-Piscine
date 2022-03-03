#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int		main(void)
{
	// Creating two bureaucrats.
	// John has a high enough grade to sign.
	// Fred does not.
	Bureaucrat		john("John", 20);
	Bureaucrat		fred("Fred", 25);
	Form			form1("My form", 20, 15);
	Form			form2(form1);

	// Trying to sign both forms with different bureaucrats.
	john.signForm(form1);
	fred.signForm(form2);

	// Outputting the status of all bureaucrats and forms.
	std::cout << std::endl << john << fred << form1 << form2 << std::endl;

	// Trying to create a form with a grade that's wrong.
	try
	{
		Form		form3("Wrong form", 0, 15);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Error message: " << e.what() << std::endl;
	}
}
