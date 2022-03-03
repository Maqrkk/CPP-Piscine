#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource(void);

		MateriaSource		&operator=(MateriaSource const &src);
		void				learnMateria(AMateria *m);
		AMateria			*createMateria(std::string const &type);

	private:
		int					_amount;
		AMateria			*_materia[4];

		void				_deleteMateria(void);
};

#endif
