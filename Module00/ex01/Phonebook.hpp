/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:05:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 16:14:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class	Phonebook
{
public:
	Phonebook();
	~Phonebook();

	void		add_contact(Contact contact);
	void		repl_contact(Contact contact, int index);
	int			search_contacts(void);
	std::string	format(std::string info);
	void		display_contact(int index);
	void		fill_phonebook(void);

	int			get_counter(void);

	void		inc_counter(void);
	void		dec_counter(void);

protected:
	Contact		_contacts[8];
	int			_counter;

};

#endif
