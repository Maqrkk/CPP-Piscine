#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <string>

class Character
{
	public:
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		Character			&operator=(Character const &src);
		void				recoverAP(void);
		void				equip(AWeapon *weapon);
		void				attack(Enemy *enemy);
		std::string const	&getName(void) const;
		int					getAP(void) const;
		AWeapon				*getWeapon(void) const;

	private:
		std::string			_name;
		int					_ap;
		AWeapon				*_weapon;
};

std::ostream				&operator<<(std::ostream &o, Character const &src);

#endif
