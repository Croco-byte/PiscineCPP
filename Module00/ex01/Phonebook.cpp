/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:32:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 16:51:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : _counter(0)
{ }

Phonebook::~Phonebook()
{ }

void		Phonebook::add_contact(Contact contact)
{
	if (contact.one_empty() == true)
		std::cout << "ERROR -- All fields are required to add a user" << std::endl << std::endl;
	else
	{
		this->_contacts[this->_counter] = contact;
		this->inc_counter();
		std::cout << "User successfully registered" << std::endl << std::endl;
	}
}

void		Phonebook::repl_contact(Contact contact, int index)
{
	if (contact.one_empty() == true)
		std::cout << "ERROR -- All fields are required to add a user" << std::endl << std::endl;
	else
	{
		this->_contacts[index] = contact;
		std::cout << "User successfully registered" << std::endl << std::endl;
	}
}

std::string	Phonebook::format(std::string info)
{
	if (info.length() > 10)
	{
		info.insert(9, ".");
		return (info.substr(0, 10));
	}
	else
		return (info);
}

int			Phonebook::search_contacts(void)
{
	if (this->_counter == 0)
	{
		std::cout << "Phonebook is currently empty" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "|==========|==========|==========|==========|" << std::endl;
		std::cout << "|  index   |first name|last name |  pseudo  |" << std::endl;
		std::cout << "|===========================================|" << std::endl;
		for (int i = 0; i < this->_counter; i++)
		{
			std::cout << "|";
			std::cout << std::setw(10) << i;
			std::cout << "|";
			std::cout << std::setw(10) << format(this->_contacts[i].get_first_name());
			std::cout << "|";
			std::cout << std::setw(10) << format(this->_contacts[i].get_last_name());
			std::cout << "|";
			std::cout << std::setw(10) << format(this->_contacts[i].get_nickname());
			std::cout << "|" << std::endl;
		}
		std::cout << "|===========================================|" << std::endl;
		return (1);
	}
}

void	Phonebook::display_contact(int index)
{
	std::cout << std::endl << "=== CONTACT N°" << index << " ===" << std::endl;
	std::cout << "> First name:		" << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "> Last name:		" << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "> Nickname:		" << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "> Login:		" << this->_contacts[index].get_login() << std::endl;
	std::cout << "> Postal address:	" << this->_contacts[index].get_postal_address() << std::endl;
	std::cout << "> Email address:	" << this->_contacts[index].get_email_address() << std::endl;
	std::cout << "> Phone number:		" << this->_contacts[index].get_phone_number() << std::endl;
	std::cout << "> Birthday date:	" << this->_contacts[index].get_birthday_date() << std::endl;
	std::cout << "> Favorite meal:	" << this->_contacts[index].get_fav_meal() << std::endl;
	std::cout << "> Underwear color:	" << this->_contacts[index].get_underwear_color() << std::endl;
	std::cout << "> Darkest secret:	" << this->_contacts[index].get_darkest_secret() << std::endl << std::endl;
}

void	Phonebook::fill_phonebook(void)
{
	Contact	new_1;
	Contact	new_2;

	new_1.set_first_name("Bob");
	new_1.set_last_name("The Builder");
	new_1.set_nickname("BOBTB");
	new_1.set_login("Bobuild");
	new_1.set_postal_address("92250");
	new_1.set_email_address("bob.thebuilder@gmail.com");
	new_1.set_phone_number("0638451477");
	new_1.set_birthday_date("23/08/1974");
	new_1.set_fav_meal("Pasta");
	new_1.set_underwear_color("Pink");
	new_1.set_darkest_secret("Only thing he couldn't fix was his marriage. RIP.");

	for (int i = 0; i < 7; i++)
		this->add_contact(new_1);
	
	new_2.set_first_name("Jean-Michel-Paul");
	new_2.set_last_name("Dupont");
	new_2.set_nickname("JMPDupont-Nick");
	new_2.set_login("Jean-MichelP");
	new_2.set_postal_address("91500");
	new_2.set_email_address("JMP@gmail.com");
	new_2.set_phone_number("0638451479");
	new_2.set_birthday_date("23/09/1956");
	new_2.set_fav_meal("Spinach");
	new_2.set_underwear_color("Orange");
	new_2.set_darkest_secret("Microwaved his hamster when he was 14");

	this->add_contact(new_2);
}

/* ------- ACCESSORS ------- */

int		Phonebook::get_counter(void)
{ return (this->_counter); }


/* ------- MUTATORS ------- */

void	Phonebook::inc_counter(void)
{ this->_counter++; }

void	Phonebook::dec_counter(void)
{ this->_counter--; }
