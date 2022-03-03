#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie(std::string type="Walker", std::string name="");
		~Zombie(void);

		void			announce(void) const;

	private:
		std::string		_name;
		std::string		_type;
		static bool		_seeded;

		void			_setRandomName(void);
};

#endif
