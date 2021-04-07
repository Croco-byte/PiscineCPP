/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:01:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 16:49:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

int		fill_flag(int ac, char **argv)
{
	std::string	flag;

	if (ac < 2)
		return (0);
	flag = argv[1];
	if (!flag.compare("fill"))
		return (1);
	return (0);
}

int		get_int_index(std::string index)
{
	if (!index.compare("0"))
		return (0);
	else if (!index.compare("1"))
		return (1);
	else if (!index.compare("2"))
		return (2);
	else if (!index.compare("3"))
		return (3);
	else if (!index.compare("4"))
		return (4);
	else if (!index.compare("5"))
		return (5);
	else if (!index.compare("6"))
		return (6);
	else if (!index.compare("7"))
		return (7);
	return (-1);
}

void	handle_full(Phonebook *phonebook)
{
	Contact		new_contact;
	std::string	answer;
	std::string	index;
	int			int_index;
	
	new_contact.empty();
	std::cout << "Phonebook already full. Would you like to replace an existing contact with the new one ? (yes / no) ";
	std::getline(std::cin, answer);
	if (std::cin.eof())
		exit (1);
	if (!answer.compare("yes"))
	{
		std::cout << "Enter the index of the existing contact you wish to replace (anything else to cancel)" << std::endl;
		std::cout << "[0-" << phonebook->get_counter() - 1 << "] > ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			exit (1);
		int_index = get_int_index(index);
		if (int_index >= 0 && int_index <= phonebook->get_counter() - 1)
		{
			std::cout << std::endl << "=== Enter the informations of the new user === " << std::endl;
			new_contact.setup();
			phonebook->repl_contact(new_contact, int_index);
		}
		else
			std::cout << "Chosen index not found. Back to main menu..." << std::endl << std::endl;
	}
	else
		std::cout << "Aborting new user creation..." << std::endl;
}

void	exec_add(Phonebook *phonebook)
{
	Contact	new_contact;

	new_contact.empty();
	if (phonebook->get_counter() >= 8)
		handle_full(phonebook);
	else
	{
		std::cout << std::endl << "=== Enter the informations of the new user === " << std::endl;
		new_contact.setup();
		phonebook->add_contact(new_contact);
	}
}

void	exec_search(Phonebook *phonebook)
{
	std::string	index;
	int			int_index;
	
	if (phonebook->search_contacts())
	{
		std::cout << "Choose the index of the contact you wish to see :" << std::endl;
		std::cout << "[0-" << phonebook->get_counter() - 1 << "] > ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			exit (1);
		int_index = get_int_index(index);
		if (int_index >= 0 && int_index <= phonebook->get_counter() - 1)
			phonebook->display_contact(int_index);
		else
			std::cout << "Chosen index not found. Back to main menu..." << std::endl << std::endl;
	}
}

void	exec(std::string command, Phonebook *phonebook)
{
	if (!command.compare("ADD"))
		exec_add(phonebook);
	else if (!command.compare("SEARCH"))
		exec_search(phonebook);
	else if (!command.compare("EXIT"))
		exit(0);
}

int		main(int ac, char **argv)
{
	Phonebook 	phonebook;
	std::string	command;

	std::cout << "$$$$$$$\\  $$\\                                     $$\\                           $$\\       " << std::endl;
	std::cout << "$$  __$$\\ $$ |                                    $$ |                          $$ |      " << std::endl;
	std::cout << "$$ |  $$ |$$$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\  $$ |  $$\\ " << std::endl;
	std::cout << "$$$$$$$  |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$ | $$  |" << std::endl;
	std::cout << "$$  ____/ $$ |  $$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$$$$$  / " << std::endl;
	std::cout << "$$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |  $$ |$$ |  $$ |$$ |  $$ |$$  _$$<  " << std::endl;
	std::cout << "$$ |      $$ |  $$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$$\\ $$$$$$$  |\\$$$$$$  |\\$$$$$$  |$$ | \\$$\\ " << std::endl;
	std::cout << "\\__|      \\__|  \\__| \\______/ \\__|  \\__| \\_______|\\_______/  \\______/  \\______/ \\__|  \\__|"<< std::endl;
	std::cout << std::endl << "SUPPORTED COMMANDS:" << std::endl;
	std::cout << "--> ADD" << std::endl << "--> SEARCH" << std::endl << "--> EXIT" << std::endl << std::endl;
	if (fill_flag(ac, argv))
		phonebook.fill_phonebook();
	while (1)
	{
		std::cout << "[ADD,SEARCH,EXIT] > ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit (1);
		exec(command, &phonebook);

	}
	return (0);
}
