#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap					&operator=(FragTrap const &src);

		void						vaulthunter_dot_exe(std::string const &target);
		unsigned int				getHitPoints(void) const;

		static const unsigned int	maxHP;
		static const unsigned int	maxEP;
		static const unsigned int	meleeDamage;
		static const unsigned int	rangedDamage;
		static const unsigned int	armorReduction;
};

#endif
