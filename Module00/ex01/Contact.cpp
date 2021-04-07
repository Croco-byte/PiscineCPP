/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:05:40 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 16:51:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{ }

Contact::~Contact()
{ }

void	Contact::empty(void)
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_login = "";
	_postal_address = "";
	_email_address = "";
	_phone_number = "";
	_birthday_date = "";
	_fav_meal = "";
	_underwear_color = "";
	_darkest_secret = "";
}

void	Contact::setup(void)
{
	std::string info_names[11] = {
		"First name",
		"Last name",
		"Nickname",
		"Login",
		"Postal address",
		"Email address",
		"Phone number",
		"Birthday date",
		"Favorite meal",
		"Underwear color",
		"Darkest secret"
	};

	std::string	info;
	for (int i = 0; i < 11; i++)
	{
		std::cout << info_names[i] << ": ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit (1);
		switch (i)
		{
			case 0:
				this->set_first_name(info);
				break;
			case 1:
				this->set_last_name(info);
				break;
			case 2:
				this->set_nickname(info);
				break;
			case 3:
				this->set_login(info);
				break;
			case 4:
				this->set_postal_address(info);
				break;
			case 5:
				this->set_email_address(info);
				break;
			case 6:
				this->set_phone_number(info);
				break;
			case 7:
				this->set_birthday_date(info);
				break;
			case 8:
				this->set_fav_meal(info);
				break;
			case 9:
				this->set_underwear_color(info);
				break;
			case 10:
				this->set_darkest_secret(info);
				break;
		}
	}
}

bool	Contact::one_empty(void)
{
	if (_first_name.compare("") == 0 || _last_name.compare("") == 0
		|| _nickname.compare("") == 0 || _login.compare("") == 0
		|| _postal_address.compare("") == 0 || _email_address.compare("") == 0
		|| _phone_number.compare("") == 0 || _birthday_date.compare("") == 0
		|| _fav_meal.compare("") == 0 || _underwear_color.compare("") == 0
		|| _darkest_secret.compare("") == 0)
			return(true);
	return (false);
}

/* -------- ACCESSORS -------- */

std::string	Contact::get_first_name(void)
{ return (this->_first_name); }

std::string	Contact::get_last_name(void)
{ return (this->_last_name); }

std::string	Contact::get_nickname(void)
{ return (this->_nickname); }

std::string	Contact::get_login(void)
{ return (this->_login); }

std::string	Contact::get_postal_address(void)
{ return (this->_postal_address); }

std::string	Contact::get_email_address(void)
{ return (this->_email_address); }

std::string	Contact::get_phone_number(void)
{ return (this->_phone_number); }

std::string	Contact::get_birthday_date(void)
{ return (this->_birthday_date); }

std::string	Contact::get_fav_meal(void)
{ return (this->_fav_meal); }

std::string	Contact::get_underwear_color(void)
{ return (this->_underwear_color); }

std::string	Contact::get_darkest_secret(void)
{ return (this->_darkest_secret); }


/* -------- Mutators --------- */

void		Contact::set_first_name(std::string new_info)
{ this->_first_name = new_info; }

void		Contact::set_last_name(std::string new_info)
{ this->_last_name = new_info; }

void		Contact::set_nickname(std::string new_info)
{ this->_nickname = new_info; }

void		Contact::set_login(std::string new_info)
{ this->_login = new_info; }

void		Contact::set_postal_address(std::string new_info)
{ this->_postal_address = new_info; }

void		Contact::set_email_address(std::string new_info)
{ this->_email_address = new_info; }

void		Contact::set_phone_number(std::string new_info)
{ this->_phone_number = new_info; }

void		Contact::set_birthday_date(std::string new_info)
{ this->_birthday_date = new_info; }

void		Contact::set_fav_meal(std::string new_info)
{ this->_fav_meal = new_info; }

void		Contact::set_underwear_color(std::string new_info)
{ this->_underwear_color = new_info; }

void		Contact::set_darkest_secret(std::string new_info)
{ this->_darkest_secret = new_info; }
