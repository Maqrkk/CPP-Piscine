#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"
# include <string>

class Sorcerer
{
	public:
		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &src);
		virtual	~Sorcerer(void);

		Sorcerer			&operator=(Sorcerer const &src);
		std::string	const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void				polymorph(Victim const &target) const;

	private:
		std::string 		_name;
		std::string			_title;

		void				_printName(void) const;
		Sorcerer(void);
};

std::ostream				&operator<<(std::ostream &o, Sorcerer const &src);

#endif
