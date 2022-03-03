#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string const &name, int signGrade, int executeGrade);
		Form(Form const &src);
		virtual ~Form();

		Form				&operator=(Form const &src);
		std::string const	&getName() const;
		bool				getSignedStatus() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				beSigned(Bureaucrat bureaucrat);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;
		Form();
};

std::ostream				&operator<<(std::ostream &o, Form const &src);

#endif
