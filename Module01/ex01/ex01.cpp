/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:15:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 19:24:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak()
{
	std::string*	panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}

/*
	To compile:
	clang++ -Wall -Werror -Wextra ex01.cpp

	To check for leaks:
	valgrind --leak-check=full ./a.out

int		main(void)
{
	memoryLeak();
	return (0);
}
*/
