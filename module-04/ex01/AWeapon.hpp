#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
	public:
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon const &src);
		virtual	~AWeapon(void);

		AWeapon				&operator=(AWeapon const &src);
		std::string const	&getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;
		virtual void		attack(void) const = 0;

	protected:
		std::string			_name;
		int					_apcost;
		int					_damage;

	private:
		AWeapon(void);
};

#endif
