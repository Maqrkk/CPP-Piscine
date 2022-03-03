#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array
{
	public:
		Array() : _elements(NULL), _size(0)
		{
			return ;
		}
		Array(unsigned int n) : _elements(NULL), _size(n)
		{
			if (n > 0)
				this->_elements = new T[n]();
			return ;
		}
		Array(Array const &src) : _size(0)
		{
			std::cout << "Copy constructor" << std::endl;
			*this = src;
			return ;
		}
		virtual	~Array()
		{
			return ;
		}

		Array		&operator=(Array const &src)
		{
			this->_destroyElements();
			if (src.size() > 0)
				this->_elements = new T[src.size()];
			for (int i = 0; i < src.size(); i++)
			{
				this->_elements[i] = src._elements[i];
			}
			this->_size = src.size();
			return *this;
		}

		T			&operator[](int const &index) const
		{
			if (index < 0 || index >= this->_size)
				throw std::exception();
			return (this->_elements[index]);
		}
		int			size() const
		{
			return this->_size;
		}

	private:
		T			*_elements;
		int			_size;

		void		_destroyElements()
		{
			if (this->_size > 0)
				delete[] this->_elements;
		}
};

#endif
