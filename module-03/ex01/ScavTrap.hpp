#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class ScavTrap
{
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap			&operator=(ScavTrap const &src);

		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				challengeNewcomer(std::string const &target);

	private:
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
		ScavTrap(void);
};

#endif
