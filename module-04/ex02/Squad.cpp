#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

Squad::Squad(void) : _squadSize(0), _marines(0)
{
	return ;
}

Squad::Squad(Squad const &src) : _squadSize(0)
{
	*this = src;
	return ;
}

Squad::~Squad(void)
{
	if (this->_squadSize > 0)
		this->_deleteUnits();
	return ;
}

Squad			&Squad::operator=(Squad const &src)
{
	if (this->_squadSize > 0)
		this->_deleteUnits();
	this->_squadSize = src._squadSize;
	this->_marines = new ISpaceMarine*[this->_squadSize];
	for (int i = 0; i < this->_squadSize; i++)
	{
		this->_marines[i] = src._marines[i]->clone();
	}
	return (*this);
}

int				Squad::getCount(void) const
{
	return (this->_squadSize);
}

ISpaceMarine	*Squad::getUnit(int num) const
{
	if (num < this->_squadSize)
		return (this->_marines[num]);
	return 0;
}

int				Squad::push(ISpaceMarine *marine)
{
	ISpaceMarine	**tmp;

	if (marine == NULL)
		return (this->_squadSize);
	for (int i = 0; i < this->_squadSize; i++)
	{
		if (this->_marines[i] == marine)
			return (this->_squadSize);
	}
	tmp = new ISpaceMarine*[this->_squadSize + 1];
	for (int i = 0; i < this->_squadSize; i++)
	{
		tmp[i] = this->_marines[i];
	}
	tmp[this->_squadSize] = marine;
	this->_squadSize++;
	delete[] this->_marines;
	this->_marines = tmp;
	return (this->_squadSize);
}

void			Squad::_deleteUnits(void)
{
	for (int i = 0; i < this->_squadSize; i++)
	{
		delete this->_marines[i];
	}
	delete[] this->_marines;
}
