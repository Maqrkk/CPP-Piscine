#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class	Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);

		void			add_contact(void);
		void			display_table(void) const;
		void			search(int n) const;
		int				get_num_contacts() const;

	private:
		int				_num_contacts;
		Contact 		_contacts[8];

		void			_format_line(int i) const;
		void			_format_value(std::string val) const;
};

#endif
