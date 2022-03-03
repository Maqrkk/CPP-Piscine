#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual	~AMateria(void);

		AMateria			&operator=(AMateria const &src);
		std::string const	&getType(void) const;
		unsigned int		getXP(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	private:
		std::string	const	_type;
		unsigned int		_xp;

		AMateria(void);
};

#endif
