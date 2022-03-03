#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <string>

class Peon : public Victim
{
	public:
		Peon(std::string const &name);
		Peon(Peon const &src);
		virtual	~Peon(void);

		Peon			&operator=(Peon const &src);
		virtual void	getPolymorphed(void) const;

	private:
		Peon(void);
};

#endif
