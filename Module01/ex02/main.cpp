/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:39:36 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:15:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent	zombie_event;
	Zombie		*soldiers[5];
	Zombie		*braineaters[5];

	std::cout << "=== Creating the commander [on the stack since it will stay the whole function] ===" << std::endl;
	Zombie		commander("Hades", "Commander");

	std::cout << std::endl << "=== Creating 5 random zombies with default type [on the heap since they might die before function ends] ===" << std::endl;
	for (int i = 0; i < 5; i++)
		soldiers[i] = zombie_event.randomChump();

	std::cout << std::endl << "=== Creating 5 random zombies with custom types [on the heap since they might die before function ends] ===" << std::endl;
	zombie_event.setZombieType("Braineater");
	for (int i = 0; i < 5; i++)
		braineaters[i] = zombie_event.randomChump();
	
	std::cout << std::endl << "=== Killing soldier zombies ... ===" << std::endl;
	for (int i = 0; i < 5; i++)
		delete(soldiers[i]);

	std::cout << std::endl << "=== Killing custom type zombies ... ===" << std::endl;
	for (int i = 0; i < 5; i++)
		delete(braineaters[i]);

	return (0);
}
