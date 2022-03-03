#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string const &name);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap			&operator=(NinjaTrap const &src);

		void				ninjaShoebox(ClapTrap &clap);
		void				ninjaShoebox(FragTrap &frag);
		void				ninjaShoebox(ScavTrap &scav);
		void				ninjaShoebox(NinjaTrap &ninja);

	private:
		NinjaTrap(void);
};

#endif
