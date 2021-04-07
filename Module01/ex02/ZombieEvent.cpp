/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:14:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("Soldier")
{
	srand(time(NULL));
}

ZombieEvent::~ZombieEvent()
{}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name, this->_type);
	return (new_zombie);
}

Zombie	*ZombieEvent::randomChump(void)
{
	int			rand_num;
	Zombie		*rand_zombie;
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
	rand_zombie = newZombie(names[rand_num]);
	return (rand_zombie);
}


/* ACCESSORS */
std::string ZombieEvent::get_type(void)
{ return (this->_type); }

/* MUTATORS */
void		ZombieEvent::setZombieType(std::string type)
{ this->_type = type; }
