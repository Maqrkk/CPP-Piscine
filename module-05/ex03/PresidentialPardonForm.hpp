#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);
		std::string const		&getTarget() const;

	private:
		std::string const		_target;

		void					_performAction() const;
		PresidentialPardonForm();
};

#endif
