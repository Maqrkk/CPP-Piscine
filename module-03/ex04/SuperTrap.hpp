#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string const &name);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap			&operator=(SuperTrap const &src);

	private:
		SuperTrap(void);
};

#endif
