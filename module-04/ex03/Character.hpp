#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
	public:
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		Character			&operator=(Character const &src);
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string const	_name;
		int					_equipped;
		AMateria			*_materia[4];

		void				_deleteMateria(void);
		Character(void);
};

#endif
