#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);

		Fixed				&operator=(Fixed const &src);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					_value;
		static const int	_fraction;

};

std::ostream				&operator<<(std::ostream &o, Fixed const &num);

#endif
