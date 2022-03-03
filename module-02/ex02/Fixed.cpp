#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int		Fixed::_fraction = 8;

Fixed::Fixed(void) : _value(0)
{
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int num)
{
	this->_value = num * (1 << Fixed::_fraction);
	return ;
}

Fixed::Fixed(const float num)
{
	this->_value = roundf(num * (1 << Fixed::_fraction));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed		&Fixed::operator=(Fixed const &src)
{
	this->_value = src.getRawBits();
	return (*this);
}

bool		Fixed::operator>(Fixed const &src) const
{
	return (this->_value > src.getRawBits());
}

bool		Fixed::operator<(Fixed const &src) const
{
	return (this->_value < src.getRawBits());
}

bool		Fixed::operator>=(Fixed const &src) const
{
	return (this->_value >= src.getRawBits());
}

bool		Fixed::operator<=(Fixed const &src) const
{
	return (this->_value <= src.getRawBits());
}

bool		Fixed::operator==(Fixed const &src) const
{
	return (this->_value == src.getRawBits());
}

bool		Fixed::operator!=(Fixed const &src) const
{
	return (this->_value != src.getRawBits());
}

Fixed		Fixed::operator+(Fixed const &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed		Fixed::operator-(Fixed const &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed		Fixed::operator*(Fixed const &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed		Fixed::operator/(Fixed const &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed		Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed		temp(*this);
	this->_value++;
	return (temp);
}

int			Fixed::getRawBits(void) const
{
	return (this->_value);
}

void		Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float		Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_fraction));
}

int			Fixed::toInt(void) const
{
	return (this->_value / (1 << Fixed::_fraction));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return out;
}

Fixed			&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed const		&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed			&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const		&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}
