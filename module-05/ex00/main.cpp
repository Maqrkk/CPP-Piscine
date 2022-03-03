#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int		main(void)
{
	// In this first try block, I will try to instantiate a Bureaucrat with
	// too high of a grade. I will first try to catch it with the wrong exception,
	// and then catch it with the generic exception catcher.
	try
	{
		Bureaucrat		john("John", 0);
		std::cout << "If you can see this, the exception wasn't thrown." << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "This should not be printed, the grade was too high, not too low." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "This is the generic error catch. Because the exception wasn't intercepted earlier, this will be printed!" << std::endl;
		std::cout << "The error is: " << e.what() << std::endl;
	}

	// Now I will create a Bureaucrat with a valid grade. Then in the try block
	// I will try to decrease it's grade too low, and the exception should be thrown.
	// I will catch it with the wrong specific error, then the right specific error,
	// and then show that the generic exception won't be caught anymore.

	Bureaucrat		john("John", 145);
	try
	{
		for (int i = 0; i < 10; i++)
		{
			john.decreaseGrade();
			std::cout << john;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "This should not be printed, the grade was too low, not too high." << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "This should print, because the grade was too low." << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "This should not print anymore, the exception has been intercepted before." << std::endl;
		std::cout << e.what() << std::endl;
	}
}
