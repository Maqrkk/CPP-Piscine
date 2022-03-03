#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : _amount(0)
{
	std::cout << "MateriaSource constructor" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) : _amount(0)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	*this = src;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor" << std::endl;
	_deleteMateria();
	return ;
}

MateriaSource		&MateriaSource::operator=(MateriaSource const &src)
{
	std::cout << "MateriaSource assignment" << std::endl;
	_deleteMateria();
	for (int i = 0; i < src._amount; i++)
		_materia[i] = src._materia[i]->clone();
	_amount = src._amount;
	return (*this);
}

void				MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL || _amount == 4)
		return ;
	_materia[_amount] = m;
	_amount++;
}

AMateria			*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _amount; i++)
	{
		if (_materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return 0;
}

void				MateriaSource::_deleteMateria(void)
{
	for (int i = 0; i < _amount; i++)
		delete _materia[i];
	_amount = 0;
}
