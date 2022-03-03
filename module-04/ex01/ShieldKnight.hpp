#ifndef SHIELDKNIGHT_HPP
# define SHIELDKNIGHT_HPP

# include "Enemy.hpp"

class ShieldKnight : public Enemy
{
	public:
		ShieldKnight(void);
		ShieldKnight(ShieldKnight const &src);
		virtual ~ShieldKnight(void);

		ShieldKnight		&operator=(ShieldKnight const &src);
		void				takeDamage(int amount);
};

#endif
