/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:59:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
{
	srand(time(NULL));
	std::cout << "[FR4G-TP " << this->_name << "]	Bootup sequence ... Directive one: protect humanity. Directive two: Obey Jack. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src._hitPoints,
												src._maxHitPoints,
												src._energyPoints,
												src._maxEnergyPoints,
												src._level,
												src._name,
												src._meleeDmg,
												src._rangeDmg,
												src._armorReduction)
{}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "[FR4G-TP " << this->_name << "]	I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "[FR4G-TP " << this->_name << "]	attacks " << target << " at melee range, inflicting " << this->_meleeDmg << " damage!" << std::endl;

}

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "[FR4G-TP " << this->_name << "]	attacks " << target << " from afar, inflicting " << this->_rangeDmg << " damage!" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorReduction > 0) ? amount - this->_armorReduction : 0;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "[FR4G-TP " << this->_name << "]	takes " << amount - this->_armorReduction << " damage!" << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[FR4G-TP " << this->_name << "]	is repaired for " << amount << " HP!" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int		key;
	std::string attacks[5] = {
		"Miniontrap (FR4G-TP throws out a Turrettrap that shoots explosive rockets)",
		"Meat Unicycle (FR4P-TP periodically emits incendiary novas)",
		"Blight bot (FR4G-TP summons a Sirentrap emitting an acid gas)",
		"Rubber Ducky (FR4G-TP continually bounce in the air and gains bullet reflection)",
		"Funzerker (FR4G-TP deploys a Holotrap and becomes invisible... Shhh...)"
	};

	key = rand() % 5;
	if (this->_energyPoints >= 25)
	{
		std::cout << "[FR4G-TP " << this->_name << "]	uses one of his special attacks on "<< target << ": " << attacks[key] << std::endl;
		this->_energyPoints -= 25;
	}
	else
	{
		std::cout << "[FR4G-TP " << this->_name << "]	doesn't have enough energy for a special attack!" << std::endl;
	}
}
