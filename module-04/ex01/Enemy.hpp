#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		Enemy				&operator=(Enemy const &src);
		std::string const	&getType(void) const;
		int					getHP(void) const;
		virtual void		takeDamage(int amount);

	protected:
		int					_hp;
		std::string			_type;

	private:
		Enemy(void);
};

#endif
