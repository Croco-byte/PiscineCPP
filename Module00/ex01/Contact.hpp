/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 14:33:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <stdlib.h>

class Contact
{
public:
	Contact();
	~Contact();

	void	empty(void);
	void	setup(void);
	bool	one_empty(void);

	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_login(void);
	std::string	get_postal_address(void);
	std::string	get_email_address(void);
	std::string	get_phone_number(void);
	std::string	get_birthday_date(void);
	std::string	get_fav_meal(void);
	std::string	get_underwear_color(void);
	std::string	get_darkest_secret(void);

	void		set_first_name(std::string new_info);
	void		set_last_name(std::string new_info);
	void		set_nickname(std::string new_info);
	void		set_login(std::string new_info);
	void		set_postal_address(std::string new_info);
	void		set_email_address(std::string new_info);
	void		set_phone_number(std::string new_info);
	void		set_birthday_date(std::string new_info);
	void		set_fav_meal(std::string new_info);
	void		set_underwear_color(std::string new_info);
	void		set_darkest_secret(std::string new_info);

protected:
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal_address;
	std::string		_email_address;
	std::string		_phone_number;
	std::string		_birthday_date;
	std::string		_fav_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;
};

#endif
