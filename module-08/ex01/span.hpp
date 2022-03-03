#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>

class Span
{
	public:
		
		Span(unsigned int n);
		Span(Span const &src);
		virtual ~Span();

		Span				&operator=(Span const &src);
		void				addNumber(int number);
		template <typename Iterator>
		void				addRange(Iterator start, Iterator end)
		{
			int		amountToAdd = end - start;
			if (amountToAdd + this->_amount > this->_space)
				throw RangeTooLargeException();
			this->_amount += amountToAdd;
			this->_numbers.insert(this->_numbers.end(), start, end);
		}
		unsigned int		shortestSpan();
		unsigned int		longestSpan();

		class TooManyNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class RangeTooLargeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class TooFewNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void		debug();

	private:
		unsigned int		_space;
		unsigned int		_amount;
		std::vector<int>	_numbers;
		bool				_sorted;

		void				_sortSpan();

		Span();
};

#endif
