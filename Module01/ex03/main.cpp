/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:39:36 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:56:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main(void)
{
	std::cout << "=== Creating a horde of 20 zombies ===" << std::endl;
	ZombieHorde	horde(20);
	horde.announce();

	std::cout << std::endl << "=== Creating a horde of 7 zombies ===" << std::endl;
	ZombieHorde	horde2(7);
	horde2.announce();

	std::cout << std::endl;
	return (0);
}
