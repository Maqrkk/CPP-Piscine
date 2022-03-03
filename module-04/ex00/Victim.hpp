#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim
{
	public:
		Victim(std::string const &name);
		Victim(Victim const &src);
		virtual	~Victim(void);

		Victim				&operator=(Victim const &src);
		std::string const	&getName(void) const;
		virtual void		getPolymorphed(void) const;

	protected:
		std::string			_name;

	private:
		Victim(void);
};

std::ostream				&operator<<(std::ostream &o, Victim const &src);

#endif
