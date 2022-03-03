#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde();

		void		announce(void) const;

	private:
		Zombie		*_zombies;
		int			_amount;
};

#endif
