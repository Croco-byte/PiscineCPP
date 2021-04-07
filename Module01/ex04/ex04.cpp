/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:02:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 15:07:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* Compiling : clang++ -Wall -Werror -Wextra -o brain ex04.cpp */


int		main(void)
{
	std::string		brain ("HI THIS IS BRAIN");
	std::string		*brainp = &brain;
	std::string		&brainref = brain;

	std::cout << "=== Displaying the string using the pointer ===" << std::endl;
	std::cout << *brainp << std::endl;

	std::cout << std::endl << "=== Displaying the string using the reference ===" << std::endl;
	std::cout << brainref << std::endl;

	return (0);
}
