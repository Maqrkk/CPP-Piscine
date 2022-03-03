#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void			ask_info(void);
		std::string		get_first_name(void) const;
		std::string		get_last_name(void) const;
		std::string		get_nickname(void) const;
		void			display_info(void) const;

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_login;
		std::string		_postal_address;
		std::string		_email_address;
		std::string		_phone_number;
		std::string		_birth_date;
		std::string		_favorite_meal;
		std::string		_underwear_color;
		std::string		_darkest_secret;

		void			_format_output(std::string field_name, std::string info) const;
		void			_ask_field(std::string question, std::string *field);
};

#endif
