#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm		&operator=(RobotomyRequestForm const &src);
		std::string const		&getTarget() const;

	private:
		std::string const		_target;
		static bool				_seeded;

		void					_performAction() const;
		RobotomyRequestForm();
};

#endif
