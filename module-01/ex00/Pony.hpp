#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class	Pony
{
	public:
		Pony(std::string name="Hank");
		~Pony(void);

		void		set_name(std::string name);
		void		pet(void);
		void		feed(void);
		void		ride(void);
		void		print_status(void) const;

	private:
		std::string	_name;
		int			_num_pet;
		int			_num_feed;
		int			_num_ride;
};

#endif
