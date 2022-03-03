#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap			&operator=(ClapTrap const &src);

		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		std::string	const	&getName(void) const;

	protected:
		unsigned int		_hitPoints;
		unsigned int		_maxHitPoints;
		unsigned int		_energyPoints;
		unsigned int		_maxEnergyPoints;
		unsigned int		_level;
		std::string			_name;
		unsigned int		_meleeDamage;
		unsigned int		_rangedDamage;
		unsigned int		_armorDamageReduction;

		static void			_seed(void);
		static bool			_seeded;

};

#endif
