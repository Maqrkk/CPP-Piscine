#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string const &name);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap			&operator=(NinjaTrap const &src);

		void				ninjaShoebox(ClapTrap &clap);
		void				ninjaShoebox(FragTrap &frag);
		void				ninjaShoebox(ScavTrap &scav);
		void				ninjaShoebox(NinjaTrap &ninja);

		static const unsigned int	maxHP;
		static const unsigned int	maxEP;
		static const unsigned int	meleeDamage;
		static const unsigned int	rangedDamage;
		static const unsigned int	armorReduction;
};

#endif
