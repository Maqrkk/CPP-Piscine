#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	public:
		Squad(void);
		Squad(Squad const &src);
		virtual ~Squad(void);

		Squad			&operator=(Squad const &src);
		int				getCount(void) const;
		ISpaceMarine	*getUnit(int num) const;
		int				push(ISpaceMarine *marine);

	private:
		int				_squadSize;
		ISpaceMarine	**_marines;

		void			_deleteUnits(void);
};

#endif
