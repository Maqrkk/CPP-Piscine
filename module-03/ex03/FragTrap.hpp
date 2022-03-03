#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap			&operator=(FragTrap const &src);

		void				vaulthunter_dot_exe(std::string const &target);

	private:
		FragTrap(void);
};

#endif
