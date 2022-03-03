#include "span.hpp"
#include <iostream>
#include <climits>
#include <algorithm>

Span::Span(unsigned int n) : _space(n), _amount(0), _sorted(false)
{
	if (n > 0)
		this->_numbers = std::vector<int>();
	return ;
}

Span::Span(Span const &src) : _space(src._space), _amount(0), _sorted(false)
{
	*this = src;
	return ;
}

Span::~Span()
{
}

Span			&Span::operator=(Span const &src)
{
	if (src._space > 0)
		this->_numbers = std::vector<int>(src._numbers);
	this->_amount = src._amount;
	this->_space = src._space;
	return *this;
}

void			Span::addNumber(int number)
{
	if (this->_amount == this->_space)
		throw TooManyNumbersException();
	this->_numbers.push_back(number);
	this->_amount++;
	this->_sorted = false;
}

unsigned int	Span::shortestSpan()
{
	if (this->_amount < 2)
		throw TooFewNumbersException();
	this->_sortSpan();
	unsigned int	result = UINT_MAX;
	for (unsigned int i = 0; i < this->_amount - 1; i++)
		if (static_cast<unsigned int>(this->_numbers[i + 1] - this->_numbers[i]) < result)
			result = this->_numbers[i + 1] - this->_numbers[i];
	return result;
}

unsigned int	Span::longestSpan()
{
	if (this->_amount < 2)
		throw TooFewNumbersException();
	this->_sortSpan();
	return static_cast<unsigned int>(this->_numbers.back() - this->_numbers.front());
}

const char		*Span::TooManyNumbersException::what() const throw()
{
	return "The span is already full.";
}

const char		*Span::RangeTooLargeException::what() const throw()
{
	return "The range is larger than the available space.";
}

const char		*Span::TooFewNumbersException::what() const throw()
{
	return "Too few numbers to calculate a span.";
}

Span::Span()
{
	return ;
}

void			Span::_sortSpan()
{
	if (this->_sorted == false)
	{
		std::sort(this->_numbers.begin(), this->_numbers.end());
		this->_sorted = true;
	}
}

// This function is purely for debug purposes, to show what's inside the span
// at any moment.
void			Span::debug()
{
	std::cout << "========= DEBUG =========" << std::endl;
	std::cout << "Size: " << this->_space << ", Current: " << this->_amount << std::endl;
	for (unsigned int i = 0; i < this->_amount; i++)
		std::cout << i + 1 << ": " << this->_numbers[i] << std::endl;
	std::cout << std::endl;
}
