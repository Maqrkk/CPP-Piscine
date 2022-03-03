#ifndef BOOMERANG_HPP
# define BOOMERANG_HPP

# include "AWeapon.hpp"

class Boomerang : public AWeapon
{
	public:
		Boomerang(void);
		Boomerang(Boomerang const &src);
		virtual ~Boomerang(void);

		Boomerang		&operator=(Boomerang const &src);
		void			attack(void) const;
};

#endif
