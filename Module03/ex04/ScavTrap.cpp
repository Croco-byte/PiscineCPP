/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:55:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:34:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3)
{
	srand(time(NULL));
	std::cout << "[SCAVTRAP " << this->_name << "]	Bootup sequence complete. Hello! I am your new steward bot." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[SCAVTRAP " << this->_name << "]	The robot is dead. Long live the robot!" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "[" << this->_name << "]	attacks reluctantly " << target << " at melee range, inflicting " << this->_meleeDmg << " damage. You can hear him say \"This isn't my job!\"" << std::endl;

}

void		ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "[" << this->_name << "]	attacks reluctantly " << target << " from afar, inflicting " << this->_rangeDmg << " damage. You can hear him mumble \"Do I look like fu***** Legolas to you?\"" << std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	int		key;
	std::string greetings[5] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance battle! Or you know... regular battle?",
		"Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"
	};

	key = rand() % 5;
	
	std::cout << "[" << this->_name << "]	greets visitor "<< target << ": \"" << greetings[key] << "\"" << std::endl;
}
