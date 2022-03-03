#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <string>

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		virtual ~Intern();

		Intern			&operator=(Intern const &src);
		Form			*makeForm(std::string const &name, std::string const &target);

		class FormTypeNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Form			*_createPresidentialPardonForm(std::string const &target);
		Form			*_createRobotomyRequestForm(std::string const &target);
		Form			*_createShrubberyCreationForm(std::string const &target);
};

#endif
