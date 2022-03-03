#ifndef GRUNT_HPP
# define GRUNT_HPP

# include "Victim.hpp"
# include <string>

class Grunt : public Victim
{
	public:
		Grunt(std::string const &name);
		Grunt(Grunt const &src);
		virtual ~Grunt(void);

		Grunt			&operator=(Grunt const &src);
		virtual void	getPolymorphed(void) const;

	private:
		Grunt(void);
};

#endif
