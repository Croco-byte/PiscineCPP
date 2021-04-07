/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:30:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:56:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _n(n)
{
	srand(time(NULL));
	this->_zombies = new Zombie [_n];
	for (int i = 0; i < _n; i++)
		setRandName(this->_zombies[i]);
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "Deleting zombies for horde with " << this->_n << " zombies." << std::endl;
	delete [] this->_zombies;
}

void	ZombieHorde::setRandName(Zombie& zombie)
{
	int			rand_num;
	std::string	names[16] = {
		"Cookie", "Nomore",
		"Chawchaw", "Wriggle",
		"Muncher", "Champ",
		"Nitwit", "Chompers",
		"Piggie", "Famine",
		"Bitemark", "Bloatie",
		"Gumze", "Gumgum",
		"Eorgh", "Gobbler"
	};

	rand_num = rand() % 16;
	zombie.set_name(names[rand_num]);
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < _n; i++)
		this->_zombies[i].announce();
}
