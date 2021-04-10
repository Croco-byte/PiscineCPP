/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:55:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 12:41:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name):
			_hitPoints(100),
			_maxHitPoints(100),
			_energyPoints(50),
			_maxEnergyPoints(50),
			_level(1),
			_name(name),
			_meleeDmg(20),
			_rangeDmg(15),
			_armorReduction(3)
{
	srand(time(NULL));
	std::cout << "[SCAVTRAP " << this->_name << "]	Bootup sequence complete. Hello! I am your new steward bot." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_maxHitPoints = src._maxHitPoints;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDmg = src._meleeDmg;
		this->_rangeDmg = src._rangeDmg;
		this->_armorReduction = src._armorReduction;
	}
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEnergyPoints = rhs._maxEnergyPoints;
		this->_level = rhs._level;
		this->_meleeDmg = rhs._meleeDmg;
		this->_rangeDmg = rhs._rangeDmg;
		this->_armorReduction = rhs._armorReduction;
	}
	return (*this);
}

void		ScavTrap::displayStatus(void) const
{
	std::cout << std::endl;
	std::cout << "|name -> " << this->_name << "| |HP -> " << this->_hitPoints << "| |EP -> " << this->_energyPoints << "| |level -> " << this->_level << "|" << std::endl;
	std::cout << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[SCAVTRAP " << this->_name << "]	The robot is dead. Long live the robot!" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "[SCAVTRAP " << this->_name << "]	attacks reluctantly " << target << " at melee range, inflicting " << this->_meleeDmg << " damage. You can hear him say \"This isn't my job!\"" << std::endl;

}

void		ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "[SCAVTRAP " << this->_name << "]	attacks reluctantly " << target << " from afar, inflicting " << this->_rangeDmg << " damage. You can hear him mumble \"Do I look like fu***** Legolas to you?\"" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorReduction > 0) ? amount - this->_armorReduction : 0;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "[SCAVTRAP " << this->_name << "]	takes " << amount - this->_armorReduction << " damage. Ouch." << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[SCAVTRAP " << this->_name << "]	is repaired for " << amount << " HP. Thanks buddy." << std::endl;
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
	
	std::cout << "[SCAVTRAP " << this->_name << "]	greets visitor "<< target << ": \"" << greetings[key] << "\"" << std::endl;
}
